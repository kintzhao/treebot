#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 开启一个1秒定时器，返回其ID
    id1 = startTimer(50);
    //ui->label->
    QObject::connect(this,&Widget::imageReady,this,&Widget::imgShow);
    //QObject::connect(this,SIGNAL(imageReady()),this,SLOT(imgShow()));

}

Widget::~Widget()
{
    delete ui;
    delete pCam_qr_estimation;
}

void Widget::timerEvent(QTimerEvent *event)
{
    // 判断是哪个定时器
    if(event->timerId() == id1){
        qDebug() << "timer1";
        pCam_qr_estimation->run();
      //  namedWindow("edges",0);
         qimg = Mat2QImage(pCam_qr_estimation->frame);
         img_test = QImage2Mat(qimg);
       // qimg.load("/home/yhzhao/Desktop/12.png");
       // img_test = QImage2Mat(qimg);
      //  imshow("edges", img_test );

        //imshow("edges", pCam_qr_estimation->frame );
      //  cv::waitKey(10);
       // pm.fromImage(qimg);

        emit imageReady();
    }
    else
    {
        qDebug() << "timer erro";
    }
}
void Widget::init(char* addr,int camId)
{
    pCam_qr_estimation = new CameraEstimation;
    pCam_qr_estimation->Init(addr,camId);
}


QImage Widget::Mat2QImage(cv::Mat const& src)
{
     cv::Mat temp; // make the same cv::Mat
     cvtColor(src, temp,CV_BGR2RGB); // cvtColor Makes a copt, that what i need
     QImage dest((const uchar *) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
     dest.bits(); // enforce deep copy, see documentation
     // of QImage::QImage ( const uchar * data, int width, int height, Format format )
     return dest;
}

cv::Mat Widget::QImage2Mat(QImage const& src)
{
     cv::Mat tmp(src.height(),src.width(),CV_8UC3,(uchar*)src.bits(),src.bytesPerLine());
     cv::Mat result; // deep copy just in case (my lack of knowledge with open cv)
     cvtColor(tmp, result,CV_BGR2RGB);
     return result;
}
void Widget::imgShow()
{
    //qimg.load("/home/yhzhao/Desktop/12.png");
    pm.fromImage(qimg);
    ui->label->setPixmap(QPixmap::fromImage(qimg));
   // ui->label->setPixmap(pm);
   // ui->label->show();
    qDebug()<<"Tigger";

   // ui->label->setPixmap(QPixmap::fromImage(*img));

}
