#include "gpi_mainwindow.hpp"
#include "ui_gpi_mainwindow.h"

GPI_MainWindow :: GPI_MainWindow (QWidget *parent)
    : QMainWindow (parent)
    , ui (new Ui::GPI_MainWindow)
{
    ui ->setupUi (this);

    this ->setWindowTitle ("gpi_ootpisp5_lab3_option5_task2_1");
    this ->setWindowIcon (QIcon (":/@/gpi_favicon.png"));

    connect (
        ui ->gpi_lineEdit_input,
        SIGNAL (textChanged (const QString&)),
        this,
        SLOT (gpi_on_gpi_lineEdit_input_textChanged(const QString&))
    );

    gpi_calculate_array ();
}

GPI_MainWindow :: ~GPI_MainWindow()
{
    delete ui;
}

// Функция выведет в поле сначала чётные цифры, затем нечётные цифры, затем остальные символы
void GPI_MainWindow :: gpi_on_gpi_lineEdit_input_textChanged (const QString &gpi_txt)
{
    Q_UNUSED (gpi_txt);
    gpi_calculate_array ();
}

void GPI_MainWindow :: gpi_calculate_array()
{
    QString             gpi_txt_in;         // Текст с поля
    QVector<QString>    gpi_arr;            // Массив слов

    bool                gpi_b;

    QVector<QString>    gpi_arr_even;       // Массив чётных чисел
    QVector<QString>    gpi_arr_odd;        // Массив нечётный чисел

    int                 gpi_number;         // Число, которое было словом

    int                 gpi_i;              // Для цикла

    QString             gpi_text_output;    // Результат
    // = = = = = = = = = = = = = = = =

    // Получаем текст с поля
    gpi_txt_in = ui ->gpi_lineEdit_input ->text ();

    // Разделяем текст на слова
    gpi_arr = gpi_txt_in .split (QRegularExpression ("\\s+"));

    // Удаляем из массива путые строки
    for (gpi_i = 0; gpi_i < gpi_arr .size (); ++gpi_i)
    {
        if (gpi_arr[gpi_i].compare("") == 0)
        {
            gpi_arr.remove(gpi_i);
        }
    }

    // Сообщаем, если в массиве есть не цифра
    for (gpi_i = 0; gpi_i < gpi_arr .size (); ++gpi_i)
    {
        gpi_arr[gpi_i] .toInt (&gpi_b, 10);

        if (gpi_b == false)
        {
            QMessageBox :: warning (this, "gpi_ Ошибка ввода", "В массиве чисел оказался символ");
            return;
        }
    }

    // Заполняем массив чётных и нечётных чисел
    for (gpi_i = 0; gpi_i < gpi_arr .size (); ++gpi_i)
    {
        gpi_number = gpi_arr[gpi_i] .toInt ();

        if (gpi_number % 2 == 0)
        {
            gpi_arr_even .push_back (gpi_arr[gpi_i]);
            continue;
        }

        if (gpi_number % 2 == 1)
        {
            gpi_arr_odd .push_back (gpi_arr[gpi_i]);
            continue;
        }
    }

    // Формируем новую строку на вывод
    gpi_text_output = "";

    for (gpi_i = 0; gpi_i < gpi_arr_even .size (); ++gpi_i)
    {
        gpi_text_output += gpi_arr_even[gpi_i] + " ";
    }

    for (gpi_i = 0; gpi_i < gpi_arr_odd .size (); ++gpi_i)
    {
        gpi_text_output += gpi_arr_odd[gpi_i] + " ";
    }

    // Выводим результат на экран
    ui->gpi_lineEdit_output->setText(gpi_text_output);
}
