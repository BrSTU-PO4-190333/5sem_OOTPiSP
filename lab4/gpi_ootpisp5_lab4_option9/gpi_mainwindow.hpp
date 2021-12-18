#ifndef GPI_MAINWINDOW_H
#define GPI_MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void gpi_on_pushButton_generateTable_clicked();
    void gpi_on_pushButton_pow2_clicked();
    void gpi_on_pushButton_pow3_clicked();

protected:
    void keyPressEvent(QKeyEvent* e) override;

private:
    Ui::MainWindow *ui;

    QColor  gpi_colorMod2       = QColor(253, 234, 168); // Светло-песочный
    QColor  gpi_colorMod3       = QColor(208, 240, 192); // Зелёный чай

    int gpi_rand(int a, int b);
    int gpi_rand_odd_or_even(bool flag, int a, int b);
    void gpi_generate_random_table();
    bool gpi_modn(int mod, float number);
    void gpi_changePlainEditTextBackground(Ui::MainWindow gpi_ui, QColor gpi_color);
};
#endif // GPI_MAINWINDOW_H
