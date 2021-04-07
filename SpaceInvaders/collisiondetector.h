#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H

#include <QRect>

class CollisionDetector
{
public:
    CollisionDetector();

    bool RectCollsion(QRect R1, QRect R2);
};

#endif // COLLISIONDETECTOR_H
