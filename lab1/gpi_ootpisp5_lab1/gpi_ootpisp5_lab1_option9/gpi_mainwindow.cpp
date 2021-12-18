#include "gpi_mainwindow.hpp"
#include "ui_gpi_mainwindow.h"

gpi_MainWindow :: gpi_MainWindow (QWidget *parent)
    : QMainWindow (parent)
    , ui (new Ui::gpi_MainWindow)
{
    ui->setupUi (this);

    this->setFixedSize (this->WinWidth, this->WinHeight);
    this->setWindowIcon (QIcon (":/@/gpi_favicon.png"));
    this->setWindowTitle ("gpi_ootpisp5_lab1_option9");

    auto timer = new QTimer (this);              //конструктор таймера

    connect (
        timer,
        SIGNAL (timeout ()),
        this,
        SLOT (gpi_animate ())
    );

    timer->start (100);                          //вызов каждые 100 милисекунд
}

gpi_MainWindow :: ~gpi_MainWindow ()
{
    delete ui;
}

void gpi_MainWindow :: gpi_animate ()
{
    repaint();
}

//Функция, которая рисует фигуру (прямоугольник, эллипс и центр)
void gpi_MainWindow :: gpi_PrintMyFigure (QPainter* painter, int x, int y)
{
    int a = 120;                                //ширина прямоугольника
    int b = 40;                                 //высота прямоугольника
    int r = 30;                                 //радиус окружности

    QRect MyRectangle (x - a/2, y - b, a, b);   //конструктор прямоугольника
    QRect MyEllipse (x - r, y, 2*r, 2*r);       //конструктор прямоугольника

    QPen MyRedPen (Qt::red, 4);                 //конструктор пера
    painter->setPen (MyRedPen);                 //установка пера
    painter->drawRect (MyRectangle);            //рисуем прямоугольник
    painter->drawEllipse (MyEllipse);           //рисуем эллипс

    QPen MyBluePen (Qt::blue, 4);               //конструктор пера
    QRect MyCenterEllipse (x - 1, y - 1, 2, 2); //конструктор прямоугольника
    painter->setPen (MyBluePen);                //установка пера
    painter->drawEllipse (MyCenterEllipse);     //рисуем элипс
}

//Функция, которая рисует сетку (тетрадка в клетку)
void gpi_MainWindow :: gpi_PrintMyBackground (QPainter* painter)
{
    QPen MyGrayPen (Qt::gray, 1);               //конструктор пера
    painter->setPen (MyGrayPen);                //установка пера

    for (int i = 0; i < this->WinWidth; i += 10)
    {
        QLine line1(i, 0, i, this->WinWidth);   //конструктор линии
        painter->drawLine (line1);              //чертим линию
        QLine line2 (0, i, this->WinWidth, i);  //конструктор линии
        painter->drawLine (line2);              //чертим линию
    }
}

//Функция, которая рисует оси Ox и Oy
void gpi_MainWindow :: gpi_PrintMyBackgroundAxles (QPainter* painter)
{
    QPen MyBlackPen (Qt::black, 4);                                         //конструктор пера
    painter->setPen (MyBlackPen);                                           //установка пера
    QLine line1 (this->WinWidth/2, 0, this->WinWidth/2, this->WinHeight);   //конструктор линии
    painter->drawLine (line1);                                              //чертим линию
    QLine line2 (0, this->WinHeight/2, this->WinWidth, this->WinHeight/2);  //конструктор линии
    painter->drawLine (line2);                                              //чертим линию
}

//Функция, которая пишет текст
void gpi_MainWindow :: gpi_PrintMyText (QPainter* painter)
{
    QPen MyBluePen (Qt::blue, 5);               //конструктор пера
    painter->setPen (MyBluePen);                //установка пера

    QFont font ("Times", 16, QFont::Bold);      //конструктор шрифта
    painter->setFont (font);                    //установка шрифта

    painter->translate (20, 500);               //установка точки печати текста
    painter->rotate (-90);                      //поворот на 90 градусов

    QString str = "Графические примитивы в библиотеке QT";
    painter->drawText (0,0, str);               //пишем текст
}

void gpi_MainWindow :: paintEvent (QPaintEvent *event)
{
    Q_UNUSED (event);
    QPainter painter (this);

    this->gpi_PrintMyBackground (&painter);
    this->gpi_PrintMyBackgroundAxles (&painter);
    this->gpi_PrintMyFigure (&painter,  this->WinWidth / 2 - this->x, this->WinHeight / 2 + this->y);
    this->gpi_PrintMyText (&painter);

    this->y = this->a * this->x * this->x * this->x;
    if (!moveDown)
    {
        this->x -= 10;
        if (this->WinHeight/2 + this->y <= 0)
        {
            moveDown = true;
        }
    }
    else
    {
        this->x += 10;
        if (this->WinHeight/2 + this->y >= this->WinHeight)
        {
            moveDown = false;
        }
    }
}
