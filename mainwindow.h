#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "canthread.h"

#include "pwmcontroller.h"
#include "gpiocontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

// 定义结果容器
struct ProcessResults {
    QString result1;// tecan1
    QString result2;
};

struct ProcessResult {
    QString commandStr1;  // 对应tecan1
    QString commandStr2;  // 对应tecan2
    QString positionStr; // 对应str2
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void AddDataToList(QStringList strList);

public slots:
    void onGetProtocolData(VCI_CAN_OBJ *vci,unsigned int dwRel,unsigned int channel);

    void onBoardInfo(VCI_BOARD_INFO vbi);

    // unsigned char* into_ascii(char* mystr);

    // void send_msg_and_print_command(QStringList mystr, unsigned int pre_str);
    QString byteToHex(quint8 byte);
    QString rawDataToHex(const QByteArray &data);
    QByteArray intoAscii(const QString &input);

    ProcessResults processString(const QString &input);// for command string process

    void moveStepper(const QString &input);

    ProcessResult processText();

    QString qtProcessString(const QString& input); // handle stepper command

private slots:


    void on_run_your_scripts_clicked();


    void on_pro_debug_open_USBCAN_clicked();

    void on_pro_debug_send_clicked();

    void on_pro_debug_init_CAN_clicked();

    void on_pro_debug_start_CAN_clicked();

    void on_pro_debug_reset_clicked();

    void on_pushButton_clicked();

    // void on_pushButton_5_clicked();

    void on_test_pwm_start_clicked();

    void on_test_pwm_stop_clicked();

    void updateCanLog(quint32 id, unsigned char* data, int dlc, bool isTx);

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void send_tecan_command(QStringList command);
    void sendStepperCommand(const QString& input, QList<int> tecan_time);
    void send_tecan_command2(QString input); // version2 use
    void send_tecan_command3(QString input);

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    CANThread *canthread;
    PwmController m_pwm;  // PWM 控制器实例
    GpioController m_gpio_2 {147}; // control gpio
    PwmController m_pwm_2 {3, 0};  //
    GpioController m_gpio; // gpio4_C3
};
#endif // MAINWINDOW_H
