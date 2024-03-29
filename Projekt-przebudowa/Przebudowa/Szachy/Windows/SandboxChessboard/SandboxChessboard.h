#ifndef SANDBOXCHESSBOARD_H
#define SANDBOXCHESSBOARD_H

#include <Szachy/HelpClass/RenderWindow.h>
#include <wtypes.h>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <Szachy/GlobalVariabies/Variables.h>
#include <Szachy/HelpClass/Button.h>

class SandboxChessboard
    {
protected:
    struct Plansza_gry
    {
        RenderWindow *window;
        u_short Rozmiar_x;
        u_short Rozmiar_y;
        u_short Rozmiar_x1;
        u_short Rozmiar_y1;
        sf::Color Pole1 = sf::Color(181, 127, 99);
        sf::Color Pole2 = sf::Color(240, 217, 181);
        std::vector<std::vector<std::pair<std::pair<sf::String, std::pair<bool, bool>>, sf::Sprite>>> Ruch;
        ~Plansza_gry()
        {
            for (std::vector<std::pair<std::pair<sf::String, std::pair<bool, bool>>, sf::Sprite>> &A : Ruch)
                A.clear();
            Ruch.clear();
        }
        Plansza_gry(RenderWindow &W, const int x = 8, const int y = 8) : Rozmiar_x(x), Rozmiar_y(y), Rozmiar_x1(x), Rozmiar_y1(y), window(&W)
        {
            std::vector<std::pair<std::pair<sf::String, std::pair<bool, bool>>, sf::Sprite>> A(y);
            Ruch.resize(x, A);
            float wx = window->getSize().x, wy = window->getSize().y;
            if (wy < wx)
                wx = wy;
            else
                wy = wx;
            for (int c = 0; c < Ruch.size(); c++)
            {
                for (int d = 0; d < A.size(); d++)
                {

                    Ruch[c][d].second.setPosition((c % Rozmiar_x1) * window->getView().getSize().x * wx / Rozmiar_x1 / window->getSize().x, (d % Rozmiar_y1) * window->getView().getSize().y * wy / Rozmiar_y1 / window->getSize().y);
                }
            }
        }
        void Zmiana_rozmiaru()
        {
            if (Rozmiar_x1 < 1 || Rozmiar_y1 < 1)
            {
                Rozmiar_x1 = Rozmiar_x, Rozmiar_y1 = Rozmiar_y;
                return;
            }

            //NOWY
            std::vector<std::pair<std::pair<sf::String, std::pair<bool, bool>>, sf::Sprite>> A(Rozmiar_y1);
            std::vector<std::vector<std::pair<std::pair<sf::String, std::pair<bool, bool>>, sf::Sprite>>> To(Rozmiar_x1, A);

            //KOPIUJ
            for (int c = 0; c < Rozmiar_x1 && c < Rozmiar_x; c++)
            {
                for (int d = 0; d < Rozmiar_y1 && d < Rozmiar_y; d++)
                {
                    To[c][d] = Ruch[c][d];
                }
            }

            //Nowy rozmiar
            Ruch.clear();
            Ruch.resize(Rozmiar_x1, A);

            float wx = window->getSize().x, wy = window->getSize().y;
            if (wy < wx)
                wx = wy;
            else
                wy = wx;

            for (int c = 0; c < Rozmiar_x1; c++)
            {
                for (int d = 0; d < Rozmiar_y1; d++)
                {
                    Ruch[c][d].second.setPosition((c % Rozmiar_x1) * window->getView().getSize().x * wx / Rozmiar_x1 / window->getSize().x, (d % Rozmiar_y1) * window->getView().getSize().y * wy / Rozmiar_y1 / window->getSize().y);
                }
            }

            //Kopiuj
            for (int c = 0; c < Rozmiar_x1 && c < Rozmiar_x; c++)
            {
                for (int d = 0; d < Rozmiar_y1 && d < Rozmiar_y; d++)
                {
                    Ruch[c][d] = To[c][d];
                    Ruch[c][d].second.setPosition((c % Rozmiar_x1) * window->getView().getSize().x * wx / Rozmiar_x1 / window->getSize().x, (d % Rozmiar_y1) * window->getView().getSize().y * wy / Rozmiar_y1 / window->getSize().y);
                    if (Ruch[c][d].first.first != "")
                    {
                        Ruch[c][d].second.setScale(window->getView().getSize().x / Ruch[c][d].second.getTexture()->getSize().x * wx / (Rozmiar_x1 * window->getSize().x),
                                                   window->getView().getSize().y / Ruch[c][d].second.getTexture()->getSize().y * wy / (Rozmiar_y1 * window->getSize().y));
                    }
                }
            }

            Rozmiar_x = Rozmiar_x1;
            Rozmiar_y = Rozmiar_y1;
        }
    };

    RenderWindow *window;
    sf::Event *event;

private:
    std::vector<sf::Text> Teksty;
    sf::RectangleShape Rysunek;
    Plansza_gry Plansza;
    std::vector<std::unique_ptr<ButtonActions>> Przyciski;
    std::vector<std::pair<sf::Sprite, std::unique_ptr<ButtonActions>>> Wybór_figur;
        std::vector<std::pair<sf::String, sf::Texture>> Tekstury;
    std::pair<sf::Sprite, short> Aktualny_wybór;
        sf::String Aktualny = "";
    sf::String Nazwa_pliku;
    bool ZAPISZ = 0;
    bool WAŻNA = 0;
        bool TEAM = 0;
    bool CzytajPlik = 0;
    bool StanMyszki = 0;

    void Dzialanie();
    void Rysowanie_plansza();
    void Rysowanie_interfejs();
    void Akcja_plansza();
    void Akcja_interfejs();
    void Tworzenie_obiektów();
        void Akcje();
    void Czytaj_plik();
    void Zapisz();

public:
    SandboxChessboard(RenderWindow &W, sf::Event &E);
    ~SandboxChessboard() { NazwyFigur.clear(); }
};
#endif // SANDBOXCHESSBOARD_H
