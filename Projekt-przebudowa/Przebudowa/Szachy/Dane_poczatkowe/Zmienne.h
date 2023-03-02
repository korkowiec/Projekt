#ifndef ZMIENNE_H
#define ZMIENNE_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <wtypes.h>
#include <iostream>
extern u_short okienko; //które okienko w case
extern u_short Team;//liczba drużyn
extern u_short Teraz; //czyj ruch
extern float czas; //wykorzystywany do renderowania okna co sekundę, zamiast co pętle
extern sf::Vector2u(Zmiana_okna);//Wykorzystywany do zmieniania skalowania planszy i figur po zmianie okna, zamiast co pętle
extern bool HokusPokus;//czy jest system sfocusowany na oknie
extern sf::Vector2f mouse_position;
extern sf::Font Dane_tekstu;
//extern void* Okienko1;
#endif // ZMIENNE_H
