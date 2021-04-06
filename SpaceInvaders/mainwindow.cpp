#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     connect(timer, &QTimer::timeout, this, &MainWindow::Update);

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

    game->Update(&painter);
}

void MainWindow::Update()
{
    this->Update();
}
