#include "serialport.h"
//#include <QMessageBox>
#include <QSerialPortInfo>
#include <QDebug>
serialPort::serialPort(QWidget *parent):
    QWidget(parent)
{
    eulerData = new EulerData();
    serial = new QSerialPort(this);
    bytesData = new QByteArray();
    serialInfo = new QSerialPortInfo();
    //QSerialPortInfo serialInfo;
    getSerialPortNames();
    connect(serial,SIGNAL(error(QSerialPort::SerialPortError)),this,SLOT(handleError(QSerialPort::SerialPortError)));
    connect(serial,SIGNAL(readyRead()),this,SLOT(readData()));
    //setCentralWidget(plainText);
}

serialPort::~serialPort()
{
    closeSerialPort();
}
void serialPort::getSerialPortNames()
{
    serialPortInfoList.append(serialInfo->availablePorts());
    foreach(QSerialPortInfo info,serialPortInfoList)
    {
        serialPortNames.append(info.portName());
    }
    serialPortList = serialPortNames;
}

void serialPort::openSerialPort(const QString &name)
{
    if(serialPortInfoList.size()==0)
    {
        qDebug()<<"No port!";
        //QMessageBox::critical(this,tr("Error"),serial->errorString());
        portStatus = "No port Found";
    }
    else
    {
        serial->setPortName(name);

        if(serial->open(QIODevice::ReadWrite))
        {
            if(serial->setBaudRate(QSerialPort::Baud9600)
               && serial->setDataBits(QSerialPort::Data8)
               && serial->setParity(QSerialPort::NoParity)
               && serial->setStopBits(QSerialPort::OneStop)
               && serial->setFlowControl(QSerialPort::NoFlowControl))
                {
                    qDebug()<<"Port opened success!";
                    portStatus = "Opened success!";
                }
            else
                {
                    serial->close();
                    //QMessageBox::critical(this,tr("Error"),serial->errorString());
                    qDebug()<<"Port opened fail!";
                    portStatus = "Opened failed!";
                }
        }
        else
        {
            //QMessageBox::critical(this,tr("Error"),serial->errorString());
            qDebug()<<"Can't open port!";
            portStatus = "Can't open port!";
        }
    }

}

void serialPort::closeSerialPort()
{
    serial->close();
    qDebug()<<"Port closed!";
    portStatus = "Port closed!";
}

void serialPort::writeData(const QByteArray &data)
{
    serial->write(data);
}
void serialPort::writeData(const int data)
{
    serial->write(intToByteArray(data));
}

void serialPort::readData()
{
    bytesData->append(serial->readAll());
    //plainText->appendPlainText(QString(*bytesData));
    qDebug()<<*bytesData;
    //maybe occur error ,need modify -Chaomin
    char* pcByteData = bytesData->data();
    char* cArray = new char[bytesData->size()];
    for(int i = 0;  i<bytesData->size();i++)
    {
        cArray[i] = pcByteData[i];
    }
    int numHeader = 0;
    int indexBytes = 0;
    float *pf = NULL;
    while(numHeader<4 && indexBytes<bytesData->size())
    {
        if(cArray[indexBytes]=='F')
        {
            numHeader++;
        }
        else
        {
            numHeader=0;
        }
        indexBytes++;
    }
    if(numHeader==4)
    {
        qDebug()<<"Received data.";
        pf = (float*)& cArray[indexBytes];
        eulerData->changeYaw(*pf);
        pf++;
        eulerData->changePitch(*pf);
        pf++;
        eulerData->changeRoll(*pf);
        qDebug()<<eulerData->getYaw()<<" "<<eulerData->getPitch()<<" "<<eulerData->getRoll();
        emit eulerDataUpdated(QString("%1").arg(eulerData->getYaw()),QString("%1").arg(eulerData->getPitch()),QString("%1").arg(eulerData->getRoll()));
    }
    bytesData->clear();
}

void serialPort::handleError(QSerialPort::SerialPortError error)
{
    if(error==QSerialPort::ResourceError)
    {
        //QMessageBox::critical(this,tr("Critical Error"),serial->errorString());
        closeSerialPort();
    }
    else if(error==QSerialPort::DeviceNotFoundError)
    {
        //QMessageBox::critical(this,tr("Critical Error"),tr("No port exist!!"));
        closeSerialPort();
    }
}
