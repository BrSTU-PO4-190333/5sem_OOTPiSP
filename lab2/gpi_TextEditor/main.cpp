#include "texteditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setApplicationName("gpi_TextEditor");
    a.setApplicationVersion("0.1");

    a.setOrganizationName("БрГТУ ПОИТ-4");
    a.setOrganizationDomain("bstu.by");

    a.setWindowIcon(QIcon(":/icons/Resources/new.png"));

    TextEditor w;
    w.show();
    return a.exec();
}
