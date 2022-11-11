//
// Created by Brian Cheng on 9/11/2022.
//
#include "DynamicObjects.h"
#include "SFML/Graphics.hpp"
#include "Ball.h"
#include "Constants.h"
#include "iostream"

Ball b = {BALL_DEFAULT_X, BALL_DEFAULT_Y, BALL_RADIUS, velX_INITIAL, velY_INITIAL, BALL_COLOR, BALL_MASS};
Ball r = {boundaryLEFT, boundaryDOWN, BALL_RADIUS, velX_INITIAL, 0, sf::Color::Red, BALL_MASS};
Ball bl = {boundaryRIGHT, boundaryDOWN, BALL_RADIUS, -velX_INITIAL, 0, sf::Color::Blue,BALL_MASS};

std::vector<Ball> balls = {r ,bl, b};


void drawDynamic(sf::RenderWindow& window){
    drawBall(window);

//     my functionalities
    for (Ball& i : balls){
        i.move();
        i.wallCollision();
        ballCollision(i);

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
    return (2*m1*u2 + u1*(m1-m2)) / (m1+m2);
}
float afterCollisionVel2(float m1, float m2, float u1, float u2){
    return (2*m1*u1 + u2*(m2-m1)) / (m1+m2);
}

void ballCollision(Ball& b){
    for (Ball& other : balls){
        //in same quadrant
        if (b != other and b.quadrantX==other.quadrantX and b.quadrantY==other.quadrantY){
//        if (b != other){
            float dx = abs(b.x - other.x);
            float dy = abs(b.y - other.y);
            if (dy*dy + dx*dx <= (b.radius + other.radius)*(b.radius + other.radius)){

                //velocity update of ball 1 (b)
                b.velX = afterCollisionVel1(b.mass, other.mass, b.velX, other.velX);
                b.velY = afterCollisionVel1(b.mass, other.mass, b.velY, other.velY);

                //velocity update of ball 2 (other)
                other.velX = afterCollisionVel2(b.mass, other.mass, b.velX, other.velX);
                other.velY = afterCollisionVel2(b.mass, other.mass, b.velY, other.velY);
            }
        }
    }
}




