#include <Szachy/Okna/Wlasna_plansza/Wlasna_plasza.h>

Wlasna_plasza::Wlasna_plasza(RenderWindow &W,sf::Event &E):window(&W),event(&E),Plansza(W)
{
    Tworzenie_obiektów();

    Dzialanie();
}

void Wlasna_plasza::Dzialanie()
{
    while(okienko==4)
    {
        window->clear();

        Akcje();
        Akcja_interfejs();

        Akcja_plansza();
        Rysowanie_interfejs();
        Rysowanie_plansza();

        window->display();
    }
}

void Wlasna_plasza::Rysowanie_plansza()
{
    if(Plansza.Rozmiar_x!=Plansza.Rozmiar_x1||Plansza.Rozmiar_y!=Plansza.Rozmiar_y1) Plansza.Zmiana_rozmiaru();
    float wx=window->getSize().x,wy=window->getSize().y;
    Rysunek.setScale(window->getView().getSize().x/wx,window->getView().getSize().y/wy); //skaluje elementy do zmiany rozmiaru okna (View!=Size)
    if(wy<wx) wx=wy; else wy=wx; //rysowanie jest polem kwadratowym niezależnie od ilości na danym boku elementów
    Rysunek.setSize(sf::Vector2f(wx/Plansza.Rozmiar_x,wy/Plansza.Rozmiar_y));
    for (short c=0;c < Plansza.Rozmiar_y;c++ )
    {
        for(short d=0;d<Plansza.Rozmiar_x;d++)
        {
            Rysunek.setPosition((d%Plansza.Rozmiar_x)*window->getView().getSize().x*wx/Plansza.Rozmiar_x/window->getSize().x,(c%Plansza.Rozmiar_y)*window->getView().getSize().y*wy/Plansza.Rozmiar_y/window->getSize().y);

            if((c+d)%2==0) Rysunek.setFillColor(Plansza.Pole1);
            else Rysunek.setFillColor(Plansza.Pole2);

            window->draw(Rysunek);
        }
    }


    for(std::vector<std::pair<std::pair<sf::String,bool>,sf::Sprite>> &P:Plansza.Ruch)for(std::pair<std::pair<sf::String,bool>,sf::Sprite> &P:P)
    {
        if(P.first.first!="")
        {
            window->Rysowanie(P.second);
        }
    }

}

void Wlasna_plasza::Rysowanie_interfejs()
{
    for(Przycisk &P:Przyciski) window->Rysowanie(P);
    //TEKST
    {
        sf::Vector2f(pos)=sf::Vector2f(0.01,0.01);
        sf::Vector2f(roz)=sf::Vector2f(0.1,0.1);
        sf::Vector2f(pos1)=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
        sf::Vector2f(roz2)=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

        //NAZWA
        {
        pos=sf::Vector2f(0.61,0.01);
        roz=sf::Vector2f(0.9,0.1);
        pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
        roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

        window->Rysowanie(Teksty[0]);
        Teksty[0].setString(Nazwa_pliku);
        Popraw_tekst(pos1,roz2,Teksty[0],*window);
        }

        //TEAM
        {

            pos=sf::Vector2f(0.51,0.11);
            roz=sf::Vector2f(0.6,0.2);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

            window->Rysowanie(Teksty[1]);
            Teksty[1].setString(std::to_string(TEAM));
            Popraw_tekst(pos1,roz2,Teksty[1],*window);
        }
    }
    //SPRITE
    {
        sf::Vector2f(pos);
        sf::Vector2f(roz);
        sf::Vector2f(pos1);
        sf::Vector2f(roz1);

        pos=sf::Vector2f(0.61,0.01);
        roz=sf::Vector2f(0.8,0.2);
        pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
        roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

        Aktualny_wybór.first.setScale((roz1.x-roz.x)*window->getView().getSize().x/Aktualny_wybór.first.getTexture()->getSize().x,
                                      (pos1.x-pos.x)* window->getView().getSize().y/Aktualny_wybór.first.getTexture()->getSize().y);

        window->Rysowanie(Aktualny_wybór.first);
    }
}

