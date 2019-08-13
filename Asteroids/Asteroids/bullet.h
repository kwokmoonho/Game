/*************************************************************
 * File: bullet.h
 * Author: Kwok Moon, Ho
 *
 * Description:
 * The Bullet class.
 *************************************************************/
#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5.5

#include <cmath>
#include "flyingObjects.h"


class Bullet : public FlyingObjects
{
public:
    Bullet() {};
    ~ Bullet(){};
    
    void fire(Point point, float angle);
    void draw();
    void advance();
    
protected:
    int life;
};



#endif /* bullet_h */
