# Introduction
A game is being developed by me.

# Prerequisites
root:

`apt install libsfml-dev -y`

# Compilation
Get into repository's dir, type this in your shell:

`g++ -std=c++11 -Wall -o ../game main.cpp hero.cpp game.cpp res-manager.cpp -lsfml-graphics -lsfml-window -lsfml-system`
