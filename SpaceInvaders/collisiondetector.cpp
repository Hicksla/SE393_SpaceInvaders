#include "collisiondetector.h"

CollisionDetector::CollisionDetector()
{

}

bool CollisionDetector::RectCollsion(QRect R1, QRect R2)
{
    if   (  (  R1.topLeft().x()  >  R2.bottomRight().x()  )||  (  R1.bottomRight().x()  <  R2.topLeft().x()  )  || (  R1.topLeft().y() > R2.bottomRight().y() ) ||
         (   R1.bottomRight().y()  <  R2.topLeft().y()   ) )
    {
        return false;
    }

    else {
        return true; //Intersected
    }


}

void CollisionDetector::CheckBulletCollisions(std::vector<Bullet> &EnemyBullets, std::vector<Bullet> &PlayerBullets)
{
    for (unsigned int i=0; i<PlayerBullets.size(); i++)
    {
        if (PlayerBullets[i].circle.y() <= 0)
        {
           PlayerBullets.erase(PlayerBullets.begin() + i);
        }
    }

    for (unsigned int i=0; i<EnemyBullets.size(); i++)
    {
        if (EnemyBullets[i].circle.y() >= 600)
        {
            EnemyBullets.erase(EnemyBullets.begin() + i);
        }
    }
}
