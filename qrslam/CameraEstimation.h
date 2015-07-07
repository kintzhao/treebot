#ifndef CameraEstimation_H
#define CameraEstimation_H

#ifdef WINDOWS_H_
#include <windows.h>
#endif

#include <stdlib.h>
#include <stdio.h>


#ifdef UNIX_H_
#include <unistd.h>
#endif

#include <fcntl.h>
#include <sys/stat.h>

#include <cstring>
#include <cstdio>
#include <math.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>

#include <opencv2/opencv.hpp>
#include <opencv/cv.h>
#include <fstream>

#include "../qr_detect/detectqrcode.h"

#define undistort 0//1

using ARToolKitPlus::TrackerSingleMarker;
using ARToolKitPlus::ARMarkerInfo;
using namespace std;
using namespace cv;


class CameraEstimation
{
public :
    CameraEstimation();
    ~CameraEstimation();

    DetctQrcode*  pQrDetect_;
    bool run(void) ;
    vector<CPointsFour>  img_points_four;
    int qr_num;


    //public function
    std::string  int2str(int num);
    void  showImage() ;
    void  getNumQrcode(void);
    bool  openCamera(int camId);
    bool  initConfigure(char *addr);


//display
    static const int MAP_BASE_Y_ = 150 ;
    static const int MAP_BASE_X_ = 500 ;


    void drawCoordinate(cv::Mat& mat);
    void storeData(void );
    bool is_odom_update ;
    bool is_img_update;

    VideoCapture cap;
    Mat frame;
    bool Init(char* addr,int camId);
    CvCapture* capture;
    IplImage* frame_temp;
};

#endif
