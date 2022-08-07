#include "ComputerHandler.h"

#include "iostream"

void ComputerHandler::handle(Paddle* p, int frameTime)
{
    Ball& ball = match.getBall();
    double ballXV = ball.getXVelocity();

    if (ballXV > 0) {
        double ballY = ball.getY();
        double pY = p->getY();
        double pVel = p->getVelocity();

        if (pY < ballY)
            p->setYVelocity(pVel * speedModifier * frameTime / 1000.0);
        else
            p->setYVelocity(-pVel * speedModifier * frameTime / 1000.0);
    }
    else
        p->setYVelocity(0);
}

