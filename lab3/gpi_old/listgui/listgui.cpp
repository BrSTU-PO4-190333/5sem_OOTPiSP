#include "listgui.hpp"
#include "ui_listgui.h"

listgui::listgui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::listgui)
{
    ui->setupUi(this);

    this->setWindowTitle("OOTPiSP lab3 listgui");
    this->setWindowIcon(QIcon(":/@/favicon.png"));
    this->setFixedSize(size());

    for (int i = 0; i < 10; i += 1)
    {
        list.append(10 + i * 2);
        int number = list.at(i);
        QString strNumber = QString::number(number);
        ui->textEdit->append(strNumber + " ");
    }
}

listgui::~listgui()
{
    delete ui;
}

void listgui::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked())
    {
        if (list.size() < 1)
        {
           ui->statusbar->showMessage("The list is empty");
           return;
        }

        list.removeLast();
        ui->statusbar->showMessage("Last item removed");
    }
    else if (ui->radioButton_2->isChecked())
    {
        int n = ui->lineEdit->text().toInt();
        list.push_front(n);
        // добавляем введённый элемент в lineEdit в начало
        ui->statusbar->showMessage("Added element to the beginning");
    }
    else if (ui->radioButton_3->isChecked())
    {
        int a, b;
        QStringList st = ui->lineEdit_2->text().split(",");
        if (st.size() < 2)
        {
            ui->statusbar->showMessage("Wrong format!");
            return;
        }
        a = st[0].toInt();
        b = st[1].toInt();

        int min = (a < b) ? a : b;
        if (min < 0)
        {
            ui->statusbar->showMessage("Item number " + QString::number(min) + " does not exist");
            return;
        }

        int max = (a > b) ? a : b;
        if (list.size() <= max)
        {
            ui->statusbar->showMessage("Item number " + QString::number(max) + " does not exist");
            return;
        }

        list.swapItemsAt(a, b);
        ui->statusbar->showMessage("Swapped elements (" + st[0] + " <---> " + st[1] + ")");
    }
    else
    {
        ui->statusbar->showMessage("Option not selected");
        return;
    }

    ui->textEdit->clear(); // перезаписываем список

    QList<int>::iterator it = list.begin();
    while (it != list.end())
    {
        int number = *it;
        QString strNumber = QString::number(number);
        ui->textEdit->append(strNumber + " ");
        it++;
    }
}

