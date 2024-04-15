#ifndef BARRA_H
#define BARRA_H

#include <QWidget>
#include <QProgressBar>
#include <QPushButton>
#include <QLineEdit>

class ProgressBarEx : public QWidget {
    Q_OBJECT

public:
    ProgressBarEx(QWidget *parent = nullptr);

public slots:
    void startDownload();
    void setPorcentaje(int porcentaje);

private:
    int progress;
    QProgressBar *pbar;
    QLineEdit *lineEditURL;
    QPushButton *downloadButton;
    static const int MAX_VALUE = 100;

    void updateBar();
};

#endif // BARRA_H


