#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include <vector>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>

#include "player.h"
#include "bullet.h"

class PlayerManager : public QObject
{
public:
    PlayerManager();
    void LoadPlayer();
    void Shoot();

    void SetPlayerCanShoot();

    Player *player = new Player;
    std::vector<Bullet> bullets;

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    QTimer *shootTimer = new QTimer;
    bool shootTimeOut = true;
};

#endif // PLAYERMANAGER_H
