#ifndef START_H
#define START_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class Start;
}

class Start : public QMainWindow
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = nullptr);
    ~Start();

    MainWindow *gameWindow;

private slots:
    void on_singlePlayerBtn_clicked();

    void on_multiplayerBtn_clicked();

    void on_Exit_clicked();

private:
    Ui::Start *ui;
};

#endif // START_H
