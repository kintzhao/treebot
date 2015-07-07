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

QByteArray uin16ToByteArrat(const quint16 i)
{
    QByteArray _bytes;
    _bytes.resize(2);
    _bytes[0] = (uchar) (0x00ff & i);
    _bytes[1] = (uchar) (0xff00 & i);
    return _bytes;
}

QByteArray Get_Crc16(uchar *puchMsg,uint usDataLen)
{
    QByteArray bytes;
    uchar uchCRCHi=0xFF;
    uchar uchCRCLo=0xFF;
    uint uIndex;
    while(usDataLen--)
    {
        uIndex = uchCRCHi ^ *puchMsg++;
        uchCRCHi=uchCRCLo ^ auchCRCHi[uIndex];
        uchCRCLo = auchCRCLo[uIndex];
    }
    QByteArray a;
    bytes.append(uchCRCLo);
    bytes.append(uchCRCHi);
    return bytes;
}
