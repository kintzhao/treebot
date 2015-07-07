/****************************************
 * MainWindow
 * Chaomin
****************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "treerobotconstant.h"
#include <QtWidgets>
#include <QObject>
#include <QLabel>
#include <QPushButton>
ofstream fout;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //not recording..
    isRecording=false;

    //serialPort initialize
    serial = new serialPort(this);
    ui->comboBox->addItems(serial->getSerialPortList());
    //===================kint
    QObject::connect(serial,&serialPort::eulerDataUpdated,this,&MainWindow::updatedEulerDataFromSP);
    QObject::connect( this, &MainWindow::signalCameraOpen,this,&MainWindow::openCamera);

    //===================kint

    //velocity slider initilize
    ui->horizontalSliderVelocity->setRange(0,100);
    ui->spinBoxVelocity->setRange(0,100);
    QObject::connect(ui->horizontalSliderVelocity,&SliderVelocity::valueChanged,ui->spinBoxVelocity,&QSpinBox::setValue);
    void (QSpinBox::*spinBoxSignal)(int) = &QSpinBox::valueChanged;
    QObject::connect(ui->spinBoxVelocity,spinBoxSignal,ui->horizontalSliderVelocity,&SliderVelocity::setValue);
    QObject::connect(ui->horizontalSliderVelocity,&SliderVelocity::signalvalueChanged,this,&MainWindow::velocityChanged);
    //status bar set
    msgLabel = new QLabel;
    msgLabel->setMinimumSize(msgLabel->sizeHint());
    msgLabel->setAlignment(Qt::AlignHCenter);
    statusBar()->addWidget(msgLabel);
    //statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}"));
    QObject::connect(ui->pushButtonOpenFile,&QPushButton::clicked,this,&MainWindow::openFile);

    //    QCameraInfo cameraInfo;
    //    QList<QCameraInfo> cameraInfoList = cameraInfo.availableCameras();
    //    camera = new QCamera(cameraInfoList.last());
    //    viewFinder = new QCameraViewfinder();
    //    imageCapture = new QCameraImageCapture(camera);
    //    ui->horizontalLayoutView->addWidget(viewFinder);
    //    camera->setViewfinder(viewFinder);
    //    camera->setCaptureMode(QCamera::CaptureStillImage);
    //    camera->start();
    QObject::connect(ui->pushButtonRecord,&QPushButton::clicked,this,&MainWindow::slotStartRecording);
    QObject::connect(ui->pushButtonOpenCamera,&QPushButton::clicked,this,&MainWindow::slotCameraOpen);
    QObject::connect(ui->pushButtonSend,&QPushButton::clicked,this,&MainWindow::sendDataBySP);
    QObject::connect(ui->pushButtonOpenPort,&QPushButton::clicked,this,&MainWindow::openSerialPort);
    //QObject::connect(ui->pushButtonClosePort,&QPushButton::clicked,this,&MainWindow::closeSerialPort);
    QObject::connect(this,&MainWindow::signalCommandDataSend,this,&MainWindow::SlotCommandDataSend);
    this->installEventFilter(this);
    QObject::connect(this,&MainWindow::signalUpdateSerialPortNames,this,&MainWindow::slotUpdateSerialPortNames);
    QObject::connect(this,&MainWindow::signalOpenFile,this,&MainWindow::loadConfigure);
    //==================kint======================
    // 开启一个1秒定时器，返回其ID
    id1 = startTimer(50);
    QObject::connect(this,&MainWindow::imageReady,this,&MainWindow::imgShow);
    camera_init_finish =false;
    pCam_qr_estimation = new CameraEstimation;
    camera_is_opened =false;
    configure_is_finished = false;
    //==================kint======================//

}

MainWindow::~MainWindow()
{
    delete ui;
    delete pCam_qr_estimation;
}
/*
//void MainWindow::updatedEulerDataFromSP(const QString &fy, const QString &fp, const QString &fr
////                                        ,const QString &ry, const QString &rp, const QString &rr,
////                                        const QString &l,const QString &w,const QString &h
//                                        )
//{
//    ui->labelF1FromSP->setText(fp);
//    ui->labelF2FromSP->setText(fr);
//    ui->labelF3FromSP->setText(fy);
////    ui->labelR1FromSP->setText(rp);
////    ui->labelR2FromSP->setText(rr);
////    ui->labelR3FromSP->setText(ry);
////    ui->labelLFromSP->setText(l);
////    ui->labelWFromSP->setText(w);
////    ui->labelHFromSP->setText(h);

//}
*/
void MainWindow::updatedEulerDataFromSP(const QStringList &s)
{
    ui->labelF1FromSP->setText(s[0]);
    ui->labelF2FromSP->setText(s[1]);
    ui->labelF3FromSP->setText(s[2]);
    ui->labelR1FromSP->setText(s[3]);
    ui->labelR2FromSP->setText(s[4]);
    ui->labelR3FromSP->setText(s[5]);
    ui->labelLFromSP->setText(s[6]);
    ui->labelWFromSP->setText(s[7]);
    ui->labelHFromSP->setText(s[8]);

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
    //qDebug()<<serial->isPortOpened();
    if(!serial->isPortOpened())
    {
        serial->openSerialPort(ui->comboBox->currentText());
    }
    else
    {
        serial->closeSerialPort();
    }
    msgLabel->setText(serial->getPortStatus());
    synButtonPortText();
}
void MainWindow::velocityChanged(int v)
{
    emit signalCommandDataSend();
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
    //msgLabel->setText(QObject::tr("NULL"));
    switch(event->key())
    {
    case Qt::Key_S:
        ui->pushButtonKey_S->setStyleSheet("background-color:#ffffff");
        commandData.keyDown=false;
        msgLabel->setText(QObject::tr("Key_S released."));
        break;
    case Qt::Key_W:
        ui->pushButtonKey_W->setStyleSheet("background-color:#ffffff");
        commandData.keyUp=false;
        msgLabel->setText(QObject::tr("Key_W released."));
        break;
    }

}

