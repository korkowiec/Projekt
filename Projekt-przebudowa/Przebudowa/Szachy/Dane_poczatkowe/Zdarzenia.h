#ifndef ZDARZENIA_H
#define ZDARZENIA_H

#include <Szachy/Dane_poczatkowe/funkcje.h>
void akcja_gra_start(void Zdarzenia_window(sf::RenderWindow &W, sf::Event &E));
sf::Text Tworzymy_tekst(sf::Vector2f(pos1),sf::Vector2f(pos2),std::string S,RenderWindow &W);
void Popraw_tekst(sf::Vector2f(pos1),sf::Vector2f(pos2),sf::Text &text,RenderWindow &window);
#endif // ZDARZENIA_H
