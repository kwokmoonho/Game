###############################################################
# Program:
#     Milestone 08, Skeet
#     Brother Clements, CS165
# Author:
#     Kwok Moon, Ho
# Summary:
#     Create a game that simulates skeet shooting.
#     On the left side of the screen, clay pigeons are randomly shot across the screen.
#     On the bottom right corner of the screen,
#     the "marksman" (the term is used very loosely here) aims his rifle.
#     Each match ends when either a bullet from the rifle destroys the pigeon or
#     when the pigeon exits the screen (called "birds away").
#
# Above and Beyond
#     When you submit your final project (not for milestones),
#     list anything here that you did to go above and beyond
#     the base requirements for your project.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o velocity.o flyingObjects.o bullet.o birds.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o rifle.o velocity.o flyingObjects.o bullet.o birds.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h bullet.h birds.h
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp
	g++ -c rifle.cpp




#######################################################################
# velocity.o            compute the movement of the birds and bullet
# flyingObjects.o			base class of the birds and bullet
# bullet.o					main method of the bullet
# birds.o					main method of the birds
#######################################################################
velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp

flyingObjects.o: flyingObjects.cpp flyingObjects.h point.h velocity.h
	g++ -c flyingObjects.cpp

bullet.o: bullet.cpp bullet.h flyingObjects.h point.h velocity.h uiDraw.h
	g++ -c bullet.cpp

birds.o: birds.cpp birds.h flyingObjects.h point.h velocity.h uiDraw.h
	g++ -c birds.cpp


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
