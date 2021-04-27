#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <vector>
#include <ctime>
#include <QPainter>
#include <QTimer>
#include <QSoundEffect>

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

    void IncreseSpeed();

    void setEnemies(QString enemies_str_lst);
    QString toString();

    std::vector<Enemy> enemies;//need to make types of enemies
    std::vector<Bullet> bullets;

    int enemiesKilled = 0;
private:
    QTimer *arrayMovementTimer = new QTimer;// in ms
    int arrayStartingInterval = 16;
    int arrayMovementInterval = arrayStartingInterval;
    QTimer *shootTimer = new QTimer;

    double xVel = 1.0;
    double yVel = 6.0;
    double mysteryShipVel = 4.0;

    int mysteryShipsLeft = 2;

    int shootOdds = 12;
    int width = 30;

    unsigned int ENEMYSTARTAMOUNT = 55;
    unsigned int ROWSIZE = 11;
    unsigned int ROWS = 5;
    bool maxSpeed = false;

    //Handles Memory for moving enemy array correctly
    Enemy_Movement enemy_dir = RIGHT;
    Enemy_Movement previous_enemy_dir = RIGHT;
    bool movement_flag = true;

    QSoundEffect laser;
};

#endif // ENEMYMANAGER_H
