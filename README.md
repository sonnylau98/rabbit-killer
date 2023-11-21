# Introduction

A game.

# Copyright

The images used in the game I developed are used without permission. 

If you are the owner of any images and believe that their use infringes on your rights, please contact me for their immediate removal.

# Prerequisites

This project is extremely immature, with only one hero character, and is currently only viable on Ubuntu/Debian systems, requiring tedious compilation.

## Installation

Enter root permissions:

`apt install libsfml-dev -y`

## Compilation

Get into `src`, type this in your shell:

`g++ -std=c++11 -Wall -o ../game main.cpp hero.cpp game.cpp res-manager.cpp -lsfml-graphics -lsfml-window -lsfml-system`

# Play

Run `../game` in dir `src`.

Have I mentioned that it's extremely immature?
