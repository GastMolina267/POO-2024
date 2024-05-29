#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QString>
#include <QVariant>
#include <QDebug>

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
    QNetworkAccessManager* manager;

private slots:
    void slot_verificar_usuario();
    void slot_cerrar_programa();
    void slot_verificar_usuario(QNetworkReply *);
};
#endif // LOGIN_H
