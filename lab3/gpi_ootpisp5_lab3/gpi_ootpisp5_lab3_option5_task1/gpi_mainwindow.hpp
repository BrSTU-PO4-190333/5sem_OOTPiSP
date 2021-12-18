#ifndef GPI_MAINWINDOW_HPP
#define GPI_MAINWINDOW_HPP

#include <QMainWindow>
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
    void        gpi_on_gpi_lineEdit_input1_textChanged (const QString &gpi_txt);
    void        gpi_on_gpi_lineEdit_input2_textChanged (const QString &gpi_txt);
    void        gpi_on_gpi_lineEdit_input3_textChanged (const QString &gpi_txt);

private:
    Ui::gpi_MainWindow *ui;
    int         gpi_n1;
    int         gpi_n2;
    int         gpi_n3;
    void        gpi_get_number1 ();
    void        gpi_get_number2 ();
    void        gpi_get_number3 ();
    void        gpi_calculate_results ();
    void        gpi_print_result ();
};
#endif // GPI_MAINWINDOW_HPP
