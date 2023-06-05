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
            case 1: //MENU
                {
                    Okno_startowe Start(window,event);
                    Start.Okno_startowe_dzialanie();
                }
            break;
            case 2://GRA_SZACHY
                {
                    Plansza Plansza(window,event,"Szachy");
                    Plansza.Gra();
                }
            break;
            case 3://PIASKOWNICA
                {
                    Piaskownica Piaskownica(window,event);
                    Piaskownica.Dzialanie();
                }
            break;
            case 4://WŁASNA_PLANSZA
                {
                    Wlasna_plasza Wlasna_plasza(window,event);


                }
            break;
            case 5://ŁADUJ_WŁASNĄ_PLANSZĘ
                {
                    Zagraj_wlasna_plansze Zagraj_wlasna_plasze(window,event);

                }
            break;
        default: window.close();
        }
    }

}
