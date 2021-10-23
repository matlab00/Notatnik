#include "notatnik.h"
#include "./ui_notatnik.h"
#include <QFileDialog>
#include <QTextCursor>
#include <QTextStream>
#include <QFile>


Notatnik::Notatnik(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notatnik)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

QString Notatnik::static_textEditContent;
QString Notatnik::static_selectedText;
QTextCursor Notatnik::static_cursor;

Notatnik::~Notatnik()
{
    delete ui;
}


void Notatnik::on_actionNowy_triggered()
{
    filePath = NULL;
    ui->textEdit->setText(NULL);
}

void Notatnik::on_actionOtworz_triggered()
{
    filePath = QFileDialog::getOpenFileName(this,"Otwieranie");
    QFile file(filePath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    QString fileText = in.readAll();
    ui->textEdit->setText(fileText);
    file.close();
}

void Notatnik::on_actionZapisz_triggered()
{
    QFile file(filePath);

    if (filePath.isEmpty()) {
        on_actionZapisz_jako_triggered();
    }

    file.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream out(&file);
    QString fileText = ui->textEdit->toPlainText();
    out << fileText;
    file.close();
}

void Notatnik::on_actionZapisz_jako_triggered()
{
    filePath = QFileDialog::getSaveFileName(this,"Zapisywanie","","*.txt");
    QFile file(filePath);
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream out(&file);
    QString fileText = ui->textEdit->toPlainText();
    out << fileText;
    file.close();
}

void Notatnik::on_actionZakoncz_triggered()
{
    QMainWindow::close();
}

void Notatnik::on_actionCofnij_triggered()
{
    ui->textEdit->undo();
}

void Notatnik::on_actionWytnij_triggered()
{
    ui->textEdit->cut();
}



void Notatnik::on_actionKopiuj_triggered()
{
    ui->textEdit->copy();
}


void Notatnik::on_actionWklej_triggered()
{
    ui->textEdit->paste();
}


void Notatnik::on_actionUsun_triggered()
{
    ui->textEdit->textCursor().insertText(NULL);
}


void Notatnik::on_actionCzcionka_triggered()
{
    Notatnik::static_cursor = ui->textEdit->textCursor();
    Notatnik::static_selectedText = ui->textEdit->textCursor().selectedText();

    FontWindow fontWindow;
    fontWindow.setModal(true);
    fontWindow.exec();
}

void Notatnik::on_actionPodglad_triggered()
{
    Notatnik::static_textEditContent = ui->textEdit->toPlainText();

    ViewWindow viewWindow;
    viewWindow.setModal(true);
    viewWindow.exec();
}



