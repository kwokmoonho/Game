/***********************************************************************
 * Header File:
 *    flyingObjects
 * Author:
 *    Kwok Moon, Ho
 * Summary:
 *    Base class of bullet and birds
 ************************************************************************/
#ifndef flyingObjects_h
#define flyingObjects_h

#include <stdio.h>
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

class FlyingObjects
{
protected:
    bool alive;
    Point position;
    Velocity speed;
    
public:
    
    
    FlyingObjects();
    virtual ~ FlyingObjects() {};
    //getter
    Point getPoint() {return position;}
    Velocity getVelocity() {return speed;}
    
    //setter
    void setPoint(Point p) {position = p;}
    void setVelocity(Velocity s) {speed = s;}
    
    //methods
    void kill() {alive = false;}
    
    virtual void advance();
    
    virtual void draw() = 0;
    bool isAlive() {return alive;}
};

#endif /* flying_objects_h */
