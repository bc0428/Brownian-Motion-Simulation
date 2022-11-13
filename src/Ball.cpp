//
// Created by Brian Cheng on 9/11/2022.
//


#include "Ball.h"
#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "iostream"
#include "DynamicObjects.h"

Ball::Ball(float x,float y,float radius,float velX,float velY, sf::Color ball_color, float mass){
     this->x = x;
     this->y = y;
     this->radius = radius;
     this->velX = velX;
     this->velY = velY;
     this->ball_color = ball_color;
     this->mass = mass;

}
bool Ball::resting(){
    return(bottomWallCollision() or this->balls_collision) and abs(velY) < MIN_VELOCITY_UPDATE;
}
void Ball::move(){

        if (!resting())
        {
            gravitation();
        }


// stop the ball when no sufficient horizontal movement
    if (abs(velX) > 0.01){
        x+= velX;
    }else{
        velX = 0;
    }


    std::cout << x <<" VelX: " << velX << ", VelY: " << velY << std::endl;
//    std::cout <<"X: " << x << ", Y: " << y << std::endl;
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
    else{
        velY=0;
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
