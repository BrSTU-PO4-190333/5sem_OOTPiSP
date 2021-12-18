#include "gpi_mainwindow.hpp"
#include "ui_gpi_mainwindow.h"

gpi_MainWindow::gpi_MainWindow (QWidget *parent)
    : QMainWindow (parent)
    , ui (new Ui::gpi_MainWindow)
{
    ui ->setupUi (this);

    this ->setWindowTitle ("gpi_ootpisp5_lab3_option5_task1");
    this ->setWindowIcon (QIcon (":/@/gpi_favicon.png"));

    connect (
        ui ->gpi_lineEdit_input1,
        SIGNAL (textChanged (const QString&)),
        this,
        SLOT (gpi_on_gpi_lineEdit_input1_textChanged(const QString&))
    );

    connect (
        ui ->gpi_lineEdit_input2,
        SIGNAL (textChanged (const QString&)),
        this,
        SLOT (gpi_on_gpi_lineEdit_input2_textChanged(const QString&))
    );

    connect (
        ui ->gpi_lineEdit_input3,
        SIGNAL (textChanged (const QString&)),
        this,
        SLOT (gpi_on_gpi_lineEdit_input3_textChanged(const QString&))
    );
}

gpi_MainWindow :: ~gpi_MainWindow ()
{
    delete ui;
}

void gpi_MainWindow :: gpi_get_number1 ()
{
    QString gpi_txt;
    bool    gpi_b;
    // = = = = = = = = = = = = = = = =

    gpi_txt = ui ->gpi_lineEdit_input1 ->text ();
    gpi_n1 = gpi_txt .toInt (&gpi_b, 10);

    if (gpi_b == false)
    {
        QMessageBox :: warning (this, "gpi_ Ошибка ввода", "В поле ввода первого числа записано не число");
        return;
    }
}

void gpi_MainWindow :: gpi_get_number2 ()
{
    QString gpi_txt;
    bool    gpi_b;
    // = = = = = = = = = = = = = = = =

    gpi_txt = ui ->gpi_lineEdit_input2 ->text ();
    gpi_n2 = gpi_txt .toInt (&gpi_b, 10);

    if (gpi_b == false)
    {
        QMessageBox :: warning (this, "gpi_ Ошибка ввода", "В поле ввода второго числа записано не число");
        return;
    }
}

void gpi_MainWindow :: gpi_get_number3 ()
{
    QString gpi_txt;
    bool    gpi_b;
    // = = = = = = = = = = = = = = = =

    gpi_txt = ui ->gpi_lineEdit_input3 ->text ();
    gpi_n3 = gpi_txt .toInt (&gpi_b, 10);

    if (gpi_b == false)
    {
        QMessageBox :: warning (this, "gpi_ Ошибка ввода", "В поле ввода третьего числа записано не число");
        return;
    }
}

void gpi_MainWindow :: gpi_on_gpi_lineEdit_input1_textChanged (const QString &gpi_txt)
{
    Q_UNUSED (gpi_txt);
    gpi_get_number1 ();
    gpi_print_result ();
}


void gpi_MainWindow :: gpi_on_gpi_lineEdit_input2_textChanged (const QString &gpi_txt)
{
    Q_UNUSED (gpi_txt);
    gpi_get_number2 ();
    gpi_print_result ();
}

void gpi_MainWindow :: gpi_on_gpi_lineEdit_input3_textChanged (const QString &gpi_txt)
{
    Q_UNUSED (gpi_txt);
    gpi_get_number3 ();
    gpi_print_result ();
}

void gpi_MainWindow :: gpi_calculate_results ()
{
    gpi_get_number1 ();
    gpi_get_number2 ();
    gpi_get_number3 ();

    if (gpi_n1 > gpi_n2 && gpi_n1 > gpi_n3)
    {
        gpi_n1 = gpi_n2 - gpi_n3;
        return;
    }

    if (gpi_n2 > gpi_n1 && gpi_n2 > gpi_n3)
    {
        gpi_n2 = gpi_n1 - gpi_n3;
        return;
    }

    if (gpi_n3 > gpi_n1 && gpi_n3 > gpi_n2)
    {
        gpi_n3 = gpi_n1 - gpi_n2;
        return;
    }

    if (gpi_n1 == gpi_n2 && gpi_n1 == gpi_n3)
    {
        gpi_n1 = gpi_n2 - gpi_n3;
        return;
    }
}

void gpi_MainWindow :: gpi_print_result ()
{
    gpi_calculate_results ();
    ui ->gpi_lineEdit_output1 ->setText (QString :: number (gpi_n1));
    ui ->gpi_lineEdit_output2 ->setText(QString :: number (gpi_n2));
    ui ->gpi_lineEdit_output3 ->setText(QString :: number (gpi_n3));
}
