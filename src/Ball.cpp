//
// Created by Brian Cheng on 9/11/2022.
//


#include "Ball.h"
#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "iostream"

struct Ball;

void Ball::move(){

    //apply gravity
    gravitation();

//    std::cout << "velX: " << velX << ", velY: " << velY << std::endl;

// stop the ball when no sufficient horizontal movement
    if (abs(velX) > 0.01){
        x+= velX;
    }else{
        velX = 0;
    }

}

void Ball::wallCollision(){
    if (leftWallCollision() or rightWallCollision()){
        //apply friction
        frictionVertical();

        leftWallCollision()? x = boundaryLEFT : x = boundaryRIGHT;
        velX*=-COLLISION_DAMPENING;

    }
    if((bottomWallCollision() or upWallCollision())){
        //reduce computation when no sufficient movement to prevent fluctuation in horizontal movement
        if (velX >0.01)
        {
            frictionHorizontal();
        }

        // reset position to improve stability after collision
        bottomWallCollision() ? y = boundaryDOWN : y = boundaryUP;
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
    //apply gravitation only when ball not at bottom and with sufficient velocity
    if (!(y == boundaryDOWN and abs(velY) < BOUNCE_STOPPING_VELOCITY))
    {
        velY += GRAVITY;
        y += velY;
    }
}


void Ball::frictionVertical() {
    velY > 0? velY -= FRICTION_COEFFICIENT: velY += FRICTION_COEFFICIENT;
}

void Ball::frictionHorizontal() {
    velX > 0? velX -= FRICTION_COEFFICIENT: velX += FRICTION_COEFFICIENT;
}
