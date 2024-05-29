#ifndef HTMLPARSER_H
#define HTMLPARSER_H

#include <QWidget>

#include <QRegularExpression>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QFile>
#include <QFileDialog>

#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui {
class Parser;
}
QT_END_NAMESPACE

class Parser : public QWidget
{
    Q_OBJECT

public:
    Parser(QWidget *parent = nullptr);
    ~Parser();

    void getRecursos();

private:
    Ui::Parser *ui;
    QNetworkAccessManager* manager;

    QString html_storage;
    QString filePath;

    int css_list_pos;
    QStringList* css_list;

    int js_list_pos;
    QStringList* js_list;

    int img_list_pos;
    QStringList* img_list;

    QImage img;

    int css_files_downloaded;
    int js_files_downloaded;

private slots:
    void slot_descargar_html();
    void slot_descargar_archivos();
    void slot_html_descargado(QNetworkReply* reply);

    void slot_descargar_CSS();
    void slot_descargar_JS();
    void slot_descargar_IMG();

    void slot_css_descargado(QNetworkReply* reply);
    void slot_js_descargado(QNetworkReply* reply);
    void slot_img_descargado(QNetworkReply* reply);

    void slot_QDialog_img_disco();
    void slot_QDialo_direccion();
    void slot_imagen_obtenida(QString);

protected:
    void paintEvent(QPaintEvent *event) override;

signals:
    void signal_HTML_descargado();

    void signal_iniciar_descarga_css();
    void signal_CSS_descargado();

    void signal_iniciar_descarga_js();
    void signal_JS_descargado();

    void signal_iniciar_descarga_img();
    void signal_IMG_descargado();
};
#endif // HTMLPARSER_H
