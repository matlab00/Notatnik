#ifndef NOTATNIK_H
#define NOTATNIK_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Notatnik; }
QT_END_NAMESPACE

class Notatnik : public QMainWindow
{
    Q_OBJECT

public:
    Notatnik(QWidget *parent = nullptr);
    ~Notatnik();
    QString filePath;

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

private:
    Ui::Notatnik *ui;
};
#endif // NOTATNIK_H
