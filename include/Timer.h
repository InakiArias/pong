#include <SDL.h>


class Timer
{
    bool started = false, paused = false;
    Uint32 startTime = 0, pauseTime = 0;

public:
    Timer();
    ~Timer();
    void start();
    void stop();
    void pause();
    void unpause();
    Uint32 getTime();

    bool isStarted() {return started;}
    bool isPaused() {return paused;}

};
