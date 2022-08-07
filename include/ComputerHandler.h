#ifndef COMPUTERHANDLER_H
#define COMPUTERHANDLER_H

#include <Handler.h>
#include <Match.h>


class ComputerHandler : public Handler
{
    double speedModifier;
    Match& match;

    public:
        ComputerHandler(double speedModifier, Match& match) : speedModifier(speedModifier), match(match) {}
        void handle(Paddle* p, int frameTime);

};

#endif // COMPUTERHANDLER_H
