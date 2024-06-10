// ventana.cpp

#include <ventana.h>

Ventana::Ventana() {
    QWidget::setWindowTitle("Bola");

    // QScreen *screen = QGuiApplication::primaryScreen();
    // QRect screenGeometry = screen->geometry();
    // QWidget::setFixedWidth(screenGeometry.width());
    // QWidget::setFixedHeight(screenGeometry.height());

    QWidget::setFixedSize(1280, 800);

    QString url = R"(C:/Users/marin/OneDrive/Imágenes/Documentos/google.png)";
    QPixmap img(url);
    lImage = new QLabel(this);
    lImage->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    lImage->setScaledContents(true);
    lImage->setMaximumSize(100, 100);
    lImage->setMinimumSize(100, 100);
    lImage->setPixmap(img);

    lDiametro = new QLabel("Diametro:");
    lVelocidad = new QLabel("Velocidad:");

    leDiametro = new QLineEdit();
    leDiametro->setPlaceholderText("Nuevo Diametro");
    leVelocidad = new QLineEdit();
    leVelocidad->setPlaceholderText("Nueva Velocidad");

    pbActualizar = new QPushButton("Actualizar");

    gbCaja = new QGroupBox();
    boxLayout = new QVBoxLayout();

    gbCaja->setTitle("Características de la Bola");

    boxLayout->addWidget(lDiametro);
    boxLayout->addWidget(leDiametro);
    boxLayout->addWidget(lVelocidad);
    boxLayout->addWidget(leVelocidad);
    boxLayout->addWidget(pbActualizar);

    gbCaja->setMaximumSize(200, 200);
    gbCaja->setLayout(boxLayout);


    layout = new QGridLayout();
    layout->addWidget(gbCaja, 0, 0, 1, 1, Qt::AlignLeft | Qt::AlignTop);

    layout->addWidget(lImage, 1, 0, 1, 1, Qt::AlignCenter | Qt::AlignTop);

    this->setLayout(layout);

    timer = new QTimer(this);
    timer->setSingleShot(false);

    connect(pbActualizar, SIGNAL(clicked(bool)), this, SLOT(slot_actualizar_bola()));
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&Ventana::slot_mover_bola));
    timer->start(velocidad);
}

void Ventana::slot_actualizar_bola() {
    if (leDiametro->text().isEmpty() == 0 || leVelocidad->text().isEmpty() == 0) {
        qDebug() << "Alguno de leDiametro o leVelocidad no estaba en NULO";
        if (leDiametro->text().isEmpty() == 0 && leDiametro->text().toInt() >= 1) {
            qDebug() << "Diametro Actualizado";
            diametro = leDiametro->text().toInt();
            lImage->setMaximumSize(diametro, diametro);
            lImage->setMinimumSize(diametro, diametro);
        }

        if (leVelocidad->text().isEmpty() == 0 && leVelocidad->text().toInt() >= 1) {
            qDebug() << "Velocidad Actualizada";
            velocidad = leVelocidad->text().toInt();
            velocidad = velocidad * 1000;
            timer->setInterval(velocidad);
        }
    }
}

void Ventana::slot_mover_bola() {
    if (pos == 0) {
        layout->removeWidget(lImage);
        layout->addWidget(lImage, 1, 0, 1, 1, Qt::AlignRight | Qt::AlignTop);
        pos = 1;
    } else if (pos == 1) {
        layout->removeWidget(lImage);
        layout->addWidget(lImage, 1, 0, 1, 1, Qt::AlignLeft | Qt::AlignTop);
        pos = -1;
    } else {
        layout->removeWidget(lImage);
        layout->addWidget(lImage, 1, 0, 1, 1, Qt::AlignRight | Qt::AlignTop);
        pos = 1;
    }
    this->setLayout(layout);
}
