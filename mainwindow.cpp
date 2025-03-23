#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QMessageBox>
#include <QDebug>
#include <cstring>
#include <QTextStream>

// 字节转两位十六进制字符串（大写）
QString MainWindow::byteToHex(quint8 byte) {
    return QString("%1").arg(byte, 2, 16, QChar('0')).toUpper();
}
// 原始数据转十六进制字符串（空格分隔）
QString MainWindow::rawDataToHex(const QByteArray &data) {
    QString hexStr;
    QTextStream stream(&hexStr);
    for (auto byte : data) {
        stream << byteToHex(static_cast<quint8>(byte)) << " ";
    }
    qDebug() << "Hex Data: " << hexStr.trimmed();
    return hexStr.trimmed(); // 移除末尾空格
}
// 字符串转 ASCII 字节数组（Latin-1 编码保证单字节）
QByteArray MainWindow::intoAscii(const QString &input) {
    QByteArray data = input.toLatin1(); // 转换为单字节编码
    qDebug() << "ASCII Data:" << data; // 调试输出
    return data;
}

QList<int> calculateStepperTimeSegments(const QString& input) {
    QList<int> results;

    // 1. 按'M'分割字符串（自动跳过空段）
    QStringList segments = input.split('M', Qt::SkipEmptyParts);

    // 正则表达式匹配数字部分
    QRegularExpression re("\\d+");

    foreach (const QString& segment, segments) {
        int sum = 0;

        // 2. 在每段中查找所有数字
        QRegularExpressionMatchIterator it = re.globalMatch(segment);
        while (it.hasNext()) {
            QRegularExpressionMatch match = it.next();
            sum += match.captured(0).toInt(); // 转换为数字并累加
        }

        results.append(sum);
    }

    return results;
}

// merge delay time, create tecan command
QString merge_stepper_time(const QVector<int>& stepper_time, QString& tecan_str) {
    // 步骤1：记录所有M的位置
    QVector<int> m_positions;
    for (int i = 0; i < tecan_str.size(); ++i) {
        if (tecan_str[i] == 'M') {
            m_positions.append(i);
        }
    }

    // 步骤2：校验M数量与数组大小一致
    if (m_positions.size() != stepper_time.size()) {
        throw std::invalid_argument("M字符数量与数组长度不匹配");
    }

    // 步骤3：从后往前插入数据
    QString merged_str = tecan_str;
    for (int i = m_positions.size() - 1; i >= 0; --i) {
        const int insert_pos = m_positions[i] + 1; // 在M后面插入
        const QString num_str = QString::number(stepper_time[i]);
        merged_str.insert(insert_pos, num_str);
    }

    return merged_str;
}

// split tecan command into pieces of 8 characters
QStringList splitStringEvery8Chars(QString &input) {
    QStringList result;
    const int chunkSize = 8;

    for (int i = 0; i < input.length(); i += chunkSize) {
        // 计算当前块的结束位置
        int endPos = qMin(i + chunkSize, input.length());
        // 截取子字符串并添加到结果列表
        result.append(input.mid(i, endPos - i));
    }

    return result;
}

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

    // 初始化pwm默认参数
    ui->periodEdit->setText("1000000");  // 1ms 周期
    ui->dutyEdit->setText("500000");     // 50% 占空比

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
    // 1. 获取输入并转换为 ASCII 字节数组
    QByteArray bytes = intoAscii(ui->pro_debug_data->text());
    // 2. 转换为十六进制字符串
    QString hexResult = rawDataToHex(bytes);

    QStringList strList = hexResult.split(" ");
    unsigned char data[8];
    memset(data,0,8);
    UINT dlc = 0;
    dlc = strList.count() > 8 ? 8 : strList.count();
    for(int i = 0;i < dlc;i ++)
        data[i] = strList.at(i).toInt(0,16);
    quint32 id = QVariant(ui->pro_debug_ID->text().toInt(0,16)).toUInt();
    if(canthread->sendData(0,
                            QVariant(ui->pro_debug_ID->text().toInt(0,16)).toUInt(),
                            ui->pro_debug_combo_frame2->currentIndex(),
                            ui->pro_debug_combo_frame1->currentIndex(),
                            data,dlc))
    // update log
    {updateCanLog(id, data, dlc, true);    }
    else
        QMessageBox::warning(this,"警告","数据发送失败！");
}

