#include "NumberTextures.h"

NumberTextures::NumberTextures()
{
    rects[0] = {3, 5, 80, 100};
    rects[1] = {491, 5, 80, 100};

    for (int i = 2; i < 10; i++) {
        rects[i] = rects[i - 1];
        rects[i].x += 85;
    }
}