void MainWindow::handleKeyPressed(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_S:
        msgLabel->setText(QObject::tr("Key_S pressed."));
        ui->pushButtonKey_S->setStyleSheet("background-color:#0055ff");
        qDebug()<<"Key_S pressed.";
        commandData.keyDown=true;
        emit signalCommandDataSend();
        break;
    case Qt::Key_W:
        msgLabel->setText(QObject::tr("Key_W pressed."));
        ui->pushButtonKey_W->setStyleSheet("background-color:#0055ff");
        qDebug()<<"Key_W pressed.";
        commandData.keyUp=true;
        emit signalCommandDataSend();
        break;
    case Qt::Key_1:
        if(ui->checkBoxKey_1->checkState()==Qt::Checked)
        {
            ui->checkBoxKey_1->setCheckState(Qt::Unchecked);
        }
        else
        {
            ui->checkBoxKey_1->setCheckState(Qt::Checked);
        }
        qDebug()<<"Key_1 pressed.";
        break;
    case Qt::Key_2:
        if(ui->checkBoxKey_2->checkState()==Qt::Checked)
        {
            ui->checkBoxKey_2->setCheckState(Qt::Unchecked);
        }
        else
        {
            ui->checkBoxKey_2->setCheckState(Qt::Checked);
        }
        qDebug()<<"Key_2 pressed.";
        break;
    case Qt::Key_3:
        if(ui->checkBoxKey_3->checkState()==Qt::Checked)
        {
            ui->checkBoxKey_3->setCheckState(Qt::Unchecked);
        }
        else
        {
            ui->checkBoxKey_3->setCheckState(Qt::Checked);
        }
        qDebug()<<"Key_3 pressed.";
        break;
    case Qt::Key_4:
        if(ui->checkBoxKey_4->checkState()==Qt::Checked)
        {
            ui->checkBoxKey_4->setCheckState(Qt::Unchecked);
        }
        else
        {
            ui->checkBoxKey_4->setCheckState(Qt::Checked);
        }
        qDebug()<<"Key_4 pressed.";
        //=============Chaomin 0627 19:19===========
        emit signalCommandDataSend();
        //==========================================
        break;
    case Qt::Key_5:
        if(ui->checkBoxKey_5->checkState()==Qt::Checked)
        {
            ui->checkBoxKey_5->setCheckState(Qt::Unchecked);
        }
        else
        {
            ui->checkBoxKey_5->setCheckState(Qt::Checked);
        }
        qDebug()<<"Key_5 pressed.";
        //=============Chaomin 0627 19:19===========
        emit signalCommandDataSend();
        //==========================================
        break;
    }
}

