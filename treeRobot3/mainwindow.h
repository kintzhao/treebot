/****************************************
 * MainWindow
 * Chaomin
****************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
//#include <QCamera>
//#include <QCameraInfo>
//#include <QCameraImageCapture>
//#include <QCameraViewfinder>
#include <QImage>
#include "serialport.h"
#include "slidervelocity.h"
#include <QLabel>
//===========kint======================
#include "../qrslam/CameraEstimation.h"
#include <fstream>

//===========kint======================
namespace Ui {
class MainWindow;
}
class CommandData
{
public:
    bool keyUp;
    bool keyDown;
    bool stateLeftLock;
    bool stateMiddleLock;
    bool stateRightLock;
    bool stateTopLock;
    bool stateRearLock;
    int velocity;
    QByteArray  bytesCommand;
    CommandData(){keyUp=false;keyDown=false;stateLeftLock=false;
                  stateMiddleLock=false;stateRightLock=false;
                  stateTopLock=false;stateRearLock=false;velocity=0;
                 bytesCommand.resize(13);}
    ~CommandData(){}
    QByteArray& getBytesCommand()
    {
        keyUp           ==true?bytesCommand[0]='Y':bytesCommand[0]='N';
        keyDown         ==true?bytesCommand[1]='Y':bytesCommand[1]='N';
        stateLeftLock   ==true?bytesCommand[2]='Y':bytesCommand[2]='N';
        stateMiddleLock ==true?bytesCommand[3]='Y':bytesCommand[3]='N';
        stateRightLock  ==true?bytesCommand[4]='Y':bytesCommand[4]='N';
        stateTopLock    ==true?bytesCommand[5]='Y':bytesCommand[5]='N';
        stateRearLock   ==true?bytesCommand[6]='Y':bytesCommand[6]='N';
        bytesCommand.replace(7,4,intToByteArray(velocity));
        //quint16 crc = qChecksum(bytesCommand.data(),11);
        //bytesCommand.replace(11,2,uin16ToByteArrat(qChecksum(bytesCommand.data(),11)));
        bytesCommand.replace(11,2,Get_Crc16((uchar*)bytesCommand.data(),11));
        return bytesCommand;
    }
};

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
    QLabel *msgLabel;   //status bar label
    QByteArray&  commandToTreeBot(CommandData &c);
    CommandData commandData;
    void openFile();
    //slots
//    void updatedEulerDataFromSP(const QString &fy,const QString &fp,const QString &fr
////                                ,const QString &ry,const QString &rp,const QString &rr,
////                                const QString &l,const QString &w,const QString &h
//                                );
    void updatedEulerDataFromSP(const QStringList& s);
    void sendDataBySP();
    void CVDataSyn();
    void openSerialPort();
    void velocityChanged(int v);
    void SlotCommandDataSend();
    void synButtonPortText();
    void slotStartRecording();
    void slotCameraOpen();      //signal relay
    void slotUpdateSerialPortNames();
signals:
    void dataSentBySP(const QString &s);
    void signalCommandDataSend();
    void signalCameraOpen(int id);     ////??
    void signalOpenFile(const QString s);
    void signalUpdateSerialPortNames();
private:
    Ui::MainWindow *ui;
    SliderVelocity *sliderVelocity;
    bool isRecording;
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

           // string fileName;
          const  char* fileName ;

        protected:
            void timerEvent(QTimerEvent *event);
            void  dataRecorder(void );
            void  openCamera(int id);
            void  loadConfigure(QString fileName);

            bool  camera_is_opened;
            bool  configure_is_finished;

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
            cv::Mat display_img;
        signals:
            void imageReady();
     //========================kint======================
};

#endif // MAINWINDOW_H
