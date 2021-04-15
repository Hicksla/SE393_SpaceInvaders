#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H

#include <QRect>
#include <vector>
#include <bullet.h>

class CollisionDetector
{
public:
    CollisionDetector();

    bool RectCollsion(QRect R1, QRect R2);
    void CheckBulletCollisions(std::vector<Bullet> &EnemyBullets, std::vector<Bullet> &PlayerBullets);
};

#endif // COLLISIONDETECTOR_H
