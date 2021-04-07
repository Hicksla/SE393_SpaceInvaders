#ifndef PLAYER_H
#define PLAYER_H

#include <QRect>

class Player
{
public:
    Player(int X, int Y);

    void Update();

    void ClearMovement();
    void SetMovingRight();
    void SetMovingLeft();

public:
    int x;
    int y;
    int xVel = 0;
    int w = 25;
    int h = 25;

    QRect rect;

    bool movingLeft = false;
    bool movingRight = false;

private:

};

#endif // PLAYER_H
