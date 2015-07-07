#include "serialport.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QPlainTextEdit>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    serialPort w;

    w.openSerialPort();
    w.writeData("Hello, Chaomin");
    w.show();
    return a.exec();
}
