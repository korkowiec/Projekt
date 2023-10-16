#ifndef BASICGAME_H
#define BASICGAME_H

#include <wtypes.h>
#include <Szachy/HelpClass/RenderWindow.h>
#include <Szachy/SpecialClass/Chessman.h>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <Szachy/Windows/BasicGame/Console.h>
#include <SFML/Window/Event.hpp>

class BasicGame
{
private:
    bool Gracz_ma_figury_specjalne();
    bool Select();

    struct PoruszanieSie
    {
        short x; // ruch w X
        short y; // ruch w Y
        u_short EL = 1; // liczba pętli, 0 == nieskończoność
        bool US = 0; // unikanie kolizji ze swoimi
        bool UW = 0; // UwU unikanie kolizji z wrogami oba bool wykorzystywanie w ruchach w pętli
        bool Z = 1; // możliwość zbijania wroga
        bool ZE = 1; // możliwość zbicia wroga kończy pętle
        bool S = 0; // możliwość zbicia swoich
        bool SE = 1; // możliwość zbicia swojego kończy pętle
        bool M = 0; // Czy musi być z pozycji początkowej
        bool T = 0; // tylko bicie figur

        PoruszanieSie(short x = 0, short y = 0, u_short EL = 1, bool US = 0, bool UW = 0, bool Z = 1, bool ZE = 1, bool S = 0, bool SE = 1, bool M = 0, bool T = 0)
            : x(x), y(y), EL(EL), US(US), UW(UW), Z(Z), ZE(ZE), S(S), SE(SE), M(M), T(T) {}
    };

    struct Rodzaje_Figura // pozwoli to ładować plik o podanej nazwie
    {
        sf::Texture texture;
        std::string name;
        std::vector<PoruszanieSie> Dane;
    };

    struct Plansza_gry
    {
        std::string nazwa;
        short board_x;
        short board_y;
        sf::Color Pole1;
        sf::Color Pole2;

        Plansza_gry(std::string nazwa = "Szachy") : nazwa(nazwa) {}
    };

    Console Console;

    bool Stan();

public:
    BasicGame(RenderWindow &W, sf::Event &E, std::string Nazwa_Planszy = "Szachy")
        : window(&W), event(&E), Plansza_gry(Nazwa_Planszy) { Tworzenie_calosci(); }

    void Ładuj_nazwy_figur();
        void Gra();
    void Zdarzenia_Podstawowe();
    void Parametry();
    void Rysowanie_Plansza();
    void SetDisplay(sf::Vector2i(a) = sf::Vector2i(0, 0),
                    sf::Vector2u(c) = sf::Vector2u(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height)); // pozwala ustawić okno do rozmiarów ekranu
    void Parametry_Planszy();
    void Ustawienie_Figur();
    void Ruch_Figur();
    void akcja_gra_szachy();
    void Tworzenie_calosci();
    void Koniec_gry();

    std::vector<Rodzaje_Figura> tekstury;
    sf::RectangleShape Rysunek;
    RenderWindow *window;
    sf::Event *event;
    sf::Event event_; // akcje zapisywane celowo tylko dla planszy
    Plansza_gry Plansza_gry;
    sf::Color Wybor3 = sf::Color(0, 255, 0, 128); // wybrana Twoja figura
    sf::Color Wybor2 = sf::Color(255, 0, 0, 128); // figura do bicia (wroga lub Twoja)
    sf::Color Wybor1 = sf::Color(0, 0, 255, 128); // wybrana pole do ruchu
    std::vector<Chessman> figury;
};

#endif // BASICGAME_H
