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
            PrzyciskAkcje *przycisk=dynamic_cast<PrzyciskAkcje *>(Rysunki[c].get());
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
            else
            {
                Animacja *A=dynamic_cast<Animacja *>(Rysunki[c].get());
                if(A!=nullptr)
                {
                    if(Rodzaj==1)
                    {
                        pos.x=0.1;
                        pos.y=0.25;
                        roz.x=0.3;
                        roz.y=0.4;
                        A->Kalibrowanie(sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y),
                                         sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y));
                    }
                    else if(Rodzaj==2)
                    {
                        pos.x=0.1;
                        pos.y=0.35;
                        roz.x=0.3;
                        roz.y=0.50;
                        A->Kalibrowanie(sf::Vector2f(pos.x,((pos.y*(window->getSize().y-window->getSize().x)+window->getSize().x)/window->getSize().y)),
                                     sf::Vector2f(roz.x,((roz.y*(window->getSize().y-window->getSize().x)+window->getSize().x)/window->getSize().y)));
                    }

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
    std::shared_ptr<u_short> jeden=std::make_shared<u_short>(1);
    std::shared_ptr<u_short> zero=std::make_shared<u_short>(0);
    u_short *Stan[6]={&okienko,&okienko,&okienko,&(*jeden),&(*jeden),&(*jeden)};
    Rysunki.emplace_back(std::make_unique<Przycisk<u_short,u_short>>(*window,*event,
                                                      okienko,Stan,1,
                                                      sf::Vector2f(0,0),
                                                      sf::Vector2f(0,0),
                                                      std::string("Menu")));

    Stan[3]=&(*zero);
    Stan[4]=&(*zero);
    Stan[5]=&(*zero);
    Rysunki.emplace_back(std::make_unique<Przycisk<u_short,u_short>>(*window,*event,
                                                                      okienko,Stan,1,
                                                      sf::Vector2f(0,0),
                                                      sf::Vector2f(0,0),
                                                      std::string("Wyjście")));

    Rysunki.emplace_back(std::make_unique<Animacja>("Zegar",*window));
    Animacja *A1=dynamic_cast<Animacja*>(Rysunki.rbegin()->get());
    if(A1!=nullptr) std::cout<<"DUPA"<<std::endl;
    Animacja_plynna A("Wzkazowka");
    Rysunki.push_back(std::make_unique<Animacja_plynna>(A));
    //Rysunki.emplace_back(std::make_unique<Animacja_plynna>("Wzkazowka"));
    Animacja_plynna *A_P=dynamic_cast<Animacja_plynna *>(Rysunki.rbegin()->get());
    if(A_P!=nullptr) std::cout<<"Jestem"<<std::endl;
}
void Interfejs::Akcje_i_rysowanie()
{
    if(Rodzaj!=0)for(u_short c=0;c<Rysunki.size();c++)
    {

        PrzyciskAkcje *przycisk=dynamic_cast<PrzyciskAkcje *>(Rysunki[c].get());
        if(przycisk != nullptr) {przycisk->Akcje();window->Rysowanie(*przycisk);}
        else
        {
            Animacja *przycisk=dynamic_cast<Animacja *>(Rysunki[c].get());
            if(przycisk != nullptr) window->Rysowanie(*przycisk);
            else
            {
                Animacja_plynna *przycisk=dynamic_cast<Animacja_plynna *>(Rysunki[c].get());
                if(przycisk != nullptr) ;
                else    window->Rysowanie(*Rysunki[c].get());

            }

        }
    }
}
