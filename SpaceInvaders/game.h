#ifndef GAME_H
#define GAME_H

#include <QPainter>
#include <QKeyEvent>
#include <vector>
#include <QTimer>
#include <QLCDNumber>
#include <QImage>

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
    void AddUiComponents(QLCDNumber *scoreUi, QLCDNumber *livesUi, QLCDNumber *levelUi);

    void BuildBarriers();
    void ClearBarriers();


private:
    QTimer *fpsTimer;
    QLCDNumber *scoreLcd;
    QLCDNumber *livesLcd;
    QLCDNumber *levelLcd;
    int score = 0;
    int lives = 3;
    int level = 1;

    QImage *virus1 = new QImage;
    QImage *virus2 = new QImage;
    QImage *bacteria = new QImage;
    QImage *whiteBloodCell = new QImage;
    QImage *redBloodCell = new QImage;

    std::vector<QRect> barriers;


    QRect *backgroundRect = new QRect(0, 0, 800, 600);

    EnemyManager *enemyManger = new EnemyManager;
    PlayerManager *playerManager = new PlayerManager;

    CollisionDetector collisionDetect;


};

#endif // GAME_H
