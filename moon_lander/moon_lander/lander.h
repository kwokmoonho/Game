/***********************************************************************
 * Header File:
 *    lander.h
 * Author:
 *    Kwok Moon, Ho
 * Summary:
 *    Contains the definition of the lander class.
 ************************************************************************/
#ifndef lander_h
#define lander_h

#include <stdio.h>
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

class Lander
{
private:
    int fuel;
    bool landed;
    bool alive;
    bool thrust;
    Point point;
    Velocity velocity;
    
public:
    //constructor
    Lander();
    
    //getter
    Point getPoint() const {return point;}
    Velocity getVelocity() const {return velocity;}
    int getFuel() {return fuel;}
    bool isAlive() {return alive;}
    bool isLanded() {return landed;}
    bool canThrust();
    
    //setter
    void setLanded(bool landed);
    void setAlive(bool alive);
    void setFuel(int fuel);
    
    //methods
    void applyGravity(float gravity);
    void applyThrustLeft();
    void applyThrustRight();
    void applyThrustBottom();
    
    void advance();
    void draw();
    void asteroid();
    
};

#endif /* lander_h */
