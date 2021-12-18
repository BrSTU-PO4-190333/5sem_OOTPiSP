#ifndef LISTGUI_HPP
#define LISTGUI_HPP

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class listgui; }
QT_END_NAMESPACE

class listgui : public QMainWindow
{
    Q_OBJECT

public:
    listgui(QWidget *parent = nullptr);
    ~listgui();

private slots:
    void on_pushButton_clicked();

private:
    Ui::listgui *ui;
    QList<int> list;
};
#endif // LISTGUI_HPP
