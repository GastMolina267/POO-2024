#include <QApplication>
#include <acceso.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Acceso login;
    return a.exec();
}
