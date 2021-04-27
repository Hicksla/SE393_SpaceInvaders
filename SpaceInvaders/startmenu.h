#ifndef STARTMENU_H
#define STARTMENU_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class StartMenu;
}

class StartMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartMenu(QWidget *parent = nullptr);
    ~StartMenu();

    MainWindow *game;

private slots:
    void on_startBtn_clicked();

private:
    Ui::StartMenu *ui;
};

#endif // STARTMENU_H
