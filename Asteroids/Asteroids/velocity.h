/***********************************************************************
 * Header File:
 *    Velocity
 * Author:
 *    Kwok Moon Ho
 * Summary:
 *    Everything we need to know about velocity.
 ************************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H


class Velocity
{
private:
    
    float dx;
    float dy;
    
public:
    
    //CONSTRUCTORS
    Velocity() {}
    Velocity(float dx, float dy) {};
    
    //SETTERS
    void setDx(float dx);
    void setDy(float dy);
       
    //GETTERS
    float getDx() const { return dx; }
    float getDy() const { return dy; }
    
};

#endif
