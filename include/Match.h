#ifndef MATCH_H
#define MATCH_H

#include <Map.h>
#include <Paddle.h>
#include <Ball.h>
#include "keys.h"


class Match
{
    Map gMap;
    Paddle paddle1, paddle2;
    Ball ball;
    int p1Score = 0, p2Score = 0;

    void resetBall(Ball* b);
    void resetPaddle1(Paddle* p);
    void resetPaddle2(Paddle* p);
    void resetPoint();

    void keepPaddleInBounds(Paddle* p);
    void setBallVelocity(Ball *b, int frameTime);
    void ballCollidesWithSides(Ball* b);
    void checkBallInBounds(Ball* b);
    void ballCollidesWithPaddle(Ball* b, Paddle* p, bool leftPaddle);


    public:
        Match(bool p1Human, bool p2Human,
              int p1UpKey = P1_UP_KEY, int p1DownKey = P1_DOWN_KEY, double p1SpeedModifier = 1,
              int p2UpKey = P2_UP_KEY, int p2DownKey = P2_DOWN_KEY, double p2SpeedModifier = 0.65);
        void update(int frameTime);
        Paddle& getPaddle1() {return paddle1;}
        Paddle& getPaddle2() {return paddle2;}
        Ball& getBall() {return ball;}
        int getP1Score() {return p1Score;}
        int getP2Score() {return p2Score;}

};
#endif // MATCH_H
