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

bool Ball::leftWindow(sf::RenderWindow& window){
    if ((x <= boundaryLEFT) or (x >= boundaryRIGHT) or (y >= boundaryDOWN) or (y <= boundaryUP)){
        return true;
    }
    return false;
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