#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "canthread.h"

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

private:
    Ui::MainWindow *ui;
    CANThread *canthread;
};
#endif // MAINWINDOW_H
