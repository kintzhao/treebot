#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "treerobotconstant.h"
#include <QtWidgets>
#include <QObject>
#include <QLabel>
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //serialPort initialize
    serial = new serialPort(this);
    ui->comboBox->addItems(serial->getSerialPortList());
    QObject::connect(serial,&serialPort::eulerDataUpdated,this,&MainWindow::updatedEulerDataFromSP);

    //velocity ui
    //sliderVelocity = new SliderVelocity(this);
    //sliderVelocity->setRange(0,100);
    ui->horizontalSliderVelocity->setRange(0,100);
    ui->spinBoxVelocity->setRange(0,100);
    //QObject::connect(sliderVelocity,&SliderVelocity::valueChanged,ui->spinBoxVelocity,&QSpinBox::setValue);
    QObject::connect(ui->horizontalSliderVelocity,&SliderVelocity::valueChanged,ui->spinBoxVelocity,&QSpinBox::setValue);
    void (QSpinBox::*spinBoxSignal)(int) = &QSpinBox::valueChanged;
    QObject::connect(ui->spinBoxVelocity,spinBoxSignal,ui->horizontalSliderVelocity,&SliderVelocity::setValue);
    //QObject::connect(ui->spinBoxVelocity,spinBoxSignal,sliderVelocity,&SliderVelocity::setValue);
    QObject::connect(ui->horizontalSliderVelocity,&SliderVelocity::signalvalueChanged,this,&MainWindow::velocityChanged);
    //QObject::connect(ui->spinBoxVelocity,spinBoxSignal,this,&MainWindow::velocityChanged);
    //QObject::connect(sliderVelocity,&SliderVelocity::signalvalueChanged,this,&MainWindow::velocityChanged);

    //status bar set

    msgLabel = new QLabel;
    msgLabel->setMinimumSize(msgLabel->sizeHint());
    msgLabel->setAlignment(Qt::AlignHCenter);
    statusBar()->addWidget(msgLabel);
    //statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}"));


//    QCameraInfo cameraInfo;
//    QList<QCameraInfo> cameraInfoList = cameraInfo.availableCameras();
//    camera = new QCamera(cameraInfoList.last());
//    viewFinder = new QCameraViewfinder();
//    imageCapture = new QCameraImageCapture(camera);
//    ui->horizontalLayoutView->addWidget(viewFinder);
//    camera->setViewfinder(viewFinder);
//    camera->setCaptureMode(QCamera::CaptureStillImage);
//    camera->start();

    QObject::connect(ui->pushButtonSend,&QPushButton::clicked,this,&MainWindow::sendDataBySP);
    QObject::connect(ui->pushButtonOpenPort,&QPushButton::clicked,this,&MainWindow::openSerialPort);
    QObject::connect(ui->pushButtonClosePort,&QPushButton::clicked,this,&MainWindow::closeSerialPort);

    this->installEventFilter(this);


    //===========kint======================
    // 开启一个1秒定时器，返回其ID
    id1 = startTimer(50);
    QObject::connect(this,&MainWindow::imageReady,this,&MainWindow::imgShow);
    camera_init_finish =false;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pCam_qr_estimation;
}
void MainWindow::updatedEulerDataFromSP(const QString &y,const QString &p,const QString &r)
{
    ui->labelPitchValueFromSP->setText(p);
    ui->labelRollValueFromSP->setText(r);
    ui->labelYawValueFromSP->setText(y);
}
void MainWindow::sendDataBySP()
{
    QString str = ui->textEdit->toPlainText();
    serial->writeData(str.toLocal8Bit());
}
void MainWindow::CVDataSyn()
{

}

