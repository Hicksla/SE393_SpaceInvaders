#include "enemymanager.h"

EnemyManager::EnemyManager()
{
    connect(arrayMovementTimer, &QTimer::timeout, this, &EnemyManager::updateEnemyArrayLoc);
    connect(shootTimer, &QTimer::timeout, this, &EnemyManager::GenEnemyBullets);
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
                    newEnemey.SetRect(QRect(125, 80, width, width));
                    enemies.push_back(newEnemey);
                }
                else
                {
                    newEnemey.SetRect(QRect(enemies[j-1].rect.x() + 50, 80, width, width));
                    enemies.push_back(newEnemey);
                }
            }

            else if (i == 1){
                if (j==0)
                {
                    newEnemey.SetRect(QRect(125, 120, width, width));
                    enemies.push_back(newEnemey);
                }
                else
                {
                    newEnemey.SetRect(QRect(enemies[j-1].rect.x() + 50, 120, width, width));
                    enemies.push_back(newEnemey);
                }

            }

            else if (i == 2){
                if (j==0)
                {
                    newEnemey.SetRect(QRect(125, 160, width, width));
                    enemies.push_back(newEnemey);
                }
                else
                {
                    newEnemey.SetRect(QRect(enemies[j-1].rect.x() + 50, 160, width, width));
                    enemies.push_back(newEnemey);
                }

            }

            else if (i == 3){
                if (j==0)
                {
                    newEnemey.SetRect(QRect(125, 200, width, width));
                    enemies.push_back(newEnemey);
                }
                else
                {
                    newEnemey.SetRect(QRect(enemies[j-1].rect.x() + 50, 200, width, width));
                    enemies.push_back(newEnemey);
                }

            }
            else if (i == 4){
                if (j==0)
                {
                    newEnemey.SetRect(QRect(125, 240, width, width));
                    enemies.push_back(newEnemey);
                }
                else
                {
                    newEnemey.SetRect(QRect(enemies[j-1].rect.x() + 50, 240, width, width));
                    enemies.push_back(newEnemey);
                }

            }
        }
    }
    enemy_dir = RIGHT;
    previous_enemy_dir = RIGHT;
    movement_flag = true;
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
            enemies[i].SetRect(QRect(x+20, y, width, width));
            if (enemies[i].rect.x() + enemies[i].rect.width() >= (800-width))
            {
                movement_flag = false;
            }
        }else if (enemy_dir == LEFT)
        {
            enemies[i].SetRect(QRect(x-20, y, width, width));
            if (enemies[i].rect.x() <= (0+20))
            {
                movement_flag = false;
            }
        }else if (enemy_dir == DOWN)
        {
            enemies[i].SetRect(QRect(x, y+20, width, width));
            movement_flag = false;
        }

    }
    arrayMovementTimer->setInterval(arrayMovementInterval);
    arrayMovementTimer->start();
}

void EnemyManager::setEnemies(QString enemies_str_lst) {
    unloadEnemies();
    QStringList enemies_lst = enemies_str_lst.split(",");
    for (QString& enemy_str:enemies_lst) {
        if (enemy_str==""||enemy_str == "e") continue;
        if (debug) {
            qDebug() << enemy_str;
        }
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

void EnemyManager::GenEnemyBullets()
{
//    srand(time(0));

//    unsigned int r;
//    unsigned int divisor;

//    if (enemies.size() % 10 < 3)
//    {
//        arrayMovementInterval -= (arrayMovementInterval/40);
//    }

//    if (enemies.size() <= 3)
//    {
//        divisor = 1;
//    }else
//    {
//        divisor = enemies.size()/ 2;
//    }

//    if (divisor)

//    for (unsigned int i=0; i<enemies.size()/divisor; i++)
//    {
//       r = rand() % enemies.size();

//       Bullet b(enemies[r].rect.x(), enemies[r].rect.y()+20, 10, -2);
//       bullets.push_back(b);
//    }
}

void EnemyManager::Pause()
{
    arrayMovementTimer->stop();
    shootTimer->start();
}

void EnemyManager::Start()
{
    shootTimer->setInterval(1200);
    arrayMovementTimer->setInterval(arrayMovementInterval);
    arrayMovementTimer->start();
    shootTimer->start();
}

void EnemyManager::IncreaseLevel()
{
//    Pause();
    arrayMovementInterval -= (arrayMovementInterval/30);
    shootOdds--;
    enemiesKilled = 0;
    loadEnemies();
//    Start();
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
