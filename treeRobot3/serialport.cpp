/****************************************
 * serialPort
 * Chaomin
****************************************/
#include "serialport.h"
//#include <QMessageBox>
#include <QSerialPortInfo>
#include <QDebug>
serialPort::serialPort(QWidget *parent):
    QWidget(parent)
{
    _isPortOpened = false;
    eulerData = new EulerData();
    serial = new QSerialPort(this);
    bytesData = new QByteArray();
    serialInfo = new QSerialPortInfo();
    getSerialPortNames();
    connect(serial,SIGNAL(error(QSerialPort::SerialPortError)),this,SLOT(handleError(QSerialPort::SerialPortError)));
    connect(serial,SIGNAL(readyRead()),this,SLOT(readData()));
}

serialPort::~serialPort()
{
    _isPortOpened = false;
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
                    _isPortOpened = true;
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
    _isPortOpened = false;
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
    bytesData->push_back(serial->readAll());
    //plainText->appendPlainText(QString(*bytesData));
    //qDebug()<<*bytesData;
    //================Chaomin=========================
    //maybe occur error ,need modify -Chaomin -20150625
    //fixed some errors -Chaomin -20150627
    char* pcByteData = bytesData->data();
    char* cArray = new char[bytesData->size()];
    for(int i = 0;  i<bytesData->size();i++)
    {
        cArray[i] = pcByteData[i];
    }
    //qDebug()<<cArray;
    int numHeader = 0;
    int indexBytes = 0;
    int dataSize = eulerData->dataSize();
    float *pf = NULL;
    int   *pl = NULL;
    while(numHeader<4 && indexBytes<bytesData->size())  //look for prefix
    {
        if(cArray[indexBytes++]=='F')
        {
            numHeader++;
        }
        else
        {
            numHeader=0;
        }
    }
    if( numHeader==4 &&
        bytesData->size()-indexBytes >= dataSize - 4 &&
        cArray[indexBytes+dataSize - 8]=='E' &&
        cArray[indexBytes+dataSize - 7]=='E' &&
        cArray[indexBytes+dataSize - 6]=='E' &&
        cArray[indexBytes+dataSize - 5]=='E')   //to sure data is vaild
    {
        pf = (float*)& cArray[indexBytes];
        eulerData->changeFrontYaw(*pf);
        pf++;
        eulerData->changeFrontPitch(*pf);
        pf++;
        eulerData->changeFrontRoll(*pf);
        pf++;
        eulerData->changeRearYaw(*pf);
        pf++;
        eulerData->changeRearPitch(*pf);
        pf++;
        eulerData->changeRearRoll(*pf);
        pl = (int*)& cArray[indexBytes + 24];
        eulerData->changeLength(*pl);
        pl++;
        eulerData->changeWidth(*pl);
        pl++;
        eulerData->changeHeight(*pl);
//        emit eulerDataUpdated(QString("%1").arg(eulerData->getFrontYaw()),
//                              QString("%1").arg(eulerData->getFrontPitch()),
//                              QString("%1").arg(eulerData->getFrontRoll())
////                              ,QString("%1").arg(eulerData->getRearYaw()),
////                              QString("%1").arg(eulerData->getRearPitch()),
////                              QString("%1").arg(eulerData->getRearRoll()),
////                              QString("%1").arg(eulerData->getLength()),
////                              QString("%1").arg(eulerData->getWidth()),
////                              QString("%1").arg(eulerData->getHeight())
//                              );
        emit eulerDataUpdated(eulerData->toStringList());
        bytesData->clear();
    }
    if(bytesData->size()>1000)      //remove invaild data
    {
        bytesData->clear();
    }

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
