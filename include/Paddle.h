#ifndef PADDLE_H
#define PADDLE_H

#include <memory>
#include "Handler.h"

class Match;

class Paddle
{
    double x, y, w, h, yVelocity = 0, velocity = 600;
    std::unique_ptr<Handler> handler;

public:
    Paddle(Match& match, bool humanPlayer, double speedModifier = 1, int upKey = 0, int downKey = 0, double x = 0, double y = 0, double w = 15, double h = 90);

    void move() {y += yVelocity;}

    double getX() {return x;}
    double getY() {return y;}
    double getW() {return w;}
    double getH() {return h;}
    double getYVelocity() {return yVelocity;}
    double getVelocity() {return velocity;}
    Handler& getHandler() {return *handler;}
    void setX(double x) {this->x = x;}
    void setY(double y) {this->y = y;}
    void setW(double w) {this->w = w;}
    void setH(double h) {this->h = h;}
    void setYVelocity(double yVelocity) {this->yVelocity = yVelocity;}
    void setVelocity(double velocity) {this->velocity = velocity;}


};

#endif // PADDLE_H
