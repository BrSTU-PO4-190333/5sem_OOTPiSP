#ifndef TOWER_HPP
#define TOWER_HPP

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class tower; }
QT_END_NAMESPACE

class tower : public QMainWindow
{
    Q_OBJECT

public:
    tower(QWidget *parent = nullptr);
    ~tower();

private:
    Ui::tower *ui;
};
#endif // TOWER_HPP