void Wlasna_plasza::Akcja_plansza()
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if(!StanMyszki) return;

        StanMyszki=0;

    }
    else
    {
        StanMyszki=1;
        return;
    }


    mouse_position =window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    float wx=window->getView().getSize().x,wy=window->getView().getSize().y;


    if(window->getSize().x>window->getSize().y) wx=wx*window->getSize().y/window->getSize().x; else wy=wy*window->getSize().x/window->getSize().y;


    wx/=Plansza.Rozmiar_x;
    wy/=Plansza.Rozmiar_y;

    int X=mouse_position.x/wx;
    int Y=mouse_position.y/wy;

   // std::cout<<"MOUSE X "<<X<<"\nMOUSE Y "<<Y<<std::endl;
    if(Y>=Plansza.Rozmiar_y||X>=Plansza.Rozmiar_x||Aktualny=="") return;
    else
    {
        if(Plansza.Ruch[Y][X].first.first=="")
        {
            Plansza.Ruch[Y][X].first.first=Aktualny;
            std::vector<std::pair<sf::String,sf::Texture>>::iterator IT;
            for(std::vector<std::pair<sf::String,sf::Texture>>::iterator it=Tekstury.begin();it<Tekstury.end();it++)
            {
                if(Aktualny==it->first)
                {
                    IT=it;
                    break;
                }
            }
        Plansza.Ruch[Y][X].second.setTexture(IT->second,1);
        float wx=window->getSize().x,wy=window->getSize().y;
        if(wy<wx) wx=wy; else wy=wx;
        Plansza.Ruch[Y][X].second.setScale(window->getView().getSize().x/IT->second.getSize().x*wx/(Plansza.Rozmiar_x*window->getSize().x),
                                               window->getView().getSize().y/IT->second.getSize().x*wy/(Plansza.Rozmiar_y*window->getSize().y));
        Plansza.Ruch[Y][X].first.second=TEAM;
        }
        else
        {
           Plansza.Ruch[Y][X].first.first="";
        }

    }
}

void Wlasna_plasza::Akcja_interfejs()
{
    if(CzytajPlik) Czytaj_plik();
    for(Przycisk &P:Przyciski) P.Akcje();
    for(std::pair<sf::Sprite,Przycisk> &P:Wybór_figur)P.second.Akcje();
    if(Aktualny_wybór.second)
    {

        Aktualny_wybór.first.setTexture(Tekstury[Aktualny_wybór.second-1].second,1),
        Aktualny=Tekstury[Aktualny_wybór.second-1].first;
        Aktualny_wybór.second=0;

    }

}

void Wlasna_plasza::Czytaj_plik()
{
    CzytajPlik=0;

    Nazwa_pliku =sf::Clipboard::getString();


}

