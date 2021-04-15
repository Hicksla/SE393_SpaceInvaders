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
#include "enemymanager.h"

enum KeyActionType {PRESS, RELEASE};

class Game : public QObject
{
public:
    Game();

    void Init();
    void Update();
    void Draw(QPainter *p, QBrush *brush);
    void CheckCollisions();
    void SetCanShoot();
    void PauseGame();

    void KeyBoardInput(QKeyEvent *key, KeyActionType action);
    void AddFpsTimer(QTimer *timer);



private:
    void loadPlayer();

private:
    QTimer *fpsTimer;
    QTimer *timer = new QTimer;

    QRect *backgroundRect = new QRect(0, 0, 800, 600);

    EnemyManager *enemyManger = new EnemyManager;

    CollisionDetector collisionDetect;

    Player player = Player(400, 500);
    std::vector<Bullet> bullets;

    Enemy_Movement enemy_dir = RIGHT;
    Enemy_Movement previous_enemy_dir = RIGHT;
    bool movement_flag = true;
    bool ShootTimeOut = true;

};

#endif // GAME_H
