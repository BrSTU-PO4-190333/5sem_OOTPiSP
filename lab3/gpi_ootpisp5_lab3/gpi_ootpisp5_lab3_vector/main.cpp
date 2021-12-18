#include <QCoreApplication>

void example1();
void example2();
void example3();
void example4();
void example5();
void example();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    example1();
    example2();
    example3();
    example4();
    example5();
    example();

    return a.exec();
}

void example1()
{
    qDebug() << "\n example1";
    QVector <float> vect1(3);
    vect1[0] = 1.0;
    vect1[1] = 0.5;
    vect1[2] = -0.4;
    qDebug() << vect1;
}

void example2()
{
    qDebug() << "\n example2";
    //QVector(3,3,3,3,3);
    QVector <int> vect2(5,3);
    qDebug() << vect2;
}

void example3()
{
    qDebug() << "\n example3";
    QVector <int> vect3;
    vect3.push_back(10);
    vect3.push_back(20);
    vect3.push_back(30);
    qDebug() << vect3;
}

void example4()
{
    qDebug() << "\n example4";
    QVector <float> vect4;
    vect4.append(34.0);
    vect4.append(0.5899);
    vect4.append(-0.678);
    qDebug() << vect4;
}

void example5()
{
    qDebug() << "\n example5";
    QVector <QString> vect5;
    vect5.append("one");
    vect5.append("two");
    vect5.append("three");
    qDebug() << vect5;
}

void example()
{
    qDebug() << "\n example";
    const QString endl = "\n";

    QTextStream out(stdout);

    // Создаём вектор, содержащий целочисленные значения
    QVector<int> vals = {1,2,3,4,5};

    // С помощью метода size() возвращаем размер вектора (количество элементов, содержащихся в нём)
    out << "The size of the vector is: " << vals.size() << endl;

    out << "The first item is: " << vals.first() << endl;
    // получаем первый элемент вектора

    out << "The last item is: " << vals.last() << endl;
    // получаем последний элемент вектора

    vals.append(6); // вставляем новый элемент в конец вектора
    vals.prepend(0); //вставляем новый элемент в начало вектора

    out << "Elements: ";

    // Перебираем элементы вектора и выводим их на экран
    for (int val: vals)
    {
        out << val << " ";
    }
    out << endl;
}