void Wlasna_plasza::Tworzenie_obiektów()
{

    sf::Vector2f(pos);
    sf::Vector2f(roz);
    sf::Vector2f(pos1);
    sf::Vector2f(roz1);


    //PRZYCISKI
    {
        //MENU
        {
            u_short *Stan[6]={&Tutaju_short,&Tutaju_short,&Tutaju_short,&uliczba_1,&uliczba_1,&uliczba_1};
            pos=sf::Vector2f(0.91,0.01);
            roz=sf::Vector2f(1,0.1);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);
            Przyciski.emplace_back(Przycisk(*window,*event,okienko,
                                    Stan,pos1,roz1,std::string("MENU")));
        }


        //X+
        {
            short stanik[6]={0,0,1,0,0,1};
            pos=sf::Vector2f(0.01,0.01);
            roz=sf::Vector2f(0.1,0.1);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);
            Przyciski.emplace_back(Przycisk(*window,*event,Plansza.Rozmiar_x1,
                                            stanik,pos1,roz1,std::string("X+")));

        }
        //X-
        {
            short stanik[6]={0,0,-1,0,0,-1};
            pos=sf::Vector2f(0.21,0.01);
            roz=sf::Vector2f(0.3,0.1);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);
            Przyciski.emplace_back(Przycisk(*window,*event,Plansza.Rozmiar_x1,
                                            stanik,pos1,roz1,std::string("X-")));
        }
        //Y+
        {
            short stanik[6]={0,0,1,0,0,1};
            pos=sf::Vector2f(0.01,0.11);
            roz=sf::Vector2f(0.1,0.2);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);
            Przyciski.emplace_back(Przycisk(*window,*event,Plansza.Rozmiar_y1,
                                            stanik,pos1,roz1,std::string("Y+")));
        }
        //Y-
        {
            short stanik[6]={0,0,-1,0,0,-1};
            pos=sf::Vector2f(0.21,0.11);
            roz=sf::Vector2f(0.3,0.2);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);
            Przyciski.emplace_back(Przycisk(*window,*event,Plansza.Rozmiar_y1,
                                            stanik,pos1,roz1,std::string("Y-")));
        }
        //Drużyna
        {
            bool *Stan[6]={&bool_0,&bool_0,&bool_0,&bool_1,&bool_1,&bool_1};
            pos=sf::Vector2f(0.31,0.11);
            roz=sf::Vector2f(0.5,0.2);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);
            Przyciski.emplace_back(Przycisk(*window,*event,TEAM,
                                    Stan,pos1,roz1,std::string("TEAM")));
        }
        //Załaduj teksture
        {
        bool *Stan[6]={&bool_0,&bool_0,&bool_1,&bool_0,&bool_0,&bool_1};
        pos=sf::Vector2f(0.31,0.01);
        roz=sf::Vector2f(0.60,0.1);
        pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
        roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

        Przyciski.emplace_back(Przycisk(*window,*event,CzytajPlik,
                                        Stan,pos1,roz1,std::string("Wczytaj\n nazwę")));

        }




    }
    //Wczytanie figur
    {
        int D=0;
        std::pair<sf::String,sf::Texture> P;
        std::fstream Plan("Pliki_tekstowe/Figury/Figury.txt", std::fstream::in);
        if(Plan.is_open())
        {
            std::string ruch;
            while(std::getline(Plan, ruch))
            {
                if(ruch=="\n") continue;
                NazwyFigur.emplace_back(ruch);
                D++;
                P.first=ruch;
                if(!P.second.loadFromFile("Grafika/Figury/"+ruch+".png"))std::cout<<"NIE UDAŁO SIE"<<std::endl;
                Tekstury.emplace_back(P);
            }
        }
        std::wstring C=L"Pliki_tekstowe/Figury_własne/Figury.txt";
        wchar_t T[C.size()+1];
        for(int c=0;c<C.size();c++)
        {
            T[c]=C[c];
        }
        T[C.size()]='\0';
        std::fstream Plan1(T, std::fstream::in);
        if(Plan1.is_open())
        {

            std::cout<<"DZIAL"<<std::endl;


            std::string ruch;
            std::getline(Plan1, ruch);
            while(std::getline(Plan1, ruch))
            {
                if(ruch=="\n") continue;
                NazwyFigur.emplace_back(ruch);
                P.first=ruch;



                if(!P.second.loadFromFile("Grafika/Figury_własne/"+ruch))
                {




                    std::wcout<<"CO SI POPSUO"<<std::endl;
                    std::wstring filePath = L"Grafika/Figury_wlasne/";
                    for(char &B:ruch)
                    {
                        filePath+=B;
                    }

                    std::wifstream file(filePath.data(), std::ios::binary);
                    if (file)
                    {
                        // Określenie rozmiaru pliku
                        file.seekg(0, std::ios::end);
                        std::streampos fileSize = file.tellg();
                        file.seekg(0, std::ios::beg);

                        // Przygotowanie bufora na dane pliku
                        std::vector<wchar_t> fileData(fileSize);
                        file.read(&fileData[0], fileSize);
                          std::vector<char> fileData1(fileSize);
                          for (unsigned int c=0;c<fileSize;c++)
                              {
                                  fileData1[c]=fileData[c];
                              }
                        // Załadowanie danych tekstury z pamięci

                        if (P.second.loadFromMemory(&fileData1[0], fileSize))
                        {

                           Tekstury.emplace_back(P);
                        }
                        else
                        {
                            std::cout<<"Co kurwa?"<<std::endl;
                        }
                        file.close();
                    }
                    else
                    {
                        std::cout<<"Nawet to nie udalo sie"<<std::endl;
                    }






                }
                else
                {
                Tekstury.emplace_back(P);
                }
            }
        }


    }
    //PRZYCISKI DO FIGUR
    {
        pos=sf::Vector2f(0.01,0.21);
        roz=sf::Vector2f(0.99,0.79);
        pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
        roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);
        int C=1,D=3;
        short Tablica[6]={0,0,0,0,0,0};
        while(C*D<Tekstury.size())if((D+C)%2)D++;else C++;

        for(int c=0;c<C;c++)for(int d=0;d<D&&c*D+d<Tekstury.size();d++)
        {
            Tablica[2]=D*c+d+1;
            Tablica[5]=D*c+d+1;
            pos=sf::Vector2f(0.01+c*0.99/C,0.21+d*0.79/D);
            roz=sf::Vector2f(0.01+c*0.99/C+0.99/C,0.21+d*0.79/D+0.79/D);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);
            Przyciski.emplace_back(Przycisk(*window,*event,Aktualny_wybór.second,
                                            Tablica,pos1,roz1,Tekstury[D*c+d].first));

        }
    }
    //Teksty
    {
        //NAZWA
        {
            pos=sf::Vector2f(0.51,0.01);
            roz=sf::Vector2f(0.9,0.2);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

            Teksty.emplace_back(Tworzymy_tekst(pos1,roz1,Nazwa_pliku,*window));
        }

        //TEAM
        {
            pos=sf::Vector2f(0.51,0.11);
            roz=sf::Vector2f(0.6,0.2);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

        Teksty.emplace_back(Tworzymy_tekst(pos1,roz1,std::string(std::to_string(TEAM)),*window));
        }
    }
    //SPRITE
    {
        pos=sf::Vector2f(0.6,0.00);
        roz=sf::Vector2f(0.9,0.2);
        pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
        roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

        sf::RectangleShape przycisk;
        if(roz1.x>pos1.x)
        {
            float x=roz1.x;
            roz1.x=pos1.x;
            pos1.x=x-roz1.x;
        }
        else pos1.x-=roz1.x;
        if(roz1.y>pos1.y)
        {
            float y=roz1.y;
            roz1.y=pos1.y;
            pos1.y=y-roz1.y;
        }
        else pos1.y-=roz1.y;
        Aktualny_wybór.first.setPosition(window->getView().getSize().x*roz1.x,window->getView().getSize().y*roz1.y);
        sf::Texture T;
        Aktualny_wybór.first.setTexture(T);
    }
}

void Wlasna_plasza::Akcje()
{
    while(window->pollEvent(*event))
    {
        mouse_position = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
        if(event->type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)||sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {okienko=0;window->close();}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) okienko=2;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)) okienko=1;

    }
}
