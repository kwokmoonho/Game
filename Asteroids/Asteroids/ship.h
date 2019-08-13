/*************************************************************
 * File: Ship.h
 * Author: Kwok Moon Ho
 *
 * Description: Defines a Ship.
 *************************************************************/
#ifndef ship_H
#define ship_H

#include "flyingObjects.h"
#define SHIP_SIZE 10


class Ship:public FlyingObjects
{
protected:
    bool thrust;
    float motion;
    
public:
    Ship();
    ~Ship(){};
    bool canThrust();
    
    void applyMotion(float motion);
    void applyThrustLeft();
    void applyThrustRight();
    void applyThrustBottom();
    void applyThrustUp();
    void advance();
    void draw();
};
#endif
