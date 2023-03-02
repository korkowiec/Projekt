#include <szachy.h>

Szachy::Szachy()
{

    srand(time(NULL));
    sf::Clock clock;
    RenderWindow window(sf::VideoMode(1,1), "Szachy");
    SetDisplay(window,sf::Vector2i(50,50),sf::Vector2u(sf::VideoMode::getDesktopMode().width-100,sf::VideoMode::getDesktopMode().height-100));
    if (!Dane_tekstu.loadFromFile("Czcionka/PolskaGurom.ttf")) window.close();
    while(window.isOpen())
    {
        sf::Event event;

        switch (okienko)
        {
            case 1:
                {
                    Okno_startowe Start(window,event);
                    Start.Okno_startowe_dzialanie();
                }
            break;
            case 2://gra_szachy
                {

                    Plansza Plansza(window,event,"Szachy");
                    Plansza.Gra();
                }
            break;
        default: window.close();
        }
    }

}
