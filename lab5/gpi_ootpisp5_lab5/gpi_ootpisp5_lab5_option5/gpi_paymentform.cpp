#include "gpi_paymentform.hpp"
#include "ui_gpi_paymentform.h"

gpi_PaymentForm::gpi_PaymentForm (QSqlDatabase* gpi_db, QWidget *parent) :
    QWidget (parent),
    ui (new Ui::gpi_PaymentForm)
{
    ui ->setupUi (this);

    this->setWindowIcon (QIcon (":/@/gpi_favicon.png"));
    this->setWindowTitle ("Таблица выплат | gpi_ootpisp5_lab5_option5");

    gpi_model = new QSqlTableModel (this, *gpi_db);
    gpi_model->setTable ("gpi_vid");
    gpi_model->select ();
    ui->gpi_tableView->setModel(gpi_model);
}

gpi_PaymentForm::~gpi_PaymentForm()
{
    delete ui;
}

void gpi_PaymentForm::on_gpi_pushButton_add_clicked()
{
    gpi_model->insertRow(gpi_model->rowCount());
}

void gpi_PaymentForm::on_gpi_pushButton_delete_clicked()
{
    gpi_model->removeRow(gpi_row);
}

void gpi_PaymentForm::on_gpi_tableView_clicked(const QModelIndex &gpi_index)
{
    gpi_row = gpi_index.row();
}
