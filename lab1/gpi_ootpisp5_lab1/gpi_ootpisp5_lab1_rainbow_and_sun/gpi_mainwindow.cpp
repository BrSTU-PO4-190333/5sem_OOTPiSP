#include "gpi_mainwindow.hpp"
#include "ui_gpi_mainwindow.h"

gpi_MainWindow :: gpi_MainWindow (QWidget *parent)
    : QMainWindow (parent)
    , ui (new Ui::gpi_MainWindow)
{
    ui->setupUi (this);

    this->setFixedSize (this->WinWidth, this->WinHeight);
    this->setWindowIcon (QIcon (":/@/gpi_favicon.png"));
    this->setWindowTitle ("gpi_ootpisp5_lab1_rainbow_and_sun");

    auto timer = new QTimer (this);

    connect (
        timer,
        SIGNAL (timeout ()),
        this,
        SLOT (gpi_animate ())
    );

    timer->start (500);
}

gpi_MainWindow :: ~gpi_MainWindow ()
{
    delete ui;
}


void gpi_MainWindow :: gpi_animate ()
{
    repaint ();
}

//A function that draws a rainbow
void gpi_MainWindow :: gpi_PrintRainbow (QPainter* painter, int r, int step, QString arr[])
{
    for (int i = 0; i < RainbowColorArrayLength; i++)
    {
        QPen apen = QPen (QColor (arr[i]));
        apen.setWidth (step);
        painter->setPen (apen);
        painter->drawArc (WinWidth/2-r/2, 10 + step*(i+1), r, r, 30*16, 120*16);
    }
}

//A function that draws the sun
void gpi_MainWindow :: gpi_PrintSun (QPainter* painter, int r, int step)
{
    QPen apen = QPen (QColor ("yellow"));
    apen.setWidth (step);
    painter->setPen (apen);
    painter->drawEllipse (WinWidth/2-r/2 + r/3, step*RainbowColorArrayLength + 60, r/3, r/3);
}

//A function that draws the sun's rays
void gpi_MainWindow :: gpi_PrintSunLayers (QPainter* painter, int r, int step, QString StringSunColor)
{
    QPen apen = QPen (QColor (StringSunColor));
    apen.setWidth (step);
    painter->setPen (apen);

    int R1 = r/2;
    int R2 = r - r/3;
    if (SunBool)
    {
        SunBool = false;
        //the first layer of the sun's rays
        painter->drawArc (WinWidth/2 - R1/2, step*RainbowColorArrayLength + 44, R1, R1, 30*16, 100*16);
        painter->drawArc (WinWidth/2 - R1/2, step*RainbowColorArrayLength + 44, R1, R1, 150*16, 100*16);
        painter->drawArc (WinWidth/2 - R1/2, step*RainbowColorArrayLength + 44, R1, R1, 270*16, 100*16);
        //the second layer of the sun's rays
        painter->drawArc (WinWidth/2 - R2/2, step*RainbowColorArrayLength + 30, R2, R2, 80*16, 100*16);
        painter->drawArc (WinWidth/2 - R2/2, step*RainbowColorArrayLength + 30, R2, R2, 200*16, 100*16);
        painter->drawArc (WinWidth/2 - R2/2, step*RainbowColorArrayLength + 30, R2, R2, 320*16, 100*16);
    }
    else
    {
        SunBool = true;
        //the first layer of the sun's rays
        painter->drawArc (WinWidth/2 - R1/2, step*RainbowColorArrayLength + 44, R1, R1, 80*16, 100*16);
        painter->drawArc (WinWidth/2 - R1/2, step*RainbowColorArrayLength + 44, R1, R1, 200*16, 100*16);
        painter->drawArc (WinWidth/2 - R1/2, step*RainbowColorArrayLength + 44, R1, R1, 320*16, 100*16);
        //the second layer of the sun's rays
        painter->drawArc (WinWidth/2 - R2/2, step*RainbowColorArrayLength + 30, R2, R2, 30*16, 100*16);
        painter->drawArc (WinWidth/2 - R2/2, step*RainbowColorArrayLength + 30, R2, R2, 150*16, 100*16);
        painter->drawArc (WinWidth/2 - R2/2, step*RainbowColorArrayLength + 30, R2, R2, 270*16, 100*16);
    }
}

void gpi_MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QString temp = RainbowColorArray[RainbowColorArrayLength - 1];
    for (int i = RainbowColorArrayLength - 1; i > 0; i--)
    {
        RainbowColorArray[i] = RainbowColorArray[i-1];
    }
    RainbowColorArray[0] = temp;

    QString StringSunColor = SunLayersColorArray[0];
    temp = SunLayersColorArray[SunLayersColorArrayLength - 1];
    for (int i = SunLayersColorArrayLength - 1; i > 0; i--)
    {
        SunLayersColorArray[i] = SunLayersColorArray[i-1];
    }
    SunLayersColorArray[0] = temp;

    int R = 200;
    int step = 6;
    this->gpi_PrintRainbow (&painter, R, step, RainbowColorArray);
    this->gpi_PrintSun (&painter, R, step);
    this->gpi_PrintSunLayers (&painter, R, step, StringSunColor);
}
