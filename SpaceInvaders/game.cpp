#include "game.h"
#include <iostream>

Game::Game()
{
    Init();
    ConnectToServer(QHostAddress("127.0.0.1"), 8006);
    connect(netReadTimer, &QTimer::timeout, this, &Game::ReadData);
    netReadTimer->setInterval(50);

    connect(timer, &QTimer::timeout, this, &Game::SetCanShoot);
    timer->setInterval(500);
}

void Game::Init()
{
    collisionDetect = CollisionDetector();
    player = Player(400, 500);
    altPlayer = Player(200, 500);

    for (int i=0; i < 4; i++)
    {
        for (int j=0; j < 13; j++)
        {
            if (i == 0){
                if (j==0)
                enemies1.push_back(QRect(55, 40, 20, 20));
                else
                {
                    enemies1.push_back(QRect(enemies1[j-1].x() + 55, 40, 20, 20));
                }
            }
        }
    }


}

void Game::Update()
{
    CheckCollisions();
    player.Update();
    altPlayer.Update();

    for (unsigned int i=0; i< bullets.size(); i++)
    {
        bullets[i].Update();
    }
}

void Game::CheckCollisions()
{
    for (unsigned int i=0; i<bullets.size(); i++)
    {
        if (bullets[i].circle.y() <= 0)
        {
            bullets.erase(bullets.begin() + i);
        }
    }

    for (unsigned int i=0; i<bullets.size(); i++)
    {
        for (unsigned int j=0; j < enemies1.size(); j++)
        {
            if (collisionDetect.RectCollsion(bullets[i].circle, enemies1[j]))
            {
                enemies1.erase(enemies1.begin() + j);
                bullets.erase(bullets.begin() + i);
            }
        }
    }

}

void Game::Draw(QPainter *p, QBrush *brush)
{

    brush->setColor(QColor(0, 0, 255));
    p->setBrush(*brush);
    p->drawRect(player.rect);

    brush->setColor(QColor(255,0,0));
    p->setBrush(*brush);
    p->drawRects(enemies1.data(), enemies1.size());

    brush->setColor(QColor(255,69,0));
    p->setBrush(*brush);
    for (unsigned int i=0; i< bullets.size(); i++)
    {
        p->drawEllipse(bullets[i].circle);
    }

    brush->setColor(QColor(150, 0, 255));
    p->setBrush(*brush);
    p->drawRect(altPlayer.rect);
}

void Game::SetCanShoot()
{
    ShootTimeOut = true;
}

void Game::KeyBoardInput(QKeyEvent *event, KeyActionType action)
{
    if (action == PRESS)
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
            player.SetMovingLeft();
            SendData("l_1");
            break;
        case Qt::Key_Right:
            player.SetMovingRight();
            SendData("r_1");
            break;
        case Qt::Key_Space:
            if (ShootTimeOut)
            {
               bullets.push_back(Bullet(player.x + ((player.w/2)-5), player.y));
               ShootTimeOut = false;
               timer->start();
               SendData("a_0_"+QString::number(player.x)+"_"+QString::number(player.y));
            }

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
            player.ClearMovement();
            SendData("s_"+QString::number(player.x)+"_"+QString::number(player.y));
            break;
        case Qt::Key_Right:
            player.ClearMovement();
            SendData("s_"+QString::number(player.x)+"_"+QString::number(player.y));
            break;
        case Qt::Key_Space:
            break;
        case Qt::Key_C:
            JoinGame("abc_"+QString::number(player.x)+"_"+QString::number(player.y));
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
            altPlayer.SetMovingLeft();
        }
        else if (msg_data[0] == "r") {
            altPlayer.SetMovingRight();
        }
        else if (msg_data[0] == "s") {
            altPlayer.ClearMovement();
            bool okx,oky;
            int x = msg_data[1].toInt(&okx);
            int y = msg_data[2].toInt(&oky);
            if (okx && oky) {
                altPlayer.x = x;
                altPlayer.y = y;
            }

        }
        else if (msg_data[0] == "a") {
            bool okx,oky;
            int x = msg_data[2].toInt(&okx);
            int y = msg_data[3].toInt(&oky);
            if (okx && oky) {
                bullets.push_back(Bullet(x + ((altPlayer.w/2)-5), y));
            } else {

                bullets.push_back(Bullet(altPlayer.x + ((altPlayer.w/2)-5), altPlayer.y));
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
