#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <vector>
#include <ctime>
#include <QPainter>
#include <QTimer>

#include "enemy.h"
#include "bullet.h"

enum Enemy_Movement {LEFT, RIGHT, DOWN};

class EnemyManager : public QObject
{
public:
    EnemyManager();

    void loadEnemies();
    void unloadEnemies();
    void updateEnemyArrayLoc();

    void GenEnemyBullets();
    void Pause();
    void Start();
    void IncreaseLevel();

    std::vector<Enemy> enemies;//need to make types of enemies
    std::vector<Bullet> bullets;

    int enemiesKilled = 0;
private:
    QTimer *arrayMovementTimer = new QTimer;
    int arrayMovementInterval = 1000; // in ms
    QTimer *shootTimer = new QTimer;

    int shootOdds = 12;
    int width = 30;

    //Handles Memory for moving enemy array correctly
    Enemy_Movement enemy_dir = RIGHT;
    Enemy_Movement previous_enemy_dir = RIGHT;
    bool movement_flag = true;
};

#endif // ENEMYMANAGER_H
