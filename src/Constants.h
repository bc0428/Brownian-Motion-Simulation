//
// Created by Brian Cheng on 9/11/2022.
//

#ifndef SIMULATION_CONSTANTS_H
#define SIMULATION_CONSTANTS_H
#include "Ball.h"
//screen config
const float SCREEN_WIDTH = 1500;
const float SCREEN_HEIGHT = 1500;
const int FPS = 60;

//ball config
const float BALL_RADIUS = 100;
const sf::Color BALL_COLOR = sf::Color::White;
const float velX_INITIAL = 100;
const float velY_INITIAL = -80;
const float BALL_DEFAULT_X = SCREEN_WIDTH/2 - BALL_RADIUS;
const float BALL_DEFAULT_Y = SCREEN_HEIGHT/2 - BALL_RADIUS;


//border config
const float BORDER_LONG = SCREEN_WIDTH;
const float BORDER_SHORT = SCREEN_HEIGHT / 20;
const float GROUND_X = 0;
const float GROUND_Y = SCREEN_HEIGHT - BORDER_SHORT;
const sf::Color BORDER_COLOR(100,100,100);

//boundary config
const float boundaryUP = 0;
const float boundaryDOWN = SCREEN_HEIGHT - 2 * BALL_RADIUS - BORDER_SHORT;
const float boundaryLEFT = BORDER_SHORT;
const float boundaryRIGHT = SCREEN_WIDTH - 2 * BALL_RADIUS - BORDER_SHORT;

//physics config
const float GRAVITY = 9.81 * 0.1;
const float COLLISION_DAMPENING =0.9;
const float BOUNCE_STOPPING_VELOCITY= 0.504; // by trial and error find velocity threshold that doesn't bounce enough anymore, to reduce computation
const float FRICTION_COEFFICIENT = 0.01; // absolute value to be subtracted from velocity


const Ball BALL_DEFAULT = {SCREEN_WIDTH/2,SCREEN_HEIGHT/2, BALL_RADIUS, velX_INITIAL, velY_INITIAL};
#endif //SIMULATION_CONSTANTS_H
