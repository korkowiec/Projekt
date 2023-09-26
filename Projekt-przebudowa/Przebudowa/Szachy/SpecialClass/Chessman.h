#ifndef CHESSMAN_H
#define CHESSMAN_H

#include <Szachy/HelpClass/RenderWindow.h>
#include <SFML/Graphics/RectangleShape.hpp>
#include <wtypes.h>
#include <SFML/Graphics/Sprite.hpp>

class BasicGame;

class Chessman : public sf::Sprite
{
private:
    BasicGame *plansza;
    RenderWindow *window;

public:
    void Ruch();
    void Posible_move();
    void DrawPozycja(const sf::Color &C, const short &X1, const short &Y1);
    void Skalowanie(sf::RenderWindow &window, const short &x, const short &y);
    void Ustaw(sf::RenderWindow &window, const short &x, const short &y, short &X1, short &Y1);
    void Parametry(sf::RenderWindow &window, sf::RectangleShape &rec, const short &x, const short &y);
    void Rysowanie_Plansza(sf::RenderWindow &window, const sf::Color &Pole1, const sf::Color &Pole2, sf::RectangleShape &Pole, const short &x, const short &y);
    void SetDisplay(sf::RenderWindow &window, sf::Vector2i (a) = sf::Vector2i(0, 0), sf::Vector2u(c) = sf::Vector2u(0, 0), bool D = 0);

    Chessman(BasicGame &P, const std::string &N, const short &x1, const short &y1, const u_short &t);
    Chessman(BasicGame &P, const std::string &N, const short &x1, const short &y1, const u_short &t, const bool &K);

    u_short team;                 // do jakiej drużyny należy
    short X, Y;                   // pozycja XY względem planszy
    short textureX, textureY;     // rozmiary tekstury
    bool King = 0, CanDestroy = 1, NotWasMoved = 1, IsSelect = 0;
    std::string NazwaTekstury;   // na podstawie nazwy będzie wiadomo, jaka to jest figura i względem tej figury będzie czytane vector<struct> z możliwymi ruchami
};

#endif // CHESSMAN_H
