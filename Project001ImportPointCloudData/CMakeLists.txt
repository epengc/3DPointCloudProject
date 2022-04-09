cmake_minimum_required(VERSION 2.8)
project(DisplayPointCloud)

set(CMAKE_BUILD_TYPE "DEBUG_MODE")
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(PCL 1.10 REQUIRED COMPONENT common io visualization)
find_package(Boost 1.71.0 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

add_definitions(${PCL_DEFINITIONS})
add_executable(create_cloud_from_txt create_cloud_from_txt.cpp)
target_link_libraries(create_cloud_from_txt ${PCL_LIBRARIES})
target_link_libraries(create_cloud_from_txt ${Boot_LIBRARIES})

