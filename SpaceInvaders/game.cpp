#include "game.h"
#include <iostream>
#include <ctime>

Game::Game()
{
    collisionDetect = CollisionDetector();
    ConnectToServer(QHostAddress("127.0.0.1"), 8006);
    connect(netReadTimer, &QTimer::timeout, this, &Game::ReadData);
    netReadTimer->setInterval(25);
}
void Game::AddFpsTimer(QTimer *timer)
{
    virus1->load(":/images/virus1.png");
    virus2->load(":/images/virus2.png");
    bacteria->load(":/images/bacteria.png");
    whiteBloodCell->load(":/images/whitebloodcell.png");
    whiteBloodCellBlue->load(":/images/whitebloodcell2.png");
    whiteBloodCellRed->load(":/images/whitebloodcell1.png");
    syringe->load(":/images/syringe.png");
    redBloodCell->load(":/images/redbloodcell.png");
    DNA->load(":/images/dna.png");
    music.setSource(QUrl::fromLocalFile(":/Last Frontier/Music/08 The Last Frontier.wav"));
    explosion.setSource(QUrl::fromLocalFile(":/explosion/Music/explosion.wav"));
    playerExplosion.setSource(QUrl::fromLocalFile(":/playerExplosion/Music/atari_boom5.wav"));
    gameOver.setSource(QUrl::fromLocalFile(":/GameOver/Music/06 The Victors' Homecoming.wav"));

    fpsTimer = timer;
}

void Game::AddUiComponents(QLCDNumber *scoreUi, QLCDNumber *livesUi, QLCDNumber *levelUi)
{
    scoreLcd = scoreUi;
    livesLcd = livesUi;
    levelLcd = levelUi;
}

void Game::PauseGame()
{

    music.stop();
    gameOver.play();
    enemyManger->Pause();
    netReadTimer->stop();

    QMessageBox msgBox;
    msgBox.setFixedSize(300, 200);
    msgBox.setText("Game Over "+ connectLevel);
    if(msgBox.exec() == QMessageBox::Ok)
    {
        CloseGame = true;
    }

}


void Game::Init()
{
    gameRunning = true;
    score = 0;
    lives = 3;
    level = 1;

    if (!playerManager->player->Alive)
    {
        playerManager->LoadPlayers();
    }

    enemyManger->loadEnemies();
    BuildBarriers();
    fpsTimer->start();
    enemyManger->Start();

    if(gameOver.isPlaying())
    {
        gameOver.stop();
    }
    music.play();

    if (connectLevel == "host") {
            connect(enemySendTimer, &QTimer::timeout, this, &Game::SendEnemies);
            connect(enemySendTimer, &QTimer::timeout, this, &Game::SendBarriers);
            enemySendTimer->setInterval(500);
            enemySendTimer->start();

            connect(statsSendTimer, &QTimer::timeout, this, &Game::SendStats);
            statsSendTimer->setInterval(3000);
            statsSendTimer->start();
        }
}

