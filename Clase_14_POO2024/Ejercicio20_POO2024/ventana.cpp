#include "ventana.h"
#include "ui_ventana.h"

#include <QGridLayout>
#include <QLabel>
#include <QFont>

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ventana)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_descargaFinalizada(QNetworkReply * )));
    QNetworkRequest request(QUrl("https://cdn.ipadizate.com/2020/05/LG-Q7-Stock-Wallpaper-1080x2160-02.jpg"));
    manager->get(request);

    ui->WidgetOne->setColor( Boton::ROJO );
    ui->WidgetTwo->setColor( Boton::AZUL );
    ui->WidgetThree->setColor( Boton::MAGENTA );
    ui->WidgetFour->setColor( Boton::AZUL );
    ui->WidgetFive->setColor( Boton::VERDE );

    QGridLayout* layout = new QGridLayout;
    QLabel* label = new QLabel;
    QFont* font = new QFont;

    font->setBold(true);
    font->setPointSize(12);

    connect(ui->WidgetOne, SIGNAL(signal_click()), this, SLOT(close()));
    label->setText("Mi Dentista");
    label->setFont(*font);
    layout->addWidget(label, 0, 0, 1, 1, Qt::AlignLeft);
    ui->WidgetOne->setLayout(layout);

    layout = new QGridLayout;
    label = new QLabel;

    connect(ui->WidgetTwo, SIGNAL(signal_click()), this, SLOT(close()));
    label->setText("Visitas");
    label->setFont(*font);
    layout->addWidget(label, 0, 0, 1, 1, Qt::AlignLeft);
    ui->WidgetTwo->setLayout(layout);

    layout = new QGridLayout;
    label = new QLabel;

    connect(ui->WidgetThree, SIGNAL(signal_click()), this, SLOT(close()));
    label->setText("Técnicas de Higiene");
    label->setFont(*font);
    layout->addWidget(label, 0, 0, 1, 1, Qt::AlignLeft);
    ui->WidgetThree->setLayout(layout);

    layout = new QGridLayout;
    label = new QLabel;

    connect(ui->WidgetFour, SIGNAL(signal_click()), this, SLOT(close()));
    label->setText("Mi Boca");
    label->setFont(*font);
    layout->addWidget(label, 0, 0, 1, 1, Qt::AlignLeft);
    ui->WidgetFour->setLayout(layout);

    layout = new QGridLayout;
    label = new QLabel;

    connect(ui->WidgetFive, SIGNAL(signal_click()), this, SLOT(close()));
    label->setText("Hora de Cepillarse");
    label->setFont(*font);
    layout->addWidget(label, 0, 0, 1, 1, Qt::AlignLeft);
    ui->WidgetFive->setLayout(layout);
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::slot_descargaFinalizada(QNetworkReply* reply) {
    im = QImage::fromData(reply->readAll());
    this->repaint();
    this->show();
}

void Ventana::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if(!im.isNull()) {
        painter.drawImage(0, 0, im.scaled(this->size()));
    }
}
