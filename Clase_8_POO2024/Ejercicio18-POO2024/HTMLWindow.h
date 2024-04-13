#ifndef HTMLWINDOW_H
#define HTMLWINDOW_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class HTMLWindow : public QWidget
{
    Q_OBJECT
public:
    explicit HTMLWindow(QWidget *parent = nullptr);

private slots:
    void fetchHTML();

private:
    QTextEdit *htmlTextEdit;
    QLineEdit *urlLineEdit;
    QNetworkAccessManager *networkManager;
};

#endif // HTMLWINDOW_H
