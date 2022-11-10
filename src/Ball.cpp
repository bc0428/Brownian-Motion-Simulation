//
// Created by Brian Cheng on 9/11/2022.
//


#include "Ball.h"
#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "iostream"

struct Ball;

void Ball::move(){
    // by trial and error find velocity threshold that doesn't bounce enough anymore, to reduce computation
    if (abs(velY) > 0.04)
    {
        std::cout << "summation" <<std::endl;
        velY += GRAVITY;
        y += velY;
    }

    x+= velX;
}

void Ball::wallCollision(){
    if (leftWallCollision() or rightWallCollision()){
        if (leftWallCollision()){
            x = boundaryLEFT;
        }
        else if (rightWallCollision()){
            x = boundaryRIGHT;
        }
        velX*=-COLLISION_DAMPENING;
    }
    if((bottomWallCollision() or upWallCollision())){
        y = boundaryDOWN;
        velY*=-COLLISION_DAMPENING;
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

void Ball::gravitation() {
    if (y < boundaryDOWN){

    }

}
