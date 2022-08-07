#include "Match.h"

Match::Match(bool p1Human, bool p2Human,
             int p1UpKey, int p1DownKey, double p1SpeedModifier,
             int p2UpKey, int p2DownKey, double p2SpeedModifier) :
    paddle1(*this, p1Human, p1SpeedModifier, p1UpKey, p1DownKey), paddle2(*this, p2Human, p2SpeedModifier, p2UpKey, p2DownKey) {
    resetPoint();
}

void Match::keepPaddleInBounds(Paddle* p) {
    int mapH = gMap.getHeight();
    int pY = p->getY();
    int pH = p->getH();

    double upperFraction = 0.021;
    double lowerFraction = 0.979;

    if (pY < mapH * upperFraction)
        p->setY(mapH * upperFraction + 1);
    else if (pY + pH >= mapH * lowerFraction)
        p->setY(mapH * lowerFraction - pH - 1);
}

void Match::setBallVelocity(Ball* b, int frameTime) {
    double bxv = b->getXVelocity();
    double byv = b->getYVelocity();
    double bv = b->getVelocity();


    if (bxv > 0)
        b->setXVelocity(bv * frameTime / 1000.0);
    else
        b->setXVelocity(-bv * frameTime / 1000.0);

    if (byv > 0)
        b->setYVelocity(bv * frameTime / 1000.0);
    else
        b->setYVelocity(-bv * frameTime / 1000.0);

}

void Match::ballCollidesWithSides(Ball* b ) {
    int mapH = gMap.getHeight();
    int bY = b->getY();
    int bR = b->getR();

    double upperFraction = 0.021;
    double lowerFraction = 0.979;

    if (bY - bR < mapH * upperFraction - 5) {
        b->setY(mapH * upperFraction + bR);
        b->setYVelocity(1);
    } else if (bY + bR >= mapH * lowerFraction + 5) {
        b->setY(mapH * lowerFraction - bR);
        b->setYVelocity(-1);
    }
}

void Match::update(int frameTime) {
    paddle1.getHandler().handle(&paddle1, frameTime);
    paddle2.getHandler().handle(&paddle2, frameTime);

    paddle1.move();
    paddle2.move();

    keepPaddleInBounds(&paddle1);
    keepPaddleInBounds(&paddle2);

    setBallVelocity(&ball, frameTime);

    ball.move();

    ballCollidesWithSides(&ball);
    ballCollidesWithPaddle(&ball, &paddle1, true);
    ballCollidesWithPaddle(&ball, &paddle2, false);

    checkBallInBounds(&ball);

}

void Match::resetBall(Ball* b) {
    b->setX(gMap.getWidth() / 2);
    b->setY(gMap.getHeight() / 2);
}

void Match::resetPaddle1(Paddle* p) {
    p->setX(gMap.getWidth() * 0.05);
    p->setY(gMap.getHeight() / 2 - p->getH() / 2);
}

void Match::resetPaddle2(Paddle* p) {
    p->setX(gMap.getWidth() * 0.95 - p->getW());
    p->setY(gMap.getHeight() / 2 - p->getH() / 2);
}

void Match::resetPoint() {
    resetPaddle1(&paddle1);

    resetPaddle2(&paddle2);

    resetBall(&ball);
}

void Match::checkBallInBounds(Ball* b) {
    int mapW = gMap.getWidth();
    int bX = b->getX();
    int bR = b->getR();

    if (bX + bR < 0) {
        p2Score++;
        resetBall(b);
    } else if (bX - bR >= mapW) {
        p1Score++;
        resetBall(b);
    }

}

void Match::ballCollidesWithPaddle(Ball* b, Paddle* p, bool leftPaddle) {
    int bX = b->getX();
    int bY = b->getY();
    int bR = b->getR();
    int pX = p->getX();
    int pY = p->getY();
    int pW = p->getW();
    int pH = p->getH();

    if (leftPaddle) {
        if (bX - bR >= pX && bX - bR <= pX + pW && bY + bR >= pY && bY - bR <= pY + pH) {
            b->setXVelocity(-b->getXVelocity());
            b->setX(pX + 2 * pW);
        }

    } else if (bX + bR >= pX && bX + bR <= pX + pW && bY + bR >= pY && bY - bR <= pY + pH) {
        b->setXVelocity(-b->getXVelocity());
        b->setX(pX - pW);
    }


}


