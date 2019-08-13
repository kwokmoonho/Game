/*************************************************************
 * File: flyingObjects.cpp
 * Author: Kwok Moon, Ho
 *
 * Description:
 * the methods class for the flyingObjects.h
 *************************************************************/
#include "flyingObjects.h"

FlyingObjects :: FlyingObjects()
{
    alive = true;
}



void FlyingObjects :: advance()
{
    position.addX(speed.getDx());
    position.addY(speed.getDy());
}


