#include "bullet.h"

Bullet::Bullet(int X, int Y)
{
    x = X;
    y = Y;
    circle.setRect(x,y, width, width);
}

void Bullet::Update()
{
    y = y - yVel;
    circle.setRect(x, y, width, width);
}
