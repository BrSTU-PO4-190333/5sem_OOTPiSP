#include "gpi_monthjobform.hpp"
#include "ui_gpi_monthjobform.h"

gpi_MonthJobForm::gpi_MonthJobForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gpi_MonthJobForm)
{
QSqlQuery           gpi_query;
QSqlRecord          gpi_record;
// = = = = = = = = = = = = = = = =

    ui->setupUi(this);

    this->setWindowIcon (QIcon (":/@/gpi_favicon.png"));
    this->setWindowTitle ("Отчёт работ сотрудников за месяц | gpi_ootpisp5_lab5_option5");

    // Получаем объединуную таблицу с полями: месяц, фамилия, имя, отчество, вид работы
    gpi_query.exec(""
        "SELECT gpi_month, gpi_family, gpi_name, gpi_otch, gpi_vid "
        "FROM gpi_fio INNER JOIN gpi_vid "
        "ON gpi_fio.gpi_id = gpi_vid.gpi_id "
        "ORDER BY gpi_month DESC;"
    "");

    gpi_record = gpi_query.record();

    int gpi_index_month = gpi_query.record().indexOf("gpi_month");
    int gpi_index_surname = gpi_query.record().indexOf("gpi_family");
    int gpi_index_name = gpi_query.record().indexOf("gpi_name");
    int gpi_index_patronymic = gpi_query.record().indexOf("gpi_otch");
    int gpi_index_job = gpi_query.record().indexOf("gpi_vid");

    int gpi_i = 0;
    while(gpi_query.next())
    {
        // Добавляем строку в таблицу
        ui->gpi_tableWidget->insertRow (ui->gpi_tableWidget->rowCount ());

        QTableWidgetItem* gpi_item;

        // Добавляю месяц в ячейку
        QString gpi_month = gpi_query.value (gpi_index_month).toString ();
        gpi_item = new QTableWidgetItem (tr ("%1").arg (gpi_month));
        ui->gpi_tableWidget->setItem (gpi_i, 0, gpi_item);

        // Добавляю фамилию в ячейку
        QString gpi_surname = gpi_query.value (gpi_index_surname).toString ();
        gpi_item = new QTableWidgetItem (tr ("%1").arg (gpi_surname));
        ui->gpi_tableWidget->setItem (gpi_i, 1, gpi_item);

        // Добавляю имя в ячейку
        QString gpi_name = gpi_query.value (gpi_index_name).toString ();
        gpi_item = new QTableWidgetItem (tr ("%1").arg (gpi_name));
        ui->gpi_tableWidget->setItem (gpi_i, 2, gpi_item);

        // Добавляю отчество в ячейку
        QString gpi_patronymic = gpi_query.value (gpi_index_patronymic).toString ();
        gpi_item = new QTableWidgetItem (tr ("%1").arg (gpi_patronymic));
        ui->gpi_tableWidget->setItem (gpi_i, 3, gpi_item);

        // Добавляю отчество в ячейку
        QString gpi_job = gpi_query.value (gpi_index_job).toString ();
        gpi_item = new QTableWidgetItem (tr ("%1").arg (gpi_job));
        ui->gpi_tableWidget->setItem (gpi_i, 4, gpi_item);

        ++gpi_i;
    }
}

gpi_MonthJobForm::~gpi_MonthJobForm ()
{
    delete ui;
}
