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
