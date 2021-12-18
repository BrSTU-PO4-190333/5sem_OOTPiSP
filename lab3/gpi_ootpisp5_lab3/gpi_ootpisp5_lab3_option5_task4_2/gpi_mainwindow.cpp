#include "gpi_mainwindow.hpp"
#include "ui_gpi_mainwindow.h"

gpi_MainWindow::gpi_MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gpi_MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("gpi_ootpisp5_lab3_option5_task4_2");
    this->setWindowIcon(QIcon(":/@/gpi_favicon.png"));

    connect (
        ui ->gpi_lineEdit_in,
        SIGNAL (textChanged (const QString &)),
        this,
        SLOT (gpi_on_gpi_lineEdit_in_textChanged (const QString &))
    );

    gpi_on_gpi_lineEdit_in_textChanged(ui ->gpi_lineEdit_in ->text ());
}

gpi_MainWindow::~gpi_MainWindow()
{
    delete ui;
}


void gpi_MainWindow::gpi_on_gpi_lineEdit_in_textChanged(const QString &gpi_t)
{
    QStringList     gpi_a;      // Массив слов
    int             gpi_i;      // Для цикла
    bool            gpi_b;      // Проверяем на число
    QVector<int>    gpi_v;      // Массив чисел
    int             gpi_n;      // Переменная хранит число, которое было строкой
    int             gpi_arif;   // Среднее арифметическое
    QString         gpi_s;      // Строку, которую вывести

    gpi_a= gpi_t .split (QRegularExpression ("\\s+"));

    // Если есть пустые строки, то удаляем
    for (gpi_i = 0; gpi_i < gpi_a .size (); ++gpi_i)
    {
        if (gpi_a[gpi_i].length() == 0)
        {
            gpi_a.remove(gpi_i);
            continue;
        }
    }

    // Проверяем на числа, иначе сообщение об ощибке
    for (gpi_i = 0; gpi_i < gpi_a .size (); ++gpi_i)
    {
        gpi_a[gpi_i].toInt(&gpi_b, 10);

        if (gpi_b == false)
        {
            QMessageBox :: warning (this, "Ошибка ввода", "В списке чисел оказался символ");
            return;
        }
    }

    // Переводим массив строк в массив чисел
    for (gpi_i = 0; gpi_i < gpi_a .size (); ++gpi_i)
    {
        gpi_n = gpi_a[gpi_i] .toInt ();
        gpi_v .append(gpi_n);
    }

    // Вычисляем среднее арифметическое
    gpi_arif = 0;
    for (gpi_i = 0; gpi_i < gpi_v .size (); ++gpi_i)
    {
        gpi_arif += gpi_v[gpi_i];
    }
    gpi_arif /= gpi_v.size();

    // Заменяем каждое чтное число средним арифметическим
    for (gpi_i = 1; gpi_i < gpi_v .size (); gpi_i += 2)
    {
        gpi_v[gpi_i] = gpi_arif;
    }

    // Создаем строку и чисел
    gpi_s = "";
    for (gpi_i = 0; gpi_i < gpi_v.size(); ++gpi_i)
    {
        gpi_s += QString::number(gpi_v[gpi_i]) + " ";
    }

    // Выводим строку на экран
    ui ->gpi_lineEdit_out ->setText (gpi_s);
}
