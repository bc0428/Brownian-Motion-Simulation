//
// Created by Brian Cheng on 10/11/2022.
//

#include "StaticObjects.h"
#include "Constants.h"
#include "SFML/Graphics.hpp"
#include "Constants.h"

void drawStatic(sf::RenderWindow& window){
    drawGround(window);
}


void drawGround(sf::RenderWindow& window) {
    sf::RectangleShape ground;
    ground.setSize(sf::Vector2f(GROUND_WIDTH, GROUND_HEIGHT));
    ground.setPosition(sf::Vector2f(GROUND_X, GROUND_Y));
    ground.setFillColor(GROUND_COLOR);

    window.draw(ground);

}