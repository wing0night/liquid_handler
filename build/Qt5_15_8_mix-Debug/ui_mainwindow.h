/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QFrame *frame;
    QFrame *frame_3;
    QLabel *label_3;
    QPushButton *pushButton;
    QFrame *frame_4;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *comboBox;
    QCheckBox *checkBox;
    QLabel *label_10;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QFrame *frame_5;
    QLabel *label_4;
    QComboBox *motor_comboBox;
    QPushButton *forward;
    QPushButton *reverse;
    QFrame *frame_6;
    QFrame *frame_2;
    QFrame *frame_7;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QFrame *frame_8;
    QPushButton *emergency_stop_1;
    QLabel *label;
    QLabel *label_2;
    QWidget *tab2;
    QFrame *frame_9;
    QFrame *frame_10;
    QFrame *frame_11;
    QPushButton *emergency_stop_2;
    QWidget *tab3;
    QFrame *frame_12;
    QLabel *label_5;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser_3;
    QFrame *frame_13;
    QLabel *label_6;
    QTextEdit *textEdit;
    QFrame *frame_14;
    QPushButton *run_your_scripts;
    QPushButton *emergency_stop_3;
    QWidget *tab;
    QLabel *label_11;
    QFrame *frame_15;
    QFrame *frame_20;
    QLabel *label_19;
    QLabel *label_12;
    QComboBox *pro_debug_combo_index;
    QLabel *label_24;
    QComboBox *pro_debug_combo_bps;
    QPushButton *pro_debug_open_USBCAN;
    QPushButton *pro_debug_reset;
    QPushButton *pro_debug_init_CAN;
    QPushButton *pro_debug_start_CAN;
    QFrame *frame_21;
    QLabel *label_20;
    QTextBrowser *pro_debug_device_info;
    QFrame *frame_22;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *pro_debug_ID;
    QComboBox *pro_debug_combo_channel;
    QComboBox *pro_debug_combo_frame1;
    QComboBox *pro_debug_combo_frame2;
    QPushButton *pro_debug_send;
    QLabel *label_23;
    QLineEdit *pro_debug_ID_2;
    QTableWidget *tableWidget;
    QWidget *tab4;
    QTextBrowser *textBrowser;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1800, 1173);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 20, 1741, 1111));
        tabWidget->setMouseTracking(false);
        tabWidget->setFocusPolicy(Qt::TabFocus);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(64, 64));
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setMovable(true);
        tabWidget->setTabBarAutoHide(false);
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        QFont font;
        font.setBold(true);
        tab1->setFont(font);
        tab1->setStyleSheet(QString::fromUtf8(""));
        frame = new QFrame(tab1);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 50, 1611, 311));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(10, 10, 441, 291));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 105, 105);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 20, 241, 21));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setStrikeOut(false);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pushButton = new QPushButton(frame_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 60, 331, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);"));
        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(460, 10, 441, 291));
        frame_4->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 105, 105);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_7 = new QLabel(frame_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 20, 241, 21));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit = new QLineEdit(frame_4);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 70, 113, 28));
        label_8 = new QLabel(frame_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 70, 80, 21));
        label_8->setFont(font);
        label_9 = new QLabel(frame_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(40, 120, 80, 21));
        label_9->setFont(font);
        comboBox = new QComboBox(frame_4);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(140, 120, 96, 29));
        checkBox = new QCheckBox(frame_4);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(280, 120, 121, 27));
        label_10 = new QLabel(frame_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(40, 170, 80, 21));
        label_10->setFont(font);
        lineEdit_2 = new QLineEdit(frame_4);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 170, 261, 28));
        pushButton_2 = new QPushButton(frame_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(50, 220, 331, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);"));
        frame_5 = new QFrame(frame);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(910, 10, 691, 141));
        frame_5->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 105, 105);"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 20, 241, 21));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        motor_comboBox = new QComboBox(frame_5);
        motor_comboBox->addItem(QString());
        motor_comboBox->addItem(QString());
        motor_comboBox->setObjectName(QString::fromUtf8("motor_comboBox"));
        motor_comboBox->setGeometry(QRect(70, 60, 131, 51));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setItalic(false);
        motor_comboBox->setFont(font2);
        motor_comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);"));
        forward = new QPushButton(frame_5);
        forward->setObjectName(QString::fromUtf8("forward"));
        forward->setGeometry(QRect(280, 20, 361, 41));
        forward->setFont(font);
        forward->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);"));
        reverse = new QPushButton(frame_5);
        reverse->setObjectName(QString::fromUtf8("reverse"));
        reverse->setGeometry(QRect(280, 70, 361, 41));
        reverse->setFont(font);
        reverse->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);"));
        frame_6 = new QFrame(frame);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(910, 160, 691, 141));
        frame_6->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 105, 105);"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(tab1);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 430, 1601, 551));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_7 = new QFrame(frame_2);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setGeometry(QRect(10, 10, 941, 521));
        frame_7->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 105, 105);"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        pushButton_3 = new QPushButton(frame_7);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(190, 60, 106, 30));
        pushButton_4 = new QPushButton(frame_7);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(380, 60, 106, 30));
        frame_8 = new QFrame(frame_2);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setGeometry(QRect(960, 10, 631, 521));
        frame_8->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 105, 105);"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        emergency_stop_1 = new QPushButton(frame_8);
        emergency_stop_1->setObjectName(QString::fromUtf8("emergency_stop_1"));
        emergency_stop_1->setGeometry(QRect(410, 420, 211, 91));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setItalic(false);
        emergency_stop_1->setFont(font3);
        emergency_stop_1->setStyleSheet(QString::fromUtf8("background-color: rgb(150, 0, 0);\n"
"font: 700 15pt \"Ubuntu Condensed\";\n"
"color: rgb(255, 255, 255);"));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("application-exit")));
        emergency_stop_1->setIcon(icon);
        emergency_stop_1->setIconSize(QSize(36, 36));
        emergency_stop_1->setFlat(false);
        label = new QLabel(tab1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 241, 21));
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(tab1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 390, 261, 21));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("emblem-system")));
        tabWidget->addTab(tab1, icon1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        frame_9 = new QFrame(tab2);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setGeometry(QRect(0, 70, 1601, 331));
        frame_9->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        frame_10 = new QFrame(tab2);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setGeometry(QRect(0, 500, 1601, 191));
        frame_10->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        frame_11 = new QFrame(tab2);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setGeometry(QRect(0, 760, 1601, 201));
        frame_11->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        emergency_stop_2 = new QPushButton(frame_11);
        emergency_stop_2->setObjectName(QString::fromUtf8("emergency_stop_2"));
        emergency_stop_2->setGeometry(QRect(1380, 100, 211, 91));
        emergency_stop_2->setFont(font3);
        emergency_stop_2->setStyleSheet(QString::fromUtf8("background-color: rgb(150, 0, 0);\n"
"font: 700 15pt \"Ubuntu Condensed\";\n"
"color: rgb(255, 255, 255);"));
        emergency_stop_2->setIcon(icon);
        emergency_stop_2->setIconSize(QSize(36, 36));
        emergency_stop_2->setFlat(false);
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("format-justify-left")));
        tabWidget->addTab(tab2, icon2, QString());
        tab3 = new QWidget();
        tab3->setObjectName(QString::fromUtf8("tab3"));
        frame_12 = new QFrame(tab3);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setGeometry(QRect(0, -10, 791, 851));
        frame_12->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame_12);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 10, 791, 71));
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        label_5->setFont(font4);
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignCenter'"));
        textBrowser_2 = new QTextBrowser(frame_12);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(0, 80, 791, 771));
        textBrowser_2->setStyleSheet(QString::fromUtf8("background-color: rgb(40, 40, 40);\n"
"color: rgb(255, 255, 255);"));
        textBrowser_3 = new QTextBrowser(frame_12);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(580, 520, 791, 771));
        textBrowser_3->setStyleSheet(QString::fromUtf8("background-color: rgb(40, 40, 40);"));
        frame_13 = new QFrame(tab3);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        frame_13->setGeometry(QRect(790, -10, 811, 851));
        frame_13->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(frame_13);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 10, 811, 71));
        label_6->setFont(font4);
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 55, 91);\n"
"color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignCenter'"));
        textEdit = new QTextEdit(frame_13);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 80, 811, 771));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 83, 83);\n"
