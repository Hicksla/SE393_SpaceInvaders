#ifndef GAME_H
#define GAME_H

#include <QPainter>
#include <QKeyEvent>

#include "player.h"

class Game
{
public:
    Game();

    void Init();
    void Update(QPainter *p);

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    Player player = Player(400, 500);
};

#endif // GAME_H
