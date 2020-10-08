#include "mainwindow.h"
#include "ui_mainwindow.h"

/*状态栏次数的全局变量*/
static int i=0;
static int times = 0;

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*永久信息在状态栏*/
    QLabel* MassageForever = new QLabel("Lee Young    1719640124    github.com/leeyoung7017/practice", this);
    ui->statusBar->addPermanentWidget(MassageForever);
    /*快捷键的提示信息*/
    ui->SendButton->setToolTip("Ctrl+Enter");
    ui->SaveFile->setToolTip("Ctrl+S");
    /*定时器的初始化*/
    timer = new QTimer();
    /*获取电脑准备好的串口*/
    QList<QSerialPortInfo> SerialPortName = SerialPortInfo.availablePorts();
    for (int i = 0;i != SerialPortName.size();i++)
    {
        ui->SeriesBox->addItem(SerialPortName.at(i).portName());
    }
    /*将信号与槽关联好*/
    connect(&SerialPort, SIGNAL(readyRead()), this, SLOT(Receive_Data()));
    connect(timer, SIGNAL(timeout()), this, SLOT(timerTransmit()));
    connect(ui->SendButton,SIGNAL(clicked()),this,SLOT(SendButton_clicked()));
    connect(ui->SendFile,SIGNAL(clicked()),this,SLOT(SendButton_clicked()));
}

MainWindow::~MainWindow()
{
    SerialPort.close();
    delete ui;
}

/*发送*/
void MainWindow::Transmit_Init(int flag)
{
    QString textEdit;
    static QByteArray TransmitEditArray;
    if(flag == transmit_config)
    {
        QPushButton *button = qobject_cast<QPushButton*>(sender());
        /*文本框*/
        if(button->objectName() == "SendButton")
        textEdit= ui->TransmitEdit->document()->toPlainText();

        /*文件*/
        if(button->objectName() == "SendFile")
        {
            QString FilePath = ui->LineEdit->text();
            File = new QFile(FilePath);
            File->open(QIODevice::ReadOnly);
            TextStream = new QTextStream(File);
            textEdit = TextStream->readAll();
            File->close();
        }
    }
    /*定时器处理*/
    if(flag == timer_config)
    {
        textEdit= ui->TransmitEdit->document()->toPlainText();
        if(textEdit == NULL)
        {
            QString FilePath = ui->LineEdit->text();
            File = new QFile(FilePath);
            File->open(QIODevice::ReadOnly);
            TextStream = new QTextStream(File);
            textEdit = TextStream->readAll();
            File->close();
        }
    }
    TransmitEditArray = textEdit.toUtf8();


    /*16进制发送*/
    if (ui->HexTransmit->isChecked() == true)
    {
        TransmitEditArray = TransmitEditArray.toHex();
        QByteArray TransmitArray = TransmitEditArray.left(2);
        int size = TransmitEditArray.length();
        for (int l = 2;l<size;l=l+2)
        {
          QByteArray array = TransmitEditArray.mid(l,2);
          TransmitArray = TransmitArray+" "+array;
        }

        TransmitEditArray = TransmitArray;
    }
    /*数据发送*/
    if (SerialPort.isOpen() == true)
    {
        SerialPort.write(TransmitEditArray);
        /*status times*/
        times++;
        MainWindow::Transmit_Times(1,times);
        MainWindow::Transmit_Size(2,TransmitEditArray.size());
        /*appear*/
        ui->TransmitEdit_2->append(TransmitEditArray);
    }
    else/*传输错误*/
    {
        transmiterror = new TransmitError();
        transmiterror->show();
    }
}
/*发送次数*/
void MainWindow::Transmit_Times(int location,int times)
{
    static QLabel *TransmitTimes = nullptr;
    ui->statusBar->removeWidget(TransmitTimes);
    TransmitTimes= new QLabel("    T(times): "+QString::number(times)+"    ",this);
    ui->statusBar->insertWidget(location,TransmitTimes);
}
/*接收次数*/
void MainWindow::Receive_Times(int location,int i)
{
    static QLabel *ReceviceTimes = nullptr;
    ui->statusBar->removeWidget(ReceviceTimes);
    ReceviceTimes= new QLabel("    R(times): "+QString::number(i)+"    ",this);
    ui->statusBar->insertWidget(location,ReceviceTimes);
}
/*发送size*/
void MainWindow::Transmit_Size(int location, int size)
{
    static QLabel *TransmitSize = new QLabel();
    ui->statusBar->removeWidget(TransmitSize);
    TransmitSize= new QLabel("    T(size): "+QString::number(size)+"    ",this);
    ui->statusBar->insertWidget(location,TransmitSize);
}
/*接收size*/
void MainWindow::Receive_Size(int location, int size)
{
    static QLabel *ReceviceSize = new QLabel();
    ui->statusBar->removeWidget(ReceviceSize);
    ReceviceSize= new QLabel("    R(size): "+QString::number(size)+"    ",this);
    ui->statusBar->insertWidget(location,ReceviceSize);
}

