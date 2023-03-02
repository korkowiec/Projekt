#include <Szachy/Okna/Gra/interfejs.h>

Interfejs::Interfejs()
{

}
void Interfejs::Rysowanie()
{

}
void Interfejs::Koniec_gry()
{

    std::string S="Przegrał gracz "+std::to_string(Teraz+1);
//    Tekst tekst(sf::String::fromUtf8(S.begin(),S.end()),Dane_tekstu);
//    tekst.setColor(sf::Color::Red);
//    tekst.setStyle(sf::Text::Regular);
//    tekst.setOutlineColor(sf::Color::Black);
//    tekst.setOutlineThickness(0);
    Rysunki.emplace_back(std::make_unique<Tekst>(sf::String::fromUtf8(S.begin(),S.end()),Dane_tekstu));
    for(u_short c=0;c<Rysunki.size();c++)
        {

            Tekst *przycisk=dynamic_cast<Tekst *>(Rysunki[c].get());
            if(przycisk != nullptr)
            {
                przycisk->setColor(sf::Color::Red);
                przycisk->setStyle(sf::Text::Regular);
                przycisk->setOutlineColor(sf::Color::Black);
                przycisk->setOutlineThickness(0);

            }

        }
}
void Interfejs::Ustal_Pole()
{
    if(window->getSize().x>200&&window->getSize().y>200&&abs((int)window->getSize().x-(int)window->getSize().y)>100)
    {
        if(window->getSize().x>window->getSize().y)
        {
            Rodzaj=1;
            //Rozmiar=sf::Vector2f((window->getSize().x-window->getSize().y)*window->getView().getSize().x/window->getSize().x,window->getView().getSize().y);
            Rozmiar=sf::Vector2f((1-window->getSize().y/window->getSize().x)*window->getView().getSize().x,window->getView().getSize().y);
            sf::RectangleShape a;
            a.setPosition(window->getSize().y*window->getView().getSize().x/window->getSize().x,0);
            a.setFillColor(sf::Color::Blue);
            a.setSize(Rozmiar);
            window->draw(a);

        }
        else
        {
            Rodzaj=2;
            Rozmiar=sf::Vector2f(window->getView().getSize().x,(window->getSize().y-window->getSize().x)*window->getView().getSize().y);
            sf::RectangleShape a;
            a.setPosition(0,window->getSize().x*window->getView().getSize().y/window->getSize().y);
            a.setFillColor(sf::Color::Blue);
            a.setSize(Rozmiar);
            window->draw(a);

        }
        sf::Vector2f(pos);
        sf::Vector2f(roz);
        for(u_short c=0;c<Rysunki.size();c++)
        {
            Przycisk *przycisk=dynamic_cast<Przycisk *>(Rysunki[c].get());
            if(przycisk != nullptr)
            {
                if(przycisk->tekst_przycisku.getString()=="Menu")
                {
                    if(Rodzaj==1)
                    {
                        pos.x=0.05;
                        pos.y=0.05;
                        roz.x=0.4;
                        roz.y=0.2;
                        przycisk->Zmiana(sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y),
                                     sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y));
                    }
                    else if(Rodzaj==2)
                    {
                        pos.x=0.05;
                        pos.y=0.55;
                        roz.x=0.4;
                        roz.y=0.95;
                        przycisk->Zmiana(sf::Vector2f(pos.x,((pos.y*(window->getSize().y-window->getSize().x)+window->getSize().x)/window->getSize().y)),
                                     sf::Vector2f(roz.x,((roz.y*(window->getSize().y-window->getSize().x)+window->getSize().x)/window->getSize().y)));
                    }
                    przycisk->tekst_przycisku.Kalibrowanie();

                }
                else if(przycisk->tekst_przycisku.getString()==L"Wyjście")
                {

                    if(Rodzaj==1)
                    {
                        pos.x=0.6;
                        pos.y=0.05;
                        roz.x=0.95;
                        roz.y=0.2;
                        przycisk->Zmiana(sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y),
                                     sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y));
                    }
                    else if(Rodzaj==2)
                    {
                        pos.x=0.6;
                        pos.y=0.95;
                        roz.x=0.95;
                        roz.y=0.55;
                        przycisk->Zmiana(sf::Vector2f(pos.x,((pos.y*(window->getSize().y-window->getSize().x)+window->getSize().x)/window->getSize().y)),
                                     sf::Vector2f(roz.x,((roz.y*(window->getSize().y-window->getSize().x)+window->getSize().x)/window->getSize().y)));
                    }
                    przycisk->tekst_przycisku.Kalibrowanie();
                }
            }
        }
    }
    else
    {
        Rodzaj=0;
    }
}
void Interfejs::Rysuj_dol()
{

}
void Interfejs::Rysuj_bok()
{

}
void Interfejs::Przyciski()
{
    Tutaju_short=okienko;
    u_short *Stan[6]={&Tutaju_short,&Tutaju_short,&Tutaju_short,&liczba_1,&liczba_1,&liczba_1};
    Rysunki.emplace_back(std::make_unique<Przycisk>(*window,*event,
                                                      okienko,Stan,
                                                      sf::Vector2f(0,0),
                                                      sf::Vector2f(0,0),
                                                      std::string("Menu")));

    Stan[3]=&liczba_0;
    Stan[4]=&liczba_0;
    Stan[5]=&liczba_0;
    Rysunki.emplace_back(std::make_unique<Przycisk>(*window,*event,
                                                      okienko,Stan,
                                                      sf::Vector2f(0,0),
                                                      sf::Vector2f(0,0),
                                                      std::string("Wyjście")));
}
void Interfejs::Akcje_i_rysowanie()
{
    if(Rodzaj!=0)for(u_short c=0;c<Rysunki.size();c++)
    {

        Przycisk *przycisk=dynamic_cast<Przycisk *>(Rysunki[c].get());
        if(przycisk != nullptr) {przycisk->Akcje();window->Rysowanie(*przycisk);}
        else
        {
            window->Rysowanie(*Rysunki[c].get());
        }
    }
}
