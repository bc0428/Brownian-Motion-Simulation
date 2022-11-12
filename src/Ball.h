//
// Created by Brian Cheng on 9/11/2022.
//

#ifndef SIMULATION_BALL_H
#define SIMULATION_BALL_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "Constants.h"

typedef struct Ball {
    float x, y, radius, velX, velY;
    sf::Color ball_color;
    float mass;

    void gravitation();
    void move();

    void wallCollision();
    bool leftWallCollision();
    bool rightWallCollision();
    bool upWallCollision();
    bool bottomWallCollision();

    void frictionVertical();
    void frictionHorizontal();


    bool operator==(const Ball& other);
    bool operator !=(const Ball& other);
} Ball;




#endif //SIMULATION_BALL_H
