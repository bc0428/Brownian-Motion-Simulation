//
// Created by Brian Cheng on 9/11/2022.
//

#ifndef SIMULATION_DYNAMICOBJECTS_H
#define SIMULATION_DYNAMICOBJECTS_H
#include "SFML/Graphics.hpp"
#include "Ball.h"

void drawDynamic(sf::RenderWindow &window);
void drawBall(sf::RenderWindow& window);

void updateVelocity(Ball& b, Ball& other, float dx,float dy);
void checkCollision(Ball& b);
float afterCollisionVel1(float m1, float m2, float u1, float u2);
float afterCollisionVel2(float m1, float m2, float u1, float u2);

void addBalls(Ball& b);


#endif //SIMULATION_DYNAMICOBJECTS_H
