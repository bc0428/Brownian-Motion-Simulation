//
// Created by Brian Cheng on 9/11/2022.
//
#include "DynamicObjects.h"
#include "SFML/Graphics.hpp"
#include "Ball.h"
#include "Constants.h"


Ball b = {BALL_DEFAULT_X, BALL_DEFAULT_Y, BALL_RADIUS, velX_INITIAL, velY_INITIAL};
Ball initial = b;

void drawDynamic(sf::RenderWindow& window){

    drawBall(window);

    b.move();
    // my functionalities
    if (b.wallCollision()){
        b = initial;
    }



    window.clear();
}

void drawBall(sf::RenderWindow& window){
    sf::CircleShape ball;
    ball.setRadius(b.getRadius());
    ball.setPosition(b.getX(), b.getY());
    ball.setFillColor(BALL_COLOR);

    window.draw(ball);
    window.display();
}



