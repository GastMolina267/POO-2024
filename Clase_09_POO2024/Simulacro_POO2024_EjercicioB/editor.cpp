#include "editor.h"

Editor::Editor(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    textEdit = new QTextEdit(this);

    searchLineEdit = new QLineEdit(this);
    searchLineEdit->setPlaceholderText("Texto a buscar");
    saveButton = new QPushButton("Guardar");
    searchButton = new QPushButton("Buscar", this);

    resultLabel = new QLabel(this);

    layout->addWidget(textEdit);
    layout->addWidget(searchLineEdit);
    layout->addWidget(searchButton);
    layout->addWidget(resultLabel);

    layout->addWidget(fileNameLineEdit);
    layout->addWidget(saveButton);

    connect(searchButton, &QPushButton::clicked, this, &Editor::search);
    connect(saveButton, &QPushButton::clicked, this, &Editor::saveToFile);
}

void Editor::search()
{
    QString searchText = searchLineEdit->text();
    QString text = textEdit->toPlainText();

    int count = 0;
    int index = text.indexOf(searchText);

    while (index != -1)
    {
        count++;
        index = text.indexOf(searchText, index + 1);
    }

    resultLabel->setText(QString::number(count) + " ocurrencias.");
}

void Editor::saveToFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Guardar archivo"), "", tr("Archivos de texto (*.txt)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("No se pudo abrir el archivo para escribir."));
        return;
    }

    QTextStream out(&file);
    out << textEdit->toPlainText();

    file.close();

    QMessageBox::information(this, tr("Guardar"), tr("El archivo se ha guardado exitosamente."));
}
