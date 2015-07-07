#include "serialport.h"
#include "ui_serialport.h"
#include <QtWidgets/QMessageBox>
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
serialPort::serialPort(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::serialPort)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    plainText = new QPlainTextEdit(this);
    connect(serial,SIGNAL(error(QSerialPort::SerialPortError)),this,SLOT(handleError(QSerialPort::SerialPortError)));
    connect(serial,SIGNAL(readyRead()),this,SLOT(readData()));
    setCentralWidget(plainText);
}

serialPort::~serialPort()
{
    closeSerialPort();
    delete ui;
}

void serialPort::openSerialPort()
{
    QSerialPortInfo serialInfo;
    QList<QSerialPortInfo> serialList=serialInfo.availablePorts();
    foreach(QSerialPortInfo info,serialList)
    {
        qDebug()<<info.portName();
    }
    if(serialList.size()==0)
    {
        qDebug()<<"No port!";
        QMessageBox::critical(this,tr("Error"),serial->errorString());

    }
    else
    {
        serial->setPort(serialList[0]);

        if(serial->open(QIODevice::ReadWrite))
        {
            if(serial->setBaudRate(QSerialPort::Baud115200)
               && serial->setDataBits(QSerialPort::Data8)
               && serial->setParity(QSerialPort::NoParity)
               && serial->setStopBits(QSerialPort::OneStop)
               && serial->setFlowControl(QSerialPort::NoFlowControl))
                {
                    qDebug()<<"Port opened success!";
                }
            else
                {
                    serial->close();
                    QMessageBox::critical(this,tr("Error"),serial->errorString());
                    qDebug()<<"Port opened fail!";
                }
        }
        else
        {
            QMessageBox::critical(this,tr("Error"),serial->errorString());
            qDebug()<<"Can't open port!";
        }
    }

}

void serialPort::closeSerialPort()
{
    serial->close();
    qDebug()<<"Port closed!";
}

void serialPort::writeData(const QByteArray &data)
{
    serial->write(data);
}

void serialPort::readData()
{
    QByteArray data=serial->readAll();
    plainText->appendPlainText(QString(data));
    qDebug()<<data;
}

void serialPort::handleError(QSerialPort::SerialPortError error)
{
    if(error==QSerialPort::ResourceError)
    {
        QMessageBox::critical(this,tr("Critical Error"),serial->errorString());
        closeSerialPort();
    }
    else if(error==QSerialPort::DeviceNotFoundError)
    {
        QMessageBox::critical(this,tr("Critical Error"),tr("No port exist!!"));
        closeSerialPort();
    }
}
