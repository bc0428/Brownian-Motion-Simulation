//
// Created by Brian Cheng on 9/11/2022.
//
#include "Updates.h"
#include "SFML/Graphics.hpp"
#include "Ball.h"
#include "Constants.h"


Ball b = {SCREEN_WIDTH/2,SCREEN_HEIGHT/2,100, 1,1};

void update(sf::RenderWindow& window){
    drawBall(window);
    b.move();
    window.clear();
}
void drawBall(sf::RenderWindow& window){
    sf::CircleShape shape;
    shape.setRadius(b.getRadius());
    shape.setPosition(b.getX(), b.getY());
    shape.setFillColor(sf::Color::Blue);
    window.draw(shape);
    window.display();
}

