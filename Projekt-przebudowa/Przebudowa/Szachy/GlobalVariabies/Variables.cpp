#include <Szachy/GlobalVariabies/Variables.h>

u_short okienko=1; //które okienko w case
u_short Team=2;//liczba drużyn
u_short Teraz=0; //czyj ruch
float czas=0; //wykorzystywany do renderowania okna co sekundę, zamiast co pętle
sf::Vector2u(Zmiana_okna)=sf::Vector2u(0,0);//Wykorzystywany do zmieniania skalowania planszy i figur po zmianie okna, zamiast co pętle
bool HokusPokus=0;//czy jest system sfocusowany na oknie
sf::Font Dane_tekstu;
sf::Vector2f mouse_position;
std::vector<std::string> NazwyFigur;
