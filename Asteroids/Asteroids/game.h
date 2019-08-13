/*************************************************************
 * File: game.h
 * Author: Kwok Moon Ho
 *
 * Description: The game of Skeet. This class holds each piece
 *  of the game . It also has
 *  methods that make the game happen (advance, interact, etc.)
 *************************************************************/

#ifndef GAME_H
#define GAME_H
#include <vector>

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "ship.h"
#include "rocks.h"
#include "bullet.h"

#define CLOSE_ENOUGH 10


/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
    /*********************************************
     * Constructor
     * Initializes the game
     *********************************************/
    Game(Point tl, Point br);
    ~Game();
    
    /*********************************************
     * Function: handleInput
     * Description: Takes actions according to whatever
     *  keys the user has pressed.
     *********************************************/
    void handleInput(const Interface & ui);
    
    /*********************************************
     * Function: advance
     * Description: Move everything forward one
     *  step in time.
     *********************************************/
    void advance();
    
    /*********************************************
     * Function: draw
     * Description: draws everything for the game.
     *********************************************/
    void draw(const Interface & ui);
    
private:
    Point topLeft;
    Point bottomRight;
    
    Ship ship;
    std::vector<Bullet> bullets;
    std::vector<Rock*> rocks;
    
    /*************************************************
     * Private methods to help with the game logic.
     *************************************************/
    void advanceBullets();
    void advanceRock();
    void createRock();
    
    void handleCollisions();
    void cleanUpZombies();
    float getClosestDistance(FlyingObjects &obj1, FlyingObjects &obj2) ;
};



#endif /* GAME_H */
