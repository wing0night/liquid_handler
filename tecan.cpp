#include "tecan.h"
#include <QTime>
#include <QMessageBox>
#include <QDebug>
#include <cstring>
#include <QTextStream>
#include <cmath>
#include <QStack>
#include <QRegularExpression>
#include <QTimer>
#include "canthread.h"


Tecan::Tecan(int tecan_num)
    : m_tecan_num(tecan_num){
    canthread = new CANThread();

    connect(canthread,SIGNAL(getProtocolData(VCI_CAN_OBJ*,unsigned int,unsigned int)),this,SLOT(onGetProtocolData(VCI_CAN_OBJ*,unsigned int,unsigned int)));
    connect(canthread,SIGNAL(boardInfo(VCI_BOARD_INFO)),this,SLOT(onBoardInfo(VCI_BOARD_INFO)));
}

void Tecan::send_md_command(QStringList command){
    unsigned int num = command.size();
    if(num == 1){
        QByteArray bytes = command[0].toLatin1();
        // 2. 转换为十六进制字符串
        QString hexResult = rawDataToHex(bytes);

        QStringList strList = hexResult.split(" ");
        unsigned char data[8];
        memset(data,0,8);
        UINT dlc = 0;
        dlc = strList.count() > 8 ? 8 : strList.count();
        for(int i = 0;i < dlc;i ++)
            data[i] = strList.at(i).toInt(0,16);
        if(canthread->sendData(0,
                                generateCanFrame1(m_tecan_num), // 0x0101
                                0,
                                0,
                                data,dlc))
        // update log
        // {updateCanLog(257, data, dlc, true);    }
        {}
        else
            QMessageBox::warning(this,"警告","数据发送失败！");
    }
    else if(num == 2){
        QByteArray bytes0 = command[0].toLatin1();
        QString hexResult0 = rawDataToHex(bytes0);
        QByteArray bytes1 = command[1].toLatin1();
        QString hexResult1 = rawDataToHex(bytes1);

        QStringList strList0 = hexResult0.split(" ");
        unsigned char data0[8];
        memset(data0,0,8);
        UINT dlc0 = 0;
        dlc0 = strList0.count() > 8 ? 8 : strList0.count();
        for(int i = 0;i < dlc0;i ++)
            data0[i] = strList0.at(i).toInt(0,16);
        if(canthread->sendData(0,
                                generateCanFrame2(m_tecan_num), // 0x0103, start multi-frame
                                0,
                                0,
                                data0,dlc0))
        // update log
        // {updateCanLog(259, data0, dlc0, true);    }
        {}

        else
            QMessageBox::warning(this,"警告","数据发送失败！");

        QStringList strList1 = hexResult1.split(" ");
        unsigned char data1[8];
        memset(data1,0,8);
        UINT dlc1 = 0;
        dlc1 = strList1.count() > 8 ? 8 : strList1.count();
        for(int i = 0;i < dlc1;i ++)
            data1[i] = strList1.at(i).toInt(0,16);
        if(canthread->sendData(0,
                                generateCanFrame1(m_tecan_num), // 0x0103, start multi-frame
                                0,
                                0,
                                data1,dlc1))
        // update log
        // {updateCanLog(257, data1, dlc1, true);    }
        {}
        else
            QMessageBox::warning(this,"警告","数据发送失败！");
    }
    else{
        // general condition, frame amount >= 3
        //start frame is the same
        QByteArray bytes0 = command[0].toLatin1();
        QString hexResult0 = rawDataToHex(bytes0);

        QStringList strList0 = hexResult0.split(" ");
        unsigned char data0[8];
        memset(data0,0,8);
        UINT dlc0 = 0;
        dlc0 = strList0.count() > 8 ? 8 : strList0.count();
        for(int i = 0;i < dlc0;i ++)
            data0[i] = strList0.at(i).toInt(0,16);
        if(canthread->sendData(0,
                                generateCanFrame2(m_tecan_num), // 0x0103, start multi-frame
                                0,
                                0,
                                data0,dlc0))
        // update log
        {}
        // {updateCanLog(259, data0, dlc0, true);    }
        else
            QMessageBox::warning(this,"警告","数据发送失败！");
        for(unsigned int i=1; i<num-1; i++){
            QByteArray bytes = command[i].toLatin1();
            QString hexResult = rawDataToHex(bytes);

            QStringList strList = hexResult.split(" ");
            unsigned char data[8];
            memset(data,0,8);
            UINT dlc = 0;
            dlc = strList.count() > 8 ? 8 : strList.count();
            for(int i = 0;i < dlc;i ++)
                data[i] = strList.at(i).toInt(0,16);
            if(canthread->sendData(0,
                                    generateCanFrame3(m_tecan_num), // 0x0103, start multi-frame
                                    0,
                                    0,
                                    data,dlc))
            // update log
            {updateCanLog(260, data, dlc, true);        }
            else
                QMessageBox::warning(this,"警告","数据发送失败！");
        }
        // last command: action command
        QByteArray bytes = command[num-1].toLatin1();
        QString hexResult = rawDataToHex(bytes);

        QStringList strList = hexResult.split(" ");
        unsigned char data[8];
        memset(data,0,8);
        UINT dlc = 0;
        dlc = strList.count() > 8 ? 8 : strList.count();
        for(int i = 0;i < dlc;i ++)
            data[i] = strList.at(i).toInt(0,16);
        if(canthread->sendData(0,
                                generateCanFrame1(m_tecan_num), // 0x0101, start multi-frame
                                0,
                                0,
                                data,dlc))
        // update log
        {updateCanLog(257, data, dlc, true);        }
        else
            QMessageBox::warning(this,"警告","数据发送失败！");
    }
}

