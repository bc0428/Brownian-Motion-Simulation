//
// Created by Brian Cheng on 10/11/2022.
//

#include "StaticObjects.h"
#include "Constants.h"

void drawStatic(sf::RenderWindow& window){
    drawBorder(window);
}


void drawBorder(sf::RenderWindow& window) {
    sf::RectangleShape borderBottom;
    sf::RectangleShape borderLeft;
    sf::RectangleShape borderRight;

    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                borderBottom.setSize(sf::Vector2f(BORDER_LONG, BORDER_SHORT));
                borderBottom.setPosition(sf::Vector2f(GROUND_X, GROUND_Y));
                borderBottom.setFillColor(BORDER_COLOR);
            }
            #pragma omp section
            {
                borderLeft.setSize(sf::Vector2f(BORDER_SHORT, BORDER_LONG));
                borderLeft.setPosition(sf::Vector2f(0, 0));
                borderLeft.setFillColor(BORDER_COLOR);
            }
            #pragma omp section
            {
                borderRight.setSize(sf::Vector2f(BORDER_SHORT, BORDER_LONG));
                borderRight.setPosition(sf::Vector2f(SCREEN_WIDTH - BORDER_SHORT, 0));
                borderRight.setFillColor(BORDER_COLOR);
            }
        }
    }

    window.draw(borderBottom);
    window.draw(borderLeft);
    window.draw(borderRight);

}