// 辅助函数：更新CAN日志
void MainWindow::updateCanLog(quint32 id, unsigned char* data, int dlc, bool isTx) {
    QStringList messageList;
    messageList << QTime::currentTime().toString("hh:mm:ss zzz");
    messageList << "无";  // 保留字段
    messageList << "无";  // 保留字段
    messageList << "CH" + QString::number(ui->pro_debug_combo_channel->currentIndex());
    messageList << (isTx ? "发送" : "接收");
    messageList << "0x" + QString::number(id, 16).toUpper();
    messageList << (ui->pro_debug_combo_frame2->currentIndex() == 0 ? "数据帧" : "远程帧");
    messageList << (ui->pro_debug_combo_frame1->currentIndex() == 0 ? "标准帧" : "扩展帧");
    messageList << "0x" + QString::number(dlc, 16).toUpper();

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
// unsigned char* into_ascii(char* mystr){
//     unsigned char* data = reinterpret_cast<unsigned char*>(mystr);
//     return data;
// }



void MainWindow::on_pushButton_clicked()
{
    // open in sequence
    bool dev = canthread->openDevice(4,//QVariant(ui->comboBox->currentIndex()).toUInt(),
                                     0,
                                     100);
    if(dev == false){
        QMessageBox::warning(this,"警告","CAN open failed！");
    }
    bool initcan = canthread->initCAN();
    if(initcan == false)
    {
        QMessageBox::warning(this,"警告","CAN open failed！");
    }
    bool startcan = canthread->startCAN();
    if (startcan == false){
        QMessageBox::warning(this,"警告","CAN open failed！");
    }
    canthread->start();
}



void MainWindow::on_test_pwm_start_clicked()
{
    // 1. 初始化 PWM
    if (!m_pwm.initPwm()) {
        QMessageBox::critical(this, "错误", "PWM 初始化失败！");
        return;
    }

    // 2. 设置周期和占空比
    bool ok;
    unsigned int period = ui->periodEdit->text().toUInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "输入错误", "周期值无效");
        return;
    }

    unsigned int duty = ui->dutyEdit->text().toUInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "输入错误", "占空比值无效");
        return;
    }

    if (!m_pwm.setPeriod(period) || !m_pwm.setDutyCycle(duty)) {
        QMessageBox::critical(this, "错误", "参数设置失败");
        return;
    }

    // 3. 启用 PWM
    if (!m_pwm.enable()) {
        QMessageBox::critical(this, "错误", "启用 PWM 失败");
    }
}


void MainWindow::on_test_pwm_stop_clicked()
{
    if (!m_pwm.disable()) {
        QMessageBox::critical(this, "错误", "关闭 PWM 失败");
    }
}


void MainWindow::on_pushButton_14_clicked()
{
    if (!m_gpio.initGpio()) {
        QMessageBox::critical(this, "错误", "direction gpio 初始化失败！");
        return;
    }
    if (!m_gpio.setDir("out")) {
        QMessageBox::critical(this, "错误", "set pin output mode failed");
        return;
    }
    if(ui->comboBox_3->currentIndex() == 0){ // dir forward
        if (!m_gpio.SetHigh()) {
            QMessageBox::critical(this, "错误", "dir control failed");
        }
    }
    else{ // dir inverse
        if (!m_gpio.SetLow()) {
            QMessageBox::critical(this, "错误", "dir control failed");
        }
    }
}

ProcessResults MainWindow::processString(const QString &input)
{
    ProcessResults results;

    // 处理第一个字符串
    QStringList parts1 = input.split('%', Qt::SkipEmptyParts);
    for (const QString &part : parts1) {
        int hashIndex = part.indexOf('#');
        results.result1 += (hashIndex != -1) ? part.left(hashIndex) + "M" : part;
    }

    // 处理第二个字符串
    QStringList parts2 = input.split('#', Qt::SkipEmptyParts);
    for (int i = 1; i < parts2.size(); ++i) {
        int percentIndex = parts2[i].indexOf('%');
        results.result2 += (percentIndex != -1) ? parts2[i].left(percentIndex) + "M" : parts2[i];
    }

    return results;
}


void MainWindow::on_pushButton_15_clicked()
{
    // 获取输入
    QString input = ui->lineEdit_7->text().trimmed();  // 去除首尾空格
    if (input.isEmpty()) {
        QMessageBox::warning(this, "错误", "输入不能为空！");
        return;
    }
    ProcessResults results = processString(input);
    QString tecan_str = results.result1;
    QString stepper_str = results.result2;
    QList<int> stepper_time = calculateStepperTimeSegments(stepper_str); // calculate time cost by steppers
    QVector<int> vector_stepper_time = QVector<int>::fromList(stepper_time);
    // calculate time costs by tecan

    // migrate, devide tecan commands and send
    QString merged_str = merge_stepper_time(vector_stepper_time, tecan_str);
    QStringList tecan_commands = splitStringEvery8Chars(merged_str);
    send_tecan_command(tecan_commands);


}



void MainWindow::send_tecan_command(QStringList command){
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
                                257, // 0x0101
                                0,
                                0,
                                data,dlc))
        // update log
        {updateCanLog(257, data, dlc, true);    }
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
                                259, // 0x0103, start multi-frame
                                0,
                                0,
                                data0,dlc0))
        // update log
        {updateCanLog(259, data0, dlc0, true);    }
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
                                257, // 0x0103, start multi-frame
                                0,
                                0,
                                data1,dlc1))
        // update log
        {updateCanLog(257, data1, dlc1, true);    }
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
                                259, // 0x0103, start multi-frame
                                0,
                                0,
                                data0,dlc0))
        // update log
        {updateCanLog(259, data0, dlc0, true);    }
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
                                    260, // 0x0103, start multi-frame
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
                                257, // 0x0101, start multi-frame
                                0,
                                0,
                                data,dlc))
        // update log
        {updateCanLog(257, data, dlc, true);        }
        else
            QMessageBox::warning(this,"警告","数据发送失败！");
    }
}