// acquire frame type 001
quint32 Tecan::generateCanFrame1(int deviceNumber) {
    const QString binaryTemplate = "000000010xxxx001"; // 合并后的16位模板

    // 验证设备编号范围
    // if (deviceNumber < 0 || deviceNumber > 15) {
    //     qWarning() << "设备编号超出范围（0-15）";
    //     return 0;
    // }

    // 转换为4位二进制字符串（自动补前导零）
    QString binary4 = QString("%1").arg(deviceNumber, 4, 2, QChar('0'));

    // 替换模板中的xxxx
    QString concreteBinary = binaryTemplate;
    concreteBinary.replace("xxxx", binary4); // 精确替换4个x位置

    // 转换为十进制
    bool ok;
    quint32 result = concreteBinary.toUInt(&ok, 2);

    if (!ok) {
        qWarning() << "二进制转换失败：" << concreteBinary;
        return 0;
    }
    return result;
}

// acquire frame type 011
quint32 Tecan::generateCanFrame2(int deviceNumber) {
    const QString binaryTemplate = "000000010xxxx011"; // 合并后的16位模板

    // 验证设备编号范围
    // if (deviceNumber < 0 || deviceNumber > 15) {
    //     qWarning() << "设备编号超出范围（0-15）";
    //     return 0;
    // }

    // 转换为4位二进制字符串（自动补前导零）
    QString binary4 = QString("%1").arg(deviceNumber, 4, 2, QChar('0'));

    // 替换模板中的xxxx
    QString concreteBinary = binaryTemplate;
    concreteBinary.replace("xxxx", binary4); // 精确替换4个x位置

    // 转换为十进制
    bool ok;
    quint32 result = concreteBinary.toUInt(&ok, 2);

    if (!ok) {
        qWarning() << "二进制转换失败：" << concreteBinary;
        return 0;
    }
    return result;
}

// acquire frame type 100
quint32 Tecan::generateCanFrame3(int deviceNumber) {
    const QString binaryTemplate = "000000010xxxx100"; // 合并后的16位模板

    // 验证设备编号范围
    // if (deviceNumber < 0 || deviceNumber > 15) {
    //     qWarning() << "设备编号超出范围（0-15）";
    //     return 0;
    // }

    // 转换为4位二进制字符串（自动补前导零）
    QString binary4 = QString("%1").arg(deviceNumber, 4, 2, QChar('0'));

    // 替换模板中的xxxx
    QString concreteBinary = binaryTemplate;
    concreteBinary.replace("xxxx", binary4); // 精确替换4个x位置

    // 转换为十进制
    bool ok;
    quint32 result = concreteBinary.toUInt(&ok, 2);

    if (!ok) {
        qWarning() << "二进制转换失败：" << concreteBinary;
        return 0;
    }
    return result;
}


