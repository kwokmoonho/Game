/***********************************************************************
 * Source File:
 *     velocity
 * Author:
 *     Kwok Moon, Ho
 * Description:
 *      method of the velocity handeling
 ************************************************************************/
#include "velocity.h"
#include <iostream>

using namespace std;

//////////////
//Constructor
//////////////
Velocity :: Velocity()
{
    dx = 0;
    dy = 0;
}

Velocity :: Velocity(float dx, float dy)
{
    this->dx = dx;
    this->dy = dy;
}


//////////////
//Setter
//////////////

/*
 set Dx
 */
void Velocity::setDx(float dx)
{
    this->dx = dx;
}

/*
 set Dy
 */
void Velocity::setDy(float dy)
{
    this->dy = dy;
}

