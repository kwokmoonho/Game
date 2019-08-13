###############################################################
# Program:
#     Project 13, Asteroids
#     Brother Clements, CS165
# Author:
#     Kwok Moon,Ho
# Summary:
#     Introduced by Atari in 1979, Asteroids was one of the most
#     successful of the first generation of arcade games and was
#     highly influential on the video game landscape for the next
#     decade. The basic premise of the game is that a ship moves
#     around the screen shooting asteroids while trying not to
#     get hit by them.
#
# Above and Beyond
#     1.ship flame always on, like a realy ship
#     2.when ship kill(), it will show "Game Over"
#     3.when user press the down arrow, the ship will decelate
#     and move with motion
#     4.bullet color change to red
#     5. flame color change to yellow
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObjects.o ship.o bullet.o rocks.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObjects.o ship.o bullet.o rocks.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o       Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o   Handles input events
#    point.o        The position on the screen
#    game.o         Handles the game interaction
#    velocity.o     Velocity (speed and direction)
#    flyingObjects.o Base class for all flying objects
#    ship.o         The player's ship
#    bullet.o       The bullets fired from the ship
#    rocks.o        Contains all of the Rock classes
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

driver.o: driver.cpp game.h
	g++ -c driver.cpp

game.o: game.cpp game.h uiDraw.h uiInteract.h point.h velocity.h flyingObjects.h bullet.h rocks.h ship.h
	g++ -c game.cpp

velocity.o: velocity.cpp velocity.h point.h
	g++ -c velocity.cpp

flyingObjects.o: flyingObjects.cpp flyingObjects.h point.h velocity.h uiDraw.h
	g++ -c flyingObjects.cpp

ship.o: ship.cpp ship.h flyingObjects.h point.h velocity.h uiDraw.h
	g++ -c ship.cpp

bullet.o: bullet.cpp bullet.h flyingObjects.h point.h velocity.h uiDraw.h
	g++ -c bullet.cpp

rocks.o: rocks.cpp rocks.h flyingObjects.h point.h velocity.h uiDraw.h
	g++ -c rocks.cpp


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
