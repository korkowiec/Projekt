#ifndef VARIABLES_H
#define VARIABLES_H

#include <wtypes.h>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Font.hpp>
#include <vector>
#include <Szachy/HelpClass/RenderWindow.h>
#include <SFML/Window/Event.hpp>

extern u_short okienko; // Numer aktualnie wyświetlanego okna w switch-case
extern u_short Team;    // Liczba drużyn
extern u_short Teraz;   // Czyj ruch
extern float czas;      // Wykorzystywany do renderowania okna co sekundę, zamiast co pętle
extern sf::Vector2u(Zmiana_okna); // Wykorzystywany do zmieniania skalowania planszy i figur po zmianie rozmiaru okna, zamiast co pętle
extern bool HokusPokus; // Czy system jest skoncentrowany na oknie
extern sf::Vector2f mouse_position; // Pozycja myszy
extern sf::Font Dane_tekstu; // Czcionka
extern std::vector<std::string> NazwyFigur;
extern RenderWindow Window;
extern sf::Event Event;
#endif // VARIABLES_H
