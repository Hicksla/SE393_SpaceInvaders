#include "player.h"

Player::Player(int X, int Y)
{
    x=X;
    y=Y;

    rect = QRect(x, y, w, h);
}

void Player::Update()
{
    rect.setRect(x, y, w, h);
}
