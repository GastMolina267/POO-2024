// image.h

#ifndef IMAGE_H
#define IMAGE_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

#include <QPainter>
#include <QImage>
#include <QPaintEvent>

#include <QPixmap>
#include <QScreen>

class Image : public QWidget {
    Q_OBJECT
private:
    QLabel* lImage;
    QGridLayout* layout;

public:
    Image();
};

#endif // IMAGE_H
