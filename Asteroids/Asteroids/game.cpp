/*************************************************************
 * File: game.cpp
 * Author: Kwok Moon Ho
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *************************************************************/
#include <limits>
#include <algorithm>

#include "game.h"
using namespace std;



/*********************************************************************
 * Function: Game::Game
 * Description: Constructor for the game.
 *********************************************************************/
Game::Game(Point tl, Point br)
{
}

Game::~Game()
{
}

/*********************************************************************
 * Function: handleCollisions
 * Description: Used to determine collisions between player, asteroids,
 * and bullets and call functions accordingly.
 *********************************************************************/
void Game::handleInput(const Interface & ui)
{
    if (ship.isAlive())
    {
        if (ui.isUp())
        {
            ship.applyThrustUp();
        }
        if (ui.isDown()) {
            ship.applyThrustBottom();
        }
        if (ui.isLeft()) {
            ship.applyThrustLeft();
        }
        if (ui.isRight()) {
            ship.applyThrustRight();
        }
        if (ui.isSpace())
        {
            Bullet newBullet;
            newBullet.fire(ship.getPoint(), ship.getAngle());
            
            bullets.push_back(newBullet);
        }
    }
}


/*********************************************************************
 * Function: advance
 * Description: The main advance function of the program.
 *********************************************************************/
void Game::advance()
{
    advanceRock();
    if (ship.isAlive())
    {
    ship.advance();
    }
    advanceBullets();
    handleCollisions();
    cleanUpZombies();
}

/* ***************************
 * createRock()
 *****************************/
void Game :: createRock()
{
    for (int i = 0; i < 5; i++)
    {
        Rock* newRock;
        newRock = new BigRock();
        rocks.push_back(newRock);
    }
}

/*********************************************************************
 * Function: draw
 * Description: Main draw function that will draw all asteroids, ships,
 * bullets, and text.
 *********************************************************************/
void Game :: draw(const Interface & ui)
{
    vector<Rock*>::iterator it;
    vector<Bullet*>::iterator lt;
    
    //rocks
    for (vector <Rock*> :: iterator it = rocks.begin(); it != rocks.end(); ++it)
    {
        (*it)->draw();
    }
    
    
    //ship and flame
    if (ship.isAlive())
    {
        ship.draw();
    }
    else if (!ship.isAlive())
    {
        drawText(Point(), "Game Over!");
    }
    
   if (ship.canThrust()) {
        drawLanderFlames(ship.getPoint(), 0,0,0);
   }
    
    //bullet
    for (int i = 0; i < bullets.size(); i++)
    {
        if (bullets[i].isAlive())
        {
            bullets[i].draw();
        }
    }
}

/****************************
 * advanceBullets()
 *****************************/
void Game :: advanceBullets()
{
    // Move each of the bullets forward if it is alive
    for (int i = 0; i < bullets.size(); i++)
    {
        if (bullets[i].isAlive())
        {
            // this bullet is alive, so tell it to move forward
            bullets[i].advance();
        }
    }
}

/****************************
 * advanceRock()
 *****************************/
void Game :: advanceRock()
{
    if (rocks.empty())
    {
        createRock();
    }
    else
    {
        for (vector <Rock*> ::iterator it = rocks.begin(); it != rocks.end(); ++it)
        {
            (*it)->advance();
            }
        }
    }

/*********************************************************************
 * Function: handleCollisions
 * Description: Used to determine collisions between player, asteroids,
 * and bullets and call functions accordingly.
 *********************************************************************/
void Game :: handleCollisions()
{
    
    for (int i =0; i < rocks.size(); i++) {
        if (ship.isAlive() && getClosestDistance(ship,*rocks[i]) < SHIP_SIZE + rocks[i]->getSize())
        {
            ship.kill();
        }
        for (int b = 0; b < bullets.size(); b++) {
            if (bullets[b].isAlive() && getClosestDistance(bullets[b], *rocks[i]) < rocks[i]->getSize()) {
                bullets[b].kill();
                rocks[i]->hit(rocks);
            }
        }
    }
}

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/

float Game :: getClosestDistance(FlyingObjects &obj1,  FlyingObjects &obj2) 
 {
 // find the maximum distance traveled
 float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
 dMax = max(dMax, abs(obj2.getVelocity().getDx()));
 dMax = max(dMax, abs(obj2.getVelocity().getDy()));
 dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
 
 float distMin = std::numeric_limits<float>::max();
 for (float i = 0.0; i <= dMax; i++)
 {
 Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
 obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
 Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
 obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
 
 float xDiff = point1.getX() - point2.getX();
 float yDiff = point1.getY() - point2.getY();
 
 float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
 
 distMin = min(distMin, distSquared);
 }
 
 return sqrt(distMin);
 }

/*********************************************************************
 * Function: cleanup
 * Description: Used to clean up destroyed asteroids and bullets.
 *********************************************************************/
void Game :: cleanUpZombies()
{
    vector<Bullet>::iterator bulletIt = bullets.begin();
    vector<Rock*>::iterator rockIt = rocks.begin();
    while (bulletIt != bullets.end())
    {
        Bullet bullet = *bulletIt;
        
        if (!bullet.isAlive())
        {
            bulletIt = bullets.erase(bulletIt);
        }
        else
        {
            bulletIt++;
        }
    }
    
    while (rockIt != rocks.end())
    {
        Rock* asteroid = *rockIt;
        
        if (!asteroid->isAlive())
        {
            rockIt = rocks.erase(rockIt);
        }
        else
        {
            rockIt++;
        }
    }
}
