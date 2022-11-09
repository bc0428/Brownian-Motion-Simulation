#include <SFML/Graphics.hpp>
//#include <iostream>


int main()
{
//    mode, window title name, style(what functions to include in title bar)
    sf::RenderWindow window(sf::VideoMode(1536,1536), "Window", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);

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

////         take text input
//                case sf::Event::TextEntered:
//                    printf("%c", evnt.text.unicode);

////         window resize case
//                case sf::Event::Resized:
//                    printf("New window width: %d, New window height: %d'\n'", evnt.size.width, evnt.size.height);
            }
        }
    }
}