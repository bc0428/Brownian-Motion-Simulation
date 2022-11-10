//
// Created by Brian Cheng on 9/11/2022.
//
#include "Updates.h"
#include "SFML/Graphics.hpp"
#include "Ball.h"
#include "Constants.h"


Ball b = {SCREEN_WIDTH/2,SCREEN_HEIGHT/2,RADIUS, velX_INITIAL,velY_INITIAL};
Ball initial = b;

void update(sf::RenderWindow& window){
    drawBall(window);



    // my functionalities
    b.move();
    if (b.leftWindow(window)){
        b = initial;
    }



    window.clear();
}
void drawBall(sf::RenderWindow& window){
    sf::CircleShape shape;
    shape.setRadius(b.getRadius());
    shape.setPosition(b.getX(), b.getY());
    shape.setFillColor(COLOR);
    window.draw(shape);
    window.display();
}

