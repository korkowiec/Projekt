#ifndef GLOBALFUNCTIONS_H
#define GLOBALFUNCTIONS_H

#include <Szachy/HelpClass/RenderWindow.h>
#include <SFML/Graphics/Text.hpp>

void SetDisplay(sf::RenderWindow &window, sf::Vector2i a = sf::Vector2i(0, 0),
                sf::Vector2u c = sf::Vector2u(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height));

sf::Text Tworzymy_tekst(sf::Vector2f pos1, sf::Vector2f pos2, std::string S, RenderWindow &W);

void akcja_gra_start(void Zdarzenia_window(sf::RenderWindow &W, sf::Event &E));

void Popraw_tekst(sf::Vector2f pos1, sf::Vector2f pos2, sf::Text &text, RenderWindow &window);

extern char boolToChar(bool number);

#endif // GLOBALFUNCTIONS_H
