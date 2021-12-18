#include <QCoreApplication>

void example();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    example();

    return a.exec();
}

void example()
{
    const char endl = '\n';

    QList<int> list;

    list << 3 << 4 << 5 << 6 << 7;
    // вносим элементы в список

    qDebug() << list;

    int firstNumber = list.takeFirst();
    // помещаем возвращенное значение в
    // переменную и удаляем из списка первый элемент
    qDebug() << "FirstNumber: " << firstNumber;
    qDebug() << list;

    list.move(0, 1); // перемещаем элемент с нулевой позиции на первую
    QList<int>::iterator it = list.begin();
    while(it != list.end())
    {
        qDebug() << *it;
        ++it;
    }
    qDebug() << endl;

    QList<int>::iterator ip = list.begin() + 1; // ставим итератор на первую позицию
    while(ip != list.end() - 1) // пока не достигаем последнего элемента
    {
        *ip *= (*ip); // возвоим в квадрат
        ++ip;
    }

    ip = list.begin(); // выводим список
    while(ip != list.end())
    {
        qDebug() << *ip;
        ++ip;
    }
}
