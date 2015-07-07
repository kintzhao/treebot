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
    //QPlainTextEdit *plainText;
    QByteArray  *bytesData;
    EulerData   *eulerData;
    QList<QSerialPortInfo> serialPortInfoList;
    QList<QString> serialPortNames;
    QStringList serialPortList;
    QSerialPortInfo *serialInfo;
    QString portStatus;
signals:
    void eulerDataUpdated(const QString &y,const QString &p,const QString &r);
};

#endif // SERIALPORT_H
