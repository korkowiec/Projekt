#include <Szachy/Okna/Piaskownica/piaskownica.h>

void Piaskownica::Dzialanie()
{

    //Tworzenie obiektów

    //Plansza

        Plansza_gry P;
        Plansza=&P;
        sf::RectangleShape rec;
        Rysunek=&rec;

    Utwórz_przyciski_i_tekst();
    //Działanie w pętli
    while(okienko==3)
    {
        window->clear();


        //Plansza->Zmiana_ruch(2);
        while(window->pollEvent(*event))
        {
            mouse_position = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
            if(event->type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)||sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {okienko=0;window->close();}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) okienko=2;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)) okienko=1;



        }

            Zdarzenia_interfejs();


            if(STANIK_BRA&&(event->type == sf::Event::MouseButtonPressed)&&(event->mouseButton.button == sf::Mouse::Left))
            {
                Zdarzenia_plansza();
                STANIK_BRA=!STANIK_BRA;

            }
            else if(!(event->mouseButton.button == sf::Mouse::Left))STANIK_BRA=1;

        Rysowanie_plansza();

        Rysowanie_interfejs();

        window->display();
    }
}

void Piaskownica::Utwórz_przyciski_i_tekst()
{


    Rozmiar=sf::Vector2f((1-window->getSize().y/window->getSize().x)*window->getView().getSize().x,window->getView().getSize().y);
    sf::Vector2f(pos)=sf::Vector2f(0.01,0.01);
    sf::Vector2f(roz)=sf::Vector2f(0.1,0.1);
    sf::Vector2f(pos1)=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    sf::Vector2f(roz2)=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    //___________PRZYCISKI___________
    {
    bool *Stan[6]={&bool_0,&bool_0,&bool_0,&bool_1,&bool_1,&bool_1};
    short stanik[6]={0,0,1,
                      0,0,1};

    //MENU
    {
    u_short *Stan[6]={&Tutaju_short,&Tutaju_short,&Tutaju_short,&uliczba_1,&uliczba_1,&uliczba_1};
    pos=sf::Vector2f(0.81,0.01);
    roz=sf::Vector2f(1,0.1);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Przyciski.emplace_back(Przycisk(*window,*event,okienko,
                                    Stan,pos1,roz2,std::string("MENU")));
    }


    //US
    {
    pos=sf::Vector2f(0.01,0.41);
    roz=sf::Vector2f(0.9,0.5);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Przyciski.emplace_back(Przycisk(*window,*event,Aktualne_dane_ruchu.US,
                                    Stan,pos1,roz2,std::string("Unika swoje")));
    }

    //UW
    {
    pos=sf::Vector2f(0.01,0.31);
    roz=sf::Vector2f(0.9,0.4);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Przyciski.emplace_back(Przycisk(*window,*event,Aktualne_dane_ruchu.UW,
                                    Stan,pos1,roz2,std::string("Unika wroga")));
    }

    //Z
    {
    pos=sf::Vector2f(0.01,0.21);
    roz=sf::Vector2f(0.9,0.3);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Przyciski.emplace_back(Przycisk(*window,*event,Aktualne_dane_ruchu.Z,
                                    Stan,pos1,roz2,std::string("Zbicie wroga")));
    }

    //ZE
    {
    pos=sf::Vector2f(0.01,0.91);
    roz=sf::Vector2f(0.9,1);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Przyciski.emplace_back(Przycisk(*window,*event,Aktualne_dane_ruchu.ZE,
                                    Stan,pos1,roz2,std::string("Po zbiciu enemy dalej możesz się ruszać")));
    }

    //S
    {
    pos=sf::Vector2f(0.01,0.51);
    roz=sf::Vector2f(0.9,0.6);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Przyciski.emplace_back(Przycisk(*window,*event,Aktualne_dane_ruchu.S,
                                    Stan,pos1,roz2,std::string("Możliwość zbicia swoich")));
    }

    //SE
    {
    pos=sf::Vector2f(0.01,0.81);
    roz=sf::Vector2f(0.9,0.9);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Przyciski.emplace_back(Przycisk(*window,*event,Aktualne_dane_ruchu.SE,
                                    Stan,pos1,roz2,std::string("Po zbiciu sojusznika dalej możesz się ruszać")));
    }

    //M
    {
    pos=sf::Vector2f(0.01,0.71);
    roz=sf::Vector2f(0.9,0.8);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Przyciski.emplace_back(Przycisk(*window,*event,Aktualne_dane_ruchu.M,
                                    Stan,pos1,roz2,std::string("Musi być w pozycji początkowej")));
    }

    //T
    {
    pos=sf::Vector2f(0.01,0.61);
    roz=sf::Vector2f(0.9,0.7);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Przyciski.emplace_back(Przycisk(*window,*event,Aktualne_dane_ruchu.T,
                                    Stan,pos1,roz2,std::string("Ruch tylko do bicia")));
    }

    //+EL
    {
    pos=sf::Vector2f(0.01,0.01);
    roz=sf::Vector2f(0.1,0.1);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Przyciski.emplace_back(Przycisk(*window,*event,Aktualne_dane_ruchu.EL,
                                    stanik,pos1,roz2,std::string("+")));
    }

    //-EL
    {
    pos=sf::Vector2f(0.21,0.01);
    roz=sf::Vector2f(0.3,0.1);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    stanik[2]=-1;
    stanik[5]=-1;

    Przyciski.emplace_back(Przycisk(*window,*event,Aktualne_dane_ruchu.EL,
                                    stanik,pos1,roz2,std::string("-")));
    }
    }
    //____________________TEKSTY______________________
    //Teksty Zmienne
    {
    //EL
    {
    pos=sf::Vector2f(0.11,0.01);
    roz=sf::Vector2f(0.2,0.1);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Teksty.emplace_back(Tworzymy_tekst(pos1,roz2,std::string(std::to_string(Aktualne_dane_ruchu.EL)),*window));
    }

    //US
    {
    pos=sf::Vector2f(0.91,0.41);
    roz=sf::Vector2f(1,0.5);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Teksty.emplace_back(Tworzymy_tekst(pos1,roz2,std::string(std::to_string(Aktualne_dane_ruchu.US)),*window));
    }

    //UW
    {
        pos=sf::Vector2f(0.91,0.31);
        roz=sf::Vector2f(1,0.4);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Teksty.emplace_back(Tworzymy_tekst(pos1,roz2,std::string(std::to_string(Aktualne_dane_ruchu.UW)),*window));
    }

    //Z
    {
        pos=sf::Vector2f(0.91,0.21);
        roz=sf::Vector2f(1,0.3);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Teksty.emplace_back(Tworzymy_tekst(pos1,roz2,std::string(std::to_string(Aktualne_dane_ruchu.Z)),*window));
    }

    //ZE
    {
        pos=sf::Vector2f(0.91,0.91);
        roz=sf::Vector2f(1,1);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Teksty.emplace_back(Tworzymy_tekst(pos1,roz2,std::string(std::to_string(Aktualne_dane_ruchu.ZE)),*window));
    }

    //S
    {
        pos=sf::Vector2f(0.91,0.51);
        roz=sf::Vector2f(1,0.6);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Teksty.emplace_back(Tworzymy_tekst(pos1,roz2,std::string(std::to_string(Aktualne_dane_ruchu.S)),*window));
    }

    //SE
    {
        pos=sf::Vector2f(0.91,0.81);
        roz=sf::Vector2f(1,0.9);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Teksty.emplace_back(Tworzymy_tekst(pos1,roz2,std::string(std::to_string(Aktualne_dane_ruchu.SE)),*window));
    }

    //M
    {
        pos=sf::Vector2f(0.91,0.71);
        roz=sf::Vector2f(1,0.8);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Teksty.emplace_back(Tworzymy_tekst(pos1,roz2,std::string(std::to_string(Aktualne_dane_ruchu.M)),*window));
    }

    //T
    {
        pos=sf::Vector2f(0.91,0.61);
        roz=sf::Vector2f(1,0.7);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Teksty.emplace_back(Tworzymy_tekst(pos1,roz2,std::string(std::to_string(Aktualne_dane_ruchu.T)),*window));
    }
    }
    //Teksty stałe
    {
    //Liczba pętli
    {
            pos=sf::Vector2f(0.01,0.11);
                    roz=sf::Vector2f(0.3,0.2);
                pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
                roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

                Teksty.emplace_back(Tworzymy_tekst(pos1,roz2,std::string("Liczba pętli"),*window));

    }
    }
}
void Piaskownica::Rysowanie_tektsu()
{

    sf::Vector2f(pos)=sf::Vector2f(0.01,0.01);
    sf::Vector2f(roz)=sf::Vector2f(0.1,0.1);
    sf::Vector2f(pos1)=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    sf::Vector2f(roz2)=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);
    //Teskt zmienn
    {
    //EL
    {
    pos=sf::Vector2f(0.11,0.01);
    roz=sf::Vector2f(0.2,0.1);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    window->Rysowanie(Teksty[0]);
    Teksty[0].setString(std::to_string(Aktualne_dane_ruchu.EL));
    Popraw_tekst(pos1,roz2,Teksty[0],*window);
    }

    //US
    {
    pos=sf::Vector2f(0.91,0.41);
    roz=sf::Vector2f(1,0.5);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    window->Rysowanie(Teksty[1]);
    Teksty[1].setString(std::to_string(Aktualne_dane_ruchu.US));
    Popraw_tekst(pos1,roz2,Teksty[1],*window);
    }

    //UW
    {
        pos=sf::Vector2f(0.91,0.31);
        roz=sf::Vector2f(1,0.4);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    window->Rysowanie(Teksty[2]);
    Teksty[2].setString(std::to_string(Aktualne_dane_ruchu.UW));
    Popraw_tekst(pos1,roz2,Teksty[2],*window);
    }

    //Z
    {
        pos=sf::Vector2f(0.91,0.21);
        roz=sf::Vector2f(1,0.3);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    window->Rysowanie(Teksty[3]);
    Teksty[3].setString(std::to_string(Aktualne_dane_ruchu.Z));
    Popraw_tekst(pos1,roz2,Teksty[3],*window);
    }

    //ZE
    {
        pos=sf::Vector2f(0.91,0.91);
        roz=sf::Vector2f(1,1);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    window->Rysowanie(Teksty[4]);
    Teksty[4].setString(std::to_string(Aktualne_dane_ruchu.ZE));
    Popraw_tekst(pos1,roz2,Teksty[4],*window);
    }

    //S
    {
        pos=sf::Vector2f(0.91,0.51);
        roz=sf::Vector2f(1,0.6);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    window->Rysowanie(Teksty[5]);
    Teksty[5].setString(std::to_string(Aktualne_dane_ruchu.S));
    Popraw_tekst(pos1,roz2,Teksty[5],*window);
    }

    //SE
    {
        pos=sf::Vector2f(0.91,0.81);
        roz=sf::Vector2f(1,0.9);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    window->Rysowanie(Teksty[6]);
    Teksty[6].setString(std::to_string(Aktualne_dane_ruchu.SE));
    Popraw_tekst(pos1,roz2,Teksty[6],*window);
    }

    //M
    {
        pos=sf::Vector2f(0.91,0.71);
        roz=sf::Vector2f(1,0.8);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    window->Rysowanie(Teksty[7]);
    Teksty[7].setString(std::to_string(Aktualne_dane_ruchu.M));
    Popraw_tekst(pos1,roz2,Teksty[7],*window);
    }

    //T
    {
        pos=sf::Vector2f(0.91,0.61);
        roz=sf::Vector2f(1,0.7);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    window->Rysowanie(Teksty[8]);
    Teksty[8].setString(std::to_string(Aktualne_dane_ruchu.T));
    Popraw_tekst(pos1,roz2,Teksty[8],*window);
    }
    }
    //Tekst Stały
    {
         //Liczba pętli
        {

            pos=sf::Vector2f(0.01,0.11);
                    roz=sf::Vector2f(0.3,0.2);
                pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
                roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

        window->Rysowanie(Teksty[9]);
        Popraw_tekst(pos1,roz2,Teksty[9],*window);
        }
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
    Rysowanie_tektsu();

    for(Przycisk &P:Przyciski)
    {
        window->Rysowanie(P);
    }

}

