#include <QApplication>
#include <QVBoxLayout>
#include "barra.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Crea una instancia de ProgressBarEx
    ProgressBarEx progressBar;

    // Configura la ventana principal
    QWidget window;
    window.setWindowTitle("Descarga de Archivos");
    window.resize(400, 150);

    // Agrega el ProgressBarEx al diseño de la ventana principal
    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(&progressBar);

    //ARCHIVOS DE PRUEBA PARA DESCARGAR
    //https://proof.ovh.net/files/1Mb.dat
    //https://proof.ovh.net/files/10Mb.dat
    //https://proof.ovh.net/files/100Mb.dat
    window.show();

    return a.exec();
}

