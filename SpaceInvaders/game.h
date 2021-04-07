#ifndef GAME_H
#define GAME_H

#include <QPainter>
#include <QKeyEvent>
#include <vector>

#include "player.h"
#include "bullet.h"

class Game
{
public:
    Game();

    void Init();
    void Update();
    void Draw(QPainter *p);
    void CheckCollisions();

    void KeyBoardInput(QKeyEvent *key);


private:

    Player player = Player(400, 500);

    QRect enemies1[13]; //need to make types of enemies

    std::vector<Bullet> bullets;

};

#endif // GAME_H
