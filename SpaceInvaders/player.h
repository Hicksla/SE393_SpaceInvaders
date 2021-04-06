#ifndef PLAYER_H
#define PLAYER_H

#include <QRect>

class Player
{
public:
    Player(int X, int Y);

    void Update();

public:
    int x;
    int y;
    int w = 50;
    int h = 50;

    QRect rect;

private:

};

#endif // PLAYER_H
