#include "game.h"
#include <iostream>
#include <ctime>

Game::Game()
{
    collisionDetect = CollisionDetector();
}
void Game::AddFpsTimer(QTimer *timer)
{
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

    if (!playerManager->player->Alive)
    {
        playerManager->LoadPlayer();
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
    }

    CheckCollisions();
    playerManager->player->Update();

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
                enemyManger->enemies.erase(enemyManger->enemies.begin() + j);
                playerManager->bullets.erase(playerManager->bullets.begin() + i);
                score += 10;
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
            lives--;
            if (lives > 0)
            {
                playerManager->player = new Player();
            }else
            {
               playerManager->player->Alive = false;
               PauseGame();
            }
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
        p->drawRect(playerManager->player->rect);
    }else
    {
        brush->setColor(QColor(0, 0, 0));
        p->setBrush(*brush);
        p->drawRect(playerManager->player->rect);
    }


    brush->setColor(QColor(255, 255, 255));
    p->setBrush(*brush);

    for (unsigned int i=0; i<enemyManger->enemies.size(); i++)
    {
        p->drawRect(enemyManger->enemies[i].rect);
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
            break;
        case Qt::Key_Right:
            playerManager->player->SetMovingRight();
            break;
        case Qt::Key_Space:
            playerManager->Shoot();
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
            break;
        case Qt::Key_Right:
            playerManager->player->ClearMovement();
            break;
        case Qt::Key_Space:
            break;
        }
    }

}
