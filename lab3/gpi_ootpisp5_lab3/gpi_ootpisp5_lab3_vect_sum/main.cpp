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
    QVector<int> vec; // создаём вектор из 11 элементов от 1 до 10
    for (int i = 0; i <= 10; i++)
    {
        vec.push_back(i);
    }
    qDebug() << vec;

    for (int i = 0; i <= 10; i++)
    {
        // заменяем элемент вектора "2" на "65"
        vec.replace(2, 65);
    }
    qDebug() << vec;

    int sum = 0; // находим сумму элементов
    for (int i = 0; i < vec.size(); i++)
    {
        // от 0 до количества элементов в векторе
        sum += vec[i];
    }
    qDebug() << "Sum = " << sum;
}
