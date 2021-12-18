#ifndef GPI_MAINWINDOW_HPP
#define GPI_MAINWINDOW_HPP

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QIcon>

QT_BEGIN_NAMESPACE
namespace Ui { class gpi_MainWindow; }
QT_END_NAMESPACE

class gpi_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
                gpi_MainWindow(QWidget *parent = nullptr);
                ~gpi_MainWindow();

public slots:
    void        gpi_animate();

private:
    Ui::gpi_MainWindow *ui;
    int         WinWidth    = 900;
    int         WinHeight   = 500;
    double      a           = 1e-4;
    int         x           = 0;
    int         y           = 0;
    bool        moveDown    = true;

protected:
    void        gpi_PrintMyFigure(QPainter* painter, int x, int y);
    void        gpi_PrintMyBackground(QPainter* painter);
    void        gpi_PrintMyBackgroundAxles(QPainter* painter);
    void        gpi_PrintMyText(QPainter* painter);
    void        paintEvent(QPaintEvent* event);
};
#endif // GPI_MAINWINDOW_HPP
