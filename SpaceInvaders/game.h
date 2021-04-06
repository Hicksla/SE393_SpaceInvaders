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
    void Update();
    void Draw(QPainter *p);

    void KeyBoardInput(QKeyEvent *key);


private:

    Player player = Player(400, 500);
};

#endif // GAME_H
