#include "gpi_mainwindow.hpp"
#include "ui_gpi_mainwindow.h"

gpi_MainWindow :: gpi_MainWindow (QWidget *parent)
    : QMainWindow (parent)
    , ui (new Ui::gpi_MainWindow)
{
    ui ->setupUi (this);

    this ->setWindowTitle ("gpi_ootpisp5_lab3_option5_task2_2");
    this ->setWindowIcon (QIcon (":/@/gpi_favicon.png"));

    connect (
        ui ->gpi_textEdit_input,
        SIGNAL (textChanged()),
        this,
        SLOT (gpi_on_gpi_textEdit_input_textChanged ())
    );

    gpi_on_gpi_textEdit_input_textChanged ();
}

gpi_MainWindow :: ~gpi_MainWindow ()
{
    delete ui;
}

void gpi_MainWindow :: gpi_on_gpi_textEdit_input_textChanged()
{
    QString                     gpi_txt_input;      // Текст из текстового поля

    int                         gpi_i;              // Для итераций по циклу
    int                         gpi_j;              // Для итерация по циклу

    QVector<QVector<QString>>   gpi_2d_vec;         // Двумерный массив (массив строк содержащий массив слов)
    QVector<QVector<int>>       gpi_2d_int_vec;     // Двумерный массив (массив строк содержащий массив слов)
    QString                     gpi_str_number;     // Число в строке
    bool                        gpi_b;              // Флаг для определения число это или нет
    int                         gpi_min;            // Минимальный элемент
    int                         gpi_max;            // Максимальный элемент
    QSet<int>                   gpi_min_indexes;    // Множество индексов с минимальным элементом
    QSet<int>                   gpi_max_indexes;    // Множество индексов с максимальным элементом
    QString                     gpi_txt_out;        // Результат, который выведем в TextEdit
    // = = = = = = = = = = = = = = = =

    gpi_txt_input = ui-> gpi_textEdit_input-> toPlainText ();   // Получам текст
    gpi_2d_vec = gpi_get_2d_vec_from_txt (gpi_txt_input);       // Текст в двумерный массив (массив строк содержащий массив слов)

    // Проверяем есть ли буквы
    for (gpi_i = 0; gpi_i < gpi_2d_vec.size(); ++gpi_i)
    {
        for(gpi_j = 0; gpi_j < gpi_2d_vec[gpi_i] .size (); ++gpi_j)
        {
            gpi_str_number = gpi_2d_vec[gpi_i][gpi_j];      // Число в строке
            gpi_str_number.toInt (&gpi_b, 10);              // Если это число, что gpi_b равен true, иначе false
            if (gpi_b == false)                             // Если слово не число
            {
                QMessageBox::warning (this, "gpi_ Ошибка ввода", "В массиве чисел содержится буква");
                --gpi_j;
                return;
            }
        }
    }

    gpi_2d_int_vec = gpi_StrVec_to_IntVec (gpi_2d_vec);     // StringVector в IntVector

    for (gpi_i = 0; gpi_i < gpi_2d_int_vec .size (); ++gpi_i)
    {
        // Находим минимальный элемент и максимальный элемент
        gpi_min = gpi_2d_int_vec[gpi_i][0];
        gpi_max = gpi_2d_int_vec[gpi_i][0];
        for (gpi_j = 0; gpi_j < gpi_2d_int_vec[gpi_i] .size (); ++gpi_j)
        {
            if (gpi_2d_int_vec[gpi_i][gpi_j] < gpi_min)     // Если меньше минимального элемента
            {
                gpi_min = gpi_2d_int_vec[gpi_i][gpi_j];
            }

            if (gpi_2d_int_vec[gpi_i][gpi_j] > gpi_max)     // Если больше максимального элемента
            {
                gpi_max = gpi_2d_int_vec[gpi_i][gpi_j];
            }
        }

        // Находим индекссы минимального элемента и находим индексы максимального элемента
        for (gpi_j = 0; gpi_j < gpi_2d_int_vec[gpi_i] .size (); ++gpi_j)
        {
            if (gpi_2d_int_vec[gpi_i][gpi_j] == gpi_min)    // Если это минимальный элемент
            {
                gpi_min_indexes .insert (gpi_j);            // Добавляем во множество индекс
            }

            if (gpi_2d_int_vec[gpi_i][gpi_j] == gpi_max)    // Если это максимальный элемент
            {
                gpi_max_indexes .insert (gpi_j);            // Добавляем во множество индекс
            }
        }

        // Меняем минимальный элемент на максимальный и меняем максимальный элемент на минимальный
        for (gpi_j = 0; gpi_j < gpi_2d_int_vec[gpi_i] .size (); ++gpi_j)
        {
            if (gpi_min_indexes .contains (gpi_j))          // Если во множестве есть индекс
            {
                gpi_2d_int_vec[gpi_i][gpi_j] = gpi_max;
            }

            if (gpi_max_indexes .contains (gpi_j))          // Если во множестве есть индекс
            {
                gpi_2d_int_vec[gpi_i][gpi_j] = gpi_min;
            }
        }

        gpi_min_indexes .clear ();
        gpi_max_indexes .clear ();

        // В результат записываем новый массив через пробел
        for (gpi_j = 0; gpi_j < gpi_2d_int_vec[gpi_i].size(); ++gpi_j)
        {
            gpi_txt_out += QString::number (gpi_2d_int_vec[gpi_i][gpi_j]);
            gpi_txt_out += " ";
        }
        gpi_txt_out += "\n";
    }

    ui ->gpi_textEdit_output ->setText (gpi_txt_out);       // Выводим результат на экран
}

