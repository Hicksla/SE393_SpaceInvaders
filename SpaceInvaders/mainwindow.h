#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>

#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void paintEvent(QPaintEvent *event);

    void UpdateGraphics();

    Game *game = new Game();

    QTimer *timer = new QTimer(this);

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
