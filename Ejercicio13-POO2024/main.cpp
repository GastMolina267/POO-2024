#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

class Ventana : public QWidget {
public:
    Ventana(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("Volumen");
        resize(300, 50);

        spinBox = new QSpinBox;
        slider = new QSlider(Qt::Horizontal);
        spinBox->setRange(0, 100);
        slider->setRange(0, 100);

        connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
        connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        connect(slider, SIGNAL(valueChanged(int)), this, SLOT(setWindowTitleFromSlider(int)));

        spinBox->setValue(15);

        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(spinBox);
        layout->addWidget(slider);
        setLayout(layout);
    }

public slots:
    void setWindowTitleFromSlider(int value) {
        setWindowTitle(QString::number(value));
    }

private:
    QSpinBox *spinBox;
    QSlider *slider;
};

int main(int argc, char** argv) {
    QApplication a(argc, argv);
    Ventana ventana;
    ventana.show();
    return a.exec();
}

