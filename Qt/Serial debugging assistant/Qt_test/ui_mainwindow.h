/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *Chinese_English_Switch;
    QAction *about;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *SeriesPortChoice;
    QComboBox *SeriesBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *BaudRate;
    QComboBox *BaudBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *OddEvenCheckBits;
    QComboBox *OddEvenBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *DataBits;
    QComboBox *DataBox;
    QHBoxLayout *horizontalLayout;
    QLabel *StopBits;
    QComboBox *StopBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QPushButton *OpenButton;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *TimeTransmit;
    QLineEdit *lineEdit;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_11;
    QCheckBox *HexReceive;
    QCheckBox *HexTransmit;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *ASCII;
    QLabel *label_7;
    QCheckBox *timestamp;
    QLineEdit *LineEdit;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *OpenFile;
    QPushButton *SendFile;
    QWidget *widget_3;
    QVBoxLayout *text;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_9;
    QTextEdit *ReceiveEdit;
    QVBoxLayout *verticalLayout_3;
    QPushButton *ClearRx_Tx;
    QPushButton *SaveFile;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_8;
    QTextEdit *TransmitEdit_2;
    QPushButton *ClearTransmit;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_7;
    QTextEdit *TransmitEdit;
    QVBoxLayout *verticalLayout_2;
    QPushButton *SendButton;
    QPushButton *ClearTransmit_2;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(928, 576);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(928, 463));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        MainWindow->setFont(font);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/image/jie.png);"));
        Chinese_English_Switch = new QAction(MainWindow);
        Chinese_English_Switch->setObjectName(QString::fromUtf8("Chinese_English_Switch"));
        Chinese_English_Switch->setCheckable(true);
        Chinese_English_Switch->setChecked(false);
        about = new QAction(MainWindow);
        about->setObjectName(QString::fromUtf8("about"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setRowWrapPolicy(QFormLayout::WrapLongRows);
        formLayout->setHorizontalSpacing(50);
        formLayout->setContentsMargins(14, 10, 20, 10);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_7->setContentsMargins(-1, -1, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 1, -1, -1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(12, -1, -1, -1);
        SeriesPortChoice = new QLabel(centralWidget);
        SeriesPortChoice->setObjectName(QString::fromUtf8("SeriesPortChoice"));
        sizePolicy1.setHeightForWidth(SeriesPortChoice->sizePolicy().hasHeightForWidth());
        SeriesPortChoice->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        SeriesPortChoice->setFont(font2);
        SeriesPortChoice->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_4->addWidget(SeriesPortChoice);

        SeriesBox = new QComboBox(centralWidget);
        SeriesBox->setObjectName(QString::fromUtf8("SeriesBox"));
        sizePolicy1.setHeightForWidth(SeriesBox->sizePolicy().hasHeightForWidth());
        SeriesBox->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(16);
        SeriesBox->setFont(font3);
        SeriesBox->setEditable(false);

        horizontalLayout_4->addWidget(SeriesBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(12, -1, -1, -1);
        BaudRate = new QLabel(centralWidget);
        BaudRate->setObjectName(QString::fromUtf8("BaudRate"));
        sizePolicy1.setHeightForWidth(BaudRate->sizePolicy().hasHeightForWidth());
        BaudRate->setSizePolicy(sizePolicy1);
        BaudRate->setFont(font2);

        horizontalLayout_5->addWidget(BaudRate);

        BaudBox = new QComboBox(centralWidget);
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->setObjectName(QString::fromUtf8("BaudBox"));
        sizePolicy1.setHeightForWidth(BaudBox->sizePolicy().hasHeightForWidth());
        BaudBox->setSizePolicy(sizePolicy1);
        BaudBox->setFont(font3);
        BaudBox->setEditable(false);

        horizontalLayout_5->addWidget(BaudBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(12, -1, -1, -1);
        OddEvenCheckBits = new QLabel(centralWidget);
        OddEvenCheckBits->setObjectName(QString::fromUtf8("OddEvenCheckBits"));
        sizePolicy1.setHeightForWidth(OddEvenCheckBits->sizePolicy().hasHeightForWidth());
        OddEvenCheckBits->setSizePolicy(sizePolicy1);
        OddEvenCheckBits->setFont(font2);

        horizontalLayout_3->addWidget(OddEvenCheckBits);

        OddEvenBox = new QComboBox(centralWidget);
        OddEvenBox->addItem(QString());
        OddEvenBox->addItem(QString());
        OddEvenBox->addItem(QString());
        OddEvenBox->setObjectName(QString::fromUtf8("OddEvenBox"));
        sizePolicy1.setHeightForWidth(OddEvenBox->sizePolicy().hasHeightForWidth());
        OddEvenBox->setSizePolicy(sizePolicy1);
        OddEvenBox->setFont(font3);

        horizontalLayout_3->addWidget(OddEvenBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(12, -1, -1, -1);
        DataBits = new QLabel(centralWidget);
        DataBits->setObjectName(QString::fromUtf8("DataBits"));
        sizePolicy1.setHeightForWidth(DataBits->sizePolicy().hasHeightForWidth());
        DataBits->setSizePolicy(sizePolicy1);
        DataBits->setFont(font2);

        horizontalLayout_2->addWidget(DataBits);

        DataBox = new QComboBox(centralWidget);
        DataBox->addItem(QString());
        DataBox->addItem(QString());
        DataBox->addItem(QString());
        DataBox->addItem(QString());
        DataBox->setObjectName(QString::fromUtf8("DataBox"));
        sizePolicy1.setHeightForWidth(DataBox->sizePolicy().hasHeightForWidth());
        DataBox->setSizePolicy(sizePolicy1);
        DataBox->setFont(font3);

        horizontalLayout_2->addWidget(DataBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(12, -1, -1, -1);
        StopBits = new QLabel(centralWidget);
        StopBits->setObjectName(QString::fromUtf8("StopBits"));
        sizePolicy1.setHeightForWidth(StopBits->sizePolicy().hasHeightForWidth());
        StopBits->setSizePolicy(sizePolicy1);
        StopBits->setFont(font2);

        horizontalLayout->addWidget(StopBits);

        StopBox = new QComboBox(centralWidget);
        StopBox->addItem(QString());
        StopBox->addItem(QString());
        StopBox->addItem(QString());
        StopBox->setObjectName(QString::fromUtf8("StopBox"));
        sizePolicy1.setHeightForWidth(StopBox->sizePolicy().hasHeightForWidth());
        StopBox->setSizePolicy(sizePolicy1);
        StopBox->setFont(font3);
        StopBox->setLayoutDirection(Qt::LeftToRight);
        StopBox->setStyleSheet(QString::fromUtf8(""));
        StopBox->setFrame(true);

        horizontalLayout->addWidget(StopBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(12, -1, -1, -1);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setFont(font3);

        horizontalLayout_6->addWidget(label);

        OpenButton = new QPushButton(centralWidget);
        OpenButton->setObjectName(QString::fromUtf8("OpenButton"));
        sizePolicy1.setHeightForWidth(OpenButton->sizePolicy().hasHeightForWidth());
        OpenButton->setSizePolicy(sizePolicy1);
        OpenButton->setFont(font2);
        OpenButton->setAutoFillBackground(false);
        OpenButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_6->addWidget(OpenButton);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(12, -1, -1, -1);
        TimeTransmit = new QCheckBox(centralWidget);
        TimeTransmit->setObjectName(QString::fromUtf8("TimeTransmit"));
        sizePolicy1.setHeightForWidth(TimeTransmit->sizePolicy().hasHeightForWidth());
        TimeTransmit->setSizePolicy(sizePolicy1);
        TimeTransmit->setFont(font3);
        TimeTransmit->setToolTipDuration(1);

        horizontalLayout_12->addWidget(TimeTransmit);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setCursor(QCursor(Qt::ArrowCursor));
        lineEdit->setLayoutDirection(Qt::RightToLeft);
        lineEdit->setAutoFillBackground(false);
        lineEdit->setStyleSheet(QString::fromUtf8(""));
        lineEdit->setFrame(true);
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit->setDragEnabled(false);

        horizontalLayout_12->addWidget(lineEdit);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Times New Roman"));
        font4.setPointSize(12);
        label_6->setFont(font4);
        label_6->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"padding:11px;"));

        horizontalLayout_12->addWidget(label_6);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        HexReceive = new QCheckBox(centralWidget);
        HexReceive->setObjectName(QString::fromUtf8("HexReceive"));
        sizePolicy1.setHeightForWidth(HexReceive->sizePolicy().hasHeightForWidth());
        HexReceive->setSizePolicy(sizePolicy1);
        HexReceive->setFont(font3);
        HexReceive->setToolTipDuration(1);
        HexReceive->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"padding:11px;"));
        HexReceive->setText(QString::fromUtf8("Hex_RX"));
        HexReceive->setChecked(false);

        horizontalLayout_11->addWidget(HexReceive);

        HexTransmit = new QCheckBox(centralWidget);
        HexTransmit->setObjectName(QString::fromUtf8("HexTransmit"));
        sizePolicy1.setHeightForWidth(HexTransmit->sizePolicy().hasHeightForWidth());
        HexTransmit->setSizePolicy(sizePolicy1);
        HexTransmit->setFont(font3);
        HexTransmit->setToolTipDuration(1);
        HexTransmit->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"padding:11px;"));
        HexTransmit->setText(QString::fromUtf8("Hex_TX"));

        horizontalLayout_11->addWidget(HexTransmit);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(9, -1, -1, -1);
        ASCII = new QCheckBox(centralWidget);
        ASCII->setObjectName(QString::fromUtf8("ASCII"));
        ASCII->setFont(font3);

        horizontalLayout_10->addWidget(ASCII);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        horizontalLayout_10->addWidget(label_7);

        timestamp = new QCheckBox(centralWidget);
        timestamp->setObjectName(QString::fromUtf8("timestamp"));
        timestamp->setFont(font3);

        horizontalLayout_10->addWidget(timestamp);


        verticalLayout->addLayout(horizontalLayout_10);

        LineEdit = new QLineEdit(centralWidget);
        LineEdit->setObjectName(QString::fromUtf8("LineEdit"));
        sizePolicy1.setHeightForWidth(LineEdit->sizePolicy().hasHeightForWidth());
        LineEdit->setSizePolicy(sizePolicy1);
        QFont font5;
        font5.setFamily(QString::fromUtf8("Times New Roman"));
        font5.setPointSize(9);
        LineEdit->setFont(font5);
        LineEdit->setCursor(QCursor(Qt::ArrowCursor));
        LineEdit->setLayoutDirection(Qt::RightToLeft);
        LineEdit->setStyleSheet(QString::fromUtf8("background-image:url();"));
        LineEdit->setReadOnly(true);

        verticalLayout->addWidget(LineEdit);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(-1, 6, -1, -1);
        OpenFile = new QPushButton(centralWidget);
        OpenFile->setObjectName(QString::fromUtf8("OpenFile"));
        sizePolicy1.setHeightForWidth(OpenFile->sizePolicy().hasHeightForWidth());
        OpenFile->setSizePolicy(sizePolicy1);
        OpenFile->setFont(font3);

        horizontalLayout_13->addWidget(OpenFile);

        SendFile = new QPushButton(centralWidget);
        SendFile->setObjectName(QString::fromUtf8("SendFile"));
        sizePolicy1.setHeightForWidth(SendFile->sizePolicy().hasHeightForWidth());
        SendFile->setSizePolicy(sizePolicy1);
        SendFile->setFont(font3);

        horizontalLayout_13->addWidget(SendFile);


        verticalLayout->addLayout(horizontalLayout_13);

        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"image: url(:/image/lee.png);\n"
"padding:11px;"));

        verticalLayout->addWidget(widget_3);


        verticalLayout_7->addLayout(verticalLayout);


        formLayout->setLayout(1, QFormLayout::LabelRole, verticalLayout_7);

        text = new QVBoxLayout();
        text->setSpacing(6);
        text->setObjectName(QString::fromUtf8("text"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        label_3->setFont(font1);

        text->addWidget(label_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setSizeConstraint(QLayout::SetDefaultConstraint);
        ReceiveEdit = new QTextEdit(centralWidget);
        ReceiveEdit->setObjectName(QString::fromUtf8("ReceiveEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(2);
        sizePolicy4.setVerticalStretch(2);
        sizePolicy4.setHeightForWidth(ReceiveEdit->sizePolicy().hasHeightForWidth());
        ReceiveEdit->setSizePolicy(sizePolicy4);
        QFont font6;
        font6.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font6.setPointSize(12);
        ReceiveEdit->setFont(font6);
        ReceiveEdit->setAutoFillBackground(false);
        ReceiveEdit->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"padding:11px;"));
        ReceiveEdit->setReadOnly(true);

        horizontalLayout_9->addWidget(ReceiveEdit);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        ClearRx_Tx = new QPushButton(centralWidget);
        ClearRx_Tx->setObjectName(QString::fromUtf8("ClearRx_Tx"));
        ClearRx_Tx->setFont(font3);

        verticalLayout_3->addWidget(ClearRx_Tx);

        SaveFile = new QPushButton(centralWidget);
        SaveFile->setObjectName(QString::fromUtf8("SaveFile"));
        SaveFile->setFont(font3);

        verticalLayout_3->addWidget(SaveFile);


        horizontalLayout_9->addLayout(verticalLayout_3);


        text->addLayout(horizontalLayout_9);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy5);
        label_4->setFont(font1);

        text->addWidget(label_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        TransmitEdit_2 = new QTextEdit(centralWidget);
        TransmitEdit_2->setObjectName(QString::fromUtf8("TransmitEdit_2"));
        sizePolicy.setHeightForWidth(TransmitEdit_2->sizePolicy().hasHeightForWidth());
        TransmitEdit_2->setSizePolicy(sizePolicy);
        TransmitEdit_2->setFont(font6);
        TransmitEdit_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"padding:11px;"));
        TransmitEdit_2->setReadOnly(true);

        horizontalLayout_8->addWidget(TransmitEdit_2);

        ClearTransmit = new QPushButton(centralWidget);
        ClearTransmit->setObjectName(QString::fromUtf8("ClearTransmit"));
        ClearTransmit->setFont(font3);
        ClearTransmit->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_8->addWidget(ClearTransmit);


        text->addLayout(horizontalLayout_8);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);
        label_5->setFont(font1);

        text->addWidget(label_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        TransmitEdit = new QTextEdit(centralWidget);
        TransmitEdit->setObjectName(QString::fromUtf8("TransmitEdit"));
        sizePolicy.setHeightForWidth(TransmitEdit->sizePolicy().hasHeightForWidth());
        TransmitEdit->setSizePolicy(sizePolicy);
        TransmitEdit->setFont(font6);
        TransmitEdit->setLayoutDirection(Qt::LeftToRight);
        TransmitEdit->setAutoFillBackground(false);
        TransmitEdit->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"padding:11px;"));

        horizontalLayout_7->addWidget(TransmitEdit);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        SendButton = new QPushButton(centralWidget);
        SendButton->setObjectName(QString::fromUtf8("SendButton"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(SendButton->sizePolicy().hasHeightForWidth());
        SendButton->setSizePolicy(sizePolicy6);
        SendButton->setFont(font2);

        verticalLayout_2->addWidget(SendButton);

        ClearTransmit_2 = new QPushButton(centralWidget);
        ClearTransmit_2->setObjectName(QString::fromUtf8("ClearTransmit_2"));
        ClearTransmit_2->setFont(font3);
        ClearTransmit_2->setLayoutDirection(Qt::LeftToRight);
        ClearTransmit_2->setAutoFillBackground(false);

        verticalLayout_2->addWidget(ClearTransmit_2);


        horizontalLayout_7->addLayout(verticalLayout_2);


        text->addLayout(horizontalLayout_7);


        formLayout->setLayout(1, QFormLayout::FieldRole, text);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 928, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(Chinese_English_Switch);
        menu_2->addAction(about);

        retranslateUi(MainWindow);

        SeriesBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\350\260\203\350\257\225\345\212\251\346\211\213(\346\235\216\346\240\221\351\230\263)", nullptr));
        Chinese_English_Switch->setText(QCoreApplication::translate("MainWindow", "\344\270\255\350\213\261\346\226\207\345\210\207\346\215\242", nullptr));
#if QT_CONFIG(tooltip)
        Chinese_English_Switch->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\255\350\213\261\346\226\207\345\210\207\346\215\242", nullptr));
#endif // QT_CONFIG(tooltip)
        about->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
#if QT_CONFIG(tooltip)
        about->setToolTip(QCoreApplication::translate("MainWindow", "about", nullptr));
#endif // QT_CONFIG(tooltip)
        label_2->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\351\205\215\347\275\256", nullptr));
        SeriesPortChoice->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\351\200\211\346\213\251", nullptr));
        SeriesBox->setCurrentText(QString());
        BaudRate->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        BaudBox->setItemText(0, QCoreApplication::translate("MainWindow", "9600", nullptr));
        BaudBox->setItemText(1, QCoreApplication::translate("MainWindow", "1200", nullptr));
        BaudBox->setItemText(2, QCoreApplication::translate("MainWindow", "2400", nullptr));
        BaudBox->setItemText(3, QCoreApplication::translate("MainWindow", "4800", nullptr));
        BaudBox->setItemText(4, QCoreApplication::translate("MainWindow", "14400", nullptr));
        BaudBox->setItemText(5, QCoreApplication::translate("MainWindow", "19200", nullptr));
        BaudBox->setItemText(6, QCoreApplication::translate("MainWindow", "38400", nullptr));
        BaudBox->setItemText(7, QCoreApplication::translate("MainWindow", "43000", nullptr));
        BaudBox->setItemText(8, QCoreApplication::translate("MainWindow", "57600", nullptr));
        BaudBox->setItemText(9, QCoreApplication::translate("MainWindow", "76800", nullptr));
        BaudBox->setItemText(10, QCoreApplication::translate("MainWindow", "115200", nullptr));
        BaudBox->setItemText(11, QCoreApplication::translate("MainWindow", "128000", nullptr));
        BaudBox->setItemText(12, QCoreApplication::translate("MainWindow", "230400", nullptr));
        BaudBox->setItemText(13, QCoreApplication::translate("MainWindow", "256000", nullptr));

        OddEvenCheckBits->setText(QCoreApplication::translate("MainWindow", "\345\245\207\345\201\266\346\240\241\351\252\214\344\275\215", nullptr));
        OddEvenBox->setItemText(0, QCoreApplication::translate("MainWindow", "NULL", nullptr));
        OddEvenBox->setItemText(1, QCoreApplication::translate("MainWindow", "odd", nullptr));
        OddEvenBox->setItemText(2, QCoreApplication::translate("MainWindow", "even", nullptr));

        DataBits->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        DataBox->setItemText(0, QCoreApplication::translate("MainWindow", "8", nullptr));
        DataBox->setItemText(1, QCoreApplication::translate("MainWindow", "7", nullptr));
        DataBox->setItemText(2, QCoreApplication::translate("MainWindow", "6", nullptr));
        DataBox->setItemText(3, QCoreApplication::translate("MainWindow", "5", nullptr));

        StopBits->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        StopBox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        StopBox->setItemText(1, QCoreApplication::translate("MainWindow", "1.5", nullptr));
        StopBox->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\346\223\215\344\275\234     ", nullptr));
        OpenButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        TimeTransmit->setText(QCoreApplication::translate("MainWindow", "\345\256\232\346\227\266\345\217\221\351\200\201 ", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
        ASCII->setText(QCoreApplication::translate("MainWindow", "ASCII\347\240\201\346\216\245\346\224\266", nullptr));
        label_7->setText(QString());
        timestamp->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\346\210\263", nullptr));
        LineEdit->setText(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\350\267\257\345\276\204", nullptr));
        OpenFile->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        SendFile->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\345\214\272", nullptr));
        ClearRx_Tx->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        SaveFile->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(shortcut)
        SaveFile->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\345\214\272", nullptr));
        ClearTransmit->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\345\206\205\345\256\271", nullptr));
        SendButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
#if QT_CONFIG(shortcut)
        SendButton->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Enter", "Ctrl+Enter\345\217\221\351\200\201"));
#endif // QT_CONFIG(shortcut)
        ClearTransmit_2->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\350\257\255\350\250\200", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
