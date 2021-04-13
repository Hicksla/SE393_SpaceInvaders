#ifndef ENEMY_H
#define ENEMY_H

#include <QRect>

enum enemy_type {EASY, MEDIUM, HARD, VERY_HARD};

class Enemy
{
public:
    Enemy();

    void SetRect(QRect Rect);

    enemy_type type;
    QRect rect;
};

#endif // ENEMY_H
