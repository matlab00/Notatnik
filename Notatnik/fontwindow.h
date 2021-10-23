#ifndef FONTWINDOW_H
#define FONTWINDOW_H

#include <QDialog>
#include <QMainWindow>
#include <QObject>
#include <QTextCursor>
#include "notatnik.h"

namespace Ui {
class FontWindow;
}

class FontWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FontWindow(QWidget *parent = nullptr);
    ~FontWindow();

private slots:
    void on_pushButton_clicked();

    void on_fontTextEdit_textChanged();

    void on_boldCheckBox_stateChanged(int arg1);

    void on_boldCheckBox_clicked();

    void on_itallicCheckBox_stateChanged(int arg1);

signals:
    void transmit(QString text);

private:
    Ui::FontWindow *ui;
    QTextCursor cursor;
    QString selectedText, fontSize;
    QFont font;
};

#endif // FONTWINDOW_H
