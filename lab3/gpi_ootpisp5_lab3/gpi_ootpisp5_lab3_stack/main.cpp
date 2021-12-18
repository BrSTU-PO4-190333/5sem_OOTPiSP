#include <QCoreApplication>
#include <QStack>

void example();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    example();

    return a.exec();
}

void example()
{
    QStack <int> stack_1, stack_2; // объявление экземпляра класса QStack
    qDebug() << "Set the number of elements: ";

    QTextStream in(stdin);
    int count = (in.readLine()).toInt(); // количество элементов стека

    qDebug() << "Enter the elements:"; // ввод элементов с клавиатуры
    for (int i = 0; i < count; i++)
    {
        int num = (in.readLine()).toInt();
        stack_1.push(num); // заносим введённые значения в стек
    }

    qDebug() << "Stack 1: " << stack_1;
    while(!stack_1.empty())
    {
        int num = stack_1.pop(); // достаем элемент
        if (num % 2 == 0) // проверяем на чётность
        {
            num += 3;
        }
        stack_2.push(num); // помещаем во второй стек
    }

    qDebug() << "Stack 2: " << stack_2;
    while(!stack_2.empty())
    {
        stack_1.push(stack_2.pop()); // перекладываем в первый стек
    }
    qDebug() << "Stack 1: " << stack_1;
}
