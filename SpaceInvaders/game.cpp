#include "game.h"
#include <iostream>
#include <ctime>

Game::Game()
{
    connect(timer, &QTimer::timeout, this, &Game::SetCanShoot);
    timer->setInterval(500);

    collisionDetect = CollisionDetector();

}
void Game::AddFpsTimer(QTimer *timer)
{
    fpsTimer = timer;
    Init();
}

void Game::PauseGame()
{
    enemyManger->Pause();
    fpsTimer->stop();
}

void Game::loadPlayer()
{
    player = Player(400, 500);
    player.Alive = true;

}


void Game::Init()
{
    enemyManger->unloadEnemies();

    if (!player.Alive)
    {
        loadPlayer();
    }

    enemyManger->loadEnemies();
    fpsTimer->start();
    enemyManger->Start();
}

void Game::Update()
{
    if (enemyManger->enemies.size() <= 0)
    {
        PauseGame();
    }else
    {
        CheckCollisions();
        player.Update();

        for (unsigned int i=0; i< bullets.size(); i++)
        {
            bullets[i].Update();
        }

        for (unsigned int i=0; i< enemyManger->bullets.size(); i++)
        {
            enemyManger->bullets[i].Update();
        }
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

    for (unsigned int i=0; i<enemyManger->bullets.size(); i++)
    {
        if (enemyManger->bullets[i].circle.y() >= 600)
        {
            enemyManger->bullets.erase(enemyManger->bullets.begin() + i);
        }
    }

    for (unsigned int i=0; i<bullets.size(); i++)
    {
        for (unsigned int j=0; j < enemyManger->enemies.size(); j++)
        {
            if (collisionDetect.RectCollsion(bullets[i].circle, enemyManger->enemies[j].rect))
            {
                enemyManger->enemies.erase(enemyManger->enemies.begin() + j);
                bullets.erase(bullets.begin() + i);
            }
        }
    }

    for (unsigned int i=0; i<enemyManger->bullets.size(); i++)
    {
        if (collisionDetect.RectCollsion(enemyManger->bullets[i].circle, player.rect))
        {
            enemyManger->bullets.erase(enemyManger->bullets.begin() + i);
            player.Alive = false;
            PauseGame();
        }
    }


    for (unsigned int j=0; j < enemyManger->enemies.size(); j++)
    {
        if (collisionDetect.RectCollsion(player.rect, enemyManger->enemies[j].rect))
        {
            player.Alive = false;
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

    if (player.Alive)
    {
        brush->setColor(QColor(0, 255, 0));
        p->setBrush(*brush);
        p->drawRect(player.rect);
    }else
    {
        brush->setColor(QColor(0, 0, 0));
        p->setBrush(*brush);
        p->drawRect(player.rect);
    }


    brush->setColor(QColor(255, 255, 255));
    p->setBrush(*brush);

    for (unsigned int i=0; i<enemyManger->enemies.size(); i++)
    {
        p->drawRect(enemyManger->enemies[i].rect);
    }

    brush->setColor(QColor(255,69,0));
    p->setBrush(*brush);
    for (unsigned int i=0; i< bullets.size(); i++)
    {
        p->drawEllipse(bullets[i].circle);
    }

    brush->setColor(QColor(255,0,0));
    p->setBrush(*brush);
    for (unsigned int i=0; i< enemyManger->bullets.size(); i++)
    {
        p->drawEllipse(enemyManger->bullets[i].circle);
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
            player.SetMovingLeft();
            break;
        case Qt::Key_Right:
            player.SetMovingRight();
            break;
        case Qt::Key_Space:
            if (ShootTimeOut)
            {
               bullets.push_back(Bullet(player.x + ((player.w/2)-5), player.y, 10, 10));
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