/*打开关闭串口*/
void MainWindow::on_OpenButton_clicked()
{
    if (ui->OpenButton->text() == tr("打开串口"))
    {
        if (SerialPort.open(QSerialPort::ReadWrite))
        {
            ui->OpenButton->setText(tr("关闭串口"));
            static QLabel *SerialName=nullptr;
            ui->statusBar->removeWidget(SerialName);
            SerialName= new QLabel("    "+ui->SeriesBox->currentText()+"     ", this);
            ui->statusBar->insertWidget(0,SerialName);
        }
        else
        {
            openerror = new OpenError();
            openerror->show();
        }
    }
    else
    {
        SerialPort.close();
        ui->OpenButton->setText(tr("打开串口"));
    }

}

/*配置串口号*/
void MainWindow::on_SeriesBox_currentIndexChanged(const QString& arg1)
{
    QString      arg2 = arg1, arg3;
    if (arg3 != arg1)
    {
        SerialPort.close();
        ui->ReceiveEdit->clear();
        ui->TransmitEdit->clear();
        ui->OpenButton->setText(tr("打开串口"));
    }
    arg3 = arg1;
    SerialPort.setPortName(arg3);


}

/*配置波特率*/
void MainWindow::on_BaudBox_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:SerialPort.setBaudRate(9600);  break;
    case 1:SerialPort.setBaudRate(1200);break;
    case 2:SerialPort.setBaudRate(2400);break;
    case 3:SerialPort.setBaudRate(4800);break;
    case 4:SerialPort.setBaudRate(14400);break;
    case 5:SerialPort.setBaudRate(19200);break;
    case 6:SerialPort.setBaudRate(38400);break;
    case 7:SerialPort.setBaudRate(43000);break;
    case 8:SerialPort.setBaudRate(57600);break;
    case 9:SerialPort.setBaudRate(76800);break;
    case 10:SerialPort.setBaudRate(115200);break;
    case 11:SerialPort.setBaudRate(128000);break;
    case 12:SerialPort.setBaudRate(230400);break;
    case 13:SerialPort.setBaudRate(256000);break;
    }
}

/*配置奇偶校验位*/
void MainWindow::on_OddEvenBox_currentIndexChanged(const QString& arg1)
{
    if (arg1 == "NULL")
        SerialPort.setParity(QSerialPort::NoParity);
    if (arg1 == "odd")
        SerialPort.setParity(QSerialPort::OddParity);
    if (arg1 == "even")
        SerialPort.setParity(QSerialPort::EvenParity);
}

/*配置数据位*/
void MainWindow::on_DataBox_currentIndexChanged(const QString& arg1)
{
    if (arg1 == "8")
        SerialPort.setDataBits(QSerialPort::Data8);
    if (arg1 == "7")
        SerialPort.setDataBits(QSerialPort::Data7);
    if (arg1 == "6")
        SerialPort.setDataBits(QSerialPort::Data6);
    if (arg1 == "5")
        SerialPort.setDataBits(QSerialPort::Data5);
}

/*配置停止位*/
void MainWindow::on_StopBox_currentIndexChanged(const QString& arg1)
{
    if (arg1 == "1")
        SerialPort.setStopBits(QSerialPort::OneStop);
    if (arg1 == "1.5")
        SerialPort.setStopBits(QSerialPort::OneAndHalfStop);
    if (arg1 == "2")
        SerialPort.setStopBits(QSerialPort::TwoStop);
}

/*发送按钮槽函数*/
void MainWindow::SendButton_clicked()
{
    Transmit_Init(transmit_config);
    /*定时器*/
    if (ui->TimeTransmit->isChecked() == true)
    {
        timer->start(ui->lineEdit->text().toInt());
    }

}

