#-------------------------------------------------
#
# Project created by QtCreator 2014-05-01T14:24:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pcl_visualizer
TEMPLATE = app


SOURCES += main.cpp\
        pclviewer.cpp

HEADERS  += pclviewer.h

FORMS    += pclviewer.ui

# Boost
INCLUDEPATH += /usr/include/boost
LIB += /usr/lib/x86_64-linux-gnu/libboost_*.so

#VTK
INCLUDEPATH += /usr/local/include/vtk-7.1
LIBS += /usr/local/lib/libvtk*.so

#PCL Header
INCLUDEPATH += /usr/include/pcl-1.8/
LIBS += /usr/lib/libpcl_*.so
