// image.cpp

#include <image.h>

Image::Image() {
    layout = new QGridLayout;

    // QScreen *screen = QGuiApplication::primaryScreen();
    // QRect screenGeometry = screen->geometry();

    QWidget::setWindowTitle("Imágen");
    // QWidget::setFixedWidth(screenGeometry.width());
    // QWidget::setFixedHeight(screenGeometry.height());

    QString url = R"(C:/Users/marin/OneDrive/Imágenes/Documentos/google.png)";
    QPixmap img(url);

    lImage = new QLabel(this);
    lImage->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    lImage->setScaledContents(true);
    lImage->setMaximumSize(100, 100);
    lImage->setPixmap(img);

    lImage->setFrameShape(QFrame::Panel);
    lImage->setFrameShadow(QFrame::Sunken);
    lImage->setLineWidth(3);
    lImage->QFrame::setStyleSheet("QFrame { background-color:blue; }");

    layout->addWidget(lImage, 0, 1, 1, 1, Qt::AlignCenter);
    this->setLayout(layout);
    this->repaint();
}
