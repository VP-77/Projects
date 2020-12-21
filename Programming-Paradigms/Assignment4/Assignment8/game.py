###########################################################################
#
# Author: Riley Nadwodny
# Date: 11/30/20
# Purpose: Replicate Mario in Python. Contains a general Sprite class
# from which Tubes, Goombas, Fireballs, and Mario are children of.
# Implements collision detection, image cycling, and screen scrolling.
# Eliminated code redundancy in this version compared to Assignment7.
#
###########################################################################

import pygame
import time

from pygame.locals import*
from time import sleep

class Model():
	def __init__(self):
		# Create array to hold sprites. Create mario differently than the rest and push Mario into the array.
		self.sprites = []
		self.mario = Mario(self, 100, 400)
		self.sprites.append(self.mario)
		self.sprites.append(Tube(self, 600, 380))
		self.sprites.append(Tube(self, 350, 450))
		self.sprites.append(Ground(self, -5000, 500))
		self.sprites.append(Goomba(self, 450, 455))

		# Create a copy of the array to add/remove sprites from
		self.spritesCopy = self.sprites.copy()

	def update(self):
		# Update the copy to reflect the original array.
		self.spritesCopy = self.sprites.copy()

		# Iterate through the copy
		for i in range(len(self.spritesCopy)):
			self.spritesCopy[i].update()

			# If the sprite is a Goomba, do collision detection with tube
			if isinstance(self.spritesCopy[i], Goomba):
				for j in range(len(self.spritesCopy)):
					if isinstance(self.spritesCopy[j], Tube):
						self.spritesCopy[i].Collision(self.spritesCopy[j])

			# If the sprite is Mario, do collision detection with tube			
			if isinstance(self.spritesCopy[i], Mario):
				for j in range(len(self.spritesCopy)):
					if isinstance(self.spritesCopy[j], Tube):
						self.spritesCopy[i].Collision(self.spritesCopy[j])

			# If the sprite is a fireball, do collision detection with Tubes and Fireballs			
			if isinstance(self.spritesCopy[i], Fireball):
				for j in range(len(self.spritesCopy)):
					if isinstance(self.spritesCopy[j], Tube):
						self.spritesCopy[i].Collision(self.spritesCopy[j])
					if isinstance(self.spritesCopy[j], Goomba):
						self.spritesCopy[i].Collision(self.spritesCopy[j])
		
	# Function to add new Fireball in front of Mario	
	def addFireball(self):
		self.sprites.append(Fireball(self, self.mario.rect.x + self.mario.rect.width, self.mario.y + 30))


class View():
	def __init__(self, model):
		screen_size = (800,600)
		self.screen = pygame.display.set_mode(screen_size, 32)
		self.model = model

	def update(self):
		# Fill with blue for the sky
		self.screen.fill([138,200,236])
		for sprite in self.model.sprites:
			# Draw sprites differently than Mario to give the appearance of a scrolling screen
			if not(isinstance(sprite, Mario)):
				self.screen.blit(sprite.image, (sprite.rect.x - (self.model.mario.x - 100), sprite.rect.y))

			# Draw Mario in the same place	
			if isinstance(sprite, Mario):
				self.screen.blit(sprite.images[self.model.mario.marioImageNum], (self.model.mario.marioLocation, sprite.rect.y))
		pygame.display.flip()


class Controller():
	def __init__(self, model):
		self.model = model
		self.keep_going = True

	def update(self):
		for i in range(len(self.model.sprites)):
			self.model.sprites[i].savePrev()
		for event in pygame.event.get():
			if event.type == QUIT:
				self.keep_going = False
			elif event.type == KEYDOWN:
				if event.key == K_ESCAPE:
					self.keep_going = False
		keys = pygame.key.get_pressed()
		# Make Mario move to the left
		if keys[K_LEFT]:
			self.model.mario.marioImageNum += 1
			self.model.mario.x -= 4
			self.model.mario.rect.x -= 4
		# Make Mario move to the right
		if keys[K_RIGHT]:
			self.model.mario.x += 4
			self.model.mario.rect.x += 4
		# Allow Mario to jump if he is not currently jumping	
		if keys[K_UP] and self.model.mario.jumping == False:
			self.model.mario.jump()
		# If Mario is not moving, assign an image to make him look like he is standing still	
		if not (keys[K_RIGHT] or keys[K_LEFT]):
			self.model.mario.marioImageNum = 3
		# Spawn fireballs. Hold to spawn a continous stream of fireballs.	
		if keys[K_LCTRL] or keys[K_RCTRL]:
				self.model.addFireball()


class Sprite():
	def __init__(self, model, x, y):
		self.model = model
		self.x = x
		self.y = y
		self.px = 0
		self.py = 0

	# Update function for Sprites
	def update(self):
		pass

	# Save a sprite's previous coordinates for collision detection
	def savePrev(self):
		self.px = self.rect.x
		self.py = self.rect.y

	# Function to detect collision between two sprites
	def Collision(self, s2):
		s = s2
		self.collision = True

		if ((self.rect.x + self.width) < s2.rect.x):
			self.collision = False
		if (self.rect.x > (s2.rect.x + s2.width)):
			self.collision = False
		if ((self.rect.y + self.height) < s2.rect.y):
			self.collision = False
		if (self.rect.y > (s2.rect.y + s2.height)):
			self.collision = False
		
		# If true, collision is occurring
		if (self.collision == True):

			#If Goomba or Fireball, make the sprite move the opposite direction
			if isinstance(self, Goomba) or isinstance(self, Fireball):
				self.flip = not(self.flip)

			#If Goomba AND Fireball, remove Fireball and set Goomba on fire	
			if isinstance(self, Fireball) and isinstance(s2, Goomba):
				self.model.sprites.remove(self)
				s2.onFire = True

			# Get the Goomba/Fireball/Mario out of the tube	
			self.getOutOfTube(s2)

	# Function to remove Sprite from a Tube
	def getOutOfTube(self, t):
		tube = t

		# Left hand side of tube
		if (((self.x + self.width) >= tube.x) and ((self.px + self.width) < tube.x)):
			self.x = tube.x - (self.width+1)
			self.rect.x = self.x
		# Right hand side of tube
		if ((self.x <= (tube.x + tube.width)) and (self.px > (tube.x + tube.width))):
			self.x = tube.x + (tube.width+1)
			self.rect.x = self.x
        # Above the tube
		if (((self.y + self.height) >= tube.y) and ((self.py + self.height) < tube.y)):
			self.y = tube.y - (self.height+1)
			self.rect.y = self.y
			if isinstance(self, Mario):
				self.jumps = 0
				self.jumping = False
        # Below the tube
		if ((self.y <= (tube.y + tube.height)) and (self.py > (tube.y + tube.height))):
			selfy = tube.y + (self.height-1)
			self.rect.y = self.y


