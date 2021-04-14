#include "game.h"
#include <iostream>

Game::Game()
{
    connect(timer, &QTimer::timeout, this, &Game::SetCanShoot);
    timer->setInterval(500);
    connect(enemyTimer, &QTimer::timeout, this, &Game::UpdateEnemyLoc);

    collisionDetect = CollisionDetector();

}
void Game::AddFpsTimer(QTimer *timer)
{
    fpsTimer = timer;
    Init();
}

void Game::loadPlayer()
{
    player = Player(400, 500);
    player.Alive = true;

}

void Game::loadEnemies()
{
    for (int i=0; i < 5; i++)
    {
        for (int j=0; j < 13; j++)
        {
            Enemy newEnemey(i);
            if (i == 0){
                if (j==0)
                {
                    newEnemey.SetRect(QRect(150, 80, 20, 20));
                    enemies.push_back(newEnemey);
                }
                else
                {
                    newEnemey.SetRect(QRect(enemies[j-1].rect.x() + 40, 80, 20, 20));
                    enemies.push_back(newEnemey);
                }
            }

            else if (i == 1){
                if (j==0)
                {
                    newEnemey.SetRect(QRect(150, 120, 20, 20));
                    enemies.push_back(newEnemey);
                }
                else
                {
                    newEnemey.SetRect(QRect(enemies[j-1].rect.x() + 40, 120, 20, 20));
                    enemies.push_back(newEnemey);
                }

            }

            else if (i == 2){
                if (j==0)
                {
                    newEnemey.SetRect(QRect(150, 160, 20, 20));
                    enemies.push_back(newEnemey);
                }
                else
                {
                    newEnemey.SetRect(QRect(enemies[j-1].rect.x() + 40, 160, 20, 20));
                    enemies.push_back(newEnemey);
                }

            }

            else if (i == 3){
                if (j==0)
                {
                    newEnemey.SetRect(QRect(150, 200, 20, 20));
                    enemies.push_back(newEnemey);
                }
                else
                {
                    newEnemey.SetRect(QRect(enemies[j-1].rect.x() + 40, 200, 20, 20));
                    enemies.push_back(newEnemey);
                }

            }
            else if (i == 4){
                if (j==0)
                {
                    newEnemey.SetRect(QRect(150, 240, 20, 20));
                    enemies.push_back(newEnemey);
                }
                else
                {
                    newEnemey.SetRect(QRect(enemies[j-1].rect.x() + 40, 240, 20, 20));
                    enemies.push_back(newEnemey);
                }

            }
        }
    }
}

void Game::unloadEnemies()
{
    enemies.clear();
    bullets.clear();
}

void Game::Init()
{

    if (!player.Alive)
    {
        loadPlayer();
    }

    loadEnemies();

    enemyTimer->setInterval(EnemySpeed);
    fpsTimer->start();
    enemyTimer->start();
}

void Game::Update()
{
    if (enemies.size() <= 0)
    {
        fpsTimer->stop();
        enemyTimer->stop();
    }else
    {
        CheckCollisions();
        player.Update();

        for (unsigned int i=0; i< bullets.size(); i++)
        {
            bullets[i].Update();
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

    for (unsigned int j=0; j < enemies.size(); j++)
    {
        if (collisionDetect.RectCollsion(player.rect, enemies[j].rect))
        {
            enemies.clear();
            player.Alive = false;
            enemyTimer->stop();
            fpsTimer->stop();
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
    if (enemy_dir == RIGHT && movement_flag == false)
    {
        enemy_dir = DOWN;
        previous_enemy_dir = RIGHT;
        movement_flag = true;
    }
    else if (enemy_dir == LEFT && movement_flag == false)
    {
        enemy_dir = DOWN;
        previous_enemy_dir = LEFT;
        movement_flag = true;
    }
    else if (enemy_dir == DOWN && previous_enemy_dir == RIGHT && movement_flag == false)
    {
        enemy_dir = LEFT;
        previous_enemy_dir = DOWN;
        movement_flag = true;
    }
    else if (enemy_dir == DOWN && previous_enemy_dir == LEFT &&movement_flag == false)
    {
        enemy_dir = RIGHT;
        previous_enemy_dir = DOWN;
        movement_flag = true;
    }

    for (unsigned int i=0; i<enemies.size(); i++)
    {
        int x = enemies[i].rect.x();
        int y = enemies[i].rect.y();
        if (enemy_dir == RIGHT)
        {
            enemies[i].SetRect(QRect(x+20, y, 20, 20));
            if (enemies[i].rect.x() + enemies[i].rect.width() >= (800-20))
            {
                movement_flag = false;
            }
        }else if (enemy_dir == LEFT)
        {
            enemies[i].SetRect(QRect(x-20, y, 20, 20));
            if (enemies[i].rect.x() <= (0+20))
            {
                movement_flag = false;
            }
        }else if (enemy_dir == DOWN)
        {
            enemies[i].SetRect(QRect(x, y+20, 20, 20));
            movement_flag = false;
        }

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
            EnemySpeed -= (EnemySpeed/10);
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
