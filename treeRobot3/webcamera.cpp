#include "webcamera.h"
WebCamera::WebCamera(QWidget *parent) : QMainWindow(parent)
{
    QCameraInfo cameraInfo;
    QList<QCameraInfo> cameraInfoList = cameraInfo.availableCameras();
    camera = new QCamera(cameraInfoList.last());

    viewFinder = new QCameraViewfinder();
    //viewFinder->show();

    camera->setViewfinder(viewFinder);

    imageCapture = new QCameraImageCapture(camera);
    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->start();


}

WebCamera::~WebCamera()
{

}

