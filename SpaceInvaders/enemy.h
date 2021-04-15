#ifndef ENEMY_H
#define ENEMY_H

#include <QRect>

enum enemy_type {EASY, MEDIUM, HARD, VERY_HARD};

class Enemy
{
public:
    Enemy(int RowLevel);

    void SetRect(QRect Rect);

    enemy_type type;
    int rowLevel;
    QRect rect;
};

#endif // ENEMY_H
