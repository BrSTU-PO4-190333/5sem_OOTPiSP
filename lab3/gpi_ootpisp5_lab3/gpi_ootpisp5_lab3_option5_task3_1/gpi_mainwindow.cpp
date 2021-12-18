#include "gpi_mainwindow.hpp"
#include "ui_gpi_mainwindow.h"

gpi_MainWindow :: gpi_MainWindow (QWidget *parent)
    : QMainWindow (parent)
    , ui (new Ui::gpi_MainWindow)
{
    ui ->setupUi (this);

    this ->setWindowTitle ("gpi_ootpisp5_lab3_option5_task3_1");
    this ->setWindowIcon (QIcon (":/@/gpi_favicon.png"));

    connect (
        ui ->gpi_lineEdit_list1,
        SIGNAL (textChanged (const QString &)),
        this,
        SLOT (gpi_on_gpi_lineEdit_list1_textChanged (const QString &))
    );

    connect (
        ui ->gpi_lineEdit_list2,
        SIGNAL (textChanged (const QString &)),
        this,
        SLOT (gpi_on_gpi_lineEdit_list2_textChanged (const QString &))
    );

    gpi_calculate_list3 ();
}

gpi_MainWindow :: ~gpi_MainWindow ()
{
    delete ui;
}

void gpi_MainWindow :: gpi_on_gpi_lineEdit_list1_textChanged (const QString &gpi_txt)
{
    Q_UNUSED(gpi_txt);
    gpi_calculate_list3 ();
}

void gpi_MainWindow :: gpi_on_gpi_lineEdit_list2_textChanged (const QString &gpi_txt)
{
    Q_UNUSED(gpi_txt);
    gpi_calculate_list3 ();
}

void gpi_MainWindow :: gpi_calculate_list3 ()
{
    QString                 gpi_txt1;   // Текст из поля для 1-ого списка
    QString                 gpi_txt2;   // Текст из поля для 2ого списка
    QString                 gpi_txt3;   // Текст, который будет результатом

    QVector<QString>        gpi_vec1;   // Массив слов 1-ого поля
    QVector<QString>        gpi_vec2;   // Массив слов 2-ого поля

    int                     gpi_i;      // Для цикла

    bool                    gpi_b;      // Флажок false - не число, true - число

    QList<int>              gpi_list1;  // 1-ый список
    QList<int>              gpi_list2;  // 2-ой список
    QList<int>              gpi_list3;  // 3-ий список

    QList<int>::iterator    gpi_it;     // Итератор для списка
    int                     gpi_min;    // Минимальный элемент
    // = = = = = = = = = = = = = = = =

    // Получаю текст из полей
    gpi_txt1 = ui ->gpi_lineEdit_list1 ->text ();
    gpi_txt2 = ui ->gpi_lineEdit_list2 ->text ();

    // Разделяю строку по пробелам
    gpi_vec1 = gpi_txt1 .split (QRegularExpression ("\\s+"));
    gpi_vec2 = gpi_txt2 .split (QRegularExpression ("\\s+"));

    // Удаляю элементы с пустой строкой
    for (gpi_i = 0; gpi_i < gpi_vec1 .size (); ++gpi_i)
    {
        if (gpi_vec1[gpi_i] .compare ("") == 0)
        {
            gpi_vec1 .remove (gpi_i);
        }
    }

    // Удаляю элементы с пустой строкой
    for (gpi_i = 0; gpi_i < gpi_vec2 .size (); ++gpi_i)
    {
        if (gpi_vec2[gpi_i] .compare ("") == 0)
        {
            gpi_vec2 .remove (gpi_i);
        }
    }

    // Сообщаю об ошибке, если это не число
    for (gpi_i = 0; gpi_i < gpi_vec1 .size (); ++gpi_i)
    {
        gpi_vec1[gpi_i] .toInt (&gpi_b, 10);
        if (gpi_b == false)
        {
            QMessageBox::warning (this, "Ошибка ввода", "В 1-ом списке чисел оказался символ");
            return;
        }
    }

    // Сообщаю об ошибке, если это не число
    for (gpi_i = 0; gpi_i < gpi_vec2 .size (); ++gpi_i)
    {
        gpi_vec2[gpi_i] .toInt (&gpi_b, 10);
        if (gpi_b == false)
        {
            QMessageBox::warning (this, "Ошибка ввода", "Во 2-ом списке чисел оказался символ");
            return;
        }
    }

    // Добавляю в 1-ый список числа
    for (gpi_i = 0; gpi_i < gpi_vec1 .size (); ++gpi_i)
    {
        gpi_list1 << gpi_vec1[gpi_i] .toInt();
    }

    // Добавляю во 2-ой список числа
    for (gpi_i = 0; gpi_i < gpi_vec2 .size (); ++gpi_i)
    {
        gpi_list2 << gpi_vec2[gpi_i] .toInt();
    }

    // Нахожу минимальный элемента во 2-ом списке
    gpi_min = *gpi_list2 .begin ();
    for (gpi_it = gpi_list2 .begin (); gpi_it != gpi_list2 .end (); ++gpi_it)
    {
        if (*gpi_it < gpi_min)
        {
            gpi_min = *gpi_it;
        }
    }

    // Формирую 3-ий список
    for (gpi_it = gpi_list1 .begin (); gpi_it != gpi_list1 .end (); ++gpi_it)
    {
        if (*gpi_it < 0)
        {
            gpi_list3 << gpi_min;
            continue;
        }

        if (*gpi_it >= 0)
        {
            gpi_list3 << *gpi_it;
            continue;
        }
    }

    // Делаю строку из 3-его списка
    gpi_txt3 = "";
    for (gpi_it = gpi_list3 .begin (); gpi_it != gpi_list3 .end (); ++gpi_it)
    {
        gpi_txt3 += QString::number(*gpi_it);
        gpi_txt3 += " ";
    }

    // Вывожу 3-ий список в LineEdit
    ui ->gpi_lineEdit_list3 ->setText (gpi_txt3);
}
