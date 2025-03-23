#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "canthread.h"

#include "pwmcontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

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

private:
    Ui::MainWindow *ui;
    CANThread *canthread;
    PwmController m_pwm;  // PWM 控制器实例
};
#endif // MAINWINDOW_H