QVector<QVector<QString>> gpi_MainWindow :: gpi_get_2d_vec_from_txt (QString gpi_txt)
{
    QVector<QVector<QString>>   gpi_2d_vec;
    QVector<QString>            gpi_lines;
    int                         gpi_lines_size;
    QVector<QString>            gpi_words;
    int                         gpi_i;
    int                         gpi_j;
    // = = = = = = = = = = = = = = = =

    gpi_lines = gpi_txt .split ("\n");                      // Разбиваем текст по строкам
    gpi_lines_size = gpi_lines .size ();                    // Определяем размер массива

    gpi_i = 0;
    while (gpi_i < gpi_lines_size)                          // Проходимся по массиву
    {
        gpi_words = gpi_lines[gpi_i] .split (" ");          // Разбиваем строку на слова

        gpi_j = 0;
        while (gpi_j < gpi_words .size ())                  // Проходимся по массиву слов
        {
            if (gpi_words[gpi_j] .size () == 0)             // Если слово пустое
            {
                gpi_words .remove (gpi_j);                  // Удалить слово
                continue;
            }

            ++gpi_j;
        }

        gpi_2d_vec .push_back (gpi_words);                  // Добавляем слово в массив
        ++gpi_i;
    }

    //qDebug() << gpi_2d_vec;
    return gpi_2d_vec;
}

QVector<QVector<int>> gpi_MainWindow :: gpi_StrVec_to_IntVec (const QVector<QVector<QString>> gpi_str_2d_vec)
{
    QVector<QVector<int>>   gpi_int_2d_vec;                 // Двумерный массив чисел
    QVector<int>            gpi_int_1d_vec;                 // Одномерный массив чисел
    int                     gpi_2d_size;                    // Размер массива
    int                     gpi_1d_size;                    // Размер массива
    int                     gpi_i;                          // Для цикла
    int                     gpi_j;                          // Для цикла
    int                     gpi_number;                     // Число
    // = = = = = = = = = = = = = = = =

    gpi_2d_size = gpi_str_2d_vec .size();
    gpi_i = 0;
    while (gpi_i < gpi_2d_size)
    {
        gpi_1d_size = gpi_str_2d_vec[gpi_i] .size ();
        gpi_j = 0;
        while (gpi_j < gpi_1d_size)
        {
            gpi_number = gpi_str_2d_vec[gpi_i][gpi_j] .toInt ();
            gpi_int_1d_vec .push_back (gpi_number);
            ++gpi_j;
        }

        if (gpi_j != 0)
            gpi_int_2d_vec .push_back (gpi_int_1d_vec);
        gpi_int_1d_vec .clear ();

        ++gpi_i;
    }

    //qDebug () << gpi_int_2d_vec;
    return gpi_int_2d_vec;
}
