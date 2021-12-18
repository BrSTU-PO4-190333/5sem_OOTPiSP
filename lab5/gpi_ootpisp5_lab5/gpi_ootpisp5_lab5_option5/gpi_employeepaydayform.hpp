#ifndef GPI_EMPLOYEEPAYDAYFORM_HPP
#define GPI_EMPLOYEEPAYDAYFORM_HPP

#include <QWidget>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QIcon>

namespace Ui {
class gpi_EmployeePaydayForm;
}

class gpi_EmployeePaydayForm : public QWidget
{
    Q_OBJECT

public:
    explicit gpi_EmployeePaydayForm(QWidget *parent = nullptr);
    ~gpi_EmployeePaydayForm();

private:
    Ui::gpi_EmployeePaydayForm *ui;
};

#endif // GPI_EMPLOYEEPAYDAYFORM_HPP
