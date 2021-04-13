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

class Game : public QObject
{
public:
    Game();

    void Init();
    void Update();
    void Draw(QPainter *p, QBrush *brush);
    void CheckCollisions();

    void SetCanShoot();

    void KeyBoardInput(QKeyEvent *key, KeyActionType action);

    QTimer *timer = new QTimer;

private:

    CollisionDetector collisionDetect;

    Player player = Player(400, 500);
    std::vector<Enemy> enemies;//need to make types of enemies
    std::vector<Bullet> bullets;

    bool ShootTimeOut = true;

};

#endif // GAME_H
