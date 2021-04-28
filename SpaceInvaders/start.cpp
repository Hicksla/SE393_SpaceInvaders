#include "start.h"
#include "ui_start.h"


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
    gameWindow->show();
    gameWindow->game->JoinGame(ui->gameStringTxt->text());
}
