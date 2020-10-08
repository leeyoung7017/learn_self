/********************************************************************************
** Form generated from reading UI file 'openerror.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENERROR_H
#define UI_OPENERROR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_OpenError
{
public:
    QPushButton *pushButton;
    QLabel *OpenError_2;

    void setupUi(QDialog *OpenError)
    {
        if (OpenError->objectName().isEmpty())
            OpenError->setObjectName(QString::fromUtf8("OpenError"));
        OpenError->resize(289, 165);
        pushButton = new QPushButton(OpenError);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 100, 71, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        pushButton->setFont(font);
        OpenError_2 = new QLabel(OpenError);
        OpenError_2->setObjectName(QString::fromUtf8("OpenError_2"));
        OpenError_2->setGeometry(QRect(60, 30, 181, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(14);
        OpenError_2->setFont(font1);

        retranslateUi(OpenError);

        QMetaObject::connectSlotsByName(OpenError);
    } // setupUi

    void retranslateUi(QDialog *OpenError)
    {
        OpenError->setWindowTitle(QCoreApplication::translate("OpenError", "error", nullptr));
        pushButton->setText(QCoreApplication::translate("OpenError", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(whatsthis)
        OpenError_2->setWhatsThis(QCoreApplication::translate("OpenError", "\351\224\231\350\257\257\346\217\220\347\244\272", nullptr));
#endif // QT_CONFIG(whatsthis)
        OpenError_2->setText(QCoreApplication::translate("OpenError", "\346\211\223\345\274\200\344\270\262\345\217\243\345\244\261\350\264\245\357\274\201\357\274\201\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpenError: public Ui_OpenError {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENERROR_H