QByteArray& MainWindow::commandToTreeBot(CommandData & c)
{
    ui->checkBoxKey_1->checkState()==0?c.stateLeftLock=false:c.stateLeftLock=true;
    ui->checkBoxKey_2->checkState()==0?c.stateMiddleLock=false:c.stateMiddleLock=true;
    ui->checkBoxKey_3->checkState()==0?c.stateRightLock=false:c.stateRightLock=true;
    ui->checkBoxKey_4->checkState()==0?c.stateTopLock=false:c.stateTopLock=true;
    ui->checkBoxKey_5->checkState()==0?c.stateRearLock=false:c.stateRearLock=true;
    c.velocity = ui->horizontalSliderVelocity->value();
    return c.getBytesCommand();
}

void MainWindow::SlotCommandDataSend()
{
    qDebug()<<commandToTreeBot(commandData);
    serial->writeData(commandToTreeBot(commandData));
}

void MainWindow::synButtonPortText()
{
    if(serial->isPortOpened())
    {
        ui->pushButtonOpenPort->setText(QObject::tr("Close Port"));
        ui->pushButtonOpenPort->setStyleSheet("background-color:#00aaff");
    }
    else
    {
        ui->pushButtonOpenPort->setText(QObject::tr("Open Port"));
        ui->pushButtonOpenPort->setStyleSheet("background-color:#ffffff");
    }
}

void MainWindow::slotCameraOpen()
{
    emit signalCameraOpen(ui->lineEditCameraID->text().toInt());
}

void MainWindow::slotStartRecording()
{
    if(isRecording)
    {
        ui->pushButtonRecord->setText(QObject::tr("Start recording"));
        ui->pushButtonRecord->setStyleSheet("background-color:#ffffff");
        fout.close();   //文件关闭
        msgLabel->setText(tr("Recording finished!"));
        isRecording = false;

    }
    else
    {
        ui->pushButtonRecord->setText(QObject::tr("Stop recording"));
        ui->pushButtonRecord->setStyleSheet("background-color:#00aaff");

        string   fileString =  ui->lineEditFileName->text().toStdString();
        fileName = fileString.c_str();
        fout.open(fileName);   //文件打开
        msgLabel->setText(tr("Recording started!"));
        isRecording = true;
    }
}
void MainWindow::openFile()
{
    QString path = QFileDialog::getOpenFileName(this,tr("Open File"),".");
    if(!path.isEmpty())
    {
        qDebug()<<"Path: "<<path;
        msgLabel->setText(path);
        emit signalOpenFile(path);
    }
    else
    {
        QMessageBox::warning(this,tr("path"),tr("you did not select a file."));
    }

}

void MainWindow::slotUpdateSerialPortNames()
{
    ui->comboBox->addItems(serial->getSerialPortList());
}
//================================kint======================

