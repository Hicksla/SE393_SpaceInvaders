#include "start.h"
#include "ui_start.h"
#include <QProcess>


Start::Start(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
}

Start::~Start()
{
    delete ui;
}

void Start::on_singlePlayerBtn_clicked()
{
    gameWindow = new MainWindow();
    gameWindow->game->isMultiplayer = false;
    gameWindow->show();

//    QProcess process;
//    process.startDetached("C:\\Users\\Brayton\\Desktop\\release\\SpaceInvaders.exe");
}

void Start::on_multiplayerBtn_clicked()
{
    gameWindow = new MainWindow();
    gameWindow->game->isMultiplayer = true;
    gameWindow->show();
    gameWindow->game->JoinGame(ui->gameStringTxt->text());
}

void Start::on_Exit_clicked()
{
    QApplication::exit();
}
