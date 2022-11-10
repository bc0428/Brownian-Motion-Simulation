//
// Created by Brian Cheng on 9/11/2022.
//
#include "DynamicObjects.h"
#include "SFML/Graphics.hpp"
#include "Ball.h"
#include "Constants.h"


Ball b = {SCREEN_WIDTH/2,SCREEN_HEIGHT/2, BALL_RADIUS, velX_INITIAL, velY_INITIAL};
Ball initial = b;

void drawDynamic(sf::RenderWindow& window){

    drawBall(window);

    b.move();
    // my functionalities
    if (b.leftWindow(window)){
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



