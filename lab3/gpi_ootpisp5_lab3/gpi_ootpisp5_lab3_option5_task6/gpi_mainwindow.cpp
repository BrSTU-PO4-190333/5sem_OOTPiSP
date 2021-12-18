#include "gpi_mainwindow.hpp"
#include "ui_gpi_mainwindow.h"

gpi_MainWindow::gpi_MainWindow (QWidget *parent)
    : QMainWindow (parent)
    , ui (new Ui::gpi_MainWindow)
{
    ui->setupUi (this);

    this->setWindowTitle ("gpi_ootpisp5_lab3_option5_task7");
    this->setWindowIcon (QIcon (":/@/gpi_favicon.png"));

    on_gpi_lineEdit_path_textChanged(":/@/gpi_f.txt");
}

gpi_MainWindow::~gpi_MainWindow ()
{
    delete ui;
}

void gpi_MainWindow::on_gpi_lineEdit_path_textChanged (const QString &gpi_path)
{
    QFile gpi_f (gpi_path);

    if (gpi_f.exists () == false)
    {
        QMessageBox::warning (this, "Ошибка открытия файла", "Файл не найден");
        return;
    }

    if (gpi_f.open (QIODevice::ReadOnly) == false)
    {
        QMessageBox::warning (this, "Ошибка открытия файла", "Файл не открылся для чтения");
        return;
    }

    QTextStream gpi_stream (&gpi_f);
    QString gpi_buf = gpi_stream.readAll ();
    qDebug() << gpi_buf;

    ui->gpi_plainTextEdit_file1->setPlainText (gpi_buf);

    gpi_f.close ();
}

void gpi_MainWindow::on_gpi_plainTextEdit_file1_textChanged()
{
    // Получаем текст с поля
    QString gpi_s = ui->gpi_plainTextEdit_file1->toPlainText ();

    // Объединяю строки
    gpi_s.replace("\n", " ");
    qDebug() << gpi_s;

    // Разделяю строку на слова
    QStringList gpi_words = gpi_s.split(" ");
    qDebug() << gpi_words;

    // Слова в цифры
    int gpi_n;
    bool gpi_b;
    QVector<int> gpi_a;
    for (int gpi_i = 0; gpi_i < gpi_words.size(); ++gpi_i)
    {
        gpi_n = gpi_words[gpi_i].toInt(&gpi_b, 10);
        if (gpi_b == true)
        {
            gpi_a.append(gpi_n);
            continue;
        }
    }
    qDebug() << gpi_a;

    QVector<int> gpi_odd;
    QVector<int> gpi_even;
    for (int gpi_i = 0; gpi_i < gpi_a.size(); ++gpi_i)
    {
        gpi_n = gpi_a[gpi_i];
        if (gpi_n % 2 == 0)
        {
            gpi_odd.append(gpi_n);
            continue;
        }

        if (gpi_n % 2 == 1)
        {
            gpi_even.append(gpi_n);
            continue;
        }
    }
    qDebug() << "odd" << gpi_odd;
    qDebug() << "even" << gpi_even;

    QString gpi_text_odd = "";
    QString gpi_text_even = "";
    for (int gpi_i = 0; gpi_i < gpi_odd.size(); ++gpi_i)
    {
        gpi_text_odd += QString::number(gpi_odd[gpi_i]) + " ";
    }

    for (int gpi_i = 0; gpi_i < gpi_even.size(); ++gpi_i)
    {
        gpi_text_even += QString::number(gpi_even[gpi_i]) + " ";
    }

    ui->gpi_plainTextEdit_file2->setPlainText(gpi_text_odd);
    ui->gpi_plainTextEdit_file3->setPlainText(gpi_text_even);

    QFile gpi_f2 ("gpi_g.txt");

    if (gpi_f2.open(QIODevice::WriteOnly) == false)
    {
        QMessageBox::warning (this, "Ошибка открытия файла", "Файл не открылся для чтения");
        return;
    }

    QTextStream gpi_stream2(&gpi_f2);
    gpi_stream2 << gpi_text_odd;
    gpi_f2.close();

    QFile gpi_f3 ("gpi_h.txt");

    if (gpi_f3.open(QIODevice::WriteOnly) == false)
    {
        QMessageBox::warning (this, "Ошибка открытия файла", "Файл не открылся для чтения");
        return;
    }

    QTextStream gpi_stream3(&gpi_f3);
    gpi_stream3 << gpi_text_even;
    gpi_f3.close();
}

