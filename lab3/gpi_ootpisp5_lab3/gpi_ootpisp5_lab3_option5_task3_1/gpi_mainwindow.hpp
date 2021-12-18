#ifndef GPI_MAINWINDOW_HPP
#define GPI_MAINWINDOW_HPP

#include <QMainWindow>
#include <QList>
#include <QRegularExpression>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class gpi_MainWindow; }
QT_END_NAMESPACE

class gpi_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    gpi_MainWindow (QWidget *parent = nullptr);
    ~gpi_MainWindow ();

private slots:
    void gpi_on_gpi_lineEdit_list1_textChanged(const QString &arg1);
    void gpi_on_gpi_lineEdit_list2_textChanged(const QString &arg1);

private:
    Ui::gpi_MainWindow *ui;
    void gpi_calculate_list3 ();
};
#endif // GPI_MAINWINDOW_HPP