void Piaskownica::Zdarzenia_interfejs()
{

    for(Przycisk &P:Przyciski)
    {
        P.Akcje();
    }
}

void Piaskownica::Zdarzenia_plansza()
{
    mouse_position =window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    float wx=window->getView().getSize().x,wy=window->getView().getSize().y;


    if(window->getSize().y<window->getSize().x) wx=wx*window->getSize().y/window->getSize().x; else wy=wy*window->getSize().x/window->getSize().y;


    wx/=Plansza->Rozmiar;
    wy/=Plansza->Rozmiar;

    int X=mouse_position.x/wx;
    int Y=mouse_position.y/wy;

    //std::cout<<"MOUSE X "<<mouse_position.x<<"\nMOUSE Y "<<mouse_position.y<<std::endl;
    if(Y>=Plansza->Rozmiar||X>=Plansza->Rozmiar||((Y==X)&&(X==((Plansza->Rozmiar-1)/2)))) return;
    else
    {
        Plansza->Ruch[Y][X].IsSelect=!Plansza->Ruch[Y][X].IsSelect;
        if(Plansza->Ruch[Y][X].IsSelect)
        {
            Plansza->Ruch[Y][X].y=((-Plansza->Rozmiar+1)/2)+Y;
            Plansza->Ruch[Y][X].x=((-Plansza->Rozmiar+1)/2)+X;

            Plansza->Ruch[Y][X].EL=Aktualne_dane_ruchu.EL;
            Plansza->Ruch[Y][X].M=Aktualne_dane_ruchu.M;
            Plansza->Ruch[Y][X].S=Aktualne_dane_ruchu.S;
            Plansza->Ruch[Y][X].SE=Aktualne_dane_ruchu.SE;
            Plansza->Ruch[Y][X].T=Aktualne_dane_ruchu.T;
            Plansza->Ruch[Y][X].US=Aktualne_dane_ruchu.US;
            Plansza->Ruch[Y][X].UW=Aktualne_dane_ruchu.UW;
            Plansza->Ruch[Y][X].Z=Aktualne_dane_ruchu.Z;
            Plansza->Ruch[Y][X].ZE=Aktualne_dane_ruchu.ZE;

        }
    }

}
