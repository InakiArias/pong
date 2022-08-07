#ifndef MAP_H
#define MAP_H


#include <SDL.h>

class Map {

    int width = 960;
    int height = 600;

public:
    Map();
    ~Map();

    int getWidth() {return width;}
    int getHeight() {return height;}

};
#endif
