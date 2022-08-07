#ifndef HANDLER_H
#define HANDLER_H
#include <SDL.h>

class Paddle;

class Handler
{
    protected:
        bool upHeld = false, downHeld = false;

    public:
        virtual void handle(Paddle* p, int frameTime) = 0;

};

#endif // HANDLER_H
