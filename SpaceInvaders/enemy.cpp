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

bool Enemy::Shoot(float time, float odds, int deltaTime)
{
    float adj_odds = deltaTime / 1000.0 * 20.0;
}
