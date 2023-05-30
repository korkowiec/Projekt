#include <Szachy/Okna/Piaskownica/piaskownica.h>

void Piaskownica::Dzialanie()
{

    //Tworzenie obiektów

    //Plansza
        Plansza_gry P;
        Plansza=&P;
        sf::RectangleShape rec;
        Rysunek=&rec;



    //Działanie w pętli
    while(okienko==3)
    {
        window->clear();
        //Plansza->Zmiana_ruch(rand()%200);
        while(window->pollEvent(*event))
        {
            mouse_position = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
            if(event->type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)||sf::Keyboard::isKeyPressed(sf::Keyboard::E)) window->close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) okienko=2;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)) okienko=1;
        }

        Zdarzenia_interfejs();

        Zdarzenia_plansza();

        Rysowanie_plansza();

        Rysowanie_interfejs();

        window->display();
    }
}



void Piaskownica::Rysowanie_plansza()
{

    float wx=window->getSize().x,wy=window->getSize().y;
    Rysunek->setScale(window->getView().getSize().x/wx,window->getView().getSize().y/wy); //skaluje elementy do zmiany rozmiaru okna (View!=Size)
    if(wy<wx) wx=wy; else wy=wx; //rysowanie jest polem kwadratowym niezależnie od ilości na danym boku elementów
    Rysunek->setSize(sf::Vector2f(wx/Plansza->Rozmiar,wy/Plansza->Rozmiar));
    for (short c=0;c < Plansza->Rozmiar;c++ )
    {
        for(short d=0;d<Plansza->Rozmiar;d++)
        {
            if(Plansza->Ruch[c][d].IsSelect)
            {
                if(Plansza->Ruch[c][d].T) Rysunek->setFillColor(Kolory[3]);
                else if(Plansza->Ruch[c][d].M) Rysunek->setFillColor(Kolory[4]);
                else Rysunek->setFillColor(Kolory[2]);
            }
            else
            {
                if((c+d)%2==0) Rysunek->setFillColor(Kolory[0]);
                else Rysunek->setFillColor(Kolory[1]);
            }
            Rysunek->setPosition((d%Plansza->Rozmiar)*window->getView().getSize().x*wx/Plansza->Rozmiar/window->getSize().x,
                                 (c%Plansza->Rozmiar)*window->getView().getSize().y*wy/Plansza->Rozmiar/window->getSize().y);
            window->draw(*Rysunek);

        }
    }
}

void Piaskownica::Rysowanie_interfejs()
{
    Rozmiar=sf::Vector2f((1-window->getSize().y/window->getSize().x)*window->getView().getSize().x,window->getView().getSize().y);
    sf::Vector2f(pos);
    sf::Vector2f(roz);
    sf::Vector2f(pos1)=;
    sf::Vector2f(roz2);
    przycisk->Zmiana(sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y),
                 sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y));
}

void Piaskownica::Zdarzenia_interfejs()
{

}

void Piaskownica::Zdarzenia_plansza()
{

}
