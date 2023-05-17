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
    u_short *Stan[6]={&Tutaju_short,&Tutaju_short,&Tutaju_short,&liczba_2,&liczba_2,&liczba_2};
    Przyciski.emplace_back(std::make_unique<Przycisk>(W,E,
                                                      okienko,Stan,
                                                      sf::Vector2f(0.4,0.3),
                                                      sf::Vector2f(0.6,0.45),
                                                      std::string("Gra")));
    Stan[3]=&liczba_0;
    Stan[4]=&liczba_0;
    Stan[5]=&liczba_0;
    Przyciski.emplace_back(std::make_unique<Przycisk>(W,E,
                                                      okienko,Stan,
                                                      sf::Vector2f(0.4,0.55),
                                                      sf::Vector2f(0.6,0.7),
                                                      std::string("Wyjście")));
    Stan[3]=&liczba_3;
    Stan[4]=&liczba_3;
    Stan[5]=&liczba_3;
    Przyciski.emplace_back(std::make_unique<Przycisk>(W,E,
                                                      okienko,Stan,
                                                      sf::Vector2f(0.1,0.40),
                                                      sf::Vector2f(0.2,0.60),
                                                      std::string("Piasek")));

}

void Okno_startowe::Okno_startowe_dzialanie()
{
    while(okienko==1) //gra_start
    {

        Okno_startowe_akcje ();



        for(u_short c=0;c<Przyciski.size();c++)
        {

            Przycisk *przycisk=dynamic_cast<Przycisk *>(Przyciski[c].get());
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

