#include "PlayerHandler.h"

#include <Handler.h>
#include "keys.h"
#include <iostream>

PlayerHandler::PlayerHandler(int upKey, int downKey) :
    upKey(upKey), downKey(downKey)
{
    //ctor
}

void PlayerHandler::handle(Paddle* p, int frameTime) {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    upHeld = currentKeyStates[upKey];
    downHeld = currentKeyStates[downKey];

    if(upHeld)
        p->setYVelocity(-p->getVelocity() * frameTime / 1000.0);
    else if(downHeld)
        p->setYVelocity(p->getVelocity() * frameTime / 1000.0);
    else
        p->setYVelocity(0);
}
