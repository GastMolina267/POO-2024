#include "HTMLWindow.h"
#include <QUrl>

HTMLWindow::HTMLWindow(QWidget *parent) : QWidget(parent)
{
    htmlTextEdit = new QTextEdit;
    urlLineEdit = new QLineEdit;
    urlLineEdit->setPlaceholderText("Enter URL and press Enter");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(htmlTextEdit);
    layout->addWidget(urlLineEdit);

    networkManager = new QNetworkAccessManager(this);
    connect(urlLineEdit, &QLineEdit::returnPressed, this, &HTMLWindow::fetchHTML);
}

void HTMLWindow::fetchHTML()
{
    QString urlString = urlLineEdit->text();
    QUrl url(urlString);
    if (!url.isValid()) {
        htmlTextEdit->setText("Invalid URL");
        return;
    }

    QNetworkRequest request(url);
    QNetworkReply *reply = networkManager->get(request);
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() != QNetworkReply::NoError) {
            htmlTextEdit->setText("Error fetching URL: " + reply->errorString());
            return;
        }

        QByteArray htmlData = reply->readAll();
        htmlTextEdit->setPlainText(htmlData);
        reply->deleteLater();
    });
}
