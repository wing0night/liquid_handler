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
    QString result1;
    QString result2;
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

private slots:

    void on_motor_comboBox_currentTextChanged(const QString &arg1);

    void on_forward_clicked();

    void on_reverse_clicked();

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

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

private:
    Ui::MainWindow *ui;
    CANThread *canthread;
    PwmController m_pwm;  // PWM 控制器实例
    GpioController m_gpio; // control gpio
    PwmController m_pwm_2 {3, 0};  //
    GpioController m_gpio_2 {147}; // gpio4_C3
};
#endif // MAINWINDOW_H
