#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include "admindb.h"
#include "linea.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QWidget
{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = nullptr);
    ~Principal();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Principal *ui;
    AdminDB *db;
    Linea *linea;

    void cargarDatos();
};

#endif // PRINCIPAL_H
