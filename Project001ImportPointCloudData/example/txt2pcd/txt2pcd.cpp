#include <iostream>
#include <fstream>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
using namespace std;


struct tagPOINT_3D{
    double x;
    double y;
    double z;
   // double nx;
   // double ny;
   // double nz;
};


tagPOINT_3D Parseline(string line){
    istringstream sline(line);
    double d;
    char c ;
    tagPOINT_3D tagpoint_3d;
    sline>>tagpoint_3d.x>>c>>tagpoint_3d.y>>c>>tagpoint_3d.z>>c>>d>>c>>d>>c>>d>>c;
    return tagpoint_3d;
}


int main()
{
    // the counter of points within one file.
    int number_txt; 
    vector<tagPOINT_3D> m_vTxtPoints;
    string file_name = "./airplane_0001.txt";

    ifstream txtfile (file_name);
    if(txtfile){
        string line;
        while(getline(txtfile, line)){
            m_vTxtPoints.push_back(Parseline(line));
        }
    }else{cout<<"Txt data is fail for loading."<<endl;}

    number_txt = m_vTxtPoints.size();
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

    // Fill in the cloud data
    cloud->width = number_txt;
    cloud->height = 1;
    cloud->is_dense = false;
    cloud->points.resize(cloud->width*cloud->height);

    for(int i=0; i<cloud->points.size(); ++i){
        cloud->points[i].x = m_vTxtPoints[i].x;
        cloud->points[i].y = m_vTxtPoints[i].y;
        cloud->points[i].z = m_vTxtPoints[i].z;
    }
    
    pcl::io::savePCDFileASCII("./airplane_0001.pcd", *cloud);
    std::cerr<<"Saved "<<cloud->points.size()<<" data points to txt2pcd.pcd."<<std::endl;
    
    // PCL Visualizer
    pcl::visualization::PCLVisualizer viewer("Cloud Viewer");
    viewer.addPointCloud(cloud);
    viewer.setBackgroundColor(1, 0.5, 1);
    viewer.spin();
    system("pause");

    return 0;
}

