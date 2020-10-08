#include "transmiterror.h"
#include "ui_transmiterror.h"

TransmitError::TransmitError(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransmitError)
{
    ui->setupUi(this);
}

TransmitError::~TransmitError()
{
    delete ui;
}


void TransmitError::on_pushButton_clicked()
{
    this->close();
}
