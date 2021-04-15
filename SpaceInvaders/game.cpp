#include "game.h"
#include <iostream>
#include <ctime>

Game::Game()
{
    collisionDetect = CollisionDetector();
    ConnectToServer(QHostAddress("127.0.0.1"), 8006);
    connect(netReadTimer, &QTimer::timeout, this, &Game::ReadData);
    netReadTimer->setInterval(50);
}
void Game::AddFpsTimer(QTimer *timer)
{
    virus1->load(":/images/virus1.png");
    virus2->load(":/images/virus2.png");
    bacteria->load(":/images/bacteria.png");
    whiteBloodCell->load(":/images/whitebloodcell.png");

    fpsTimer = timer;
    Init();
}

void Game::AddUiComponents(QLCDNumber *scoreUi, QLCDNumber *livesUi, QLCDNumber *levelUi)
{
    scoreLcd = scoreUi;
    livesLcd = livesUi;
    levelLcd = levelUi;
}

void Game::PauseGame()
{
    enemyManger->Pause();
    fpsTimer->stop();
}


void Game::Init()
{
    enemyManger->unloadEnemies();
    playerManager->bullets.clear();

    score = 0;
    lives = 3;
    level = 1;
//fix
    if (!playerManager->player->Alive)
    {
        //playerManager->LoadPlayer();
        playerManager->LoadPlayers();
    }

    enemyManger->loadEnemies();
    fpsTimer->start();
    enemyManger->Start();
}

void Game::Update()
{
    if (enemyManger->enemies.size() <= 0)
    {
        enemyManger->IncreaseLevel();
        level++;
        lives++;
    }

    CheckCollisions();
    playerManager->player->Update();
    playerManager->altPlayer->Update();

    for (unsigned int i=0; i< playerManager->bullets.size(); i++)
    {
        playerManager->bullets[i].Update();
    }

    for (unsigned int i=0; i< enemyManger->bullets.size(); i++)
    {
        enemyManger->bullets[i].Update();
    }

    scoreLcd->display(score);
    livesLcd->display(lives);
    levelLcd->display(level);

}

void Game::CheckCollisions()
{
    collisionDetect.CheckBulletCollisions(enemyManger->bullets, playerManager->bullets);

    for (unsigned int i=0; i<playerManager->bullets.size(); i++)
    {
        for (unsigned int j=0; j < enemyManger->enemies.size(); j++)
        {
            if (collisionDetect.RectCollsion(playerManager->bullets[i].circle, enemyManger->enemies[j].rect))
            {
                switch (enemyManger->enemies[j].rowLevel) {
                case 0:
                    score += 40;
                    break;
                case 1:
                    score += 20;
                    break;
                case 2:
                    score += 20;
                    break;
                case 3:
                    score += 10;
                    break;
                case 4:
                    score += 10;
                    break;
                }

                enemyManger->enemies.erase(enemyManger->enemies.begin() + j);
                playerManager->bullets.erase(playerManager->bullets.begin() + i);
            }
        }
    }

    for (unsigned int i=0; i<enemyManger->bullets.size(); i++)
    {
        if (collisionDetect.RectCollsion(enemyManger->bullets[i].circle, playerManager->player->rect))
        {
            enemyManger->bullets.erase(enemyManger->bullets.begin() + i);
            lives--;
            if (lives > 0)
            {
                playerManager->player = new Player();
            }else
            {
               playerManager->player->Alive = false;
               lives = 0;
               livesLcd->display(0);
               PauseGame();
            }
        }
    }


    for (unsigned int j=0; j < enemyManger->enemies.size(); j++)
    {
        if (collisionDetect.RectCollsion(playerManager->player->rect, enemyManger->enemies[j].rect))
        {
            PauseGame();
            break;
        }
    }

}

void Game::Draw(QPainter *p, QBrush *brush)
{
    brush->setColor(QColor(0, 0, 0));
    p->setBrush(*brush);
    p->drawRect(*backgroundRect);

    if (playerManager->player->Alive)
    {
        brush->setColor(QColor(0, 255, 0));
        p->setBrush(*brush);
        p->drawImage(playerManager->player->rect, *whiteBloodCell);
        p->drawImage(playerManager->altPlayer->rect, *whiteBloodCell);
    }else
    {
        brush->setColor(QColor(0, 0, 0));
        p->setBrush(*brush);
        p->drawRect(playerManager->player->rect);
    }


    for (unsigned int i=0; i<enemyManger->enemies.size(); i++)
    {
        switch (enemyManger->enemies[i].rowLevel) {
        case 0:
            p->drawImage(enemyManger->enemies[i].rect, *virus1);
            break;
        case 1:
            p->drawImage(enemyManger->enemies[i].rect, *virus2);
            break;
        case 2:
            p->drawImage(enemyManger->enemies[i].rect, *virus2);
            break;
        case 3:
            p->drawImage(enemyManger->enemies[i].rect, *bacteria);
            break;
        case 4:
            p->drawImage(enemyManger->enemies[i].rect, *bacteria);
            break;
        }
    }

    brush->setColor(QColor(255,69,0));
    p->setBrush(*brush);
    for (unsigned int i=0; i< playerManager->bullets.size(); i++)
    {
        p->drawEllipse(playerManager->bullets[i].circle);
    }

    brush->setColor(QColor(255,0,0));
    p->setBrush(*brush);
    for (unsigned int i=0; i< enemyManger->bullets.size(); i++)
    {
        p->drawEllipse(enemyManger->bullets[i].circle);
    }
}

