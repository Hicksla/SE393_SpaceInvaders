#ifndef GAME_H
#define GAME_H

#include <QPainter>
#include <QKeyEvent>
#include <vector>
#include <QTimer>
#include <QLCDNumber>
#include <QImage>
#include <QTcpSocket>
#include <QHostAddress>
#include <QDebug>

#include "collisiondetector.h"
#include "enemymanager.h"
#include "playermanager.h"
#include "bullet.h"
#include "settings.h"

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
    void UnpauseGame();
    void SendStartGame();

    void KeyBoardInput(QKeyEvent *key, KeyActionType action);
    void AddFpsTimer(QTimer *timer);
    void AddUiComponents(QLCDNumber *scoreUi, QLCDNumber *livesUi, QLCDNumber *levelUi);


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


    QRect *backgroundRect = new QRect(0, 0, 800, 600);

    EnemyManager *enemyManger = new EnemyManager;
    PlayerManager *playerManager = new PlayerManager;

    CollisionDetector collisionDetect;

    // Network
    void ConnectToServer(QHostAddress address, int port);
    void SendData(QString data);
    void ReadData();
    void JoinGame(QString gameStr);
    void SendEnemies();
    void SendStats();

    QTcpSocket clientSocket;
    QString gameString = "waitingList";
    QString connectLevel = "";

    QTimer *netReadTimer = new QTimer;
    QTimer *enemySendTimer = new QTimer;
    QTimer *statsSendTimer = new QTimer;


};

#endif // GAME_H
