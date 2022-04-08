#include <iostream>
#include <pcl/io/pcd_io.h>
#include "stdafx.h"
using namespace std;


int numofPoints(char* fname){
    int n_points = 0;
    int c = 0;
    FILE *fp;
    fp = fopen(fname, "r");
    do{
        c = fgetc(fp);
        if(c=='\n'){
            ++n_points;
        }
    }while(c!=EOF);

    fclose(fp);
    return n_points;
}


int main()
{
    // the counter of points within one file.
    int n_points = 0; 
    FILE *fp_1;
    fp_1 = fopen("1.xyz","r");
    n_points = numofPoints("1.xyz");
    cout<<"There are "<<n<<" point in the file ..."<<endl;

    // Create a cloud point file and put the xyz value to a points cloud pointer.
    pcl::PointCloud<pcl::PointXYZ> cloud;
    cloud.width = n;
    cloud.height = 1;
    cloud.is_dense = false;
    cloud.points.resize(cloud.width*cloud.height);

    // Put the points cloud to new points cloud pointer x, y, z
    double x, y, z;
    int i=0;
    while(3==fscanf(fp_1, "%lf, %lf, %lf\n", &x, &y, &z)){
        cloud.points[i].x = x;
        cloud.points[i].y = y;
        cloud.points[i].z = z;
        ++i;
    }
    fclose(fp_1);

    // put points cloud information to a pcd file
    pcl::io::savePCDFileASCII("03.pcd", cloud);
    std::cerr<<"Saved "<<cloud.points.size()<<" data points to test_pcd.pcd."<<std::endl;
    system(pause);

    return 0;
}

