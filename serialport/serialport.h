#ifndef SERIALPORT_H
#define SERIALPORT_H
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QMainWindow>
#include <QtSerialPort/QSerialPort>
namespace Ui
{
    class serialPort;
}

class serialPort : public QMainWindow
{
    Q_OBJECT

public:
    explicit serialPort(QWidget *parent = 0);
    ~serialPort();
public slots:
    void openSerialPort();
    void closeSerialPort();
    void writeData(const QByteArray &data);
    void readData();

    void handleError(QSerialPort::SerialPortError error);
private:
    Ui::serialPort *ui;
    QSerialPort *serial;
    QPlainTextEdit *plainText;
    //QByteArray *rxd;
};

#endif // SERIALPORT_H
