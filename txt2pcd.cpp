#include <iostream>
#include <fstream>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
using namespace std;


typedef struct tagPOINT_3D{
    double x;
    double y;
    double z;
    double nx;
    double ny;
    double nz;
}POINT_WORLD


int main()
{
    // the counter of points within one file.
    int number_txt; 
    FILE *fp_txt;
    tagPOINT_3D TxtPoint;
    vector<tagPOINT_3D> m_vTxtPoints;
    string file_name = "/home/epengc/Documents/3DPointCloudProject/*.txt";
    fp_txt = fopen(file_name,"r");

    if(fp_txt){
        while(6==fscanf(fp_txt, "%lf, %lf, %lf, %lf, %lf, %lf", 
                        &TxtPoint.x, &TxtPoint.y, &TxtPoint.z, 
                        &TxtPoint.nx, &TxtPoint.ny, &TxtPoint.nz)){
            m_vTxtPoints.push_back(TxtPoint);
        }
    }else(cout<<"Txt data is fail for loading."<<endl;)

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
    
    pcl::io::savePCDFileASCII("/home/epengc/Documents/3DPointCloudProject/*.pcd", *cloud);
    std::cerr<<"Saved "<<cloud->points.size()<<" data points to txt2pcd.pcd."<<std::endl;
    
    // PCL Visualizer
    pcl::visualization::PCLVisualizer viewer("Cloud Viewer");
    viewer.addPointCloud(cloud);
    viewer.setBackgroundColor(1, 0.5, 1);
    viewer.spin();
    system("pause");

    return 0;
}

