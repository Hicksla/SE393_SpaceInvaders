#ifndef GAME_H
#define GAME_H

#include <QPainter>
#include <QKeyEvent>
#include <vector>
#include <QTimer>

#include "collisiondetector.h"
#include "enemymanager.h"
#include "playermanager.h"

enum KeyActionType {PRESS, RELEASE};

class Game : public QObject
{
public:
    Game();

    void Init();
    void Update();
    void Draw(QPainter *p, QBrush *brush);
    void CheckCollisions();
    void PauseGame();

    void KeyBoardInput(QKeyEvent *key, KeyActionType action);
    void AddFpsTimer(QTimer *timer);


private:
    QTimer *fpsTimer;

    QRect *backgroundRect = new QRect(0, 0, 800, 600);

    EnemyManager *enemyManger = new EnemyManager;
    PlayerManager *playerManager = new PlayerManager;

    CollisionDetector collisionDetect;


};

#endif // GAME_H
