#include <Szachy/Okna/Okno_startowe/okno_startowe.h>

Okno_startowe::Okno_startowe(RenderWindow &W,sf::Event &E)
{

    window=&W;
    event=&E;

    //Okienko startowe

    if (!tlo_textura.loadFromFile("Grafika/Tla/Menu/Okienko_startowe.png")) {
        okienko=0; Okno_startowe::~Okno_startowe();
    }
    std::unique_ptr<sf::Sprite> tlo = std::make_unique<sf::Sprite>(tlo_textura);
        tlo->setPosition(0,0);
        tlo->setScale(W.getView().getSize().x/tlo_textura.getSize().x,W.getView().getSize().y/tlo_textura.getSize().y);
    Przyciski.emplace_back(std::move(tlo));

        Tutaju_short=okienko;
    u_short dwa =2;
        u_short zero=0;
        u_short trzy =3;
    u_short cztery =4;
        u_short piec =5;
        u_short *Stan[6]={&okienko,&okienko,&okienko,&dwa,&dwa,&dwa};
        Przyciski.emplace_back(std::make_unique<Przycisk<u_short,u_short>>(W,E,
                                                          okienko,Stan,1,
                                                          sf::Vector2f(0.4,0.3),
                                                          sf::Vector2f(0.6,0.45),
                                                          std::string("Gra")));
    Stan[3]=&zero;
    Stan[4]=&zero;
    Stan[5]=&zero;
    Przyciski.emplace_back(std::make_unique<Przycisk<u_short,u_short>>(W,E,
                                                                         okienko,Stan,1,
                                                      sf::Vector2f(0.4,0.55),
                                                      sf::Vector2f(0.6,0.7),
                                                      std::string("Wyjście")));
    Stan[3]=&trzy;
    Stan[4]=&trzy;
    Stan[5]=&trzy;
    Przyciski.emplace_back(std::make_unique<Przycisk<u_short,u_short>>(W,E,
                                                                         okienko,Stan,1,
                                                      sf::Vector2f(0.1,0.20),
                                                      sf::Vector2f(0.2,0.40),
                                                      std::string("Piasek")));
    Stan[3]=&cztery;
    Stan[4]=&cztery;
    Stan[5]=&cztery;
    Przyciski.emplace_back(std::make_unique<Przycisk<u_short,u_short>>(W,E,
                                                                         okienko,Stan,1,
                                                      sf::Vector2f(0.1,0.41),
                                                      sf::Vector2f(0.3,0.60),
                                                      std::string("Stwórz_plansze")));
    Stan[3]=&uliczba_5;
    Stan[4]=&uliczba_5;
    Stan[5]=&uliczba_5;
    Przyciski.emplace_back(std::make_unique<Przycisk<u_short,u_short>>(W,E,
                                                                         okienko,Stan,1,
                                                      sf::Vector2f(0.8,0.40),
                                                      sf::Vector2f(0.99,0.60),
                                                      std::string("Zagraj_własną\nplanszę")));
}

void Okno_startowe::Okno_startowe_dzialanie()
{
    while(okienko==1) //gra_start
    {

        Okno_startowe_akcje ();



        for(u_short c=0;c<Przyciski.size();c++)
        {

            PrzyciskAkcje *przycisk=dynamic_cast<PrzyciskAkcje *>(Przyciski[c].get());
            if(przycisk != nullptr) {przycisk->Akcje();window->Rysowanie(*przycisk);}
            else
            {
                //sf::Sprite *tlo=dynamic_cast<sf::Sprite *>(Przyciski[c].get());
                window->Rysowanie(*Przyciski[c].get());
            }
        }

//        for(const auto &P : Przyciski)
//        {
//        }

        window->display();
    }
}
void Okno_startowe::Okno_startowe_akcje ()
{
    while(window->pollEvent(*event))
    {
        mouse_position = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
        if(event->type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window->close();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) okienko=2;
    }
}

