#include "enemymanager.h"
#include <iostream>

EnemyManager::EnemyManager()
{
    laser.setSource(QUrl::fromLocalFile(":/laser/Music/laser.wav"));
    connect(shootTimer, &QTimer::timeout, this, &EnemyManager::GenEnemyBullets);
    connect(arrayMovementTimer, &QTimer::timeout, this, &EnemyManager::updateEnemyArrayLoc);
}

void EnemyManager::loadEnemies()
{
    unloadEnemies();
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

void EnemyManager::IncreseSpeed()
{
    if (maxSpeed == true)
    {
        return;
    }else{
        if (enemies.size() == ENEMYSTARTAMOUNT - ROWSIZE || enemies.size() == ENEMYSTARTAMOUNT - (2*ROWSIZE)
                || enemies.size() == ENEMYSTARTAMOUNT - (3*ROWSIZE) || enemies.size() == ENEMYSTARTAMOUNT - (4*ROWSIZE))
        {
            xVel += .02;
        }else if (enemies.size() == 3)
        {
           xVel += .03;
        }else if(enemies.size() == 1)
        {
            xVel += .04;
            maxSpeed = true;
        }
    }

}

void EnemyManager::updateEnemyArrayLoc()
{
    IncreseSpeed();

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

        if (enemies[i].rowLevel == -1)
        {
            if (x+enemies[i].rect.width() + mysteryShipVel >= 800 || x - mysteryShipVel <= 0 )
            {
                enemies.erase(enemies.begin() + i);
            }else
            {
                enemies[i].SetRect(QRect(x+mysteryShipVel, y, width, width));
            }

        }else{
            if (enemy_dir == RIGHT)
            {
                enemies[i].SetRect(QRect(x+xVel, y, width, width));
                if (enemies[i].rect.x() + enemies[i].rect.width() >= (800-(100-width)))
                {
                    movement_flag = false;
                }
            }else if (enemy_dir == LEFT)
            {
                enemies[i].SetRect(QRect(x-xVel, y, width, width));
                if (enemies[i].rect.x() <= 100)
                {
                    movement_flag = false;
                }
            }else if (enemy_dir == DOWN)
            {
                enemies[i].SetRect(QRect(x, y+yVel, width, width));
                movement_flag = false;
            }
        }

    }

    if (enemies.size() <= ENEMYSTARTAMOUNT - 26 && mysteryShipsLeft == 2)
    {
        Enemy mysteryShip(-1);
        mysteryShip.SetRect(QRect(145, 80, 30, 30));
        enemies.push_back(mysteryShip);
        mysteryShipVel = 4.0;
        mysteryShipsLeft--;

    }else if (enemies.size() <= ENEMYSTARTAMOUNT - 39 && mysteryShipsLeft == 1)
    {
        Enemy mysteryShip(-1);
        enemies.push_back(mysteryShip);
        mysteryShip.SetRect(QRect(655, 80, 30, 30));
        mysteryShipVel = -4.0;
        mysteryShipsLeft--;
    }

}

void EnemyManager::GenEnemyBullets()
{
    srand(time(0));

    unsigned int r;

   r = rand() % enemies.size();

   Bullet b(enemies[r].rect.x(), enemies[r].rect.y()+20, 10, -6);
   bullets.push_back(b);
   laser.play();

}

void EnemyManager::Pause()
{
    shootTimer->stop();
}

void EnemyManager::Start()
{
    xVel = 20.0;
    yVel = 26.0;
    mysteryShipVel *= -30;
    mysteryShipsLeft = 2;
    mysteryShipVel = 30.0;
    maxSpeed = false;
    shootTimer->setInterval(1200);
    shootTimer->start();
    arrayMovementTimer->setInterval(arrayMovementInterval);
    arrayMovementTimer->start();
}

void EnemyManager::IncreaseLevel()
{
    Pause();
    bullets.clear();
    loadEnemies();
    Start();
}

void EnemyManager::setEnemies(QString enemies_str_lst) {
    enemies.clear();
    QStringList enemies_lst = enemies_str_lst.split(",");
    for (QString& enemy_str:enemies_lst) {
        if (enemy_str==""||enemy_str == "e") continue;
        QStringList enemy_data = enemy_str.split(":");
        bool okLevel,okx,oky;
        int level = enemy_data[0].toInt(&okLevel);
        int x = enemy_data[1].toInt(&okx);
        int y = enemy_data[2].toInt(&oky);
        if (!okx||!oky) return;

        Enemy newEnemy(level);
        newEnemy.SetRect(QRect(x,y,width,width));
        enemies.push_back(newEnemy);
    }
}

QString EnemyManager::toString() {
    QString enemies_str;

    // enemy data sep: :
    // enemy sep: ,

    for (Enemy& e:enemies) {
         enemies_str +=QString::number(e.rowLevel)+":"+QString::number(e.rect.x())+":"+QString::number(e.rect.y())+",";

    }
    return enemies_str;
}
