/* read me :
 *1. the num of qrcode N :we init as the static..    --->>> the method of vector add.
 *
 *2.
 *
 *
*/
// ***ros 里程订阅的修改
//   标记  //rosOdom

#include "CameraEstimation.h"

CameraEstimation::CameraEstimation()
{  
    is_img_update  = false;

}

CameraEstimation::~CameraEstimation()
{
    delete pQrDetect_;
    cvReleaseCapture( &capture );
    cvReleaseImage( &frame_temp );
    cap.release();
}

bool CameraEstimation::openCamera(int camId)
{
    cap.open(camId); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
    {
        cout<<"!!!!!!!!!!!!!please plus usb camera !!!"<<endl ;
        cout<<"!!!!!!!!!!!!!please plus usb camera !!!"<<endl ;
        cv::waitKey(100000);
        return false;
    }
    else
    {
        cout<<"usb camera  has plused !!!"<<endl ;
        // pQrDetect_ = new DetctQrcode(addr);
        return true;
    }
}
bool CameraEstimation::initConfigure(char* addr)
{
    if(addr != NULL)
    {
        pQrDetect_ = new DetctQrcode(addr);
        return true;
    }
    else
        return false ;
}

bool CameraEstimation::Init(char* addr,int camId)
{
    cap.open(camId); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
    {
        cout<<"!!!!!!!!!!!!!please plus usb camera !!!"<<endl ;
        cout<<"!!!!!!!!!!!!!please plus usb camera !!!"<<endl ;
        cv::waitKey(100000);
        return false;
    }
    else
    {
        cout<<"usb camera  has plused !!!"<<endl ;
        pQrDetect_ = new DetctQrcode(addr);
        return true;
    }
}



std::string  CameraEstimation::int2str(int num)
{
    std::stringstream ss;
    ss << num;
    std::string text = ss.str();
    return text;

}

void CameraEstimation::drawCoordinate(cv::Mat& mat)
{
    std::string text ="Y";
    cv::putText(mat,text,cvPoint(20,20),CV_FONT_HERSHEY_COMPLEX,1,CV_RGB(0,0,255));
    cv::line(mat,cv::Point(1,1),cv::Point(1,mat.rows),CV_RGB(255,0,0),1,8);

    text ="O";
    cv::putText(mat,text,cvPoint(20,mat.rows-20),CV_FONT_HERSHEY_COMPLEX,1,CV_RGB(0,0,255));

    text ="X";
    cv::putText(mat,text,cvPoint(mat.cols-20,mat.rows-20),CV_FONT_HERSHEY_COMPLEX,1,CV_RGB(0,0,255));
    cv::line(mat,cv::Point(1,mat.rows-1),cv::Point(mat.cols,mat.rows-1),CV_RGB(255,0,0),1,8);
}


bool CameraEstimation::run(void)
{
    // cap >> frame; // get a new frame from camera
    bool frame_is_getted = cap.read(frame);
    if(frame_is_getted)
    {
        cout<<"cam_capture success"<<endl  ;
    }
    else {
        cout<<"cam_capture erro"<<endl;
        cout<<"sorrry,please replug the usb camera !!"<<endl;
        return false;
    }
    img_points_four =  pQrDetect_->detectLandmarks(frame,qr_num);
    pQrDetect_->getQrPos();
    if(!pQrDetect_->points2d_.empty())
    {
        pQrDetect_->computePose();
        is_img_update = true;  // pQrDetect_->QrCodeMapping(visual_mark_num_,robot_pose); //获取的观测值是实际物理距离值
        cout<<pQrDetect_->points2d_.size()<<endl;
    }
    return true;
}
