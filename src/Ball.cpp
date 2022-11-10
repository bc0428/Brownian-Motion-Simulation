//
// Created by Brian Cheng on 9/11/2022.
//


#include "Ball.h"
struct Ball;

void Ball::move(){
    x+= velX;
    y+= velY;
}

void Ball::setX(float x) {
    Ball::x = x;
}

void Ball::setY(float y) {
    Ball::y = y;
}

void Ball::setRadius(float radius) {
    Ball::radius = radius;
}

float Ball::getX(){
    return x;
}
float Ball::getY(){
    return y;
}
float Ball::getRadius(){
    return radius;
}