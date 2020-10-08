/********************************************************************************
** Form generated from reading UI file 'transmiterror.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSMITERROR_H
#define UI_TRANSMITERROR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TransmitError
{
public:
    QPushButton *pushButton;
    QLabel *SerialLabel;

    void setupUi(QDialog *TransmitError)
    {
        if (TransmitError->objectName().isEmpty())
            TransmitError->setObjectName(QString::fromUtf8("TransmitError"));
        TransmitError->resize(310, 154);
        pushButton = new QPushButton(TransmitError);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 90, 61, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        pushButton->setFont(font);
        SerialLabel = new QLabel(TransmitError);
        SerialLabel->setObjectName(QString::fromUtf8("SerialLabel"));
        SerialLabel->setGeometry(QRect(70, 0, 249, 119));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(14);
        SerialLabel->setFont(font1);
        SerialLabel->raise();
        pushButton->raise();

        retranslateUi(TransmitError);

        QMetaObject::connectSlotsByName(TransmitError);
    } // setupUi

    void retranslateUi(QDialog *TransmitError)
    {
        TransmitError->setWindowTitle(QCoreApplication::translate("TransmitError", "error", nullptr));
        pushButton->setText(QCoreApplication::translate("TransmitError", "\351\200\200\345\207\272", nullptr));
        SerialLabel->setText(QCoreApplication::translate("TransmitError", "   \344\270\262\345\217\243\346\234\252\346\211\223\345\274\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransmitError: public Ui_TransmitError {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSMITERROR_H
