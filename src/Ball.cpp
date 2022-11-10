//
// Created by Brian Cheng on 9/11/2022.
//


#include "Ball.h"
#include "SFML/Graphics.hpp"
#include "Constants.h"

struct Ball;

void Ball::move(){
    x+= velX;
    y+= velY;

}

void Ball::wallCollision(){
    if (leftWallCollision() or rightWallCollision()){
        velX*=-1;
    }
    if(bottomWallCollision() or upWallCollision()){
        velY*=-1;
    }
}

bool Ball::leftWallCollision(){
    return x <= boundaryLEFT;
}
bool Ball::rightWallCollision() {
    return x >= boundaryRIGHT;
}

bool Ball::upWallCollision() {
    return y <= boundaryUP;
}

bool Ball::bottomWallCollision() {
    return y >= boundaryDOWN;
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
