#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QIODevice>
#include <QObject>
#include <QTimer>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QTranslator>
#include "transmiterror.h"
#include "openerror.h"

#define transmit_config 0
#define timer_config 1

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Transmit_Times(int location,int times);
    void Receive_Times(int location,int i);
    void Transmit_Size(int location,int size);
    void Receive_Size(int location,int size);
    void Transmit_Init(int flag);/*transmit_config*//*timer_config*/
    void Chiness_English_Switch();

private slots:
    void on_OpenButton_clicked();

    void on_SeriesBox_currentIndexChanged(const QString &arg1);

    void on_OddEvenBox_currentIndexChanged(const QString &arg1);

    void on_DataBox_currentIndexChanged(const QString &arg1);

    void on_BaudBox_currentIndexChanged(int index);

    void on_StopBox_currentIndexChanged(const QString &arg1);

    void on_ClearTransmit_clicked();

    void on_ClearRx_Tx_clicked();

    void Receive_Data();

    void on_ClearTransmit_2_clicked();

    void timerTransmit();

    void on_OpenFile_clicked();

    void on_SaveFile_clicked();

    void SendButton_clicked();

    void on_ASCII_clicked(bool checked);

    void on_HexReceive_clicked(bool checked);

    void on_Chinese_English_Switch_triggered(bool checked);

    void on_about_triggered();

private:
    Ui::MainWindow *ui;
    QSerialPort SerialPort;
    QSerialPort *serialport;
    QSerialPortInfo SerialPortInfo;
    TransmitError *transmiterror;
    OpenError *openerror;
    QTimer *timer;
    QFileDialog *FileDialog;
    QFile *File;
    QTextStream *TextStream;
    QTranslator *translator;
};

#endif // MAINWINDOW_H
