#include "Game.h"

const char* BG_PATH = "bg.jpg";
const char* MENU_BG_PATH = "menubg.png";
const char* BALL_PATH = "ball.png";
const char* SPRITES_PATH = "sprites.png";

const int MAX_FPS = 60;
const int MIN_FRAME_TIME = 1000 / MAX_FPS;

Game::Game() {
    this->init();
    this->loadMedia();
}

Game::~Game() {
    this->close();
}

void Game::init() {

    SDL_Init(SDL_INIT_VIDEO);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    this->gWindow = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->sWidth, this->sHeight, SDL_WINDOW_SHOWN);

    this->gRenderer = SDL_CreateRenderer(this->gWindow, -1, SDL_RENDERER_ACCELERATED);

    //SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
}

void Game::loadMedia() {
    this->bg.setRenderer(this->gRenderer);
    this->bg.loadFromFile(BG_PATH);

    this->menuBg.setRenderer(this->gRenderer);
    this->menuBg.loadFromFile(MENU_BG_PATH);

    this->ballTexture.setRenderer(this->gRenderer);
    this->ballTexture.loadFromFile(BALL_PATH, true);

    this->numberTextures.sprites.setRenderer(this->gRenderer);
    this->numberTextures.sprites.loadFromFile(SPRITES_PATH);
}

void Game::close() {

    //Destroy window
    SDL_DestroyRenderer(this->gRenderer);
    SDL_DestroyWindow(this->gWindow);

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

void Game::renderPaddle(Paddle& p) {
    SDL_Rect paddleRect = {(int) p.getX(), (int) p.getY(), (int) p.getW(), (int) p.getH()};
    SDL_RenderFillRect(gRenderer, &paddleRect);
}

void Game::renderBall(Ball& b) {
    SDL_Rect r = {(int) (b.getX() - b.getR()), (int) (b.getY() - b.getR()), (int) b.getR() * 2, (int) b.getR() * 2};
    this->ballTexture.render(r.x, r.y, r.w, r.h);
}

void Game::renderScores() {
    int p1Score = match->getP1Score();
    int p2Score = match->getP2Score();

    SDL_Rect p1UnitsRect = numberTextures.rects[p1Score % 10];
    SDL_Rect p2UnitsRect = numberTextures.rects[p2Score % 10];

    numberTextures.sprites.render(360, 25, 60, 75, &p1UnitsRect);

    if (p1Score > 9) {
        SDL_Rect p1TensRect = numberTextures.rects[p1Score / 10];
        numberTextures.sprites.render(280, 25, 60, 75, &p1TensRect);
    }

    if (p2Score > 9) {

        if (p2Score / 10 == 1) {
            SDL_Rect p2TensRect = numberTextures.rects[p2Score / 10];
            numberTextures.sprites.render(495, 25, 60, 75, &p2TensRect);
            numberTextures.sprites.render(575, 25, 60, 75, &p2UnitsRect);
        }
        else {
            SDL_Rect p2TensRect = numberTextures.rects[p2Score / 10];
            numberTextures.sprites.render(540, 25, 60, 75, &p2TensRect);
            numberTextures.sprites.render(620, 25, 60, 75, &p2UnitsRect);
        }

    }
    else {
        numberTextures.sprites.render(540, 25, 60, 75, &p2UnitsRect);
    }


}

void Game::clearRender() {
    SDL_SetRenderDrawColor(this->gRenderer, 0, 0, 0, 0);
    SDL_RenderClear(this->gRenderer);
}

void Game::refresh() {
    SDL_RenderPresent(this->gRenderer);
}

void Game::run() {
    //Main loop flag
    bool quit = false;

    int frames = 0;
    fpsTimer.start();

    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit ) {
        frames++;

        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 ) {
            //User requests quit
            if( e.type == SDL_QUIT ) {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                match = nullptr;
            }
            else if (match == nullptr && e.type == SDL_MOUSEBUTTONDOWN) {
                int x = e.button.x;
                int y = e.button.y;

                if (x > 455 && x < 530 && y > 230 && y < 285) {
                    frameTimer.start();
                    match = std::make_unique<Match>(true, false);
                }
                else if (x > 425 && x < 530 && y > 305 && y < 360) {
                    frameTimer.start();
                    match = std::make_unique<Match>(true, true);
                }

            }
        }

        this->clearRender();

        if (match != nullptr) {
            Uint32 frameTime = frameTimer.getTime();

            if (frameTime < MIN_FRAME_TIME) {
                SDL_Delay(MIN_FRAME_TIME - frameTime);
                frameTime = MIN_FRAME_TIME;
            }

            match->update(frameTime);

            frameTimer.start();

            this->bg.render(0, 0);
            SDL_SetRenderDrawColor(this->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
            this->renderScores();
            this->renderPaddle(match->getPaddle1());
            this->renderPaddle(match->getPaddle2());
            this->renderBall(match->getBall());
        }
        else {
            this->menuBg.render(0, 0);
        }

        this->refresh();

        //std::cout << "FPS: " << frames * 1000 / fpsTimer.getTime()  << std::endl;
        //std::cout << "Ballv: " << (match ? match->getBall().getXVelocity(): 1 ) << std::endl;
    }
}