void MainWindow::openSerialPort()
{
    serial->openSerialPort(ui->comboBox->currentText());
    msgLabel->setText(serial->getPortStatus());
}
void MainWindow::closeSerialPort()
{
    serial->closeSerialPort();
    msgLabel->setText(serial->getPortStatus());
}
void MainWindow::velocityChanged(int v)
{
    serial->writeData(SET_VELOCITY);
    serial->writeData(v);
    qDebug()<<"Velocity: "<<v;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type()==QEvent::KeyPress)
    {
        handleKeyPressed((QKeyEvent *)event);
        return true;
    }
    else if(event->type()==QEvent::KeyRelease)
    {
        handleKeyRelease((QKeyEvent *)event);
        return true;
    }
    else
    {
        return QObject::eventFilter(obj,event);
    }
}
void MainWindow::handleKeyRelease(QKeyEvent *event)
{
    ui->labelDirectionStatus->setText(QObject::tr("NULL"));
}

void MainWindow::handleKeyPressed(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_A:
        serial->writeData(SET_DIRECTION_LEFT);
        ui->labelDirectionStatus->setText(QObject::tr("Left"));
        qDebug()<<"Direction: Left";
        break;
    case Qt::Key_S:
        serial->writeData(SET_DIRECTION_RIGHT);
        ui->labelDirectionStatus->setText(QObject::tr("Right"));
        qDebug()<<"Direction: Right";
        break;
    case Qt::Key_W:
        serial->writeData(SET_DIRECTION_UP);
        ui->labelDirectionStatus->setText(QObject::tr("Up"));
        qDebug()<<"Direction: Up";
        break;
    case Qt::Key_D:
        serial->writeData(SET_DIRECTION_DOWN);
        ui->labelDirectionStatus->setText(QObject::tr("Down"));
        break;
    }
}

//===========kint======================

void MainWindow::timerEvent(QTimerEvent *event)
{
    // 判断是哪个定时器
    if(event->timerId() == id1 )
    {
       qDebug() << "timer1";
        if(camera_init_finish) //初始判断
        {
            bool run_state = pCam_qr_estimation->run();
            if (!run_state)  // 重插式
            {
                cout<<"============================================================="<<endl;
                cout<<"waitting for replus the usb camera !!"<<endl;
                cout<<"replus the usb camera ,camera will reinit and be ok !!"<<endl;
                cout<<"============================================================="<<endl;
                cv::waitKey(1000);
                pCam_qr_estimation->Init(configure_file,camera_ID);
            }
            else //  释放信号
            {
                pCam_qr_estimation->pQrDetect_->t_[0];
                qimg = Mat2QImage(pCam_qr_estimation->frame);
                img_test = QImage2Mat(qimg);
                emit imageReady();
           }
        }
        else
        {
            qDebug() << "  camera init not finish ";
            init(configure_file,camera_ID);
        }
    }
    else
    {
        qDebug() << "timer erro  ";
    }
}
void MainWindow::init(char* addr,int camId)
{
    camera_ID = camId;
    configure_file = addr;
   pCam_qr_estimation = new CameraEstimation;
   bool camera_state =  pCam_qr_estimation->Init(addr,camId) ;
   if(!camera_state)
   {
       cout<<"usb  camera does not plug in !"<<endl;
       cout<<"please close program  and plug in usb camera ,then restart it !"<<endl;
       //getchar();
       camera_init_finish = false;
   }
   else
   {
       cout <<"camera open !"<<endl;
       camera_init_finish = true;
   }
}


QImage MainWindow::Mat2QImage(cv::Mat const& src)
{
     cv::Mat temp; // make the same cv::Mat
     cvtColor(src, temp,CV_BGR2RGB); // cvtColor Makes a copt, that what i need
     QImage dest((const uchar *) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
     dest.bits(); // enforce deep copy, see documentation
     // of QImage::QImage ( const uchar * data, int width, int height, Format format )
     return dest;
}

cv::Mat MainWindow::QImage2Mat(QImage const& src)
{
     cv::Mat tmp(src.height(),src.width(),CV_8UC3,(uchar*)src.bits(),src.bytesPerLine());
     cv::Mat result; // deep copy just in case (my lack of knowledge with open cv)
     cvtColor(tmp, result,CV_BGR2RGB);
     return result;
}
void MainWindow::imgShow()
{
    //qimg.load("/home/yhzhao/Desktop/12.png");
    ui->labelImage->setPixmap(QPixmap::fromImage(qimg));
    qDebug()<<"Tigger";
}




