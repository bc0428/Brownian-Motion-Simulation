//
// Created by Brian Cheng on 9/11/2022.
//

#ifndef SIMULATION_BALL_H
#define SIMULATION_BALL_H


#include <SFML/Graphics/RenderWindow.hpp>

typedef struct Ball {
    float x, y, radius, velX, velY;

    void setX(float x);
    void setY(float y);
    void setRadius(float radius);

    float getX();
    float getY();
    float getRadius();

    void move();
    bool leftWindow(sf::RenderWindow& window);
} Ball;


#endif //SIMULATION_BALL_H
