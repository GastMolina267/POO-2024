#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QImage>
#include <QPainter>

#include <formulario.h>
#include <weather.h>
#include <admindb.h>
#include <registro.h>

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

private:
    Ui::Login *ui;
    Formulario* form;
    AdminDB* adminDB;
    Registro* registro;

    QNetworkAccessManager* manager;
    Weather* weather;
    QImage im;

    int blockCheck;

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void slot_verificar_usuario();
    void slot_esconderTemperatura();
    void slot_registro();
    void slot_actualizarTemperatura(const QString &temperatura);
    void slot_descargaFinalizada(QNetworkReply* reply);
};
#endif // LOGIN_H
