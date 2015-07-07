#include "util.h"
//int convert to QByteArray
QByteArray intToByteArray(const int i)
{
    QByteArray _bytes;
    _bytes.resize(4);
    _bytes[0] = (uchar) (0x000000ff & i);
    _bytes[1] = (uchar) (0x0000ff00 & i);
    _bytes[2] = (uchar) (0x00ff0000 & i);
    _bytes[3] = (uchar) (0xff000000 & i);
    return _bytes;
}
