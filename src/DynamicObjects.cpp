//
// Created by Brian Cheng on 9/11/2022.
//
#include <cmath>
#include "DynamicObjects.h"
#include "SFML/Graphics.hpp"
#include "Ball.h"
#include "Constants.h"
#include "iostream"

//Ball b = {BALL_DEFAULT_X, BALL_DEFAULT_Y, BALL_RADIUS, velX_INITIAL, velY_INITIAL, BALL_COLOR, BALL_MASS};
//Ball r = {boundaryLEFT, boundaryDOWN, BALL_RADIUS, velX_INITIAL, 0, sf::Color::Red, BALL_MASS};
//Ball bl = {boundaryRIGHT/2, boundaryDOWN, BALL_RADIUS, 0, 20, sf::Color::Blue,BALL_MASS};

//Ball one = {BALL_DEFAULT_X, boundaryDOWN, BALL_RADIUS, 0, 0, BALL_COLOR, BALL_MASS};
//Ball two = {BALL_DEFAULT_X+2*BALL_RADIUS, boundaryDOWN, BALL_RADIUS, 0, velY_INITIAL, BALL_COLOR, BALL_MASS};
//Ball three = {BALL_DEFAULT_X-2*BALL_RADIUS,boundaryDOWN, BALL_RADIUS, 0, velY_INITIAL, BALL_COLOR, BALL_MASS};
//Ball four = {BALL_DEFAULT_X-4*BALL_RADIUS, boundaryDOWN, BALL_RADIUS, 0, velY_INITIAL, BALL_COLOR, BALL_MASS};
//Ball five = {BALL_DEFAULT_X+5*BALL_RADIUS, boundaryDOWN, BALL_RADIUS, velX_INITIAL, velY_INITIAL, BALL_COLOR, BALL_MASS};
//std::vector<Ball> balls = {one,two,three,four,five};

Ball down = {BALL_DEFAULT_X, boundaryDOWN/2, BALL_RADIUS, 0, velY_INITIAL, sf::Color::Red, BALL_MASS};
Ball up = {BALL_DEFAULT_X, boundaryDOWN, BALL_RADIUS, 0, 0, BALL_COLOR, BALL_MASS};
std::vector<Ball> balls = {up, down};

//std::vector<Ball> balls = {};
void addBalls(Ball& b){
    balls.push_back(b);
}

void drawDynamic(sf::RenderWindow& window){
    drawBall(window);

//     my functionalities
    for (Ball& i : balls){
        i.move();
        i.wallCollision();
        checkCollision(i);
    }
    std::cout<<'\n';


    window.clear();
}

void drawBall(sf::RenderWindow& window){

    for (Ball a : balls){
    sf::CircleShape drawableBall;
    drawableBall.setRadius(a.radius);
    drawableBall.setOrigin(a.radius, a.radius);
    drawableBall.setPosition(a.x, a.y);
    drawableBall.setFillColor(a.ball_color);
    window.draw(drawableBall);
    }

    window.display();
}
float afterCollisionVel1(float m1, float m2, float u1, float u2){
    return (2*m2*u2 + u1*(m1-m2)) / (m1+m2);
}
float afterCollisionVel2(float m1, float m2, float u1, float u2){
    return (2*m1*u1 + u2*(m2-m1)) / (m1+m2);
}

void checkCollision(Ball& b){
    b.balls_collision = false;

    for (Ball& other : balls){
        if (b != other){
            float dx = other.x - b.x;
            float dy = other.y - b.y;

            if(abs(dx)< DETECTION_LENGTH and abs(dy) < DETECTION_LENGTH){
//                std::cout<< "X: " << other.x << " Y: " << b.x << std::endl;

                if (dy*dy + dx*dx <= (b.radius + other.radius)*(b.radius + other.radius)){
//                    std::cout << "COLLISION!!!"<<std::endl;

                    b.balls_collision = true;
                    updateVelocity(b,other,dx,dy);

                }
            }
        }
    }
}

void updateVelocity(Ball &b, Ball& other, float dx, float dy) {
    float theta = atan(dx / dy);

//                    linear transformation to the collision plane
    float b_vy = b.velX* sin(theta) + b.velY * cos(theta);
    float other_vy = other.velX* sin(theta) + other.velY * cos(theta);
    float b_vx = b.velX * cos(theta) - b.velY * sin(theta);
    float other_vx = other.velX * cos(theta) - other.velY * sin(theta);;

    // new velocity update, change in perpendicular direction only
    float tempY = afterCollisionVel1(b.mass, other.mass, b_vy, other_vy);
    other_vy = afterCollisionVel2(b.mass, other.mass, b_vy, other_vy);
    b_vy = tempY;

    //reverse back to original plane
    b.velX = b_vx * cos(theta) + b_vy * sin(theta);
    b.velY = -b_vx * sin(theta) + b_vy * cos(theta);
    other.velX = other_vx * cos(theta) + other_vy * sin(theta);
    other.velY = -other_vx * sin(theta) + other_vy * cos(theta);

}




