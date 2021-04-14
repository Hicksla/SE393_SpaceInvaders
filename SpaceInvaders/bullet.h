#ifndef BULLET_H
#define BULLET_H

#include <QRect>

class Bullet
{
public:
    Bullet(int X, int Y, int Width, int YVel);

    void Update();

    int x;
    int y;
    int width;
    int yVel;

    QRect circle;
};

#endif // BULLET_H