void Game::KeyBoardInput(QKeyEvent *event, KeyActionType action)
{
    if (action == PRESS)
    {
        if (event->isAutoRepeat())
            return;

        switch(event->key()) {
        case Qt::Key_Escape:
            playerManager->player->SetPlayerPosition(390, 550);
            playerManager->altPlayer->SetPlayerPosition(290, 550);
            Init();
            break;
        case Qt::Key_W:
            break;
        case Qt::Key_A:
            break;
        case Qt::Key_S:
            break;
        case Qt::Key_D:
            break;
        case Qt::Key_Up:
            break;
        case Qt::Key_Down:
            break;
        case Qt::Key_Left:
            playerManager->player->SetMovingLeft();
            SendData("l_1");
            break;
        case Qt::Key_Right:
            playerManager->player->SetMovingRight();
            SendData("r_1");
            break;
        case Qt::Key_Space:
            playerManager->Shoot();
            SendData("a_0_"+QString::number(playerManager->player->x)+"_"+QString::number(playerManager->player->y));
            break;
        }
    }

    else if (action == RELEASE)
    {
        if (event->isAutoRepeat())
            return;
        switch(event->key()) {
        case Qt::Key_Escape:
            break;
        case Qt::Key_W:
            break;
        case Qt::Key_A:
            break;
        case Qt::Key_S:
            break;
        case Qt::Key_D:
            break;
        case Qt::Key_Up:
            break;
        case Qt::Key_Down:
            break;
        case Qt::Key_Left:
            playerManager->player->ClearMovement();
            SendData("s_"+QString::number(playerManager->player->x)+"_"+QString::number(playerManager->player->y));
            break;
        case Qt::Key_Right:
            playerManager->player->ClearMovement();
            SendData("s_"+QString::number(playerManager->player->x)+"_"+QString::number(playerManager->player->y));
            break;
        case Qt::Key_Space:
            break;
        case Qt::Key_C:
            JoinGame("abc_"+QString::number(playerManager->player->x)+"_"+QString::number(playerManager->player->y));
        }
    }

}

void Game::ConnectToServer(QHostAddress address, int port) {
    clientSocket.connectToHost(address, port);
    netReadTimer->start();
}

void Game::SendData(QString data) {
    if (clientSocket.state() != QTcpSocket::ConnectedState) {
        return;
    }
    clientSocket.write(data.toLocal8Bit());

}

void Game::ReadData() {
    if (clientSocket.state() != QTcpSocket::ConnectedState) {
        return;
    }

    QString data(clientSocket.readAll());
    if (data=="") return;

    // switch to iterate through all when done testing **********
    QStringList data_list = data.split("$");

    for (QString msg_data_list:data_list) {
        QStringList msg_data = msg_data_list.split("_");

        if (msg_data[0] == "connect") {
            connectLevel = msg_data[1];
        }
        else if (msg_data[0] == "disconnect") {
    //        connectLevel = "";
    //        gameString = "waitingList";
            JoinGame("waitingList");
        }
        else if (msg_data[0] == "l") {
            playerManager->altPlayer->SetMovingLeft();
        }
        else if (msg_data[0] == "r") {
            playerManager->altPlayer->SetMovingRight();
        }
        else if (msg_data[0] == "s") {
            playerManager->altPlayer->ClearMovement();
            bool okx,oky;
            int x = msg_data[1].toInt(&okx);
            int y = msg_data[2].toInt(&oky);
            if (okx && oky) {
                playerManager->altPlayer->x = x;
                playerManager->altPlayer->y = y;
            }

        }
        else if (msg_data[0] == "a") {
            bool okx,oky;
            int x = msg_data[2].toInt(&okx);
            int y = msg_data[3].toInt(&oky);
            if (okx && oky) {
                playerManager->bullets.push_back(Bullet(x + ((playerManager->altPlayer->w/2)-5), y, 10, 10));
            } else {

                playerManager->bullets.push_back(Bullet(playerManager->altPlayer->x + ((playerManager->altPlayer->w/2)-5), playerManager->altPlayer->y, 10, 10));
            }
        }
        qDebug() << msg_data;
    }

}

void Game::JoinGame(QString gameStr) {
    if (connectLevel != "attempt" && gameStr != "") {
        QString msg = "connect_"+gameStr;
        connectLevel = "attempt";
        clientSocket.write(msg.toLocal8Bit());
    }
}

