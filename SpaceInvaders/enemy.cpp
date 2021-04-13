#include "enemy.h"

Enemy::Enemy()
{
    type = EASY;
}

void Enemy::SetRect(QRect Rect)
{
    rect = Rect;
}
