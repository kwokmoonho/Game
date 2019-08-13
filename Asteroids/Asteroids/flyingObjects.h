/***********************************************************************
 * Header File:
 *    flyingObjects
 * Author:
 *    Kwok Moon, Ho
 * Summary:
 *    Base class of bullet and ship and rock
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
    float angle;
    
public:
    FlyingObjects();
    virtual ~ FlyingObjects() {};
    //getter
    Point getPoint() {return position;}
    Velocity getVelocity() {return speed;}
    float getAngle() {return angle;}
    
    //setter
    void setPoint(Point p) {position = p;}
    void setPosition(int x, int y) {position.setX(x);position.setY(y);}
    void setVelocity(Velocity s) {speed = s;}
    void setAngle(float angle) {this->angle = angle;}
    
    //methods
    void kill() {alive = false;}
    virtual void advance();
    virtual void draw() = 0;
    bool isAlive() {return alive;}
    void wrap();
};

#endif /* flying_objects_h */
