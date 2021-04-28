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
    gameWindow->show();
    gameWindow->game->Init();
    gameWindow->game->playerManager->altPlayer->SetPlayerPosition(830,630);

//    QProcess process;
//    process.startDetached("C:\\Users\\Brayton\\Desktop\\release\\SpaceInvaders.exe");
}

void Start::on_multiplayerBtn_clicked()
{
    gameWindow = new MainWindow();
    gameWindow->game->ConnectToServer(QHostAddress("10.74.0.121"), 8006);
    gameWindow->show();
    gameWindow->game->JoinGame(ui->gameStringTxt->text());
}

void Start::on_Exit_clicked()
{
    QApplication::exit();
}
