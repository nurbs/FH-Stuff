#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

    private:
        char emap[256];
        char dmap[256];

    public:
        MainWindow(QWidget *parent=0);
        ~MainWindow();

        QByteArray encrypt(QByteArray&, char*);

    public slots:
        void on_editClearText_textChanged();
        void on_editCryptText_textChanged();
};

#endif // MAINWINDOW_H
