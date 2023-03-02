#ifndef INTERFEJS_H
#define INTERFEJS_H

#include <Szachy/Dane_poczatkowe/Zdarzenia.h>
#include <Szachy/Klasy_pomocnice/przycisk.h>
class Interfejs
{
public:

    Interfejs();
    Interfejs(RenderWindow &W,sf::Event &E):window(&W),event(&E){Przyciski();}
    void Rysowanie();
    void Ustal_Pole();
    void Akcje_i_rysowanie();
    void Koniec_gry();
private:
    void Rysuj_dol();
    void Rysuj_bok();
    void Przyciski();
    RenderWindow *window;
    sf::Vector2f(Rozmiar);
    sf::Event *event;
    std::vector<std::unique_ptr<sf::Drawable>> Rysunki;

    u_short Rodzaj=0;//0-nic, 1-bok, 2-dol

};

#endif // INTERFEJS_H
