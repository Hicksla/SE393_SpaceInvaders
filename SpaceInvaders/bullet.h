#ifndef BULLET_H
#define BULLET_H

#include <QRect>

class Bullet
{
public:
    Bullet(int x, int y);

    void Update();

    int x;
    int y;
    int width = 10;
    int yVel = 15;

    QRect circle;
};

#endif // BULLET_H
