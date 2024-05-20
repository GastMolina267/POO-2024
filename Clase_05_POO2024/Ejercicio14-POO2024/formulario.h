#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QRandomGenerator>
#include <QMessageBox>

class Formulario : public QWidget
{
    Q_OBJECT

public:
    Formulario(QWidget *parent = nullptr);

signals:
    void dataEntered();

private slots:
    void saveData();

private:
    QLabel *nombreLabel;
    QLabel *apellidoLabel;
    QLabel *claveLabel;
    QLabel *cedulaLabel;
    QLineEdit *nombreLineEdit;
    QLineEdit *apellidoLineEdit;
    QLineEdit *claveLineEdit;
    QLineEdit *cedulaLineEdit;
    QPushButton *guardarButton;
    QGridLayout *layout;
};

#endif // FORMULARIO_H


