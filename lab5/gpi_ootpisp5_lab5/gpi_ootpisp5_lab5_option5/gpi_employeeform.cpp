#include "gpi_employeeform.hpp"
#include "ui_gpi_employeeform.h"

gpi_EmployeeForm::gpi_EmployeeForm (QSqlDatabase* gpi_db, QWidget *parent) :
    QWidget (parent),
    ui (new Ui::gpi_EmployeeForm)
{
    ui->setupUi (this);

    this->setWindowIcon (QIcon (":/@/gpi_favicon.png"));
    this->setWindowTitle ("Таблица сотрудников | gpi_ootpisp5_lab5_option5");

    gpi_model = new QSqlTableModel (this, *gpi_db);
    gpi_model->setTable ("gpi_fio");
    gpi_model->select ();
    ui->gpi_tableView->setModel (gpi_model);
}

gpi_EmployeeForm::~gpi_EmployeeForm ()
{
    delete ui;
}

void gpi_EmployeeForm::on_gpi_pushButton_add_clicked ()
{
    gpi_model->insertRow (gpi_model->rowCount ());
}

void gpi_EmployeeForm::on_gpi_pushButton_delete_clicked ()
{
    gpi_model->removeRow (gpi_row);
}

void gpi_EmployeeForm::on_gpi_tableView_clicked (const QModelIndex &gpi_index)
{
    gpi_row = gpi_index.row ();
}
