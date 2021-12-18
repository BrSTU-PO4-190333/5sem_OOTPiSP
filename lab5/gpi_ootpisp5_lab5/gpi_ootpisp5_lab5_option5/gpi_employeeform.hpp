#ifndef GPI_EMPLOYEEFORM_HPP
#define GPI_EMPLOYEEFORM_HPP

#include <QWidget>
#include <QIcon>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class gpi_EmployeeForm;
}

class gpi_EmployeeForm : public QWidget
{
    Q_OBJECT

public:
    explicit gpi_EmployeeForm(QSqlDatabase* gpi_db, QWidget *parent = nullptr);
    ~gpi_EmployeeForm();

private slots:
    void on_gpi_pushButton_add_clicked();
    void on_gpi_pushButton_delete_clicked();
    void on_gpi_tableView_clicked(const QModelIndex &index);

private:
    Ui::gpi_EmployeeForm*   ui;
    QSqlTableModel*         gpi_model;
    int                     gpi_row;
};

#endif // GPI_EMPLOYEEFORM_HPP
