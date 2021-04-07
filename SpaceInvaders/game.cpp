#include "game.h"
#include <iostream>

Game::Game()
{
    Init();
    connect(timer, &QTimer::timeout, this, &Game::SetCanShoot);
    timer->setInterval(500);
}

void Game::Init()
{
    collisionDetect = CollisionDetector();
    player = Player(400, 500);

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

void Game::Draw(QPainter *p)
{

    p->drawRect(player.rect);

    p->drawRects(enemies1.data(), enemies1.size());

    for (unsigned int i=0; i< bullets.size(); i++)
    {
        p->drawEllipse(bullets[i].circle);
    }
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
