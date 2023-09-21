#ifndef ZMIENNE_H
#define ZMIENNE_H

#include <Szachy/Dane_poczatkowe/Matematyka.h>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <vector>
#include <wtypes.h>
#include <iostream>
#include <codecvt>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <stb_image_write.h>
#include <filesystem>

// Deklaracje zmiennych globalnych

extern u_short okienko; // Numer aktualnie wyświetlanego okna w switch-case
extern u_short Team;    // Liczba drużyn
extern u_short Teraz;   // Czyj ruch
extern float czas;      // Wykorzystywany do renderowania okna co sekundę, zamiast co pętle
extern sf::Vector2u(Zmiana_okna); // Wykorzystywany do zmieniania skalowania planszy i figur po zmianie rozmiaru okna, zamiast co pętle
extern bool HokusPokus; // Czy system jest skoncentrowany na oknie
extern sf::Vector2f mouse_position; // Pozycja myszy
extern sf::Font Dane_tekstu; // Czcionka

#endif // ZMIENNE_H
