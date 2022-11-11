//
// Created by Brian Cheng on 9/11/2022.
//
#include "DynamicObjects.h"
#include "SFML/Graphics.hpp"
#include "Ball.h"
#include "Constants.h"
#include "iostream"

Ball b = {BALL_DEFAULT_X, BALL_DEFAULT_Y, BALL_RADIUS, velX_INITIAL, velY_INITIAL, BALL_COLOR};
Ball r = {boundaryLEFT, boundaryUP, BALL_RADIUS, velX_INITIAL, velY_INITIAL, sf::Color::Red};
Ball bl = {boundaryLEFT, boundaryDOWN, BALL_RADIUS, velX_INITIAL, velY_INITIAL, sf::Color::Blue};

std::vector<Ball> balls = {b,r,bl};


void drawDynamic(sf::RenderWindow& window){
    drawBall(window);

//     my functionalities
    for (Ball& i : balls){
        i.move();
        i.wallCollision();
    }


    window.clear();
}

void drawBall(sf::RenderWindow& window){

    for (Ball a : balls){
    sf::CircleShape drawableBall;
    drawableBall.setRadius(a.radius);
    drawableBall.setPosition(a.x, a.y);
    drawableBall.setFillColor(a.ball_color);
    window.draw(drawableBall);
    }

    window.display();
}



