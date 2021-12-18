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

    QMap<QString, QString> phones; // объявляем экземпляр класса QMap
    phones["Anna"] = "79195679845"; // заполнение словаря
    phones["Irina"] = "79128349028";
    phones.insert("Alex", "89632675687");
    phones.insert("Danil", "89092345681");

    QMap<QString, QString>::iterator it = phones.begin();
    for ( ; it != phones.end(); ++it)
    {
        // вывод словаря
        qDebug() << "Name: " << it.key() << "Phone: " << it.value();
    }
    qDebug() << endl;

    qDebug() << "Phone Alex:" << phones.value("Alex");
    // получаем значение

    qDebug() << "Phone 89092345681: " << phones.key("89092345681");

    if (phones.contains("Oleg"))
    {
        // проверяем наличие записи в словаре
        qDebug() << "Phone: " << phones["Oleg"];
    }

    if (phones.contains("Irina"))
    {
        qDebug() << "Phone: " << phones["Irina"];
    }
}
