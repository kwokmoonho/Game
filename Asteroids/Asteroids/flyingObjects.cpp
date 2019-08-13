/*************************************************************
 * File: flyingObjects.cpp
 * Author: Kwok Moon, Ho
 *
 * Description:
 * the methods class for the flyingObjects.h
 *************************************************************/
#include "flyingObjects.h"

/****************************
 * Consttructor
 *****************************/
FlyingObjects :: FlyingObjects()
{
    alive = true;
    angle = 0;
}

/****************************
 * advance()
 *****************************/
void FlyingObjects :: advance()
{
    position.addX(speed.getDx());
    position.addY(speed.getDy());
    wrap();
}

/*********************************************************************
 * Function: wrap
 * Description: When the object leaves the screen it is wrapped back around
 * to the other side.
 *********************************************************************/
void FlyingObjects::wrap()
{
    if (getPoint().getX() < -200)
        setPosition(200, getPoint().getY());
    else if (getPoint().getX() > 200)
        setPosition(-200, getPoint().getY());
    
    if (getPoint().getY() < -200)
        setPosition(getPoint().getX(), 200);
    else if (getPoint().getY() > 200)
        setPosition(getPoint().getX(), -200);
    
}
