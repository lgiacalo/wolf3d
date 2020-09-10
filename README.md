# Wolf3d 42 Project

*Inspiré du célèbre jeu éponyme des années 90 qui fut le premier First Person Shooter, ce projet aborde la technique du ray-casting. Le but est de représenter une vue dynamique à l’intérieur d’un labyrinthe dans lequel on peut se déplacer.*

## Description:

This project’s objectives are similar to all this first year’s objectives: Rigor, use of C, use
of basic algorithms, information research, data mining etc.

As a graphic design project, Wolf3D will enable you to solidify your skills in this area:
windows, colors, events, fill shapes etc.

## Requirements:

Mac OS X El Capitan(10.11.5) or higher

## Installation
* `git clone https://github.com/lgiacalo/wolf3d.git`
* `cd wolf3d`
* `make`


## Running
Run `./wolf3d [map_file]`, a window should appear. You can navigate through the
map using the arrow keys. Exit by closing the window or pressing ESC.

## Map file format
It's a very simple format. Open a file in your favorite text editor, make sure
you have a grid of integers (each one being it's block ID), and it should work
right out of the box. Spawn position is the first empty space available from the
top left.

```
1 1 1 1 1
1 0 2 0 1
1 0 0 0 1
1 1 1 1 1
```


![wolf3d screenshot](/map/wolf1.png?raw=true)
![wolf3d screenshot](/map/wolf2.png?raw=true)