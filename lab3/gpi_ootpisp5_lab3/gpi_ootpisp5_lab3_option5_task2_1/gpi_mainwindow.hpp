#ifndef GPI_MAINWINDOW_HPP
#define GPI_MAINWINDOW_HPP

#include <QMainWindow>
#include <QRegularExpression>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class GPI_MainWindow; }
QT_END_NAMESPACE

class GPI_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    GPI_MainWindow (QWidget *parent = nullptr);
    ~GPI_MainWindow ();

private slots:
    void gpi_on_gpi_lineEdit_input_textChanged (const QString &arg1);

private:
    Ui::GPI_MainWindow *ui;
    void gpi_calculate_array ();
};
#endif // GPI_MAINWINDOW_HPP
