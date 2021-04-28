
#include "start.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Start s;
    s.show();

    MainWindow m;
    s.gameWindow = &m;
    return a.exec();
}
