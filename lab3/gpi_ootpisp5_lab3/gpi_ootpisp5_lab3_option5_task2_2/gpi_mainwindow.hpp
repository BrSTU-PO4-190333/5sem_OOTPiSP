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
    void                        gpi_on_gpi_textEdit_input_textChanged ();

private:
    Ui::gpi_MainWindow*         ui;
    QVector<QVector<QString>>   gpi_get_2d_vec_from_txt (QString gpi_txt);
    QVector<QVector<int>>       gpi_StrVec_to_IntVec (const QVector<QVector<QString>> gpi_str_2d_vec);

};
#endif // GPI_MAINWINDOW_HPP
