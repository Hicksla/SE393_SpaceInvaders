#include "enemy.h"

Enemy::Enemy(int RowLevel)
{
    type = EASY;
    rowLevel = RowLevel;
}

void Enemy::SetRect(QRect Rect)
{
    rect = Rect;
}

