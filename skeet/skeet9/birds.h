/*************************************************************
 * File: bird.h
 * Author: Kwok Moon, Ho
 *
 * Description:
 * A Bird class (containing the common elements of all birds)
 * Separate classes for each of the three types of birds.
 *************************************************************/

#ifndef birds_h
#define birds_h

#include <stdio.h>
#include "flyingObjects.h"
//
//Bird class
//
class Bird : public FlyingObjects
{
protected:
    int lives;
    int score;
    int bonus;
    int radius;
    
public:
    //constructor
    Bird();
    Bird(Point p);
    
    ~Bird(){};
    virtual int hit();
};

//standard bird class
class StandardBird : public Bird
{
public:
    StandardBird() {}
    ~ StandardBird(){};
    void draw();
    void advance(Bird & StandardBird) {};
};

//tough bird class
class ToughBird : public Bird
{
public:
    ToughBird();
    ~ ToughBird(){};
    void draw();
    void advance(Bird & ToughBird) {};
};

//scared bird class
class SacredBird : public Bird
{
public:
    SacredBird();
    ~ SacredBird(){};
    void draw();
    void advance(Bird & ScreBird) {};
};

#endif /* birds_h */
