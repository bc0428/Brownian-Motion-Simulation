//
// Created by Brian Cheng on 9/11/2022.
//

#ifndef SIMULATION_CONSTANTS_H
#define SIMULATION_CONSTANTS_H
//ball config
const float RADIUS = 100;
const sf::Color COLOR = sf::Color::Blue;
const float velX_INITIAL = 5;
const float velY_INITIAL = 5;

//screen config
const float SCREEN_WIDTH = 1500;
const float SCREEN_HEIGHT = 1500;
const float boundaryUP = RADIUS;
const float boundaryDOWN = SCREEN_HEIGHT - RADIUS;
const float boundaryLEFT = RADIUS;
const float boundaryRIGHT = SCREEN_WIDTH - RADIUS;




#endif //SIMULATION_CONSTANTS_H
