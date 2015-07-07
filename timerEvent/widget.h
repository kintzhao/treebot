#ifndef WIDGET_H
#define WIDGET_H
//#include <QtWidgets/QWidget>
#include <QWidget>
#include <QImage>
#include "../qrslam/CameraEstimation.h"


namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    CameraEstimation* pCam_qr_estimation ;
    void init(char* addr,int camId);
    QImage Mat2QImage(cv::Mat const& src) ;
    cv::Mat QImage2Mat(QImage const& src) ;
    void imgShow();
protected:
    void timerEvent(QTimerEvent *event);

private:
    Ui::Widget *ui;
    int id1,id2,id3;
    QImage qimg;
    QPixmap pm;
    cv::Mat img_test;
signals:
    void imageReady();
//slots:

};

#endif // WIDGET_H
