 #ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QImage>
#include "serialport.h"
#include "slidervelocity.h"
#include <QLabel>
//===========kint======================
#include "../qrslam/CameraEstimation.h"
//===========kint======================
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    serialPort* serial;
//    QCamera *camera;
//    QCameraViewfinder *viewFinder;
//    QCameraImageCapture *imageCapture;
    QImage *image;
    QLabel *msgLabel;
    //slots
    void updatedEulerDataFromSP(const QString &y,const QString &p,const QString &r);
    void sendDataBySP();
    void CVDataSyn();
    void openSerialPort();
    void closeSerialPort();
    void velocityChanged(int v);
signals:
    void dataSentBySP(const QString &s);
private:
    Ui::MainWindow *ui;
    SliderVelocity *sliderVelocity;
    void handleKeyPressed(QKeyEvent *event);
    void handleKeyRelease(QKeyEvent *event);
protected:
    bool eventFilter(QObject *, QEvent *);  //key'event filter
//========================kint======================
    public:
        CameraEstimation* pCam_qr_estimation ;
        void init(char* addr,int camId);
        QImage Mat2QImage(cv::Mat const& src) ;
        cv::Mat QImage2Mat(QImage const& src) ;

    protected:
        void timerEvent(QTimerEvent *event);

    public:
        float r_[3];
        float t_[3];
        void imgShow();
        QImage qimg;
        QPixmap pm;
        cv::Mat img_test;
        int id1,id2,id3;
        int camera_ID;
        char* configure_file;
        bool camera_init_finish;
    signals:
        void imageReady();
 //========================kint======================
};

#endif // MAINWINDOW_H
