#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QImage>
#include <QPainter>
#include "admindb.h"

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
    AdminDB* adminDB;

    QNetworkAccessManager* manager;
    QImage im;

private slots:
    void slot_verificar_usuario();
    void slot_registrarse();
    void slot_descargaFinalizada(QNetworkReply* reply);

protected:
    void paintEvent(QPaintEvent *event) override;

signals:
    void signal_logging_in();
    void signal_go_to_registry();
};
#endif // LOGIN_H
