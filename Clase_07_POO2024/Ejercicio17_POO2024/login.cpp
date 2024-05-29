#include "login.h"


Login::Login() {
    // qInfo() << QSslSocket::sslLibraryBuildVersionString(); Obtener Info de la Librería de OpenSSL instalada en el Sistema.
    // qInfo() << QSslSocket::sslLibraryVersionString(); Obtener Info de la Librería de OpenSSL instalada en el Sistema.
    // qDebug() << QSslSocket::supportsSsl(); Obtener Info de si soporta OpenSSL la instalación actual.

    lBienvenido = new QLabel("Bienvenido");
    lBienvenido->setAlignment(Qt::AlignCenter);
    QFont fontBienvenido = lBienvenido->font();
    fontBienvenido.setBold(true);
    fontBienvenido.setPointSize(12);
    lBienvenido->setFont(fontBienvenido);

    lUsuario = new QLabel("Usuario");
    lClave = new QLabel("Clave");
    leUsuario = new QLineEdit;
    leClave = new QLineEdit;
    leClave->setEchoMode( QLineEdit::Password );
    pbEntrar = new QPushButton("Entrar");

    layout = new QGridLayout;
    layout->addWidget(lBienvenido, 0, 0, 1, 3);
    layout->addWidget(lUsuario, 1, 0, 1, 1);
    layout->addWidget(lClave, 2, 0, 1, 1);
    layout->addWidget(leUsuario, 1, 1, 1, 2);
    layout->addWidget(leClave, 2, 1, 1, 2);
    layout->addWidget(pbEntrar, 3, 0, 1, 3);

    QObject::connect( pbEntrar, SIGNAL( clicked(bool) ), this , SLOT( slot_validarUsuario() ) );
    this->setLayout(layout);

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_descargaFinalizada(QNetworkReply * )));
    QNetworkRequest request(QUrl("https://media.geeksforgeeks.org/wp-content/uploads/20230426115225/computer-image-660.jpg"));
    manager->get(request);
}

void Login::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if(!im.isNull()) {
        painter.drawImage(0, 0, im.scaled(this->size()));
        QLabel* lURL = new QLabel("URL IMG: https://media.geeksforgeeks.org/wp-content/uploads/20230426115225/computer-image-660.jpg");
        lURL->setAlignment(Qt::AlignCenter);
        layout->addWidget(lURL, 6, 0, 1, 0);
    }
}

void Login::slot_descargaFinalizada(QNetworkReply* reply) {
    im = QImage::fromData(reply->readAll());
    this->repaint();
}

void Login::slot_validarUsuario() {
    if (leUsuario->text() == "admin" && leClave->text() == "1234") {
        Ventana* ventana_point = new Ventana;
        this->hide();
    } else {
        leClave->clear();
    }
}