/*定时器处理函数*/
void MainWindow::timerTransmit()
{
    /*取消定时器*/
    if (ui->TimeTransmit->isChecked() == false)
    {
        if (timer->isActive() == true)
            timer->stop();
    }
    Transmit_Init(timer_config);
}

/*自定义接受数据*/
void MainWindow::Receive_Data()
{
    QByteArray ReadArray = SerialPort.readAll();
    QString Read = nullptr;
    int data;
    QDateTime time = QDateTime::currentDateTime(); //获取当前时间
    int cut_timestamp = time.toTime_t(); //将当前时间转为时间戳
    /*status times*/
    i++;
    MainWindow::Receive_Times(3,i);
    MainWindow::Receive_Size(4,ReadArray.size());

    /*16进制接收*/
    if (ui->HexReceive->isChecked() == true)
    {
        ReadArray = ReadArray.toHex();
        /*将数据以空格划分*/
        QByteArray read = ReadArray.left(2);
        int size = ReadArray.length();
        for (int l = 2;l<size;l=l+2)
        {
          QByteArray array = ReadArray.mid(l,2);
          read = read+" "+array;
        }
        ReadArray = read;
    }

    /*ASCII接收*/
    if(ui->ASCII->isChecked() == true)
    {
        for(int j = 0;j<ReadArray.size();j=j+3)
        {
             QString string =  ReadArray.mid(j,2);
             data =string.toInt(nullptr,16);
            Read +=char(data);
        }
        ReadArray = Read.toUtf8();
    }

    /*appear*/
    if (ReadArray.data())
    {
        if(ui->timestamp->isChecked() == true)
            ui->ReceiveEdit->append(QString::number(cut_timestamp)+":"+ReadArray);
        else
            ui->ReceiveEdit->append(ReadArray);
    }
}

/*清空发送文本框内容*/
void MainWindow::on_ClearTransmit_clicked()
{
    ui->TransmitEdit_2->clear();
    times = 0;
}
/*清空显示文本框内容*/
void MainWindow::on_ClearRx_Tx_clicked()
{
    ui->ReceiveEdit->clear();
    i = 0;
}
/*清空发送内容*/
void MainWindow::on_ClearTransmit_2_clicked()
{
    ui->TransmitEdit->clear();
}

/*打开文件*/
void MainWindow::on_OpenFile_clicked()
{
    FileDialog = new QFileDialog();
    QString FilePath = FileDialog->getOpenFileName(this, tr("打开文件"));
    ui->LineEdit->setText(FilePath);
}

/*将接收到的内容保存至文件中*/
void MainWindow::on_SaveFile_clicked()
{
    FileDialog = new QFileDialog();
    QString FilePath = FileDialog->getOpenFileName(this, tr("保存文件"));
    File = new QFile(FilePath);
    File->open(QIODevice::WriteOnly);
    QString ReceiveText = ui->ReceiveEdit->document()->toPlainText();
    QByteArray ReceiveTextArray = ReceiveText.toUtf8();
    File->write(ReceiveTextArray);
    File->close();
}
/*16进制与ASCII二选一*/
void MainWindow::on_ASCII_clicked(bool checked)
{
    if(checked == true)
        ui->HexReceive->setChecked(false);
}
void MainWindow::on_HexReceive_clicked(bool checked)
{
    if(checked == true)
        ui->ASCII->setChecked(false);
}

/*中英文切换*/
void MainWindow::on_Chinese_English_Switch_triggered(bool checked)
{
    translator = new QTranslator(this);

    if(checked == true)
    {
        translator->load(":/resources/tr_en");
        qApp->installTranslator(translator);
        ui->retranslateUi(this);
    }
    if(checked == false)
    {
        translator->load(":/resources/tr_zh");
        qApp->installTranslator(translator);
        ui->retranslateUi(this);
    }
}

/*关于的设置*/
void MainWindow::on_about_triggered()
{
    static int i = 0;
    if(i == 1)
    {
        ui->TransmitEdit->append("拜托！");
        ui->TransmitEdit_2->append("拜托！");
        ui->ReceiveEdit->append("拜托！");
    }
    if(i == 0)
    {
        ui->TransmitEdit->append("希望老师多给点分！");
        ui->TransmitEdit_2->append("希望老师多给点分！");
        ui->ReceiveEdit->append("希望老师多给点分！");
        i=1;
    }
}
