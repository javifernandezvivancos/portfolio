#include <QtGui/QApplication>
#include "mainwindow.h"

MainWindow *w= NULL;
QApplication *a= NULL;

int main(int argc, char *argv[])
{
    a= new QApplication(argc, argv);
    w= new MainWindow();
    w->show();
    int res= a->exec();
    delete w;
    delete a;
    return res;
}
