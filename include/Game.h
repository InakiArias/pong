#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>
#include "Timer.h"
#include "Match.h"
#include "Ball.h"
#include "Handler.h"
#include "Texture.h"
#include "NumberTextures.h"

class Game {
    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    int sWidth = 960, sHeight = 600;

    Timer frameTimer;

    Timer fpsTimer;

    Texture bg, menuBg, ballTexture;
    NumberTextures numberTextures;

    std::unique_ptr<Match> match;

public:
    Game();
    ~Game();
    void run();
private:
    void init();
    void loadMedia();
    void close();
    void clearRender();
    void render();
    void refresh();
    void renderPaddle(Paddle& p);
    void renderBall(Ball& b);
    void renderScores();
};


#endif // GAME_H
