#include "startmenu.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartMenu s;
    s.show();

    MainWindow m;
    s.game = &m;
    return a.exec();
}
