#ifndef CHESS_H
#define CHESS_H

#include <Szachy/HelpClass/RenderWindow.h>
#include <SFML/Window/Event.hpp>

class Chess
{
private:
    RenderWindow &Window;
    sf::Event &Event;
public:
    Chess();
};

#endif // CHESS_H
