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
    QMap<QString, int> map;
    map["ten"] = 10;
    map["twenty"] = 20;
    map["thirty"] = 30;

    QMap<QString, int>::iterator it = map.begin();
    for ( ; it != map.end(); ++it)
    {
        qDebug() << "key:" << it.key() << "value:" << it.value();
    }
}

void example2()
{
    qDebug() << "\n example2";
    QMap<QString, int> map2;
    map2.insert("one", 1);
    map2.insert("two", 2);
    map2.insert("three", 3);

    QMap<QString, int>::iterator it = map2.begin();
    for ( ; it != map2.end(); ++it)
    {
        qDebug() << "key:" << it.key() << "value:" << it.value();
    }
}
