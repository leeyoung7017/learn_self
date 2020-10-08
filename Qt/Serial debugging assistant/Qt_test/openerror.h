#ifndef OPENERROR_H
#define OPENERROR_H

#include <QDialog>

namespace Ui {
class OpenError;
}

class OpenError : public QDialog
{
    Q_OBJECT

public:
    explicit OpenError(QWidget *parent = nullptr);
    ~OpenError();

private slots:
    void on_pushButton_clicked();

private:
    Ui::OpenError *ui;
};

#endif // OPENERROR_H
