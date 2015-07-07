#ifndef WEBCAMERA_H
#define WEBCAMERA_H

#include <QMainWindow>
#include <QCamera>
#include <QCameraInfo>
#include <QCameraImageCapture>
#include <QCameraViewfinder>
class WebCamera : public QMainWindow
{
    Q_OBJECT
public:
    explicit WebCamera(QWidget *parent = 0);
    ~WebCamera();

signals:

public slots:

private:
    QCamera *camera;
    QCameraViewfinder *viewFinder;
    QCameraImageCapture *imageCapture;

};

#endif // WEBCAMERA_H
