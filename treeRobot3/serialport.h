/****************************************
 * serialPort
 * Chaomin
****************************************/
#ifndef SERIALPORT_H
#define SERIALPORT_H
//#include <QPlainTextEdit>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QWidget>
#include <QObject>
#include "eulerdata.h"
#include <QStringList>
#include "util.h"
class serialPort : public QWidget
{
    Q_OBJECT

public:
    explicit serialPort(QWidget *parent = 0);
    ~serialPort();
    void getSerialPortNames();      //syn serialPort List of comboBox
    QStringList& getSerialPortList(){return serialPortList;}    //access the private elem
    bool isPortOpened(){return _isPortOpened;}
    EulerData   *eulerData;
public slots:
    void openSerialPort(const QString &name);
    void closeSerialPort();
    void writeData(const QByteArray &data);
    void writeData(const int data);
    void readData();
    void handleError(QSerialPort::SerialPortError error);
    QString& getPortStatus(){return portStatus;}
private:
    QSerialPort *serial;
    bool _isPortOpened;
    //QPlainTextEdit *plainText;
    QByteArray  *bytesData;
   // EulerData   *eulerData;
    QList<QSerialPortInfo> serialPortInfoList;
    QList<QString> serialPortNames;
    QStringList serialPortList;
    QSerialPortInfo *serialInfo;
    QString portStatus;

signals:
//    void eulerDataUpdated(const QString &fy,const QString &fp,const QString &fr
////                          ,const QString &ry,const QString &rp,const QString &rr,
////                          const QString &l,const QString &w,const QString &h
//                          );
    void eulerDataUpdated(const QStringList& s);
};

#endif // SERIALPORT_H
