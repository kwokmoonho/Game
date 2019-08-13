/***********************************************************************
 * Source File:
 *     bullet.cpp
 * Author:
 *     Kwok Moon, Ho
 * Description:
 *
 ************************************************************************/
#include "bullet.h"
#include <iostream>

using namespace std;

/**********************************************************************
 * Function: draw()
 * Purpose: draws the bullet
 **********************************************************************/
void Bullet:: draw()
{
    drawDot(getPoint());
}

/**********************************************************************
 * Function: fire()
 * Purpose: Takes and sets the bullet point and angle
 **********************************************************************/
void Bullet:: fire(Point p, float a)
{
    position = p;
    angle = a;
}

/**********************************************************************
 * Function: Advance()
 * Purpose: advances the bullet on the screen
 **********************************************************************/
void Bullet:: advance()
{
    speed.setDx(BULLET_SPEED * (-cos(M_PI / 180.0 * angle)));
    speed.setDy(BULLET_SPEED * (sin(M_PI / 180.0 * angle)));
    
    FlyingObjects::advance();
}
