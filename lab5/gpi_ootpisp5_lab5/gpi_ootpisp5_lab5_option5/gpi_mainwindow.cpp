#include "gpi_mainwindow.hpp"
#include "ui_gpi_mainwindow.h"

gpi_MainWindow::gpi_MainWindow (QWidget *parent)
    : QMainWindow (parent)
    , ui (new Ui::gpi_MainWindow)
{
QSqlQuery*              gpi_query;
// = = = = = = = = = = = = = = = =

    ui->setupUi (this);

    this->setWindowIcon (QIcon (":/@/gpi_favicon.png"));
    this->setWindowTitle ("Меню | gpi_ootpisp5_lab5_option5");

    gpi_db = QSqlDatabase::addDatabase ("QSQLITE");
    gpi_db.setDatabaseName ("./gpi_.sqlite");

    if (gpi_db.open () == false)
    {
        qDebug (" gpi_mainwindow no open db");
        QMessageBox::warning (this, "Ошибка подключения", "gpi_mainwindow Не подключены к БД");
        return;
    }

    gpi_query = new QSqlQuery (gpi_db);

    // Создание таблицы сотрудников
    gpi_query->exec (""
        "CREATE TABLE 'gpi_fio' ("
            "'gpi_id' INT PRIMARY KEY, "
            "'gpi_family' TEXT, "
            "'gpi_name' TEXT, "
            "'gpi_otch' TEXT"
        ");"
    "");

    // Создание таблицы выплат
    gpi_query->exec (""
        "CREATE TABLE 'gpi_vid' ("
            "'gpi_contract' TEXT PRIMARY KEY, "
            "'gpi_id' INT, "
            "'gpi_vid' TEXT, "
            "'gpi_month' date, "
            "'gpi_summa' INT"
        ");"
    "");
}

gpi_MainWindow::~gpi_MainWindow()
{
    delete ui;
}

// Функция, которая вызывает таблицу сотрудников
void gpi_MainWindow::on_gpi_pushButton_employeeform_clicked ()
{
gpi_EmployeeForm*       gpi_ef;
// = = = = = = = = = = = = = = = =

    gpi_ef = new gpi_EmployeeForm (&gpi_db);
    gpi_ef->show ();
}

// Функция, которая вызывает таблицу выплат
void gpi_MainWindow::on_gpi_pushButton_paymentform_clicked()
{
gpi_PaymentForm*        gpi_pf;
// = = = = = = = = = = = = = = = =

    gpi_pf = new gpi_PaymentForm(&gpi_db);
    gpi_pf->show();
}

// Функция вывода заработной платы по месяцам
void gpi_MainWindow::on_gpi_pushButton_monthpayday_clicked()
{
    gpi_EmployeePaydayForm* gpi_epf;

    gpi_epf = new gpi_EmployeePaydayForm();
    gpi_epf->show();
}

// Функция вывода работ по каждому сотруднику за месяц
void gpi_MainWindow::on_gpi_pushButton_monthjob_clicked()
{
    gpi_MonthJobForm* gpi_mjf;

    gpi_mjf = new gpi_MonthJobForm();
    gpi_mjf->show();
}

// Функция для закрытия меню
void gpi_MainWindow::on_gpi_pushButton_closeapp_clicked()
{
    this->close();
}
