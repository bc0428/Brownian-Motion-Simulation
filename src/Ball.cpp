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



// stop the ball when no sufficient horizontal movement
    if (abs(velX) > 0.01){
        x+= velX;
    }else{
        velX = 0;
    }

//    update quadrant information
    quadrantX = (x-boundaryUP) / QUADRANT_WIDTH;
    quadrantY = (y-boundaryLEFT) / QUADRANT_WIDTH;
//        std::cout << x <<" QX: " << quadrantX << ", QY: " << quadrantY << std::endl;
    std::cout << x <<" VelX: " << velX << ", VelY: " << velY << std::endl;
}

void Ball::wallCollision(){
    if (leftWallCollision() or rightWallCollision()){
        //apply friction
        frictionVertical();

        leftWallCollision()? x = boundaryLEFT : x = boundaryRIGHT;
        velX*=-COLLISION_DAMPENING;


        // located at lower corners, setting mass to infinity to act as wall extension
        if (velY == 0 and velX == 0){
            mass = std::numeric_limits<float>::max();
        }

    }
    if((bottomWallCollision() or upWallCollision())){
        //reduce computation when no sufficient movement to prevent fluctuation in horizontal movement
        if (abs(velX) >0.01)
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

bool Ball::operator==(const Ball &other) {
    return x == other.x and y == other.y and
           velX == other.velX and velY == other.velY;
}

bool Ball::operator!=(const Ball &other) {
    return x != other.x or y != other.y or
           velX != other.velX or velY != other.velY;
}
