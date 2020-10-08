#ifndef TRANSMITERROR_H
#define TRANSMITERROR_H

#include <QDialog>

namespace Ui {
class TransmitError;
}

class TransmitError : public QDialog
{
    Q_OBJECT

public:
    explicit TransmitError(QWidget *parent = nullptr);
    ~TransmitError();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TransmitError *ui;
};

#endif // TRANSMITERROR_H
