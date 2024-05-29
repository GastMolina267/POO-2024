#ifndef LABEL_H
#define LABEL_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QFont>
#include <QDebug>

class Label : public QLabel
{
    Q_OBJECT
public:
    explicit Label( const QString& text = "", QWidget* parent = nullptr );
    ~Label() override;

protected:
    void mousePressEvent(QMouseEvent* event) override;

signals:
    void signal_clicked();
};

#endif // LABEL_H
