/***********************************************************************
 * Source File:
 *     bullet.cpp
 * Author:
 *     Kwok Moon, Ho
 * Description:
 *
 ************************************************************************/
#include "bullet.h"
/****************************
 * fire
 *****************************/
void Bullet::fire(Point point, float angle)
{
    position = point;
    setAngle(angle);
    life = 0;
}

/****************************
 * draw()
 *****************************/
void Bullet::draw()
{
    drawDot(getPoint());
}

/****************************
 * advance()
 *****************************/
void Bullet::advance()
{
    Point newPosition;
    speed.setDx(BULLET_SPEED * (sin(3.14 / 180.0 * (angle-180))));
    speed.setDy(BULLET_SPEED * (-cos(3.14 / 180.0 * (angle-180))));
    newPosition.setX(getPoint().getX() + getVelocity().getDx());
    newPosition.setY(getPoint().getY() + getVelocity().getDy());
    
    setPoint(newPosition);
    life++;
    
    if (life >= 40)
        kill();
}
