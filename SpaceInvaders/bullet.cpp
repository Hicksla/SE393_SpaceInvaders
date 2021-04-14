#include "bullet.h"

Bullet::Bullet(int X, int Y, int Width, int YVel)
{
    x = X;
    y = Y;
    width = Width;
    yVel = YVel;
    circle.setRect(x,y, width, width);
}

void Bullet::Update()
{
    y = y - yVel;
    circle.setRect(x, y, width, width);
}
