#ifndef ACCESO_H
#define ACCESO_H

#include <QWidget>

#include <QImage>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

#include <QPainter>

#include <ventana.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Acceso;
}
QT_END_NAMESPACE
class Acceso : public QWidget
{
    Q_OBJECT

    public:
        Acceso(QWidget *parent = nullptr);
        ~Acceso();

    protected:
        void paintEvent(QPaintEvent *);

    private:
        Ui::Acceso *ui;

        Ventana* ventana;

        QImage im;
        QNetworkAccessManager* manager;

        int intentos = 0;

    private slots:
        void slot_verificar_usuario();
        void slot_descarga_finalizada(QNetworkReply * reply);
};
#endif // ACCESO_H
