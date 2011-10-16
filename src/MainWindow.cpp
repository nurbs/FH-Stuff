#include "MainWindow.h"
#include <stdio.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    unsigned char i;
    setupUi(this);

    for(i=255;i--;)
    {
        emap[i] = i;
        dmap[i] = i;
    }
}

MainWindow::~MainWindow()
{
}

QByteArray MainWindow::encrypt(QByteArray &src, char *map)
{
    char *in, *out;
    int len;
    int i;

    len = src.size();
    in = src.data();

    QByteArray dst(len, 0);
    out = dst.data();

    for(i=len;i--;)
    {
        (*out) = map[(*in)];
        out++; in++;
    }

    return dst;
}

void MainWindow::on_editClearText_textChanged()
{
    printf("A");
    if(!editClearText->document()->isModified()) return;

    QByteArray orig = editClearText->document()->toPlainText().toAscii();
    QByteArray res = this->encrypt(orig, (char*) emap);
    editCryptText->document()->setPlainText(res);
    editCryptText->document()->setModified(false);
}

void MainWindow::on_editCryptText_textChanged()
{
    printf("B");
    if(!editCryptText->document()->isModified()) return;

    QByteArray orig = editCryptText->document()->toPlainText().toAscii();
    QByteArray res = this->encrypt(orig, (char*) dmap);
    editClearText->document()->setPlainText(res);
    editClearText->document()->setModified(false);
}

