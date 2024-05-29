#include "htmlparser.h"
#include "ui_htmlparser.h"
#include <QMessageBox>

Parser::Parser(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Parser)
    , css_files_downloaded(0)
    , js_files_downloaded(0)
{
    ui->setupUi(this);

    connect(ui->pbBuscar, SIGNAL(clicked(bool)), this, SLOT(slot_descargar_html()));
    connect(this, SIGNAL(signal_HTML_descargado()), this, SLOT(slot_descargar_archivos()));
    connect(ui->pbDibujar, SIGNAL(clicked(bool)), this, SLOT(slot_QDialog_img_disco()));
    connect(ui->pbEstablecer, SIGNAL(clicked(bool)), this, SLOT(slot_QDialo_direccion()));
}

Parser::~Parser()
{
    delete ui;
}

void Parser::getRecursos() {

    qDebug() << "Consiguiendo Recursos...";
    qDebug() << "HTML es Vacio?" << html_storage.isEmpty();

    css_list = new QStringList();

    QRegularExpression cssRegex("<link\\s+.*?href=\"(.*?)\".*?>");
    QRegularExpressionMatchIterator cssMatches = cssRegex.globalMatch(html_storage);
    while(cssMatches.hasNext()) {
        qDebug() << "Adentro de CSS";
        QRegularExpressionMatch match = cssMatches.next();
        QString cssURL = match.captured(1);
        css_list->push_back(cssURL);
    }

    qDebug() << "CSS obtenido";

    js_list = new QStringList();

    QRegularExpression jsRegex("<script\\s+.*?src=\"(.*?)\".*?>");
    QRegularExpressionMatchIterator jsMatches = jsRegex.globalMatch(html_storage);
    while(jsMatches.hasNext()) {
        qDebug() << "Adentro de JS";
        QRegularExpressionMatch match = jsMatches.next();
        QString jsURL = match.captured(1);
        js_list->push_back(jsURL);
    }

    qDebug() << "JS obtenido";

    img_list = new QStringList();

    QRegularExpression imgRegex("<img\\s+.*?src=\"(.*?)\".*?>");
    QRegularExpressionMatchIterator imgMatches = imgRegex.globalMatch(html_storage);
    while(imgMatches.hasNext()) {
        qDebug() << "Adentro de IMG";
        QRegularExpressionMatch match = imgMatches.next();
        QString imgURL = match.captured(1);
        img_list->push_back(imgURL);
    }

    qDebug() << "IMG obtenido";
    qDebug() << "Todos los Recursos Conseguidos...";
    QMessageBox::information(this, "Conseguido", "Todos los recursos obtenidos.");
}

void Parser::slot_descargar_html() {
    if (!(ui->leURL->text().isEmpty()) && !(ui->leGuardado->text().isEmpty())) {
        qDebug() << "Descargando HTML...";

        filePath = ui->leGuardado->text();
        filePath += "/";
        qDebug() << "Direccion de Guardado:" << filePath;

        manager = new QNetworkAccessManager(this);
        connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_html_descargado(QNetworkReply * )));
        QNetworkRequest request(QUrl(ui->leURL->text()));
        manager->get(request);
    } else if(ui->leURL->text().isEmpty()){
        qDebug() << "Falta la URL a analizar. Vuelva a Intentar";
        QMessageBox::warning(this, "Error", "Falta la URL. Vuelve a intentar.");
    }else {
        qDebug() << "Falta el Directorio de Guardado. Vuelva a Intentar";
        QMessageBox::warning(this, "Error", "Falta el Directorio de Guardado. Vuelve a intentar.");
    }
}

void Parser::slot_descargar_archivos() {
    getRecursos();

    qDebug() << "A punto de ponerme a descargar todos los Recursos...";
    QMessageBox::information(this, "Iniciando", "Empezando la descarga de Recursos");

    css_list_pos = 0;
    connect(this, SIGNAL(signal_iniciar_descarga_css()), this, SLOT(slot_descargar_CSS()));
    emit signal_iniciar_descarga_css();

    js_list_pos = 0;
    connect(this, SIGNAL(signal_iniciar_descarga_js()), this, SLOT(slot_descargar_JS()));
    emit signal_iniciar_descarga_js();

    img_list_pos = 0;
    connect(this, SIGNAL(signal_iniciar_descarga_img()), this, SLOT(slot_descargar_IMG()));
    emit signal_iniciar_descarga_img();

    qDebug() << "Finalizado!";
    QMessageBox::information(this, "Finalizado", "Descarga de archivos finalizada");
}

void Parser::slot_html_descargado(QNetworkReply* reply) {
    qDebug() << "Guardando HTML y Emitiendo SIGNAL...";
    html_storage = reply->readAll();

    QString fileName = "/txt.html";
    QFile file(filePath + fileName);
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "Se ha creado el Archivo HTML";
        QMessageBox::information(this, "Archivo HTML creado", "Se ha creado el Archivo " +fileName+ ".");
    }
    file.write(html_storage.toUtf8());

    ui->teHTML->setText(html_storage);
    emit signal_HTML_descargado();
}

