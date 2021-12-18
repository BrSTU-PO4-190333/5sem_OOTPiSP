#ifndef GPI_MONTHJOBFORM_HPP
#define GPI_MONTHJOBFORM_HPP

#include <QWidget>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QIcon>
#include <QTableWidgetItem>

namespace Ui {
class gpi_MonthJobForm;
}

class gpi_MonthJobForm : public QWidget
{
    Q_OBJECT

public:
    explicit gpi_MonthJobForm(QWidget *parent = nullptr);
    ~gpi_MonthJobForm();

private:
    Ui::gpi_MonthJobForm *ui;
};

#endif // GPI_MONTHJOBFORM_HPP
