#ifndef BALL_H
#define BALL_H


class Ball
{
    double x, y, r, xVelocity = 1, yVelocity = 1, velocity = 500;

public:
    Ball(double x = 0, double y = 0, double r = 15)  : x(x), y(y), r(r) {}
    ~Ball() {}

    void move() {x += xVelocity; y += yVelocity;}

    double getX() {return x;}
    double getY() {return y;}
    double getR() {return r;}
    double getXVelocity() {return xVelocity;}
    double getYVelocity() {return yVelocity;}
    double getVelocity() {return velocity;}
    void setX(double x) {this->x = x;}
    void setY(double y) {this->y = y;}
    void setR(double r) {this->r = r;}
    void setXVelocity(double xVelocity) {this->xVelocity = xVelocity;}
    void setYVelocity(double yVelocity) {this->yVelocity = yVelocity;}
    void setVelocity(double velocity) {this->velocity = velocity;}
};

#endif // BALL_H
