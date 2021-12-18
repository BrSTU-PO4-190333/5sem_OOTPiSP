#ifndef gpi_MainWindow_HPP
#define gpi_MainWindow_HPP

#include <QMainWindow>
#include <QPainter>
#include <QTimer>

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
    void gpi_animate();

private:
    Ui::gpi_MainWindow *ui;
    int WinWidth = 512;
    int WinHeight = 256;

    const int RainbowColorArrayLength = 7;
    QString RainbowColorArray[7] = {
        "red",
        "orange",
        "yellow",
        "green",
        "cyan",
        "blue",
        "purple"
    };

    bool SunBool = true;
    const int SunLayersColorArrayLength = 3;
    QString SunLayersColorArray[3] = {
        "orange",
        "red",
        "darkRed"
    };

protected:
    void gpi_PrintRainbow(QPainter* painter, int r, int step, QString arr[]);
    void gpi_PrintSun(QPainter* painter, int r, int step);
    void gpi_PrintSunLayers(QPainter* painter, int r, int step, QString StringSunColor);
    void paintEvent(QPaintEvent* event);
};
#endif // gpi_MainWindow_HPP
