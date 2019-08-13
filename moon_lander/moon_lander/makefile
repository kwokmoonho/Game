###############################################################
# Program:
#     Project 07, Moon Lander
#     Brother Clements, CS165
# Author:
#     Kwok Moon, Ho
# Summary:
#     The dimensions of the screen are: (-200, -200) to (200, 200).
#     The lander begins with 500 units of fuel.
#     To land successfully, the lander must:
#     have its center within the horizontal boundaries of the platform.
#     be within 4 pixels vertically, above the platform.
#     arrive at the platform with a velocity of no more than 3 pixels per frame in
#     any direction.
#     Gravity on the moon can be modeled as 0.1 pixels per frame.
#     The left arrow key causes thrust on the left of the lander which propels it
#     to the right (and similar for the right and down arrows).
#     The left and right thrust amounts are 0.1 pixels per frame, and consume 1
#     unit of fuel.
#     The upward thrust (caused by the down arrow) amount is 0.3 pixels per frame,
#     and consumes 3 units of fuel.
#     The lander should have inertia, in other words, once it begins moving left,
#     it should continue moving left unless additional thrust is made.
#     The lander should not continue to move after crashing or landing.
#     After successfully landing, the game should display, "You have successfully
#     landed!"
#     After crashing, the game should display, "You have crashed."
#     After running out of fuel, the lander should not be able to apply thrusters
#     (but can continue falling).
#     Any other contact with the ground or platform results in a crash.
#     Above and Beyond
#     When you submit your final project (not for milestones),
#     list anything here that you did to go above and beyond
#     the base requirements for your project.
#
#     *Feature 1: purple color flame
#     *Feature 2: the lander will started in the moon
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main Moon Lander game
###############################################################
a.out: lander.o velocity.o driver.o ground.o game.o uiInteract.o uiDraw.o point.o
	g++ lander.o velocity.o driver.o ground.o game.o uiInteract.o uiDraw.o point.o $(LFLAGS)
	tar -j -cf moonLander.tar makefile *.h *.cpp

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

ground.o: ground.cpp ground.h
	g++ -c ground.cpp

game.o: game.h game.cpp uiDraw.h uiInteract.h point.h ground.h
	g++ -c game.cpp

driver.o: driver.cpp game.h uiInteract.h
	g++ -c driver.cpp
######################################################################
# lander.o              call the others function from the lander
# velocity.o            compute the movement of the lander
######################################################################
lander.o: lander.cpp lander.h point.h velocity.h uiDraw.h
    g++ -c lander.cpp

velocity.o: velocity.cpp velocity.h
    g++ -c velocity.cpp


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
