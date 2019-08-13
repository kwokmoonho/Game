#include "rocks.h"


/****************************
 * Rock class
 *****************************/
Rock::Rock()
{
    position.setX(random(-200,200));
    position.setY(random(100, 200));
    
    speed.setDx(1);
    
    if (position.getY() >= 0)
    {
        speed.setDy(random(-4, 0));
    }
    else
    {
        speed.setDy(random(0, 4));
    }
}

/****************************
 * Method of the SmallRock class
 *****************************/
void SmallRock::draw()
{
    rotation += SMALL_ROCK_SPIN;
    drawSmallAsteroid(getPoint(), rotation);
}

/***************************
 * Method of the MediumRock class
 *****************************/
MediumRock:: MediumRock(Point newPosition, Velocity newVelocity)
{
    size = MEDIUM_ROCK_SIZE;
    setPoint(newPosition);
    setVelocity(newVelocity);
    rotation = 5;
}

/****************************
 * draw
 *****************************/
void MediumRock::draw()
{
    rotation += MEDIUM_ROCK_SPIN;
    drawMediumAsteroid(getPoint(), rotation);
}

/****************************
 * hit
 *****************************/
void MediumRock :: hit(std::vector<Rock*> &rocks)
{
    kill();
    Velocity newVelocity;
    newVelocity = getVelocity();
    
    //first small rock
    newVelocity.setDx(getVelocity().getDx() + 3);
    rocks.push_back(new SmallRock (getPoint(),newVelocity));
    
    //second small rock
    newVelocity.setDx(getVelocity().getDx() - 3);
    rocks.push_back(new SmallRock (getPoint(),newVelocity));
}

/* ***************************
 * Method of the BigRock class
 *****************************/
void BigRock::draw()
{
    rotation += BIG_ROCK_SPIN;
    drawLargeAsteroid(getPoint(), rotation);
}

/****************************
 * hit()
 *****************************/
void BigRock :: hit(std::vector<Rock*> &rocks)
{
    kill();
    //Rock* newRockM;
    Velocity newVelocity;
    newVelocity = getVelocity();
    
    //small rock
    newVelocity.setDx(getVelocity().getDx() + 2);
    rocks.push_back(new SmallRock (getPoint(),newVelocity));
    
    //first medium rock
    newVelocity.setDx(getVelocity().getDx());
    newVelocity.setDy(getVelocity().getDy() + 1);
    rocks.push_back(new MediumRock (getPoint(),newVelocity));
    
    //second medium rock
    newVelocity.setDy(getVelocity().getDy() - 1);
    rocks.push_back(new MediumRock (getPoint(),newVelocity));
}


