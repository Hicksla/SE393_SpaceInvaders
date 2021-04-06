#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     connect(timer, &QTimer::timeout, this, this->UpdateGraphics);
     timer->setInterval(33);
     timer->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{

    QPainter painter(this);

    QBrush brush;

    brush.setColor(QColor(255,0,0));
    brush.setStyle(Qt::BrushStyle::SolidPattern);

    painter.setPen(Qt::PenStyle::NoPen);
    painter.setBrush(brush);

    game->Draw(&painter);
}

void MainWindow::UpdateGraphics()
{
    game->Update(); // Update game objects before draw
    this->update();// ui update
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    game->KeyBoardInput(event);
}
