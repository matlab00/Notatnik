#include "viewwindow.h"
#include "ui_viewwindow.h"

ViewWindow::ViewWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->textEdit->setText(Notatnik::static_textEditContent);
}

ViewWindow::~ViewWindow()
{
    delete ui;
}
