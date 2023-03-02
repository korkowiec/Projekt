#ifndef OKNO_STARTOWE_H
#define OKNO_STARTOWE_H

#include <Szachy/Klasy_pomocnice/przycisk.h>
#include <Szachy/Dane_poczatkowe/Zdarzenia.h>

class Okno_startowe
{
public:
    Okno_startowe(RenderWindow &W,sf::Event &E);
    void Okno_startowe_dzialanie();
    void Okno_startowe_akcje ();
private:
    RenderWindow* window;
    sf::Event* event;
    std::vector<std::unique_ptr<sf::Drawable>> Przyciski;
    sf::Texture tlo_textura;
    //sf::Event Event_l;
};

#endif // OKNO_STARTOWE_H
