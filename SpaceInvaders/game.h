#ifndef GAME_H
#define GAME_H

#include <QPainter>
#include <QKeyEvent>
#include <vector>
#include <QTimer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QDebug>

#include "player.h"
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
    std::vector<QRect> enemies1; //need to make types of enemies
    std::vector<Bullet> bullets;



    bool ShootTimeOut = true;


    void ConnectToServer(QHostAddress address, int port);
    void SendData(QString data);
    void ReadData();
    void JoinGame(QString gameStr);

    QTcpSocket clientSocket;
    QString gameString = "waitingList";
    QString connectLevel = "";

    QTimer *netReadTimer = new QTimer;

    Player altPlayer = Player(200,500);
    std::vector<Bullet> altBullets;
    bool altShootTimeOut = true;

};

#endif // GAME_H
