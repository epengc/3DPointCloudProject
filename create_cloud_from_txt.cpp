#include <pcl/visualization/pcl_visualizer.h>
#include <boost/thread/thread.hpp>
#include <ctime>

/*--Read txt file --
 *
--------------------*/

void CreateCloudFromTxt(const std::string &file_path, pcl::PointCloud<pcl::PointXYZ>::Ptr cloud){
    std::ifstream file(file_path.c_str());
    std::string line;
    pcl::PointXYZ point;
    while(getline(file,line)){
        std::stringstream ss(line);
        ss>>point.x;
        ss>>point.y;
        ss>>point.z;
        cloud->push_back(point);
    }
    file.close();
}


void Visualization(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud){
    // using boost::shared_ptr to release the ptr automaticaly
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("viewer"));
    // add the needs point cloud data
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> single_color(cloud, 255, 0, 0);
    viewer->addPointCloud<pcl::PointXYZ>(cloud, single_color, "example");
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 2, "example");
    while(!viewer->wasStopped()){
        viewer->spinOnce(100);
        boost::this_thread::sleep(boost::posix_time::microseconds(100000));
    }
}


int main(int argc, char** argv){
    if(argc<2) std::cout << "Usage: $>creat_cloud_from_txt --file_path" << std::endl;
    clock_t start, end;
    start = clock();
    // load the point cloud from txt file
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    CreateCloudFromTxt(argc[1], cloud);
    end=clock();
    std::cout<<"Runtime of the code: "<<(double)(end-start)<<" ms"<<endl;

    // display the point cloud
    Visualization(cloud);
    return 0;
}

