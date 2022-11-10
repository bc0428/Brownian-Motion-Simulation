//
// Created by Brian Cheng on 9/11/2022.
//

#ifndef SIMULATION_CONSTANTS_H
#define SIMULATION_CONSTANTS_H
#include "Ball.h"
//ball config
const float BALL_RADIUS = 100;
const sf::Color BALL_COLOR = sf::Color::Blue;
const float velX_INITIAL = 5;
const float velY_INITIAL = 5;
const int DEFAULT_X = 0;
const int DEFAULT_Y = 0;


//screen config
const float SCREEN_WIDTH = 1500;
const float SCREEN_HEIGHT = 1500;
const float boundaryUP = BALL_RADIUS;
const float boundaryDOWN = SCREEN_HEIGHT - 2 * BALL_RADIUS;
const float boundaryLEFT = BALL_RADIUS;
const float boundaryRIGHT = SCREEN_WIDTH - 2 * BALL_RADIUS;

//ground config
const float GROUND_WIDTH = SCREEN_WIDTH;
const float GROUND_HEIGHT = SCREEN_HEIGHT/10;
const float GROUND_X = 0;
const float GROUND_Y = SCREEN_HEIGHT-GROUND_HEIGHT;
const sf::Color GROUND_COLOR = sf::Color::Green;


const Ball BALL_DEFAULT = {SCREEN_WIDTH/2,SCREEN_HEIGHT/2, BALL_RADIUS, velX_INITIAL, velY_INITIAL};
#endif //SIMULATION_CONSTANTS_H
