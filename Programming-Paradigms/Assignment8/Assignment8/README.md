# Libraries Used

Pygame is a Python library used for creating games in Python. For this assignment, it was used to recreate Mario.
Time is a Python library that provides various time-related functions.

## Installation

Use the package manager [pip](https://pip.pypa.io/en/stable/) to install Pygame

```bash
pip install pygame
```

## Description

This project makes great use of inheritance and polymorphism. This project is a basic recreation of Super Mario.

The requirements of this project were as follows:
  Image Cycling for Mario to simulate walking
  		Mario is standing still when not moving
  Image Cycling for Goombas. Set the Goomba on fire when appropriate
  Collision detection between all sprites (Mario, Tubes, Goombas, and Fireballs)
      When Fireball and Goomba collide, remove Fireball and set Goomba on fire. Remove Goomba after a short amount of time.
      Do not allow Mario to pass through a Tube from any direction (left, right, top, bottom)
      Do not allow Goombas to pass through a Tube from left or right directions
      Do not allow Fireballs to pass through a Tube from left or right direction
   Remove Fireballs when they go off screen
   Simulate screen-scrolling by drawing sprites and Mario correctly
   Read in keyboard inputs to control Mario and shoot Fireballs from MArio
   Does not allow Mario to double/infinitely jump
      Only lets him jump a certain height
      Allows Mario to jump off of the tops of Tubes
   		Make Mario fall back to the ground when in the air
   Does not allow any of the sprites to fall through the ground
