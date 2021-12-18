#ifndef GPI_MAINWINDOW_HPP
#define GPI_MAINWINDOW_HPP

#include <QMainWindow>
#include <QIcon>
#include <QMessageBox>

#include "gpi_employeeform.hpp"
#include "gpi_paymentform.hpp"
#include "gpi_monthjobform.hpp"
#include "gpi_employeepaydayform.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class gpi_MainWindow; }
QT_END_NAMESPACE

class gpi_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    gpi_MainWindow(QWidget *parent = nullptr);
    ~gpi_MainWindow();

private slots:
    void on_gpi_pushButton_employeeform_clicked();
    void on_gpi_pushButton_paymentform_clicked();
    void on_gpi_pushButton_monthpayday_clicked();
    void on_gpi_pushButton_monthjob_clicked();
    void on_gpi_pushButton_closeapp_clicked();

private:
    Ui::gpi_MainWindow*     ui;
    QSqlDatabase            gpi_db;
};
#endif // GPI_MAINWINDOW_HPP
