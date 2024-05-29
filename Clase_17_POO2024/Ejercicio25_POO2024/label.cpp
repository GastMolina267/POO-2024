#include "label.h"

Label::Label(const QString& text, QWidget* parent)
    : QLabel(parent)
{
    this->setText(text);
}

Label::~Label() { }

void Label::mousePressEvent(QMouseEvent *event) {
    qDebug() << "Click en Label";
    emit signal_clicked();
}
