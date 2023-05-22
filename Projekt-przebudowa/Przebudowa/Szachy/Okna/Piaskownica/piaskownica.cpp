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

        while(window->pollEvent(*Event))
        {
            mouse_position = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
            if(Event->type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)||sf::Keyboard::isKeyPressed(sf::Keyboard::E)) window->close();
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
    sf::Vector2f Skala(window->getView().getSize().x/wx,window->getView().getSize().y/wy);
    if(wy<wx) wx=wy; else wy=wx; //rysowanie jest polem kwadratowym niezależnie od ilości na danym boku elementów
    Rysunek->setPosition(0,0);
    Rysunek->setSize(sf::Vector2f(wx/Plansza->Rozmiar,wy/Plansza->Rozmiar));
    sf::Vector2f Rozmiar(wx,wy);
    Rysunek->setFillColor(Plansza->Pole1);
    window->draw(*Rysunek);
    Rysunek->setFillColor(Plansza->Pole2);
    Rysunek->setSize(sf::Vector2f(wx/Plansza->Rozmiar,wy/Plansza->Rozmiar));
    for (short c=0;c < Plansza->Rozmiar;c++ )
    {
        for(short d=0;d<Plansza->Rozmiar;d++)
        {
            if((c+d)%2==0)
            {
                Rysunek->setPosition((d%Plansza->Rozmiar)*window->getView().getSize().x*wx/Plansza->Rozmiar/window->getSize().x,(c%Plansza->Rozmiar)*window->getView().getSize().y*wy/Plansza->Rozmiar/window->getSize().y);
                window->draw(*Rysunek);
            }
        }
    }
}

void Piaskownica::Rysowanie_interfejs()
{

}

void Piaskownica::Zdarzenia_interfejs()
{

}

void Piaskownica::Zdarzenia_plansza()
{

}