void MainWindow::timerEvent(QTimerEvent *event)
{
    // 判断是哪个定时器
    if(event->timerId() == id1 )
    {
        qDebug() << "timer1";
        emit signalUpdateSerialPortNames();
        if(configure_is_finished && camera_is_opened ) //相机已经打开 配置已经加载
        {
            bool run_state = pCam_qr_estimation->run();
            if(run_state)
            {
                cv::resize(pCam_qr_estimation->pQrDetect_->show_landmark_img_,display_img,cv::Size(0,0),0.5,0.5,cv::INTER_CUBIC);//缩小一倍  650  1650
                qimg = Mat2QImage(display_img);
                emit imageReady();  //  释放信号
            }
        }
        else
            qDebug() << "  camera init not finish ";
    }
    else
        qDebug() << "timer erro  ";
}
//void MainWindow::init(char* addr,int camId)
//{
//    bool camera_state =  pCam_qr_estimation->openCamera() ;
//    if(!camera_state)
//    {
//        cout<<"usb  camera does not plug in !"<<endl;
//        cout<<"please close program  and plug in usb camera ,then restart it !"<<endl;
//        //getchar();
//        camera_init_finish = false;
//    }
//    else
//    {
//        cout <<"camera open !"<<endl;
//        camera_init_finish = true;
//    }
//    return camera_state;
//}


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

    ui->labelR1FromCV->setText(QString("%1").arg(pCam_qr_estimation->pQrDetect_->r_[0], 0,'g',3));
    ui->labelR2FromCV->setText(QString("%1").arg(pCam_qr_estimation->pQrDetect_->r_[1], 0,'g',3));
    ui->labelR3FromCV->setText(QString("%1").arg(pCam_qr_estimation->pQrDetect_->r_[2], 0,'g',3));

    ui->labelT1FromCV->setText(QString("%1").arg(pCam_qr_estimation->pQrDetect_->t_[0], 0,'g',3));
    ui->labelT2FromCV->setText(QString("%1").arg(pCam_qr_estimation->pQrDetect_->t_[1], 0,'g',3));
    ui->labelT3FromCV->setText(QString("%1").arg(pCam_qr_estimation->pQrDetect_->t_[2], 0,'g',3));
    qDebug()<<"Tigger";

    if(isRecording )
    {
        dataRecorder();
    }

}

void MainWindow::dataRecorder(void)
{
    QStringList serialData = serial->eulerData->getEulerDataStringList();

    for(int i=0 ; i < serialData.size();i++)
    {
        fout << serialData[i].toStdString().data();
        fout <<"    ";
    }
    for(int i=0 ; i < 3;i++)
    {
        fout << pCam_qr_estimation->pQrDetect_->t_[i]  ;
        fout <<"    ";
    }
    for(int i=0 ; i < 3;i++)
    {
        fout << pCam_qr_estimation->pQrDetect_->r_[i]  ;
        fout <<"    ";
    }
    fout <<"    "<<endl;
}


void MainWindow::openCamera(int id)
{
    cout<<id<<endl;
    camera_ID = id;
    camera_is_opened =  pCam_qr_estimation->openCamera(camera_ID) ;
    if(camera_is_opened)
    {
        ui->pushButtonOpenCamera->setStyleSheet("background-color:#00aaff");  //相机打开
    }
    else
        ui->pushButtonOpenCamera->setStyleSheet("background-color:#ffffff");  //相机打开
}

void MainWindow::loadConfigure(QString fileName)
{   
    //char * fileName2= const_cast<char*>(fileName.toStdWString().c_str());
    //char * fileName2= const_cast<char*>(fileName.toStdWString().c_str());
    QByteArray ba = fileName.toLatin1();
    char * fileName2=ba.data();
    configure_file = fileName2;
    if( pCam_qr_estimation->initConfigure(configure_file))
    {
        cout<<"configure_file"<<endl;
        configure_is_finished  = true;
        ui->pushButtonOpenFile->setEnabled(false);
    }
    else
        configure_is_finished  = false;
}

//================================kint======================//
