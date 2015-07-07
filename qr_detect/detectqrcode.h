#include <stdlib.h>
#include <stdio.h>
#include <sys/timeb.h>

#ifdef UNIX_H_
#include <unistd.h>
#endif
#ifdef WINDOWS_H_
#include <windows.h>
#endif

#include <fcntl.h>
#include <sys/stat.h>

#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <fstream>

#include <opencv2/opencv.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "ARToolKitPlus/TrackerSingleMarker.h"
#include "ARToolKitPlus/ar.h"
#include "../camera_calibration/class/GeometryTypes.hpp"


#define undistort 0//1

using ARToolKitPlus::TrackerSingleMarker;
using ARToolKitPlus::ARMarkerInfo;
using namespace std;
using namespace cv;

/// struct
typedef struct ConerPoint
{
    double X;
    double Y;
    void init(double x1,double y1)
    {
        X= x1;
        Y= y1;
    }
    void init(ConerPoint x1)
    {
        X=x1.X ;
        Y=x1.Y ;

    }
}ConerPoint;

typedef struct CPointsFour
{
    int ID;
    ConerPoint corn0;
    ConerPoint corn1;
    ConerPoint corn2;
    ConerPoint corn3;
    ConerPoint center;

    void init(ConerPoint p0,ConerPoint p1,ConerPoint p2,ConerPoint p3,ConerPoint p4)
    {
        corn0.init(p0);
        corn1.init(p1);
        corn2.init(p2);
        corn3.init(p3);
        center.init(p4);
    }

}CPointsFour;

typedef struct ConerPointWorld
{
    float X;
    float Y;
    float Z;
    void init(float x1,float y1,float z1)
    {
        X= x1;
        Y= y1;
        Z= z1;
    }
    void init(ConerPointWorld x1)
    {
        X=x1.X ;
        Y=x1.Y ;
        Z=x1.Z ;
    }
}ConerPointWorld;

typedef struct CPointsFourWorld
{
    int ID;
    ConerPointWorld corn0;
    ConerPointWorld corn1;
    ConerPointWorld corn2;
    ConerPointWorld corn3;
    ConerPointWorld center;

    void init(ConerPointWorld p0,ConerPointWorld p1,ConerPointWorld p2,ConerPointWorld p3,ConerPointWorld p4)
    {
        corn0.init(p0);
        corn1.init(p1);
        corn2.init(p2);
        corn3.init(p3);
        center.init(p4);
    }

}CPointsFourWorld;



typedef struct CamraInner
{
    double fx;
    double fy;
    double dx;
    double dy;
}CamraInner;

typedef struct QrLandMark
{
    int    Id   ;
    int    Dir  ;
    float  Theta ;
    double X;
    double Y;
    double Side;
}QrLandMark;

typedef std::map <std::string, std::string> MapType;

class DetctQrcode
{
public:
    /// construction & destruction
    DetctQrcode( char * mapFile);
    ~DetctQrcode();

    static const int ar_mode_width  = 640;
    static const int ar_mode_height = 480;
    static const int ar_mode_bpp    = 1;
public:
    /// public method
    vector<CPointsFour>  detectLandmarks(cv::Mat image, int& MarkNum);
    void imTotruePos(double &ar_mode_width, double &ar_mode_height, double theta);
    std::string  int2str(int num);
    void PosToXY(double &ar_mode_width,double &ar_mode_height,double delta);
private:
    /// private method
    std::string arrToStr( const char *c, int i );
    void   createMap(MapType &input_data_, char *filename);
    void   undistortImage( IplImage* frame, cv::Mat & map1,cv::Mat & map2);
    void   gradientNormalizePic(cv::Mat &cutout);
    int    flipv(int y);
    int    fliph(int x);
    double getPan(double a1, double b1,double a2, double b2, int dirNum, int side);
    double combinePan(double pan, double pan2);
    double normalizePan(double pan);
    double calcPan(ARMarkerInfo arcode ,vector<int> orients_);
    void   normalizeOrientation(ARMarkerInfo nMarker_info, vector<int> orients_, int &dirNum,int &v1, int &v2, int &side);
    double averageVector(vector<double> data, double multiplier, double shift, double range ,int bucketAmount);
    double sideCalc(ARMarkerInfo Mark);

    void   loopClear();
    void   ValueToOld(void);
    void   trackerFunction(TrackerSingleMarker *trackerFast);
    void   drawQrcode(void)  ;
    void   drawCoordinate(cv::Mat& mat);
private:
    /// private member
    CamraInner camInnerPara;
    vector<float>   ht_;
    vector<int>     orients_;
    vector<int>     x_off_;
    vector<int>     y_off_;
    vector<int>     side_sizes_;    

    vector<CPointsFourWorld>    corners_world_;

    MapType         input_data_;
    bool            useBCH ;

private:
    vector<double> pan_res_acc;
    double pos_pan_acc;
    cv::Mat camera_matrix_;
    cv::Mat distcoeffs_ ;
    cv::Mat  map1,map2;
    cv::Mat gray ;

    ARMarkerInfo* nMarker_info;
    ARMarkerInfo   Mark;
    int nNumMarkers;
    double pan, old_pan;

    vector<int> detectedID;
    vector< vector<double> > ID_X;
    vector< vector<double> > ID_Y;
    vector< vector<double> > side_size;
    vector< vector<double> > ID_Theta;

    vector< vector<CPointsFour> > coners;
    vector<CPointsFour>  coners_aver;

    QrLandMark  QrMark;
    QrLandMark  Q_temp ;
    QrLandMark  mark_arrys[20];
    bool        found_code ;
    vector<ARMarkerInfo> MarkerPrototypes;
    vector<QrLandMark>   QrMarks;
    std::vector<int>     markerId ;

public:
    cv::Mat res;
    cv::Mat show_landmark_img_;
    TrackerSingleMarker* p_tracker_marks_ =NULL;


    CPointsFour averageCPointsFour(vector<CPointsFour> data, double multiplier, double shift, double range ,int bucketAmount);
    std::vector<cv::Point2f>  points2d_;
    std::vector<cv::Point3f>  points3d_;
    Transformation            pose3d;
    void computePose(void);
    void  getQrPos(void) ;
    float r_[3];
    float t_[3];

};

