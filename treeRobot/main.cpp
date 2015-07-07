#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//================kint==============
    w.init(argv[1], 1);
//================kint==============
    w.show();
    return a.exec();

}
