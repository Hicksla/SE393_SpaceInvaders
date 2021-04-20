#include "game.h"
#include <iostream>
#include <ctime>

Game::Game()
{
    collisionDetect = CollisionDetector();
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
    ClearBarriers();

    score = 0;
    lives = 3;
    level = 1;

    if (!playerManager->player->Alive)
    {
        playerManager->LoadPlayer();
    }

    enemyManger->loadEnemies();
    BuildBarriers();
    fpsTimer->start();
    enemyManger->Start();
}

void Game::Update()
{
    if (enemyManger->enemies.size() <= 0)
    {
        enemyManger->IncreaseLevel();
        ClearBarriers();
        BuildBarriers();
        level++;
        lives++;
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

    for(unsigned int i=0; i<barriers.size(); i++)
    {
        for (unsigned int j=0; j<enemyManger->bullets.size(); j++)
        {
            if (collisionDetect.RectCollsion(barriers[i], enemyManger->bullets[j].circle))
            {
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

    //Check if enemeies make it to the bottom

}

void Game::Draw(QPainter *p, QBrush *brush)
{
    brush->setColor(QColor(0, 0, 0));
    p->setBrush(*brush);
    p->drawRect(*backgroundRect);

    brush->setColor(QColor(0, 255, 0));
    p->setBrush(*brush);
    p->drawRects(barriers.data(), barriers.size());

    if (playerManager->player->Alive)
    {
        brush->setColor(QColor(0, 255, 0));
        p->setBrush(*brush);
        p->drawImage(playerManager->player->rect, *whiteBloodCell);
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
