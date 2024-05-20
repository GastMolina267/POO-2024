#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QTimer>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crear un objeto QLabel
    QLabel label;

    // Cargar la imagen desde un archivo JPG
    QPixmap imagen("C:/Users/marin/Downloads/string_index.png");

    // Establecer la imagen en el QLabel
    label.setPixmap(imagen);

    // Mostrar el QLabel de forma maximizada
    label.showMaximized();

    // Configurar un temporizador para cerrar la aplicación después de 3 segundos
    QTimer::singleShot(3000, [&](){
        label.close();
        app.quit();
    });

    return app.exec();
}
