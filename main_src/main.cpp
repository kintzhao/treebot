#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    int cam_id = atoi(argv[2]);
    cout<<cam_id<<" cam_id   " <<endl;
    QApplication a(argc, argv);
    MainWindow w;
    w.init(argv[1], 1);
    w.show();
    return a.exec();

}


