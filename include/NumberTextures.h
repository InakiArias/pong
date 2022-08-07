#ifndef NUMBERTEXTURES_H
#define NUMBERTEXTURES_H
#include "Texture.h"
#include <SDL.h>


class NumberTextures
{
    public:
        Texture sprites;
        SDL_Rect rects[10];
        NumberTextures();
};

#endif // NUMBERTEXTURES_H
