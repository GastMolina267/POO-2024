#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMessageBox>

class Editor : public QWidget
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = nullptr);

private slots:
    void search();
    void saveToFile();

signals:
    void saveRequested(const QString &fileName, const QString &content);

private:
    QTextEdit *textEdit;
    QLineEdit *searchLineEdit;
    QPushButton *searchButton;
    QPushButton *saveButton;
    QLabel *resultLabel;
    QLineEdit *fileNameLineEdit;
};

#endif // EDITOR_H
