#ifndef REGISTRO_H
#define REGISTRO_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QImage>
#include <QPainter>
#include <admindb.h>

namespace Ui {
class Registro;
}

class Registro : public QWidget
{
    Q_OBJECT

public:
    explicit Registro(QWidget *parent = nullptr);
    ~Registro();

private:
    Ui::Registro *ui;
    AdminDB* adminDB;

    QNetworkAccessManager* manager;
    QImage im;

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void slot_registrarUsuario();
    void slot_go_to_login();
    void slot_descargaFinalizada(QNetworkReply* reply);

signals:
    void signal_go_to_login();
};

#endif // REGISTRO_H
