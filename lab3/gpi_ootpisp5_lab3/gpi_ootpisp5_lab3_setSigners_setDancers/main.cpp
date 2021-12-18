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

    QSet<QString> signers;
    QSet<QString> dancers;

    signers << "Ivan"
            << "Evgeniy"
            << "Anastasia"
            << "Alexander"
            << "Xenia";
    qDebug() << signers << endl;

    dancers << "Marina"
            << "Peter"
            << "Ivan"
            << "Xenia";
    qDebug() << dancers << endl;

    QSet<QString> result = signers;
    result.unite(dancers);
    qDebug() << "Combining sets:";
    qDebug() << result << endl;

    result = signers;
    result.intersect(dancers);
    qDebug() << "Intersection of sets:";
    qDebug() << result << endl;

    result = signers;
    result.subtract(dancers);
    qDebug() << "Difference of sets signers - dancers:";
    qDebug() << result << endl;

    result = dancers;
    result.subtract(signers);
    qDebug("Difference of sets dancer - signers:");
    qDebug() << result << endl;
}
