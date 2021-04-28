#include "start.h"
#include "ui_start.h"
#include <QProcess>
#include "helpmenu.h"


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
    gameWindow->game->ConnectToServer(QHostAddress("127.0.0.1"), 8006);
    gameWindow->show();
    gameWindow->game->JoinGame(ui->gameStringTxt->text());
}

void Start::on_Exit_clicked()
{
    QApplication::exit();
}

void Start::on_help_btn_clicked()
{
    HelpMenu *help = new HelpMenu();
    help->show();
}