void Parser::slot_descargar_CSS() {
    if (css_list->isEmpty() || css_list_pos == css_list->size()) {
        if (css_files_downloaded == css_list->size()) {
            QMessageBox::information(this, "Archivos CSS creados", "Se han creado todos los archivos CSS.");
        }
        return;
    } else {
        manager = new QNetworkAccessManager();
        connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_css_descargado(QNetworkReply *)));

        qDebug() << "Descargando CSS... Estoy en la Posicion" << css_list_pos << "| Size de Lista es:" << css_list->size();
        qDebug() << "URL en la Posicion Actual:" << css_list->at(css_list_pos);
        QNetworkRequest request(QUrl(css_list->at(css_list_pos)));
        manager->get(request);
    }
}

void Parser::slot_descargar_JS() {
    if (js_list->isEmpty() || js_list_pos == js_list->size()) {
        if (js_files_downloaded == js_list->size()) {
            QMessageBox::information(this, "Archivos JS creados", "Se han creado todos los archivos JS.");
        }
        return;
    } else {
        manager = new QNetworkAccessManager();
        connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_js_descargado(QNetworkReply *)));

        qDebug() << "Descargando JS... Estoy en la Posicion" << js_list_pos << "| Size de Lista es:" << js_list->size();
        qDebug() << "URL en la Posicion Actual:" << js_list->at(js_list_pos);
        QNetworkRequest request(QUrl(js_list->at(js_list_pos)));
        manager->get(request);
    }
}

void Parser::slot_descargar_IMG() {
    if (img_list->isEmpty() || img_list_pos == img_list->size()) {
        return;
    } else {
        manager = new QNetworkAccessManager();
        connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_img_descargado(QNetworkReply *)));

        qDebug() << "Descargando IMG... Estoy en la Posicion" << img_list_pos << "| Size de Lista es:" << img_list->size();
        qDebug() << "URL en la Posicion Actual:" << img_list->at(img_list_pos);
        QNetworkRequest request(QUrl(img_list->at(img_list_pos)));
        manager->get(request);

        connect(this, SIGNAL(signal_IMG_descargado()), this, SLOT(slot_descargar_IMG()));
        img_list_pos++;
    }
}

void Parser::slot_css_descargado(QNetworkReply* reply) {
    qDebug() << "Descargando Archivo CSS y Guardando...";
    QString temp_storage = reply->readAll();

    QString fileName = QString::number(css_list_pos);
    fileName += ".css";
    qDebug() << "Filename del CSS:" << fileName;

    QFile file(filePath + fileName);
    if (!file.open(QIODevice::ReadWrite)) {
        qDebug() << "No se pudo crear un Archivo CSS con el Nombre" << fileName;
    }
    file.write(temp_storage.toUtf8());

    css_files_downloaded++;
    css_list_pos++;
    if (css_files_downloaded == css_list->size()) {
        QMessageBox::information(this, "Archivos CSS creados", "Se han descargado TODOS los archivos CSS.");
    }
    slot_descargar_CSS();
}

void Parser::slot_js_descargado(QNetworkReply* reply) {
    qDebug() << "Descargando Archivo JS y Guardando...";
    QString temp_storage = reply->readAll();

    QString fileName = QString::number(js_list_pos);
    fileName += ".js";
    qDebug() << "Filename del JS:" << fileName;

    QFile file(filePath + fileName);
    if (!file.open(QIODevice::ReadWrite)) {
        qDebug() << "No se pudo crear un Archivo JS con el Nombre" << fileName;
    }
    file.write(temp_storage.toUtf8());

    js_files_downloaded++;
    js_list_pos++;
    if (js_files_downloaded == js_list->size()) {
        QMessageBox::information(this, "Archivos JS creados", "Se han descargado TODOS los archivos JS.");
    }
    slot_descargar_JS();
}

void Parser::slot_img_descargado(QNetworkReply* reply) {
    qDebug() << "Descargando Archivo IMG y Guardando...";
    QImage temp_storage = QImage::fromData(reply->readAll());

    QString fileName = QString::number(img_list_pos);
    fileName += "img.png";
    qDebug() << "Filename de la IMG:" << fileName;

    QString fullFileName = filePath + fileName;
    QFile file(filePath + fileName);
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "Se ha creado un Archivo IMG con el Nombre" << fileName;
        QMessageBox::information(this, "Imágen creada", "Se ha creado una imágen con el nombre " +fileName+ ".");
    }
    temp_storage.save(fullFileName);
    emit signal_IMG_descargado();
}

void Parser::slot_QDialog_img_disco() {
    QFileDialog dialog(this, "Abrir");
    dialog.setNameFilter("Imagen (*.png *.jpg)");
    connect(&dialog, SIGNAL(fileSelected(QString)), this, SLOT(slot_imagen_obtenida(QString)));
    dialog.exec();
}

void Parser::slot_QDialo_direccion() {
    QString dir = QFileDialog::getExistingDirectory(this, "Seleccionar Directorio", "",
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!dir.isEmpty()) {
        filePath = dir;
        qDebug() << "Directorio seleccionado para guardar archivos:" << filePath;
        ui->leGuardado->setText(filePath);
    } else {
        qDebug() << "No se seleccionó ningún directorio.";
    }
}


void Parser::slot_imagen_obtenida(QString str) {
    QFile file(str);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "No se pudo abrir el Archivo";
        QMessageBox::warning(this, "Apertura fallida", "Error.No se pudo abrir un archivo.");
        return;
    }

    QByteArray imageData = file.readAll();

    img.loadFromData(imageData);
    this->repaint();
}

void Parser::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if(!img.isNull()) {
        painter.drawImage(0, 0, img.scaled(this->size()));
    }
}
