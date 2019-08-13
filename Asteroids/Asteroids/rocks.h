/***********************************************************************
 * Header File:
 *    rocks : Defines the Asteroids 
 * Author:
 *    Kwok Moon Ho
 * Summary:
 *     THe file contains the classes needed for the Asteroids.
 ************************************************************************/
#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#include "flyingObjects.h"
#include "point.h"
#include "uiDraw.h"
#include "velocity.h"
#include <vector>

/****************************
 * Rock class
 *****************************/
class Rock : public FlyingObjects
{
public:
    Rock();
    int getSize() {return size;}
    virtual void hit(std::vector<Rock*> &rocks) = 0;
    
protected:
    int size;
    int rotation;
};

/****************************
 * Small Rock class
 *****************************/
class SmallRock : public Rock
{
public:
    SmallRock(Point newPosition, Velocity newVelocity)
    {
        size = SMALL_ROCK_SIZE;
        setPoint(newPosition);
        setVelocity(newVelocity);
        rotation = 10;
    }
    void draw();
    void advance(Point target);
    void hit(std::vector<Rock*> &rocks){kill();}
};

/****************************
 * Medium Rock class
 *****************************/
class MediumRock : public Rock
{
public:
    MediumRock(Point newPosition, Velocity newVelocity);
    void draw();
    void advance(Point target);
    void hit(std::vector<Rock*> &rocks);
};

/****************************
 * Big Rock class
 *****************************/
class BigRock : public Rock
{
public:
    BigRock() {size = BIG_ROCK_SIZE; rotation = 0;}
    void draw();
    void advance(Point target);
    void hit(std::vector<Rock*> &rocks);
};

#endif /* rocks_h */
