#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnWidth(0,120);
    ui->tableWidget->setColumnWidth(1,120);
    ui->tableWidget->setColumnWidth(2,120);
    ui->tableWidget->setColumnWidth(3,100);
    ui->tableWidget->setColumnWidth(4,80);
    ui->tableWidget->setColumnWidth(5,120);
    ui->tableWidget->setColumnWidth(6,90);
    ui->tableWidget->setColumnWidth(7,90);
    ui->tableWidget->setColumnWidth(8,80);
    ui->tableWidget->setColumnWidth(9,250);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    canthread = new CANThread();

    connect(canthread,SIGNAL(getProtocolData(VCI_CAN_OBJ*,unsigned int,unsigned int)),this,SLOT(onGetProtocolData(VCI_CAN_OBJ*,unsigned int,unsigned int)));
    connect(canthread,SIGNAL(boardInfo(VCI_BOARD_INFO)),this,SLOT(onBoardInfo(VCI_BOARD_INFO)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

// for listen to CAN msgs
void MainWindow::onGetProtocolData(VCI_CAN_OBJ *vci,unsigned int dwRel,unsigned int channel)
{
    QStringList messageList;
    QString str;
    for(unsigned int i = 0;i < dwRel;i ++)
    {
        messageList.clear();
        messageList << QTime::currentTime().toString("hh:mm:ss zzz");//时间
        if(vci[i].TimeFlag == 1)
        {
            messageList << "0x" + QString("%1").arg(vci[i].TimeStamp,8,16,QChar('0')).toUpper();//时间
            messageList << QString::number(QVariant(vci[i].TimeStamp * 0.0001).toFloat(), 'f', 4);//QString("%1").arg(QVariant(vci[i].TimeStamp * 0.1).toUInt(),8,10,QChar('0'));//时间
        }
        else
        {
            messageList << "无";//时间
            messageList << "无";//时间
        }
        messageList << "CH" + QString::number(channel);
        messageList << "接收";//收发
        messageList << "0x" + QString("%1").arg(vci[i].ID,8,16,QChar('0')).toUpper();//ID
        messageList << ((vci[i].RemoteFlag == 1) ? "远程帧" : "数据帧");//类型
        messageList << ((vci[i].ExternFlag == 1) ? "扩展帧" : "标准帧");//Frame
        QString str = "";
        if(vci[i].RemoteFlag == 0)//数据帧显示数据
        {
            messageList << "0x" + QString::number(vci[i].DataLen,16).toUpper();//长度
            str = "x| ";
            for(int j = 0;j < vci[i].DataLen;j ++)
                str += QString("%1 ").arg(vci[i].Data[j],2,16,QChar('0')).toUpper();//QString::number(recvCANData[i].frame.data[j],16) + " ";
        }
        else
            messageList << "0x0";//长度
        messageList << str;//数据
        AddDataToList(messageList);
    }
}



void MainWindow::on_motor_comboBox_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Motor1"){
        // open the commucation with motor1
        QTextBrowser *textBrowser = ui->textBrowser;
        textBrowser->append("<span style='color: green;'>Info </span>Controlling motor1");
    }
    else if(arg1 == "Motor2"){
        // open CAN of motor2
        QTextBrowser *textBrowser = ui->textBrowser;
        textBrowser->append("<span style='color: green;'>Info </span>Controlling motor2");
    }
    else{
        //
    }
}


void MainWindow::on_forward_clicked()
{
    QTextBrowser *textBrowser = ui->textBrowser;
    textBrowser->append("<span style='color: green;'>info </span>go forward");
}

void MainWindow::on_reverse_clicked()
{
    QTextBrowser *textBrowser = ui->textBrowser;
    textBrowser->append("<span style='color: green;'>info </span>go reverse");
}


void MainWindow::on_run_your_scripts_clicked()
{
    QTextBrowser *textBrowser = ui->textBrowser;
    textBrowser->append("<span style='color: green;'>info </span>Running Scripts1");
}




void MainWindow::on_pro_debug_open_USBCAN_clicked()
{
    if(ui->pro_debug_open_USBCAN->text() == tr("open USB-CAN"))
    {
        UINT baundRate = 0;
        if(ui->pro_debug_combo_bps->currentText().indexOf("Kbps") != -1)
            baundRate = ui->pro_debug_combo_bps->currentText().remove("Kbps").toUInt();
        else
            baundRate = QVariant(ui->pro_debug_combo_bps->currentText().remove("Mbps").toFloat()).toUInt();
        bool dev = canthread->openDevice(4,//QVariant(ui->comboBox->currentIndex()).toUInt(),
                                         QVariant(ui->pro_debug_combo_index->currentIndex()).toUInt(),
                                         baundRate);
        if(dev == true)
        {
            ui->pro_debug_combo_index->setEnabled(false);
            ui->pro_debug_combo_bps->setEnabled(false);
            ui->pro_debug_init_CAN->setEnabled(true);
            ui->pro_debug_open_USBCAN->setText(tr("close USB-CAN"));
        }
        else
            QMessageBox::warning(this,"警告","打开设备失败！");
    }
    else if(ui->pro_debug_open_USBCAN->text() == tr("close USB-CAN"))
    {
        ui->pro_debug_combo_index->setEnabled(true);
        ui->pro_debug_combo_bps->setEnabled(true);
        ui->pro_debug_combo_channel->setEnabled(true);
        ui->pro_debug_send->setEnabled(false);
        ui->pro_debug_init_CAN->setEnabled(false);
        ui->pro_debug_reset->setEnabled(false);
        ui->pro_debug_start_CAN->setEnabled(false);
        ui->pro_debug_open_USBCAN->setText(tr("打开设备"));
        canthread->stop();
        canthread->closeDevice();
    }
}


