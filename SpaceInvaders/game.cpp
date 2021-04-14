#include "game.h"
#include <iostream>

Game::Game()
{
    Init();
    connect(timer, &QTimer::timeout, this, &Game::SetCanShoot);
    timer->setInterval(500);

    connect(enemyTimer, &QTimer::timeout, this, &Game::UpdateEnemyLoc);
    enemyTimer->setInterval(1000);
}

void Game::Init()
{
    collisionDetect = CollisionDetector();
    player = Player(400, 500);

    for (int i=0; i < 4; i++)
    {
        for (int j=0; j < 13; j++)
        {
            Enemy newEnemey(i);
            if (i == 0){
                if (j==0)
                {
                    newEnemey.SetRect(QRect(55, 40, 20, 20));
                    enemies.push_back(newEnemey);
                }
                else
                {
                    newEnemey.SetRect(QRect(enemies[j-1].rect.x() + 55, 40, 20, 20));
                    enemies.push_back(newEnemey);
                }
            }

            else if (i == 1){
                if (j==0)
                {
                    newEnemey.SetRect(QRect(55, 80, 20, 20));
                    enemies.push_back(newEnemey);
                }
                else
                {
                    newEnemey.SetRect(QRect(enemies[j-1].rect.x() + 55, 80, 20, 20));
                    enemies.push_back(newEnemey);
                }

            }

            else if (i == 2){
                if (j==0)
                {
                    newEnemey.SetRect(QRect(55, 120, 20, 20));
                    enemies.push_back(newEnemey);
                }
                else
                {
                    newEnemey.SetRect(QRect(enemies[j-1].rect.x() + 55, 120, 20, 20));
                    enemies.push_back(newEnemey);
                }

            }

            else if (i == 3){
                if (j==0)
                {
                    newEnemey.SetRect(QRect(55, 160, 20, 20));
                    enemies.push_back(newEnemey);
                }
                else
                {
                    newEnemey.SetRect(QRect(enemies[j-1].rect.x() + 55, 160, 20, 20));
                    enemies.push_back(newEnemey);
                }

            }
        }
    }
    enemyTimer->start();
}

void Game::Update()
{
    CheckCollisions();
    player.Update();

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
        for (unsigned int j=0; j < enemies.size(); j++)
        {
            if (collisionDetect.RectCollsion(bullets[i].circle, enemies[j].rect))
            {
                enemies.erase(enemies.begin() + j);
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

    for (unsigned int i=0; i<enemies.size(); i++)
    {
        p->drawRect(enemies[i].rect);
    }

    brush->setColor(QColor(255,69,0));
    p->setBrush(*brush);
    for (unsigned int i=0; i< bullets.size(); i++)
    {
        p->drawEllipse(bullets[i].circle);
    }
}

void Game::UpdateEnemyLoc()
{
    for (unsigned int i=0; i<enemies.size(); i++)
    {
        int x = enemies[i].rect.x();
        int y = enemies[i].rect.y();
        enemies[i].SetRect(QRect(x+20, y, 20, 20));
    }

    enemyTimer->start();
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
            break;
        case Qt::Key_Right:
            player.SetMovingRight();
            break;
        case Qt::Key_Space:
            if (ShootTimeOut)
            {
               bullets.push_back(Bullet(player.x + ((player.w/2)-5), player.y));
               ShootTimeOut = false;
               timer->start();
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
            break;
        case Qt::Key_Right:
            player.ClearMovement();
            break;
        case Qt::Key_Space:
            break;
        }
    }

}
