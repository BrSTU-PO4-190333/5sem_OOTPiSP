#include "tower.hpp"
#include "ui_tower.h"

tower::tower(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tower)
{
    ui->setupUi(this);

    this->setFixedSize(size());
}

tower::~tower()
{
    delete ui;
}

