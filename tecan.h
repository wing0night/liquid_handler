#ifndef TECAN_H
#define TECAN_H

#include "canthread.h"

class Tecan
{
public:
    Tecan(int tecan_num = 0);

    void send_md_command(QStringList command);
    QString rawDataToHex(const QByteArray &data);
    quint32 generateCanFrame1(int deviceNumber);
    quint32 generateCanFrame2(int deviceNumber);
    quint32 generateCanFrame3(int deviceNumber);


private:
    int m_tecan_num;
    CANThread *canthread;









};

#endif // TECAN_H
