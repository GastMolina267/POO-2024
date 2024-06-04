#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QImage>
#include <QPainter>

#include <admindb.h>
#include <form.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Login;
}
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    static Login& getInstance(); // Método para obtener la instancia única

private:
    static Login* instance; // Cambio: instancia única de Login
    Ui::Login *ui;
    AdminDB* adminDB;
    Form* form;

    QNetworkAccessManager* manager;
    QImage im;

    int blockCheck;

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void slot_verificar_usuario();
    void slot_descargaFinalizada(QNetworkReply* reply);
};
#endif // LOGIN_H
