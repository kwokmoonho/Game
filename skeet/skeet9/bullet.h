/*************************************************************
 * File: bullet.h
 * Author: Kwok Moon, Ho
 *
 * Description:
 * The Bullet class.
 *************************************************************/
#ifndef bullet_h
#define bullet_h

#include <stdio.h>
#include <cmath>

#include "flyingObjects.h"


#define BULLET_SPEED 10.0


class Bullet : public FlyingObjects
{
protected:
    float angle;
    
public:
    //constructor
    Bullet() : angle(45.0) {}
    ~ Bullet() {};
    
    //method
    void draw();
    void advance();
    void fire(Point p, float a);
    
};

#endif /* bullet_h */
