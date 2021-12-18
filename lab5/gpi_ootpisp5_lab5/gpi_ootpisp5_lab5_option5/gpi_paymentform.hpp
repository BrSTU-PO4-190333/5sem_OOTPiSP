#ifndef GPI_PAYMENTFORM_HPP
#define GPI_PAYMENTFORM_HPP

#include <QWidget>
#include <QIcon>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class gpi_PaymentForm;
}

class gpi_PaymentForm : public QWidget
{
    Q_OBJECT

public:
    explicit gpi_PaymentForm(QSqlDatabase* gpi_db, QWidget *parent = nullptr);
    ~gpi_PaymentForm();

private slots:
    void on_gpi_pushButton_add_clicked();
    void on_gpi_pushButton_delete_clicked();
    void on_gpi_tableView_clicked(const QModelIndex &index);

private:
    Ui::gpi_PaymentForm*    ui;
    QSqlTableModel*         gpi_model;
    int                     gpi_row;
};

#endif // GPI_PAYMENTFORM_HPP
