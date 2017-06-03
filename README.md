# Barebones 2D Game Engine + Demo

## Overview
A computer game engine written in C with the basic necessities for developing a 2D video game.

#### Objectives
- Implement a game engine and validate its functionality by using it to develop a fully functioning video game prototype.
- Demonstrate architecture and object-oriented patterns for computer game design.

#### Game Engine Fundamentals
This basic game architecture should be able to support the following:
1. The Game Loop
2. Graphics Rendering: Drawing, Animation, Camera
3. Device Input: Keyboard, Mouse, Joystick
4. Physics: Platformer, Collision Detection and Resolution
5. Game Objects: Player Avatar, Background, Scenery, Projectiles, Etc.
6. Audio: Music, Sound Effects

## External Libraries
This barebones game engine relies on the use of these open source software and libraries:

- [Simple DirectMedia Layer (SDL)](https://www.libsdl.org/)
- [Open Graphics Library (OpenGL)](https://www.opengl.org/)
- [OpenGL Extension Wrangler Library (GLEW)](http://glew.sourceforge.net/)
- [FMOD](http://www.fmod.com/) 
- [XInput](https://msdn.microsoft.com/en-us/library/windows/desktop/ee417014(v=vs.85).aspx) 

## Demo Gameplay
The `master` brach currently contains code for the playable video game prototype. This demo was concurrently developed alongside a similar project developed in *[GameMaker: Studio](http://opencv.org/)*, an existing game engine. The idea behind this was to compare functionality and support against a fully fledged proprietary game development engine.

#### How To Play:
Clear blocks by shooting them with matching colored projectiles. Clear all the blocks on the stage to comlplete the level. Falling off the stage will result in losing a life. The player is given three lives to clear all eight levels.

#### Controls:
- Movement: W, A, S, D
- Jump: N
- Shoot: B
- Select Projectile: V

### Writings
For more on this project and video game development discussion:
- [*CS Game Development*](https://kalquiza108.wordpress.com/)

### Readings
- *Game Engine Architecture* by Jason Gregory 
- *Foundations of Game Engine Development* by Eric Lengye

### Todos
- Create demo executable for Windows and Mac OS X

#### Course Details
CS 134: Computer Game Design and Programming
