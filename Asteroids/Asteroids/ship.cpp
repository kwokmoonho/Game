/*************************************************************
 * File: Ship.cpp
 * Author: Kwok Moon Ho
 *
 * Description: Contains the function bodies for the Ship class.
 *
 *************************************************************/

#include "ship.h"

/****************************
 * constructor
 *****************************/
Ship::Ship()
{
    thrust = true;
    motion = 0.5;
    alive = true;
}

/****************************
 * can turust
 *****************************/
bool Ship:: canThrust()
{
    if (alive == false )
    {
        return false;
    }
    else
        return true;
}

/****************************
 * apply motion
 *****************************/
void Ship:: applyMotion(float motion)
{
    speed.setDy(speed.getDy() + motion);
}

/****************************
 * apply thrust left
 *****************************/
void Ship::applyThrustLeft()
{
    setAngle(angle += 6);
}

/****************************
 * apply thrust right
 *****************************/
void Ship::applyThrustRight()
{
    setAngle(angle -= 6);
}

/****************************
 * apply thrust bottom
 *****************************/
void Ship::applyThrustBottom()
{
    speed.setDx(0.5 * (sin(M_PI / 180.0 * (getAngle()-180))));
    speed.setDy(0.5 * (-cos(M_PI / 180.0 * (getAngle()-180))));
}

/****************************
 * apply thrust up
 *****************************/
void Ship::applyThrustUp()
{
    speed.setDx(3 * (sin(M_PI / 180.0 * (getAngle()-180))));
    speed.setDy(3 * (-cos(M_PI / 180.0 * (getAngle()-180))));
}

/****************************
 * advance()
 *****************************/
void Ship:: advance()
{
    position.setX(position.getX() + speed.getDx());
    position.setY(position.getY() + speed.getDy());
    wrap();
}

/****************************
 * draw
 *****************************/
void Ship:: draw()
{
    drawShip(position,angle);
}
