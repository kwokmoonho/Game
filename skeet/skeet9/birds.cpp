#include "birds.h"
#include <iostream>
using namespace std;

/*
 constructor
 */
Bird:: Bird()
{
    position.setX(-200.0);
    position.setY(random(-150, 150));
    
    speed.setDx(random(3, 6));
    
    if (position.getY() >= 0)
    {
        speed.setDy(random(-4, 0));
    }
    else
    {
        speed.setDy(random(0, 4));
    }
    radius = 15;
    score = 1;
    bonus = 0;
    lives = 1;
    
}

Bird :: Bird(Point p)
{
    setPoint(p);
}

int Bird:: hit()
{
    lives--;
    if (lives == 0)
    {
        kill();
        return score + bonus;
    }
    return score;
}

///
//StandardBird
///
void StandardBird :: draw()
{
    drawLander(getPoint());
}



///
//ToughBird
///
ToughBird:: ToughBird()
{
    lives = 3;
    bonus = 2;
    
    speed.setDx(random(2, 4));
    
    if (position.getY() >= 0)
    {
        speed.setDy(random(-3, 0));
    }
    else
    {
        speed.setDy(random(0, 3));
    }
}


void ToughBird:: draw()
{
    drawToughBird(getPoint(), radius, lives);
}


//
//scared bird
//
SacredBird:: SacredBird()
{
    bonus = -11;
}

void SacredBird:: draw()
{
    drawSacredBird(getPoint(), radius);
}




















