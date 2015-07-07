#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
//#ifdef UNIX_H_
//#define testa 1
//#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //================kint==============
    //w.configure_file = argv[1];
   //  w.camera_ID = atoi(argv[2]);
    // w.init(argv[1], 1);
    //================kint==============
    w.show();
    return a.exec();

}
