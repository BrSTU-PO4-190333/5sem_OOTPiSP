#include <QCoreApplication>
#include <QQueue>

void example();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    example();

    return a.exec();
}

void example()
{
    QQueue<int> que;

    QTextStream in(stdin);
    qDebug() << "Number of items in the queue";
    int count = (in.readLine()).toInt();

    qDebug() << "Values:";
    for (int i = 0; i < count; i++)
    {
        int num = (in.readLine()).toInt();
        que.enqueue(num); // помещаем введённые значения в очередь
    }
    qDebug() << "Queue Elements:" << que;
    int len = que.length(); // заносим в переменную значение длины очереди
    for (int i = 0; i < len; i++)
    {
        int num = que.dequeue(); // извлекаем элемент из очереди
        if (num % 2 == 0) // проверка на чётность
        {
            num += 3;
        }
        que.enqueue(num); // записываем обратно в очередь
    }
    qDebug() << "Queue:" << que;
}
