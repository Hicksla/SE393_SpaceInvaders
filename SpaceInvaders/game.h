#ifndef GAME_H
#define GAME_H

#include <QPainter>
#include <QKeyEvent>
#include <vector>
#include <QTimer>

#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "collisiondetector.h"

enum KeyActionType {PRESS, RELEASE};
enum Enemy_Movement {LEFT, RIGHT, DOWN};

class Game : public QObject
{
public:
    Game();

    void Init();
    void Update();
    void Draw(QPainter *p, QBrush *brush);
    void CheckCollisions();
    void UpdateEnemyLoc();
    void SetCanShoot();

    void KeyBoardInput(QKeyEvent *key, KeyActionType action);
    void AddFpsTimer(QTimer *timer);



private:
    void loadPlayer();
    void loadEnemies();
    void unloadEnemies();

private:
    QTimer *fpsTimer;
    QTimer *timer = new QTimer;
    QTimer *enemyTimer = new QTimer;

    QRect *backgroundRect = new QRect(0, 0, 800, 600);

    CollisionDetector collisionDetect;

    Player player = Player(400, 500);
    std::vector<Enemy> enemies;//need to make types of enemies
    std::vector<Bullet> bullets;

    int EnemySpeed = 100;
    Enemy_Movement enemy_dir = RIGHT;
    Enemy_Movement previous_enemy_dir = RIGHT;
    bool movement_flag = true;
    bool ShootTimeOut = true;

};

#endif // GAME_H
