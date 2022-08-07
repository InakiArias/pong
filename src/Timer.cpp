#include "Timer.h"

Timer::Timer() {}

Timer::~Timer() {}

void Timer::start() {

    started = true;
    paused = false;
    startTime = SDL_GetTicks();
    pauseTime = 0;

}

void Timer::stop() {

    started = false;
    paused = false;
    startTime = 0;
    pauseTime = 0;

}

void Timer::pause() {
    if (!paused) {
        paused = true;
        pauseTime = SDL_GetTicks() - startTime;
    }
}

void Timer::unpause() {
    if (paused) {
        paused = false;
        startTime = SDL_GetTicks() - pauseTime;
    }
}

Uint32 Timer::getTime() {
    if (!started)
        return 0;
    if (paused)
        return pauseTime;

    return SDL_GetTicks() - startTime;
}


