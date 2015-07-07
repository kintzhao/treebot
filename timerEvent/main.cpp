#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    int cam_id = atoi(argv[2]);
    cout<<cam_id<<" cam_id   " <<endl;
    QApplication a(argc, argv);
    Widget w;
    w.init(argv[1], cam_id);
    w.show();

    return a.exec();
}



