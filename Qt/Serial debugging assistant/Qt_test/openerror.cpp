#include "openerror.h"
#include "ui_openerror.h"

OpenError::OpenError(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenError)
{
    ui->setupUi(this);
}

OpenError::~OpenError()
{
    delete ui;
}

void OpenError::on_pushButton_clicked()
{
    this->close();
}
