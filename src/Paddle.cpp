#include "Paddle.h"
#include "PlayerHandler.h"
#include "ComputerHandler.h"

 Paddle::Paddle(Match& match, bool humanPlayer, double speedModifier, int upKey, int downKey, double x, double y, double w, double h)  : x(x), y(y), w(w), h(h) {
    if (humanPlayer)
        handler = std::make_unique<PlayerHandler>(upKey, downKey);
    else
        handler = std::make_unique<ComputerHandler>(speedModifier, match);
}
