//#include <SFML/Graphics.hpp>
#include <iostream>
#include "DynamicObjects.h"
#include "Constants.h"
#include "StaticObjects.h"


int main()
{
//    mode, window title name, style(what functions to include in title bar)
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Window", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
    window.setFramerateLimit(FPS);



// create loop for window to stay open
    while (window.isOpen()){

        sf::Event evnt;

//        window activities
        while (window.pollEvent(evnt)){
//        close window case
            switch(evnt.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    sf::Vector2i pos = sf::Mouse::getPosition(window);
                    float x = static_cast<float>(pos.x);
                    float y = static_cast<float>(pos.y);

                    x<boundaryLEFT ? x = boundaryLEFT: x;
                    x>boundaryRIGHT ? x = boundaryRIGHT: x;
                    y<boundaryUP ? y = boundaryUP: y;
                    y>boundaryDOWN ? x = boundaryDOWN: y;

                    Ball b = {x,y,BALL_RADIUS, 0,
                              velY_INITIAL, BALL_COLOR, BALL_MASS};
                    addBalls(b);

////         take text input
//                case sf::Event::TextEntered:
//                    printf("%c", evnt.text.unicode);

////         window resize case
//                case sf::Event::Resized:
//                    printf("New window width: %d, New window height: %d'\n'", evnt.size.width, evnt.size.height);
            }
        }


        drawStatic(window);
        drawDynamic(window);
    }
}