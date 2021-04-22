#include "enemymanager.h"

EnemyManager::EnemyManager()
{
    //connect(arrayMovementTimer, &QTimer::timeout, this, &EnemyManager::updateEnemyArrayLoc);
    connect(shootTimer, &QTimer::timeout, this, &EnemyManager::GenEnemyBullets);
}

void EnemyManager::loadEnemies()
{

    for (int i=0; i < 5; i++)
    {
        for (int j=0; j < 11; j++)
        {
            Enemy newEnemey(i);
            if (i == 0){
                if (j==0)
                {
                    newEnemey.SetRect(QRect(145, 80, width, width));
                    enemies.push_back(newEnemey);
                }
                else
                {
                    newEnemey.SetRect(QRect(enemies[j-1].rect.x() + 30, 80, width, width));
                    enemies.push_back(newEnemey);
                }
            }

            else if (i == 1){
                if (j==0)
                {
                    newEnemey.SetRect(QRect(145, 120, width, width));
                    enemies.push_back(newEnemey);
                }
                else
                {
                    newEnemey.SetRect(QRect(enemies[j-1].rect.x() + 30, 120, width, width));
                    enemies.push_back(newEnemey);
                }

            }

            else if (i == 2){
                if (j==0)
                {
                    newEnemey.SetRect(QRect(145, 160, width, width));
                    enemies.push_back(newEnemey);
                }
                else
                {
                    newEnemey.SetRect(QRect(enemies[j-1].rect.x() + 30, 160, width, width));
                    enemies.push_back(newEnemey);
                }

            }

            else if (i == 3){
                if (j==0)
                {
                    newEnemey.SetRect(QRect(145, 200, width, width));
                    enemies.push_back(newEnemey);
                }
                else
                {
                    newEnemey.SetRect(QRect(enemies[j-1].rect.x() + 30, 200, width, width));
                    enemies.push_back(newEnemey);
                }

            }
            else if (i == 4){
                if (j==0)
                {
                    newEnemey.SetRect(QRect(145, 240, width, width));
                    enemies.push_back(newEnemey);
                }
                else
                {
                    newEnemey.SetRect(QRect(enemies[j-1].rect.x() + 30, 240, width, width));
                    enemies.push_back(newEnemey);
                }

            }
        }
    }
}

void EnemyManager::unloadEnemies()
{
    enemies.clear();
    bullets.clear();
}

void EnemyManager::updateEnemyArrayLoc()
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
            enemies[i].SetRect(QRect(x+xVel, y, width, width));
            if (enemies[i].rect.x() + enemies[i].rect.width() >= (800-(145-width)))
            {
                movement_flag = false;
            }
        }else if (enemy_dir == LEFT)
        {
            enemies[i].SetRect(QRect(x-xVel, y, width, width));
            if (enemies[i].rect.x() <= (145))
            {
                movement_flag = false;
            }
        }else if (enemy_dir == DOWN)
        {
            enemies[i].SetRect(QRect(x, y+yVel, width, width));
            movement_flag = false;
        }

    }

    arrayMovementTimer->setInterval(arrayStartingInterval);
    arrayMovementTimer->start();
}

void EnemyManager::GenEnemyBullets()
{
    srand(time(0));

    unsigned int r;

   r = rand() % enemies.size();

   Bullet b(enemies[r].rect.x(), enemies[r].rect.y()+20, 10, -6);
   bullets.push_back(b);

}

void EnemyManager::Pause()
{
    arrayMovementTimer->stop();
    shootTimer->start();
}

void EnemyManager::Start()
{
    xVel = 2.0;
    yVel = 7.0;
    shootTimer->setInterval(1200);
    shootTimer->start();
}

void EnemyManager::IncreaseLevel()
{
    Pause();
    bullets.clear();
    shootOdds--;
    enemiesKilled = 0;
    loadEnemies();
    Start();
}
