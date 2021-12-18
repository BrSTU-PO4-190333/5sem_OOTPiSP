#include "gpi_mainwindow.hpp"
#include "ui_gpi_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_generateTable, SIGNAL(clicked()), this, SLOT(gpi_on_pushButton_generateTable_clicked()));
    connect(ui->pushButton_pow2, SIGNAL(clicked()), this, SLOT(gpi_on_pushButton_pow2_clicked()));
    connect(ui->pushButton_pow3, SIGNAL(clicked()), this, SLOT(gpi_on_pushButton_pow3_clicked()));

    this->setWindowIcon(QIcon(":/@/gpi_favicon.png"));
    this->setWindowTitle("gpi_ootpisp5_lab4_option9");

    srand(1234567890);
    gpi_generate_random_table();

    ui->label_sumMod2->setStyleSheet(""
        + QString("background-color: %1;").arg(this->gpi_colorMod2.name())
        + QString("border: 1px solid %1;").arg(this->gpi_colorMod2.name())
        + "color: black;"
    );

    ui->label_sumMod3->setStyleSheet(""
        + QString("background-color: %1;").arg(this->gpi_colorMod3.name())
        + QString("border: 1px solid %1;").arg(this->gpi_colorMod3.name())
        + "color: black;"
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::gpi_rand(int a, int b)
{
    return rand() % (b - a + 1) + a;
}

int MainWindow::gpi_rand_odd_or_even(bool flag, int a, int b)
{
    int number = gpi_rand(a, b);
    while(1)
    {
        if (number % 2 == 0 && flag == true)
        {
            return number;
        }
        else if (number % 2 == 1 && flag == false)
        {
            return number;
        }
        number = gpi_rand(a, b);
    }
}

void MainWindow::gpi_generate_random_table()
{
    int     gpi_i               = 0;
    int     gpi_j               = 0;
    int     gpi_rows            = ui->tableWidget->rowCount();
    int     gpi_cols            = ui->tableWidget->columnCount();
    int     gpi_num;
    int     gpi_flag            = true;

    if (ui->radioButton->isChecked())
    {
        gpi_flag = true;
    }
    else
    {
        gpi_flag = false;
    }

    // = = = = = = = = = = = = = = = =

    while (gpi_i < gpi_rows)
    {
        gpi_j = 0;
        while (gpi_j < gpi_cols)
        {
            gpi_num = gpi_rand_odd_or_even (gpi_flag, 1, 100);
            QTableWidgetItem* gpi_item = new QTableWidgetItem (tr ("%1").arg (gpi_num));
            ui->tableWidget->setItem (gpi_i, gpi_j, gpi_item);
            ++gpi_j;
        }
        ++gpi_i;
    }

    ui->label_sumMod2->setText("");
    ui->label_sumMod3->setText("");
}

bool MainWindow::gpi_modn(int mod, float number)
{
    while (number > 1)
    {
        number /= mod;
    }

    return number == 1 ? (true) : (false);
}

void MainWindow::gpi_on_pushButton_generateTable_clicked ()
{
    gpi_generate_random_table ();
}

void MainWindow::gpi_on_pushButton_pow2_clicked()
{
    int     gpi_i               = 0;
    int     gpi_j               = 0;
    int     gpi_rows            = ui->tableWidget->rowCount ();
    int     gpi_cols            = ui->tableWidget->columnCount ();
    int     gpi_sum             = 0;
    QString gpi_sum_result;
    int     gpi_num;
    // = = = = = = = = = = = = = = = =

    while (gpi_i < gpi_rows)
    {
        gpi_j = 0;
        while (gpi_j < gpi_cols)
        {
            gpi_num = ui->tableWidget->item(gpi_i, gpi_j)->text().toInt();
            if ( gpi_modn (2, gpi_num))
            {
                ui->tableWidget->item (gpi_i, gpi_j)->setBackground (this->gpi_colorMod2);
                gpi_sum += 1;
            }
            ++gpi_j;
        }
        ++gpi_i;
    }

    gpi_sum_result = QString::number(gpi_sum);
    ui->label_sumMod2->setText(gpi_sum_result);
}

void MainWindow::gpi_on_pushButton_pow3_clicked ()
{
    int     gpi_i               = 0;
    int     gpi_j               = 0;
    int     gpi_rows            = ui->tableWidget->rowCount ();
    int     gpi_cols            = ui->tableWidget->columnCount ();
    int     gpi_sum             = 0;
    QString gpi_sum_result;
    int     gpi_num;
    // = = = = = = = = = = = = = = = =

    while (gpi_i < gpi_rows)
    {
        gpi_j = 0;
        while (gpi_j < gpi_cols)
        {
            gpi_num = ui->tableWidget->item(gpi_i, gpi_j)->text().toInt();
            if ( gpi_modn (3, gpi_num))
            {
                ui->tableWidget->item (gpi_i, gpi_j)->setBackground (this->gpi_colorMod3);
                gpi_sum += 1;
            }
            ++gpi_j;
        }
        ++gpi_i;
    }

    gpi_sum_result = QString::number(gpi_sum);
    ui->label_sumMod3->setText(gpi_sum_result);
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_G)
    {
        gpi_on_pushButton_generateTable_clicked();
        return;
    }

    if(e->key() == Qt::Key_2)
    {
        gpi_on_pushButton_pow2_clicked();
        return;
    }

    if(e->key() == Qt::Key_3)
    {
        gpi_on_pushButton_pow3_clicked();
        return;
    }
}