# Class for the Ground
class Ground(Sprite):
	def __init__(self, model, x, y):
		super().__init__(model, x, y)
		self.image = pygame.Surface([20000, 100])
		self.image.fill('#84C011')
		self.rect = self.image.get_rect()
		self.rect.x = self.x
		self.rect.y = self.y
		self.width = self.rect.width
		self.height = self.rect.height


class Tube(Sprite):
	def __init__(self, model, x, y):
		super().__init__(model, x, y)
		self.image = pygame.image.load("tube.png")
		self.rect = self.image.get_rect()
		self.flip = True
		self.rect.x = self.x
		self.rect.y = self.y
		self.width = self.rect.width
		self.height = self.rect.height

	def update(self):
		pass


class Goomba(Sprite):
	def __init__(self, model, x, y):
		super().__init__(model, x, y)
		self.flip = True
		self.image = pygame.image.load("goomba.png")
		self.rect = self.image.get_rect()
		self.rect.x = self.x
		self.rect.y = self.y
		self.width = self.rect.width
		self.height = self.rect.height
		self.onFire = False
		self.frames = 0

	def update(self):

		# Bounce Goomba between the tubes
		if self.flip == True:
			self.x += 4
			self.rect.x = self.x
		if self.flip == False:
			self.x -= 4
			self.rect.x = self.x
		
		# If Goomba is on fire, load fire image. Count frames until removal. Remove at 75
		if self.onFire == True:
			self.image = pygame.image.load("goomba_fire.png")
			self.frames += 1
			if self.frames == 75:
				self.model.sprites.remove(self)


class Mario(Sprite):
	def __init__(self, model, x, y):
		super().__init__(model, x, y)
		self.marioImageNum = 0
		self.vertVel = 12.0
		self.marioLocation = 100
		self.jumping = False
		self.jumps = 0
		self.images = [pygame.image.load("mario1.png"), pygame.image.load("mario2.png"), pygame.image.load("mario3.png"), pygame.image.load("mario4.png"), pygame.image.load("mario5.png")]
		self.rect = self.images[self.marioImageNum].get_rect()
		self.rect.x = self.x
		self.rect.y = self.y
		self.width = self.rect.width
		self.height = self.rect.height

	def update(self):
		self.marioImageNum += 1
		self.jumps += 1

		# Give Mario gravity
		self.vertVel += 1.2
		self.y += self.vertVel
		self.rect.y = self.y

		# Keep Mario from falling through the ground
		if self.y > (500 - self.height):
			self.vertVel = 0
			self.rect.y = 500 - self.height
			self.jumps = 0
			self.jumping = False
		
		# Do not allow Mario to go off the top of the screen
		if self.y < 0:
			self.y = 0
		
		# Cycle through Mario images correctly
		if self.marioImageNum > 4:
			self.marioImageNum = 0

	# Allow Mario to jump a certain height
	def jump(self):
		if self.jumps < 5:
			self.vertVel = self.vertVel - 5
			self.y = self.rect.y


class Fireball(Sprite):
	def __init__(self, model, x, y):
		super().__init__(model, x, y)
		self.image = pygame.image.load("fireball.png")
		self.rect = self.image.get_rect()
		self.flip = False
		self.rect.x = self.x
		self.rect.y = self.y
		self.width = self.rect.width
		self.height = self.rect.height
		self.vertVel = 0
	
	def update(self):
		# Give the Fireball gravity and make it bounce
		self.vertVel += 1.2
		self.y += self.vertVel
		self.y -= 8
		self.rect.y = self.y

		# Do not allow the Fireball to fall through the ground
		if self.y > (500 - self.height):
			self.vertVel = 0
			self.rect.y = 500 - self.height
		
		# Do not allow the Fireball to go off the top of the screen
		if self.y < 0:
			self.y = 0

		# Move Fireball to the right side of the screen
		if not(self.flip):
			self.x += 3
			self.rect.x = self.x
		# Move fireball to the left side of the screen
		if self.flip:
			self.x -= 3
			self.rect.x = self.x
		
		# If the Fireball gets behind Mario and off the screen or
		# gets in front of Mario and off the screen, remove from list
		# to save resources
		if self.x + self.width < (self.model.mario.x - 100) or self.x > self.model.mario.x + 700:
			self.model.sprites.remove(self)


print("Use the arrow keys to move. Press Esc to quit.")
print("Press L-CTRL or R-CTRL key to spawn fireballs. Hold to spawn a continous stream.")
pygame.init()
m = Model()
v = View(m)
c = Controller(m)
while c.keep_going:
	c.update()
	m.update()
	v.update()
	sleep(0.04)
print("Goodbye")