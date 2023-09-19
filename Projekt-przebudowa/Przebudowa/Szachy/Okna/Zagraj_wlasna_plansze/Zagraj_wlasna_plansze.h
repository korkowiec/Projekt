#ifndef ZAGRAJ_WLASNA_PLANSZE_H
#define ZAGRAJ_WLASNA_PLANSZE_H

#include <Szachy/Okna/Gra/Plansza.h>

class Zagraj_wlasna_plansze
{
protected:
    RenderWindow *window;
    sf::Event *event;
    std::vector<std::unique_ptr<PrzyciskAkcje>> Plansze;
    std::vector<std::string> Nazwy;
    std::string Wybór;
    short aktualny = 0;

private:
    void Dzialanie();
    void Czytaj();
    void Graj();
    void Twórz();

public:
    Zagraj_wlasna_plansze(RenderWindow &W, sf::Event &E);
};

#endif // ZAGRAJ_WLASNA_PLANSZE_H
