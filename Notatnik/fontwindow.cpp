#include "fontwindow.h"
#include "ui_fontwindow.h"
#include <QObject>

FontWindow::FontWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FontWindow)
{
    ui->setupUi(this);
    font.defaultFamily();
    font.setPointSize(12);

    ui->textEdit->setFont(font);
    ui->textEdit->setText("XxYyZz");
    ui->textEdit->setAlignment(Qt::AlignCenter);
    ui->boldCheckBox->setChecked(false);
    ui->itallicCheckBox->setChecked(false);

    selectedText = NULL;

}

FontWindow::~FontWindow()
{
    delete ui;
}

void FontWindow::on_fontTextEdit_textChanged()
{
    fontSize = ui->fontTextEdit->toPlainText();
    font.setPointSize(fontSize.toInt());
    ui->textEdit->setFont(font);
}

void FontWindow::on_pushButton_clicked()
{
    selectedText = Notatnik::static_selectedText;

    if (!ui->fontTextEdit->toPlainText().isEmpty())
    selectedText = "<font size=" + fontSize + ">" + selectedText + "</font>";

    if (ui->boldCheckBox->isChecked() && !selectedText.contains("<b>"))
    {
        selectedText = "<b>" + selectedText + "</b>";
    }
    if (ui->itallicCheckBox->isChecked() && !selectedText.contains("<i>"))
    {
        selectedText = "<i>" + selectedText + "</i>";
    }
    Notatnik::static_cursor.insertText(selectedText);
    this->close();
}



void FontWindow::on_boldCheckBox_stateChanged(int arg1)
{
    if (ui->boldCheckBox->isChecked())
    {
        font.setBold(true);
        ui->textEdit->setFont(font);
    }

    if(!ui->boldCheckBox->isChecked())
    {
        font.setBold(false);
        ui->textEdit->setFont(font);
    }
}

void FontWindow::on_boldCheckBox_clicked()
{
        //dummy function
}



void FontWindow::on_itallicCheckBox_stateChanged(int arg1)
{
    if (ui->itallicCheckBox->isChecked())
    {
        font.setItalic(true);
        ui->textEdit->setFont(font);
    }

    if(!ui->itallicCheckBox->isChecked())
    {
        font.setItalic(false);
        ui->textEdit->setFont(font);
    }
}

