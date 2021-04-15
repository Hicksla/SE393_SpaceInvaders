#ifndef PLAYER_H
#define PLAYER_H

#include <QRect>

class Player
{
public:
    Player();

    void Update();

    void ClearMovement();
    void SetMovingRight();
    void SetMovingLeft();
    void SetPlayerPosition(int x, int y);

public:
    int x;
    int y;
    int xVel = 0;
    int w = 25;
    int h = 25;

    int Alive = true;

    QRect rect;

private:
    bool movingLeft = false;
    bool movingRight = false;


};

#endif // PLAYER_H
