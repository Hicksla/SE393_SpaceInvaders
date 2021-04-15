#include "enemymanager.h"

EnemyManager::EnemyManager()
{
    connect(arrayMovementTimer, &QTimer::timeout, this, &EnemyManager::updateEnemyArrayLoc);

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
                    newEnemey.SetRect(QRect(200, 80, 20, 20));
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
                    newEnemey.SetRect(QRect(200, 120, 20, 20));
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
                    newEnemey.SetRect(QRect(200, 160, 20, 20));
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
                    newEnemey.SetRect(QRect(200, 200, 20, 20));
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
                    newEnemey.SetRect(QRect(200, 240, 20, 20));
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

    GenEnemyBullets();
    arrayMovementTimer->start();
}

void EnemyManager::GenEnemyBullets()
{
    srand(time(0));

    unsigned int r;
    unsigned int eSize = enemies.size();
    for (unsigned int i=0; i<eSize; i++)
    {
       r = rand() % eSize*12;

       if (r < eSize)
       {
           Bullet b(enemies[r].rect.x(), enemies[r].rect.y()+20, 10, -2);
           bullets.push_back(b);
       }
    }
}

void EnemyManager::Pause()
{
    arrayMovementTimer->stop();
}

void EnemyManager::Start()
{
    arrayMovementTimer->setInterval(arrayMovementInterval);
    arrayMovementTimer->start();
}
