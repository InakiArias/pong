#ifndef PLAYERHANDLER_H
#define PLAYERHANDLER_H

#include "Paddle.h"

class PlayerHandler : public Handler
{
    int upKey, downKey;

    public:
        PlayerHandler(int upKey, int downKey);
        void handle(Paddle* p, int frameTime);

};

#endif // PLAYERHANDLER_H
