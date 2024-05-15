#include <QApplication>
#include "pintura.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Pintura p;
    p.show();
    return a.exec();
}