void MainWindow::on_pro_debug_send_clicked()
{
    if(ui->pro_debug_combo_frame1->currentIndex() == 0)//标准帧，ID 范围0-0x7FF
    {
        if(ui->pro_debug_ID->text().toInt(0,16) > 0x7FF)
        {
            QMessageBox::warning(this,"警告","发送失败，标准帧ID范围为0~0x7FF！");
            return;
        }
    }
    else
    {
        if(ui->pro_debug_ID->text().toInt(0,16) > 0x1FFFFFFF)
        {
            QMessageBox::warning(this,"警告","发送失败，扩展帧ID范围为0~0x1FFFFFFF！");
            return;
        }
    }
    QStringList strList = ui->pro_debug_data->text().split(" ");
    unsigned char data[8];
    memset(data,0,8);
    UINT dlc = 0;
    dlc = strList.count() > 8 ? 8 : strList.count();
    for(int i = 0;i < dlc;i ++)
        data[i] = strList.at(i).toInt(0,16);
    if(canthread->sendData(QVariant(ui->pro_debug_combo_frame1->currentIndex()).toUInt(),
                            QVariant(ui->pro_debug_ID->text().toInt(0,16)).toUInt(),
                            ui->pro_debug_combo_frame2->currentIndex(),
                            ui->pro_debug_combo_frame1->currentIndex(),
                            data,dlc))
    {//发送成功，打印数据
        QStringList messageList;

        messageList.clear();
        messageList << QTime::currentTime().toString("hh:mm:ss zzz");//时间
        messageList << "无";//时间
        messageList << "无";//时间
        messageList << "CH" + QString::number(QVariant(ui->pro_debug_combo_channel->currentIndex()).toUInt());
        messageList << "发送";//收发
        messageList << "0x" + ui->pro_debug_ID->text().toUpper();//ID
        messageList << ((ui->pro_debug_combo_frame2->currentIndex() == 0) ? "数据帧" : "远程帧");//类型
        messageList << ((ui->pro_debug_combo_frame1->currentIndex() == 0) ? "标准帧" : "扩展帧");//Frame
        QString str = "";
        if(ui->pro_debug_combo_frame2->currentIndex() == 0)//数据帧显示数据
        {
            messageList << "0x" + QString::number(dlc,16).toUpper();//长度
            str = "x| ";
            for(int j = 0;j < dlc;j ++)
                str += QString("%1 ").arg((unsigned char)data[j],2,16,QChar('0')).toUpper();//QString::number((unsigned char)data[j],16) + " ";
        }
        else
            messageList << "0x0";//长度
        messageList << str;//数据
        AddDataToList(messageList);
    }
    else
        QMessageBox::warning(this,"警告","数据发送失败！");
}

void MainWindow::AddDataToList(QStringList strList)
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    for(int i = 0; i < strList.count();i ++)
    {
        QTableWidgetItem *item = new QTableWidgetItem(strList.at(i),0);
        ui->tableWidget->setItem(row, i, item);
        if(i != strList.count() - 1)
            ui->tableWidget->item(row,i)->setTextAlignment(Qt::AlignCenter | Qt::AlignHCenter);

    }
    ui->tableWidget->scrollToBottom();
}

void MainWindow::on_pro_debug_init_CAN_clicked()//初始化
{
    if(canthread->initCAN())
    {
        ui->pro_debug_start_CAN->setEnabled(true);
        ui->pro_debug_open_USBCAN->setEnabled(false);
    }
    else
        QMessageBox::warning(this,"警告","CAN初始化失败！");
}


void MainWindow::on_pro_debug_start_CAN_clicked()
{
    if(canthread->startCAN())
    {
        ui->pro_debug_init_CAN->setEnabled(false);
        ui->pro_debug_reset->setEnabled(true);
        ui->pro_debug_send->setEnabled(true);
        canthread->start();
    }
    else
        QMessageBox::warning(this,"警告","CAN启动失败！");
}


void MainWindow::on_pro_debug_reset_clicked()
{
    if(canthread->reSetCAN())
    {
        ui->pro_debug_init_CAN->setEnabled(false);
        ui->pro_debug_start_CAN->setEnabled(false);
        ui->pro_debug_open_USBCAN->setEnabled(true);
    }
    else
        QMessageBox::warning(this,"警告","CAN复位失败！");
}

QString versionStr(USHORT ver)
{
    return "V" + QString::number((ver & 0x0FFF) /0x100,16).toUpper() + "." + QString("%1 ").arg((ver & 0x0FFF) % 0x100,2,16,QChar('0')).toUpper();
}
// display usbcan device info
void MainWindow::onBoardInfo(VCI_BOARD_INFO vbi)
{
    ui->label_17->setText(QString::number(vbi.can_Num));
    ui->label_18->setText(versionStr(vbi.hw_Version));
    ui->label_25->setText(versionStr(vbi.in_Version));
    ui->label_26->setText(QString::number(vbi.irq_Num));
}




