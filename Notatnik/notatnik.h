#ifndef NOTATNIK_H
#define NOTATNIK_H

#include <QMainWindow>
#include <QTextCursor>
#include "viewwindow.h"
#include "fontwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Notatnik; }
QT_END_NAMESPACE

class Notatnik : public QMainWindow
{
    Q_OBJECT

public:
    Notatnik(QWidget *parent = nullptr);
    ~Notatnik();
    static QString static_textEditContent;
    static QTextCursor static_cursor;
    static QString static_selectedText;

private slots:
    void on_actionNowy_triggered();

    void on_actionOtworz_triggered();

    void on_actionZapisz_triggered();

    void on_actionZapisz_jako_triggered();

    void on_actionZakoncz_triggered();

    void on_actionCofnij_triggered();

    void on_actionWytnij_triggered();

    void on_actionKopiuj_triggered();

    void on_actionWklej_triggered();

    void on_actionUsun_triggered();

    void on_actionCzcionka_triggered();

    void on_actionPodglad_triggered();

private:
    Ui::Notatnik *ui;
    QString filePath;
};
#endif // NOTATNIK_H
