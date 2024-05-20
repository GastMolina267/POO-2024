#include <manager.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Manager* manager = new Manager();

    return a.exec();
}
