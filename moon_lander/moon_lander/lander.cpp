/***********************************************************************
 * Source File:
 *     lander
 * Author:
 *     Kwok Moon, Ho
 * Description:
 *     method of the lander handeling
 ************************************************************************/
#include <stdio.h>
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "game.h"
#include <iostream>
//#include <cassert>

using namespace std;

//////////////
//Constructor
//////////////
Lander :: Lander()
{
    fuel = 500;
    landed = false;
    alive = true;
    thrust = true;
    
}

//////////////
//Setter
//////////////

/*
 set fuel
 */
void Lander :: setFuel(int fuel)
{
    if (fuel < 0) {
        this->fuel = 0;
    } else {
        this->fuel = fuel;
    }
    //assert(fuel >=0);
}


/*
 set alive
 */
void Lander :: setAlive(bool alive)
{
    this->alive = alive;
}


/*
 set landed
 */
void Lander:: setLanded(bool landed)
{
    this->landed = landed;
}


//////////////
//getter
////////////
/*
 canthrust
 */
bool Lander:: canThrust()
{
    if (alive == false || landed == true || fuel <=0)
    {
        return false;
    }
    else
        return true;
}


////////////////
//methods
////////////////

/*
 apply grivaty
 */
void Lander:: applyGravity(float gravity)
{
    velocity.setDy(velocity.getDy() - gravity);
}

/*
 apply thrust left
 */
void Lander:: applyThrustLeft()
{
    setFuel(this->fuel - 1);
    if (this->fuel <=0) {
        return;
    }
    velocity.setDx(velocity.getDx() + 0.1);
}

/*
 apply thrust right
 */
void Lander::applyThrustRight()
{
    setFuel(this->fuel - 1);
    if (this->fuel <=0) {
        return;
    }
    velocity.setDx(velocity.getDx() - 0.1);
}

/*
 apply thrust bottom
 */
void Lander::applyThrustBottom()
{
    setFuel(this->fuel - 3);
    if (this->fuel <=0) {
        return;
    }
    velocity.setDy(velocity.getDy() + 0.3);
}

/*
 advance
 */
void Lander:: advance()
{
    point.setX(point.getX() + velocity.getDx());
    point.setY(point.getY() + velocity.getDy());
}

/*
 draw
 */
void Lander:: draw()
{
    drawLander(point);
}
