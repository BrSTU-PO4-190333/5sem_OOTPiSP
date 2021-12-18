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
    QVector<QString> vec;
    vec << "one"
        << "two"
        << "three";
    QVector<QString>::iterator it = vec.begin();
    for ( ; it != vec.end(); ++it)
    {
        qDebug() << "Element:" << *it;
    }

    QVector<QString>::iterator id = vec.end();
    for ( ; id != vec.begin(); )
    {
        --id;
        qDebug() << "Element:" << *id;
    }
}

void example2()
{
    qDebug() << "\n example2";
    QList<QString> lst;
    lst << "one"
        << "two"
        << "three";
    QList<QString>::iterator it = lst.begin();
    for ( ; it != lst.end(); ++it)
    {
        qDebug() << "Element:" << *it;
    }

    QList<QString>::iterator id = lst.end();
    for ( ; id != lst.begin(); )
    {
        --id;
        qDebug() << "Element:" << *id;
    }
}
