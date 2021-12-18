#include "gpi_mainwindow.hpp"
#include "ui_gpi_mainwindow.h"

gpi_MainWindow :: gpi_MainWindow (QWidget *parent)
    : QMainWindow (parent)
    , ui (new Ui::gpi_MainWindow)
{
    ui ->setupUi (this);

    this->setWindowTitle("gpi_ootpisp5_lab3_option5_task4_1");
    this->setWindowIcon(QIcon(":/@/gpi_favicon.png"));

    connect (
        ui ->gpi_lineEdit_input,
        SIGNAL (textChanged (const QString &)),
        this,
        SLOT (gpi_on_gpi_lineEdit_input_textChanged (const QString &))
    );

    gpi_calculate_stack ();
}

gpi_MainWindow :: ~gpi_MainWindow ()
{
    delete ui;
}

void gpi_MainWindow :: gpi_on_gpi_lineEdit_input_textChanged (const QString &gpi_txt)
{
    Q_UNUSED(gpi_txt);
    gpi_calculate_stack ();
}

void gpi_MainWindow :: gpi_calculate_stack ()
{
    QString                 gpi_txt;
    QVector<QString>        gpi_vec;

    int                     gpi_i;

    bool                    gpi_b;

    QStack<int>             gpi_stc;
    QStack<int>::iterator   gpi_it;
    int                     gpi_min;
    int                     gpi_max;
    QStack<int>             gpi_stc2;

    QString                 gpi_txt_out;
    // = = = = = = = = = = = = = = =

    gpi_txt = ui ->gpi_lineEdit_input ->text ();
    gpi_vec = gpi_txt .split (QRegularExpression ("\\s+"));

    for (gpi_i = 0; gpi_i < gpi_vec .size (); ++gpi_i)
    {
        if (gpi_vec[gpi_i] .compare ("") == 0)
        {
            gpi_vec .remove (gpi_i);
        }
    }

    for (gpi_i = 0; gpi_i < gpi_vec .size (); ++gpi_i)
    {
        gpi_vec[gpi_i].toInt(&gpi_b, 10);

        if (gpi_b == false)
        {
            QMessageBox :: warning (this, "Ошибка ввода", "В стеке чисел оказался символ");
            return;
        }
    }

    for (gpi_i = 0; gpi_i < gpi_vec .size (); ++gpi_i)
    {
        gpi_stc << gpi_vec[gpi_i] .toInt ();
    }

    gpi_min = *gpi_stc .begin ();
    gpi_max = *gpi_stc .begin ();
    for (gpi_it = gpi_stc .begin (); gpi_it != gpi_stc .end (); ++gpi_it)
    {
        if (*gpi_it < gpi_min)
        {
            gpi_min = *gpi_it;
        }

        if (*gpi_it > gpi_max)
        {
            gpi_max = *gpi_it;
        }
    }

    for (gpi_it = gpi_stc .begin (); gpi_it != gpi_stc .end (); ++gpi_it)
    {
        if (*gpi_it == gpi_min)
        {
            gpi_stc2 << gpi_max;
            continue;
        }

        if (*gpi_it == gpi_max)
        {
            gpi_stc2 << gpi_min;
            continue;
        }

        gpi_stc2 << *gpi_it;
    }

    gpi_txt_out = "";
    for (gpi_it = gpi_stc2 .begin (); gpi_it != gpi_stc2 .end (); ++gpi_it)
    {
        gpi_txt_out += QString :: number (*gpi_it);
        gpi_txt_out += " ";
    }

    ui ->gpi_lineEdit_output ->setText(gpi_txt_out);
}
