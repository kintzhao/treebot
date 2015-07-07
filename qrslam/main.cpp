//#include "../qr_detect/detectqrcode.h"
#include "./CameraEstimation.h"
#include "../serialport/serialport.h"

int main(int argc, char** argv)
{
   // CameraEstimation cam_qr_estimation(argv[1]);
    CameraEstimation pCam_qr_estimation ;//= new CameraEstimation();
    int cam_id = atoi(argv[2]);
    pCam_qr_estimation.Init(argv[1], cam_id);
    while (1)
    {
        pCam_qr_estimation.run();
        if (cvWaitKey(5) == 27)
        {
            break;
        }
       // namedWindow("edges",1);
        //imshow("edges", pCam_qr_estimation.frame);
       // cv::waitKey(10);
    }
    exit(0);
    return 0;
}











