/***********************************************************************
 * Header File:
 *    velocity.h
 * Author:
 *    Kwok Moon, Ho
 * Summary:
 *    Contains the definition of the velocity class.
 ************************************************************************/
#ifndef velocity_h
#define velocity_h

#include <stdio.h>

class Velocity
{
private:
    float dx;
    float dy;
    
public:
    //constructor
    Velocity();
    Velocity(float dx,float dy);
    
    //getter
    float getDx() const {return dx;}
    float getDy() const {return dy;}
    
    //setter
    void setDx(float dx);
    void setDy(float dy);
    
};

#endif /* velocity_h */
