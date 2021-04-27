#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     connect(timer, &QTimer::timeout, this, &MainWindow::UpdateGraphics);
     timer->setInterval(16);

     game->AddFpsTimer(timer);
     game->AddUiComponents(ui->scoreLcd, ui->livesLcd, ui->levelLcd);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{

    QPainter painter(this);

    QBrush brush;
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    painter.setPen(Qt::PenStyle::NoPen);
    painter.setBrush(brush);

    game->Draw(&painter, &brush);
}

void MainWindow::UpdateGraphics()
{
    if(this->isHidden() == true)
    {
        game->ClearGameObjects();
        game->PauseGame();
        return;
    }

    game->Update(); // Update game objects before draw
    this->update();// ui update
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    game->KeyBoardInput(event, PRESS);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    game->KeyBoardInput(event, RELEASE);
}

