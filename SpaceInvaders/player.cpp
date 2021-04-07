#include "player.h"

Player::Player(int X, int Y)
{
    x=X;
    y=Y;

    rect = QRect(x, y, w, h);
}

void Player::Update()
{
    x += xVel;
    rect.setRect(x, y, w, h);
}

void Player::ClearMovement()
{
    movingRight = false;
    movingLeft = true;
    xVel = 0;
}

void Player::SetMovingRight()
{
    movingRight = true;
    xVel = 10;
}

void Player::SetMovingLeft()
{
    movingLeft = true;
    xVel = -10;
}
