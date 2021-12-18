#include <QCoreApplication>

void example1();
void example2();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    example1();
    example2();

    return a.exec();
}

void example1()
{
    qDebug() << "\n example1";
    QList<int> list;
    list << 10 << 20 << 30;
    qDebug() << list;
}

void example2()
{
    qDebug() << "\n example2";
    QList<QString> list2;
    list2.append("one");
    list2.append("two");
    list2.append("three");
    qDebug() << list2;
}