"color: rgb(255, 255, 255);"));
        frame_14 = new QFrame(tab3);
        frame_14->setObjectName(QString::fromUtf8("frame_14"));
        frame_14->setGeometry(QRect(0, 840, 1601, 141));
        frame_14->setStyleSheet(QString::fromUtf8("background-color: rgb(146, 146, 146);"));
        frame_14->setFrameShape(QFrame::StyledPanel);
        frame_14->setFrameShadow(QFrame::Raised);
        run_your_scripts = new QPushButton(frame_14);
        run_your_scripts->setObjectName(QString::fromUtf8("run_your_scripts"));
        run_your_scripts->setGeometry(QRect(1120, 30, 211, 91));
        run_your_scripts->setFont(font3);
        run_your_scripts->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 82, 117);\n"
"color: rgb(255, 255, 255);"));
        run_your_scripts->setIconSize(QSize(36, 36));
        run_your_scripts->setFlat(false);
        emergency_stop_3 = new QPushButton(frame_14);
        emergency_stop_3->setObjectName(QString::fromUtf8("emergency_stop_3"));
        emergency_stop_3->setGeometry(QRect(1370, 30, 211, 91));
        emergency_stop_3->setFont(font3);
        emergency_stop_3->setStyleSheet(QString::fromUtf8("background-color: rgb(150, 0, 0);\n"
"font: 700 15pt \"Ubuntu Condensed\";\n"
"color: rgb(255, 255, 255);"));
        emergency_stop_3->setIcon(icon);
        emergency_stop_3->setIconSize(QSize(36, 36));
        emergency_stop_3->setFlat(false);
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("emblem-downloads")));
        tabWidget->addTab(tab3, icon3, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 10, 241, 21));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        frame_15 = new QFrame(tab);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        frame_15->setGeometry(QRect(0, 50, 1611, 311));
        frame_15->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);
        frame_20 = new QFrame(frame_15);
        frame_20->setObjectName(QString::fromUtf8("frame_20"));
        frame_20->setGeometry(QRect(10, 10, 441, 291));
        frame_20->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 105, 105);"));
        frame_20->setFrameShape(QFrame::StyledPanel);
        frame_20->setFrameShadow(QFrame::Raised);
        label_19 = new QLabel(frame_20);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(30, 20, 241, 21));
        label_19->setFont(font1);
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_12 = new QLabel(frame_20);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(30, 60, 61, 21));
        QFont font5;
        font5.setPointSize(11);
        font5.setBold(true);
        font5.setStrikeOut(false);
        label_12->setFont(font5);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pro_debug_combo_index = new QComboBox(frame_20);
        pro_debug_combo_index->addItem(QString());
        pro_debug_combo_index->addItem(QString());
        pro_debug_combo_index->setObjectName(QString::fromUtf8("pro_debug_combo_index"));
        pro_debug_combo_index->setGeometry(QRect(90, 50, 96, 29));
        label_24 = new QLabel(frame_20);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(30, 100, 91, 21));
        label_24->setFont(font5);
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pro_debug_combo_bps = new QComboBox(frame_20);
        pro_debug_combo_bps->addItem(QString());
        pro_debug_combo_bps->addItem(QString());
        pro_debug_combo_bps->setObjectName(QString::fromUtf8("pro_debug_combo_bps"));
        pro_debug_combo_bps->setGeometry(QRect(130, 90, 121, 29));
        pro_debug_open_USBCAN = new QPushButton(frame_20);
        pro_debug_open_USBCAN->setObjectName(QString::fromUtf8("pro_debug_open_USBCAN"));
        pro_debug_open_USBCAN->setGeometry(QRect(30, 140, 141, 30));
        pro_debug_reset = new QPushButton(frame_20);
        pro_debug_reset->setObjectName(QString::fromUtf8("pro_debug_reset"));
        pro_debug_reset->setGeometry(QRect(210, 140, 106, 30));
        pro_debug_init_CAN = new QPushButton(frame_20);
        pro_debug_init_CAN->setObjectName(QString::fromUtf8("pro_debug_init_CAN"));
        pro_debug_init_CAN->setGeometry(QRect(30, 190, 141, 30));
        pro_debug_start_CAN = new QPushButton(frame_20);
        pro_debug_start_CAN->setObjectName(QString::fromUtf8("pro_debug_start_CAN"));
        pro_debug_start_CAN->setGeometry(QRect(210, 190, 141, 30));
        frame_21 = new QFrame(frame_15);
        frame_21->setObjectName(QString::fromUtf8("frame_21"));
        frame_21->setGeometry(QRect(460, 10, 441, 291));
        frame_21->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 105, 105);"));
        frame_21->setFrameShape(QFrame::StyledPanel);
        frame_21->setFrameShadow(QFrame::Raised);
        label_20 = new QLabel(frame_21);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(40, 20, 241, 21));
        label_20->setFont(font1);
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pro_debug_device_info = new QTextBrowser(frame_21);
        pro_debug_device_info->setObjectName(QString::fromUtf8("pro_debug_device_info"));
        pro_debug_device_info->setGeometry(QRect(20, 50, 401, 221));
        frame_22 = new QFrame(frame_15);
        frame_22->setObjectName(QString::fromUtf8("frame_22"));
        frame_22->setGeometry(QRect(910, 10, 691, 291));
        frame_22->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 105, 105);"));
        frame_22->setFrameShape(QFrame::StyledPanel);
        frame_22->setFrameShadow(QFrame::Raised);
        label_21 = new QLabel(frame_22);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(40, 20, 241, 21));
        label_21->setFont(font1);
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_22 = new QLabel(frame_22);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(40, 60, 61, 21));
        label_22->setFont(font5);
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pro_debug_ID = new QLineEdit(frame_22);
        pro_debug_ID->setObjectName(QString::fromUtf8("pro_debug_ID"));
        pro_debug_ID->setGeometry(QRect(100, 50, 141, 28));
        pro_debug_combo_channel = new QComboBox(frame_22);
        pro_debug_combo_channel->addItem(QString());
        pro_debug_combo_channel->addItem(QString());
        pro_debug_combo_channel->setObjectName(QString::fromUtf8("pro_debug_combo_channel"));
        pro_debug_combo_channel->setGeometry(QRect(300, 50, 121, 29));
        pro_debug_combo_frame1 = new QComboBox(frame_22);
        pro_debug_combo_frame1->addItem(QString());
        pro_debug_combo_frame1->addItem(QString());
        pro_debug_combo_frame1->setObjectName(QString::fromUtf8("pro_debug_combo_frame1"));
        pro_debug_combo_frame1->setGeometry(QRect(40, 100, 171, 29));
        pro_debug_combo_frame2 = new QComboBox(frame_22);
        pro_debug_combo_frame2->addItem(QString());
        pro_debug_combo_frame2->addItem(QString());
        pro_debug_combo_frame2->setObjectName(QString::fromUtf8("pro_debug_combo_frame2"));
        pro_debug_combo_frame2->setGeometry(QRect(250, 100, 171, 29));
        pro_debug_send = new QPushButton(frame_22);
        pro_debug_send->setObjectName(QString::fromUtf8("pro_debug_send"));
        pro_debug_send->setGeometry(QRect(450, 100, 141, 30));
        label_23 = new QLabel(frame_22);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(40, 160, 81, 21));
        label_23->setFont(font5);
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pro_debug_ID_2 = new QLineEdit(frame_22);
        pro_debug_ID_2->setObjectName(QString::fromUtf8("pro_debug_ID_2"));
        pro_debug_ID_2->setGeometry(QRect(120, 150, 141, 28));
        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 10)
            tableWidget->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QBrush brush(QColor(138, 226, 52, 255));
        brush.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setForeground(brush);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 380, 1611, 591));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        QIcon icon4(QIcon::fromTheme(QString::fromUtf8("application-x-executable")));
        tabWidget->addTab(tab, icon4, QString());
        tab4 = new QWidget();
        tab4->setObjectName(QString::fromUtf8("tab4"));
        QIcon icon5(QIcon::fromTheme(QString::fromUtf8("help-contents")));
        tabWidget->addTab(tab4, icon5, QString());
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(100, 1020, 1601, 91));
        QFont font6;
        font6.setPointSize(11);
        textBrowser->setFont(font6);
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 215, 207);"));
        textBrowser->setTabStopDistance(159.000000000000000);
        textBrowser->setCursorWidth(2);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);
        motor_comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "CAN Device Setting", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Open USBCANFD-Linux Device", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Send data", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "ID(0x):", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "protocol:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "CAN", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "CANFD", nullptr));

        checkBox->setText(QCoreApplication::translate("MainWindow", "CANFD acc", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "data(0x)", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "send", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Motor CAN", nullptr));
        motor_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Motor1", nullptr));
        motor_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Motor2", nullptr));

        motor_comboBox->setCurrentText(QCoreApplication::translate("MainWindow", "Motor1", nullptr));
        forward->setText(QCoreApplication::translate("MainWindow", "Forward", nullptr));
        reverse->setText(QCoreApplication::translate("MainWindow", "Reverse", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "initialize", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "bault rate", nullptr));
        emergency_stop_1->setText(QCoreApplication::translate("MainWindow", "Emergency Stop", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Connect Your Device", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Set Global Parameter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QString());
        emergency_stop_2->setText(QCoreApplication::translate("MainWindow", "Emergency Stop", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Example", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Edit Your Own Markdown Script", nullptr));
        run_your_scripts->setText(QCoreApplication::translate("MainWindow", "Run your scripts", nullptr));
        emergency_stop_3->setText(QCoreApplication::translate("MainWindow", "Emergency Stop", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab3), QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "settings for USB-CAN", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "USB-CAN Device Setting", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "index", nullptr));
        pro_debug_combo_index->setItemText(0, QCoreApplication::translate("MainWindow", "0", nullptr));
        pro_debug_combo_index->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));

        label_24->setText(QCoreApplication::translate("MainWindow", "bauld rate", nullptr));
        pro_debug_combo_bps->setItemText(0, QCoreApplication::translate("MainWindow", "100Kbps", nullptr));
        pro_debug_combo_bps->setItemText(1, QCoreApplication::translate("MainWindow", "500Kbps", nullptr));

        pro_debug_open_USBCAN->setText(QCoreApplication::translate("MainWindow", "open USB-CAN", nullptr));
        pro_debug_reset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        pro_debug_init_CAN->setText(QCoreApplication::translate("MainWindow", "init CAN", nullptr));
        pro_debug_start_CAN->setText(QCoreApplication::translate("MainWindow", "start CAN", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "USB-CAN device info", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Send data", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "ID(0x)", nullptr));
        pro_debug_combo_channel->setItemText(0, QCoreApplication::translate("MainWindow", "channel 1", nullptr));
        pro_debug_combo_channel->setItemText(1, QCoreApplication::translate("MainWindow", "channel 2", nullptr));

        pro_debug_combo_frame1->setItemText(0, QCoreApplication::translate("MainWindow", "standard frame", nullptr));
        pro_debug_combo_frame1->setItemText(1, QCoreApplication::translate("MainWindow", "extended frame", nullptr));

        pro_debug_combo_frame2->setItemText(0, QCoreApplication::translate("MainWindow", "data frame", nullptr));
        pro_debug_combo_frame2->setItemText(1, QCoreApplication::translate("MainWindow", "extended frame", nullptr));

        pro_debug_send->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "data(0x)", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Sys time", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Time flag", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Time flag(s)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "CAN channel", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "direction", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "frame type", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "frame format", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "length", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "data", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QString());
        tabWidget->setTabText(tabWidget->indexOf(tab4), QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