void Game::Update()
{
    if (enemyManger->enemies.size() <= 0)
    {
        music.stop();
        ClearBarriers();
        BuildBarriers();
        enemyManger->IncreaseLevel();
        level++;
        lives++;
        music.play();
    }

    CheckCollisions();
    //enemyManger->updateEnemyArrayLoc();
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

    for(unsigned int i=0; i<barriers.size(); i++)
    {
        for (unsigned int j=0; j<enemyManger->bullets.size(); j++)
        {
            if (collisionDetect.RectCollsion(barriers[i], enemyManger->bullets[j].circle))
            {
                explosion.play();
                enemyManger->bullets.erase(enemyManger->bullets.begin() + j);
                barriers.erase(barriers.begin() + i);
            }
        }
    }

    for(unsigned int i=0; i<barriers.size(); i++)
    {
        for (unsigned int j=0; j<playerManager->bullets.size(); j++)
        {
            if (collisionDetect.RectCollsion(barriers[i], playerManager->bullets[j].circle))
            {
                explosion.play();
                playerManager->bullets.erase(playerManager->bullets.begin() + j);
                barriers.erase(barriers.begin() + i);
            }
        }
    }

    for (unsigned int i=0; i<playerManager->bullets.size(); i++)
    {
        for (unsigned int j=0; j < enemyManger->enemies.size(); j++)
        {
            if (collisionDetect.RectCollsion(playerManager->bullets[i].circle, enemyManger->enemies[j].rect))
            {
                switch (enemyManger->enemies[j].rowLevel) {
                case -1:
                    score += 100;
                    break;
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

                explosion.play();
                enemyManger->enemies.erase(enemyManger->enemies.begin() + j);
                playerManager->bullets.erase(playerManager->bullets.begin() + i);
            }
        }
    }

    for (unsigned int i=0; i<enemyManger->bullets.size(); i++)
    {
        if (collisionDetect.RectCollsion(enemyManger->bullets[i].circle, playerManager->player->rect))
        {
            playerExplosion.play();
            enemyManger->bullets.erase(enemyManger->bullets.begin() + i);
            // removed for easier testing *******
            lives--;
            if (lives > 0)
            {
                playerManager->player = new Player();
            }else
            {
               lives = 0;
               livesLcd->display(0);
               EndGame();
               return;
            }
        }
    }
    // alt player
    for (unsigned int i=0; i<enemyManger->bullets.size(); i++)
    {
        if (collisionDetect.RectCollsion(enemyManger->bullets[i].circle, playerManager->altPlayer->rect))
        {
            playerExplosion.play();
            enemyManger->bullets.erase(enemyManger->bullets.begin() + i);
            // removed for easier testing *******
            lives--;
            if (lives > 0)
            {
                playerManager->altPlayer = new Player();
            }else
            {
               lives = 0;
               livesLcd->display(0);
               EndGame();
               return;
            }
        }
    }

    for (unsigned int i=0; i<enemyManger->enemies.size(); i++)
    {
        for (unsigned int j=0; j<barriers.size(); j++)
        {
            if (enemyManger->enemies[i].rect.y()+enemyManger->enemies[i].rect.height() >= barriers[j].y())
            {
                EndGame();
                return;
//                break;
            }
        }
    }

    for (unsigned int i=0; i<enemyManger->enemies.size(); i++)
    {
        if (enemyManger->enemies[i].rect.y()+enemyManger->enemies[i].rect.height() >= playerManager->player->rect.y())
        {
            EndGame();
            return;
//            break;
        }
        // alt player
        if (enemyManger->enemies[i].rect.y()+enemyManger->enemies[i].rect.height() >= playerManager->altPlayer->rect.y())
        {
            EndGame();
            return;
//            break;
        }
    }

}

void Game::Draw(QPainter *p, QBrush *brush)
{
    brush->setColor(QColor(0, 0, 0));
    p->setBrush(*brush);
    p->drawRect(*backgroundRect);

    brush->setColor(QColor(0, 255, 0));
    p->setBrush(*brush);
    p->drawRects(barriers.data(), barriers.size());


    p->drawImage(playerManager->player->rect, *whiteBloodCellBlue);
    p->drawImage(playerManager->altPlayer->rect, *whiteBloodCellRed);


    for (unsigned int i=0; i<enemyManger->enemies.size(); i++)
    {
        switch (enemyManger->enemies[i].rowLevel) {
        case -1:
            p->drawImage(enemyManger->enemies[i].rect, *redBloodCell);
            break;
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

    for (unsigned int i=0; i< enemyManger->bullets.size(); i++)
    {
        p->drawImage(enemyManger->bullets[i].circle, *DNA);
    }

    for (unsigned int i=0; i< playerManager->bullets.size(); i++)
    {
        p->drawImage(playerManager->bullets[i].circle, *syringe);
    }


}

void Game::BuildBarriers()
{
    barriers.push_back(QRect(155, 470, 20, 20));
    barriers.push_back(QRect(175, 470, 20, 20));
    barriers.push_back(QRect(195, 470, 20, 20));
    barriers.push_back(QRect(155, 490, 20, 20));
    barriers.push_back(QRect(175, 490, 20, 20));
    barriers.push_back(QRect(195, 490, 20, 20));
    barriers.push_back(QRect(155, 510, 20, 20));
    barriers.push_back(QRect(195, 510, 20, 20));

    barriers.push_back(QRect(310, 470, 20, 20));
    barriers.push_back(QRect(330, 470, 20, 20));
    barriers.push_back(QRect(350, 470, 20, 20));
    barriers.push_back(QRect(310, 490, 20, 20));
    barriers.push_back(QRect(330, 490, 20, 20));
    barriers.push_back(QRect(350, 490, 20, 20));
    barriers.push_back(QRect(310, 510, 20, 20));
    barriers.push_back(QRect(350, 510, 20, 20));

    barriers.push_back(QRect(465, 470, 20, 20));
    barriers.push_back(QRect(485, 470, 20, 20));
    barriers.push_back(QRect(505, 470, 20, 20));
    barriers.push_back(QRect(465, 490, 20, 20));
    barriers.push_back(QRect(485, 490, 20, 20));
    barriers.push_back(QRect(505, 490, 20, 20));
    barriers.push_back(QRect(465, 510, 20, 20));
    barriers.push_back(QRect(505, 510, 20, 20));

    barriers.push_back(QRect(620, 470, 20, 20));
    barriers.push_back(QRect(640, 470, 20, 20));
    barriers.push_back(QRect(660, 470, 20, 20));
    barriers.push_back(QRect(620, 490, 20, 20));
    barriers.push_back(QRect(640, 490, 20, 20));
    barriers.push_back(QRect(660, 490, 20, 20));
    barriers.push_back(QRect(620, 510, 20, 20));
    barriers.push_back(QRect(660, 510, 20, 20));
}

void Game::ClearBarriers()
{
    barriers.clear();
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
            Init();
            // need to add end game networking
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
            if(playerManager->Shoot()) {
                SendData("a_0_"+QString::number(playerManager->player->x)+"_"+QString::number(playerManager->player->y));
            }
            break;
        case Qt::Key_I:
            EndGame();
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
            break;
        case Qt::Key_V:
            SendData("start_0");
            break;
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
    clientSocket.write((data+"$").toLocal8Bit());

}

void Game::ReadData() {
    if (clientSocket.state() != QTcpSocket::ConnectedState) {
        return;
    }


    QString data(clientSocket.readAll());
    if (data=="") return;

    QStringList data_list = data.split("$");

    for (QString& msg_data_list:data_list) {
        if (msg_data_list == "") continue;
        QStringList msg_data = msg_data_list.split("_");

        if (msg_data[0] == "connect") {
            qDebug() << msg_data[0];
            qDebug() << msg_data[1];
            qDebug() << msg_data[2];
            connectLevel = msg_data[2];
            if (connectLevel == "host") {
                gameString = msg_data[1];
            }
            else if (connectLevel == "join") {
                gameString = msg_data[1];
            }
        }
        else if (gameString == "waitingList") {
            return;
        }

        if (msg_data[0] == "start") {
            Init();
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
                playerManager->bullets.push_back(Bullet(x + ((playerManager->altPlayer->w/2)-5), y, 20, 20));
                playerManager->laser2.play();
            } else {

                playerManager->bullets.push_back(Bullet(playerManager->altPlayer->x + ((playerManager->altPlayer->w/2)-5), playerManager->altPlayer->y, 20, 20));
                playerManager->laser2.play();
            }
        }
        else if (msg_data[0] == "e") {
            if (connectLevel == "join") {
                // parse enemy data
                enemyManger->setEnemies(msg_data[1]);
                SendData("e_0");
            }
            else if (connectLevel == "host") {
//                enemyManger->Start();
            }
        }
        else if (msg_data[0] == "stats") {
            bool okScore,okLives,okLevel;
            int newScore = msg_data[1].toInt(&okScore);
            int newLives = msg_data[2].toInt(&okLives);
            int newLevel = msg_data[3].toInt(&okLevel);
            if (okScore&&okLives&&okLevel) {
                score = newScore;
                lives = newLives;
                level = newLevel;
            }
        }
        else if (msg_data[0] == "sync") {
            // stop everything, and start it again
            enemyManger->Pause();
            fpsTimer->stop();

            fpsTimer->start();
            enemyManger->Start();
        }
        else if (msg_data[0] == "b") {
            SetBarriers(msg_data[1]);
        }
        else if (msg_data[0] == "end") {
            qDebug() << connectLevel << " received end";
            EndGame();
        }

    }

}

void Game::JoinGame(QString gameStr) {
    if (connectLevel != "attempt" && gameStr != "") {
        QString msg = "connect_"+gameStr+"$";
        connectLevel = "attempt";
        clientSocket.write(msg.toLocal8Bit());
    }
}

void Game::SendEnemies() {
//    enemyManger->Pause();
    SendData("e_"+enemyManger->toString());
}

void Game::SendStats() {
    SendData("stats_"+QString::number(score)+"_"+QString::number(lives)+"_"+QString::number(level));
}

void Game::SendBarriers() {
    QString barrier_str;
    for (QRect& barrier: barriers) {
        barrier_str += QString::number(barrier.x())+":"+QString::number(barrier.y())+",";
    }
    SendData("b_"+barrier_str);
}

void Game::SetBarriers(QString barrier_data) {
    ClearBarriers();
    QStringList barrier_str_lst = barrier_data.split(",");
    for (QString& barrier_str:barrier_str_lst) {
        if (barrier_str == "") continue;
        QStringList barrier_lst = barrier_str.split(":");
        if (barrier_str == "") continue;
        bool okx,oky;
        int x = barrier_lst[0].toInt(&okx);
        int y = barrier_lst[1].toInt(&oky);
        if (!okx&&!oky) continue;

        barriers.push_back(QRect(x,y,20,20));
    }
}

void Game::EndGame() {
     if (gameRunning) {
         PauseGame();
         SendEndGame();
         gameRunning = false;
     }

}

void Game::SendEndGame() {
    SendData("end_0");
    JoinGame("waitingList");
}
