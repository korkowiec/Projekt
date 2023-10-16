#include <Szachy/Windows/SandboxChessboard/SandboxChessboard.h>
#include <Szachy/GlobalVariabies/GlobalFunctions.h>
#include <filesystem>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <Szachy/HelpClass/Button.h>
#include <SFML/Window/Clipboard.hpp>
#include <fstream>
#include <SFML/Window/Event.hpp>

SandboxChessboard::SandboxChessboard(RenderWindow &W,sf::Event &E):window(&W),event(&E),Plansza(W)
{
    Tworzenie_obiektów();

    Dzialanie();
}

void SandboxChessboard::Dzialanie()
{
    while(::window==4)
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

void SandboxChessboard::Rysowanie_plansza()
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


    for(std::vector<std::pair<std::pair<sf::String,std::pair<bool,bool>>,sf::Sprite>> &P:Plansza.Ruch)for(std::pair<std::pair<sf::String,std::pair<bool,bool>>,sf::Sprite> &P:P)
    {
        if(P.first.first!="")
        {
            window->Rysowanie(P.second);
        }
    }

}

void SandboxChessboard::Rysowanie_interfejs()
{
    for(std::unique_ptr<ButtonActions> &P:Przyciski) window->Rysowanie(*P);
    //TEKST
    {
        sf::Vector2f(pos)=sf::Vector2f(0.01,0.01);
        sf::Vector2f(roz)=sf::Vector2f(0.1,0.1);
        sf::Vector2f(pos1)=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
        sf::Vector2f(roz2)=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

        //NAZWA
        {
        pos=sf::Vector2f(0.61,0.01);
        roz=sf::Vector2f(0.8,0.1);
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

        //WAŻNA
        {
            pos=sf::Vector2f(0.84,0.11);
            roz=sf::Vector2f(0.9,0.2);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

            window->Rysowanie(Teksty[2]);
            Teksty[2].setString(std::to_string(WAŻNA));
            Popraw_tekst(pos1,roz2,Teksty[2],*window);
        }
        //X
        {
            pos=sf::Vector2f(0.11,0.01);
            roz=sf::Vector2f(0.2,0.1);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

            window->Rysowanie(Teksty[3]);
            Teksty[3].setString(std::to_string(Plansza.Rozmiar_x));
            Popraw_tekst(pos1,roz2,Teksty[3],*window);
        }
        //Y
        {
            pos=sf::Vector2f(0.11,0.11);
            roz=sf::Vector2f(0.2,0.2);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

            window->Rysowanie(Teksty[4]);
            Teksty[4].setString(std::to_string(Plansza.Rozmiar_y));
            Popraw_tekst(pos1,roz2,Teksty[4],*window);}

    }
    //SPRITE
    {
        sf::Vector2f(pos);
        sf::Vector2f(roz);
        sf::Vector2f(pos1);
        sf::Vector2f(roz1);

        pos=sf::Vector2f(0.11,0.11);
        roz=sf::Vector2f(0.2,0.2);
        pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
        roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

        Aktualny_wybór.first.setScale((roz1.x-roz.x)*window->getView().getSize().x/Aktualny_wybór.first.getTexture()->getSize().x,
                                      (pos1.x-pos.x)* window->getView().getSize().y/Aktualny_wybór.first.getTexture()->getSize().y);

        window->Rysowanie(Aktualny_wybór.first);
    }
}

void SandboxChessboard::Akcja_plansza()
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
        if(Plansza.Ruch[X][Y].first.first=="")
        {
            Plansza.Ruch[X][Y].first.first=Aktualny;
            std::vector<std::pair<sf::String,sf::Texture>>::iterator IT;
            for(std::vector<std::pair<sf::String,sf::Texture>>::iterator it=Tekstury.begin();it<Tekstury.end();it++)
            {
                if(Aktualny==it->first)
                {
                    IT=it;
                    break;
                }
            }
        Plansza.Ruch[X][Y].second.setTexture(IT->second,1);
        float wx=window->getSize().x,wy=window->getSize().y;
        if(wy<wx) wx=wy; else wy=wx;
        Plansza.Ruch[X][Y].second.setScale(window->getView().getSize().x/IT->second.getSize().x*wx/(Plansza.Rozmiar_x*window->getSize().x),
                                               window->getView().getSize().y/IT->second.getSize().y*wy/(Plansza.Rozmiar_y*window->getSize().y));
        Plansza.Ruch[X][Y].first.second.first=TEAM;
        Plansza.Ruch[X][Y].first.second.second=WAŻNA;
        }
        else
        {
           Plansza.Ruch[X][Y].first.first="";
        }

    }
}

void SandboxChessboard::Akcja_interfejs()
{
    if(CzytajPlik) Czytaj_plik();
    for(std::unique_ptr<ButtonActions> &P:Przyciski) P->Akcje();
    for(std::pair<sf::Sprite,std::unique_ptr<ButtonActions>> &P:Wybór_figur)P.second->Akcje();
    if(Aktualny_wybór.second)
    {

        Aktualny_wybór.first.setTexture(Tekstury[Aktualny_wybór.second-1].second,1),
        Aktualny=Tekstury[Aktualny_wybór.second-1].first;
        Aktualny_wybór.second=0;

    }
    if(ZAPISZ&&Nazwa_pliku.getSize()<250)Zapisz();

}

void SandboxChessboard::Czytaj_plik()
{
    CzytajPlik=0;

    Nazwa_pliku =sf::Clipboard::getString();


}

void SandboxChessboard::Tworzenie_obiektów()
{

    sf::Vector2f(pos);
    sf::Vector2f(roz);
    sf::Vector2f(pos1);
    sf::Vector2f(roz1);


    //PRZYCISKI
    {
        //MENU
        {
         uint8_t one=1;
            uint8_t *Stan[6]={&::window,&::window,&::window,&one,&one,&one};
            pos=sf::Vector2f(0.91,0.01);
            roz=sf::Vector2f(1,0.1);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);
            Przyciski.emplace_back(std::make_unique<Button<uint8_t,uint8_t>>(*window,*event,::window,
                                    Stan,1,pos1,roz1,std::string("MENU")));
        }


        //X+
        {
            uint8_t zero=0, one=1;
            uint8_t *stanik1[6]={&zero,&zero,&one,&zero,&zero,&one};
            pos=sf::Vector2f(0.01,0.01);
            roz=sf::Vector2f(0.1,0.1);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

            Przyciski.emplace_back(std::make_unique<Button<u_short,uint8_t>>(*window,*event,Plansza.Rozmiar_x1,
                                            stanik1,0,pos1,roz1,std::string("X+")));

        }
        //X-
        {
            int8_t zero=0, _one=-1;
            int8_t *stanik1[6]={&zero,&zero,&_one,&zero,&zero,&_one};
            pos=sf::Vector2f(0.21,0.01);
            roz=sf::Vector2f(0.3,0.1);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);
            Przyciski.emplace_back(std::make_unique<Button<u_short,int8_t>>(*window,*event,Plansza.Rozmiar_x1,
                                            stanik1,0,pos1,roz1,std::string("X-")));
        }
        //Y+
        {
            uint8_t zero=0, one=1;
            uint8_t *stanik1[6]={&zero,&zero,&one,&zero,&zero,&one};
            pos=sf::Vector2f(0.01,0.11);
            roz=sf::Vector2f(0.1,0.2);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

            Przyciski.emplace_back(std::make_unique<Button<u_short,uint8_t>>(*window,*event,Plansza.Rozmiar_y1,
                                            stanik1,0,pos1,roz1,std::string("Y+")));
        }
        //Y-
        {
            int8_t zero=0, _one=-1;
            int8_t *stanik1[6]={&zero,&zero,&_one,&zero,&zero,&_one};
            pos=sf::Vector2f(0.21,0.11);
            roz=sf::Vector2f(0.3,0.2);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

            Przyciski.emplace_back(std::make_unique<Button<u_short,int8_t>>(*window,*event,Plansza.Rozmiar_y1,
                                            stanik1,0,pos1,roz1,std::string("Y-")));
        }
        //Drużyna
        {
            bool zero=0, one=1;
            bool *Stan[6]={&zero,&zero,&zero,&one,&one,&one};
            pos=sf::Vector2f(0.31,0.11);
            roz=sf::Vector2f(0.5,0.2);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);
            Przyciski.emplace_back(std::make_unique<Button<bool,bool>>(*window,*event,TEAM,
                                    Stan,1,pos1,roz1,std::string("TEAM")));
        }
        //Załaduj teksture
        {
            bool zero=0, one=1;
            bool *Stan[6]={&zero,&zero,&zero,&one,&one,&one};
            pos=sf::Vector2f(0.31,0.01);
            roz=sf::Vector2f(0.60,0.1);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

            Przyciski.emplace_back(std::make_unique<Button<bool,bool>>(*window,*event,CzytajPlik,
                                            Stan,1,pos1,roz1,std::string("Wczytaj\n nazwę")));

        }
        //ZAPISZ
        {
            bool zero=0, one=1;
            bool *Stan[6]={&zero,&zero,&zero,&one,&one,&one};
            pos=sf::Vector2f(0.91,0.11);
            roz=sf::Vector2f(1,0.2);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

            Przyciski.emplace_back(std::make_unique<Button<bool,bool>>(*window,*event,ZAPISZ,
                                            Stan,1,pos1,roz1,std::string("ZAPISZ")));

        }

        //WAŻNA
        {
            bool zero=0, one=1;
            bool *Stan[6]={&zero,&zero,&zero,&one,&one,&one};
            pos=sf::Vector2f(0.84,0.01);
            roz=sf::Vector2f(0.9,0.1);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

            Przyciski.emplace_back(std::make_unique<Button<bool,bool>>(*window,*event,WAŻNA,
                                            Stan,1,pos1,roz1,std::string("WAŻNA")));

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
                if(!P.second.loadFromFile("Grafika/Figury/"+ruch+".png"));//std::cout<<"NIE UDAŁO SIE"<<std::endl;
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
        C+=L'\0';
        std::fstream Plan1(T, std::fstream::in);
        if(Plan1.is_open())
        {
            std::string ruch;
            //std::getline(Plan1, ruch);
            while(std::getline(Plan1, ruch))
            {
                if(ruch=="\n") continue;
                NazwyFigur.emplace_back(ruch);
                P.first=ruch;
                if(ruch.find('.')!=std::string::npos)



                {

                    //std::wcout<<"CO SI POPSUO"<<std::endl;
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

                        file.close();
                    }
                    else
                    {
                        //std::string NazwaplikuUTF8 = std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(Nazwapliku);

                        std::wstring filePath = L"Grafika/Figury_własne/";
                        filePath+=std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>>().from_bytes(ruch);
//                        for(char &B:ruch)
//                        {
//                            filePath+=B;
//                        }

                        std::wifstream file(filePath.data(), std::ios::binary);

                        if(file)
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

                            file.close();
                        }
                    }

                }


                else if(!P.second.loadFromFile("Grafika/Figury_własne/"+ruch));






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
        //short Tablica[6]={0,0,0,0,0,0};
        while(C*D<Tekstury.size())if((D+C)%2)D++;else C++;

        for(int c=0;c<C;c++)for(int d=0;d<D&&c*D+d<Tekstury.size();d++)
        {
                short Tablica1[6]={0,0,short(D*c+d+1),0,0,short(D*c+d+1)};
            short *Tablica[6]={&Tablica1[0],&Tablica1[1],&Tablica1[2],&Tablica1[3],&Tablica1[4],&Tablica1[5]};
            pos=sf::Vector2f(0.01+c*0.99/C,0.21+d*0.79/D);
            roz=sf::Vector2f(0.01+c*0.99/C+0.99/C,0.21+d*0.79/D+0.79/D);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);
            Przyciski.emplace_back(std::make_unique<Button<short,short>>(*window,*event,Aktualny_wybór.second,
                                            Tablica,0,pos1,roz1,Tekstury[D*c+d].first));

        }
    }
    //Teksty
    {
        //NAZWA
        {
            pos=sf::Vector2f(0.51,0.01);
            roz=sf::Vector2f(0.8,0.2);
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
        //WAŻNA
        {
            pos=sf::Vector2f(0.84,0.11);
            roz=sf::Vector2f(0.9,0.2);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

        Teksty.emplace_back(Tworzymy_tekst(pos1,roz1,std::string(std::to_string(WAŻNA)),*window));
        }
        //X
        {
            pos=sf::Vector2f(0.11,0.2);
            roz=sf::Vector2f(0.01,0.1);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

        Teksty.emplace_back(Tworzymy_tekst(pos1,roz1,std::string(std::to_string(Plansza.Rozmiar_x)),*window));
        }
        //Y
        {
            pos=sf::Vector2f(0.11,0.2);
            roz=sf::Vector2f(0.11,0.2);
            pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
            roz1=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

        Teksty.emplace_back(Tworzymy_tekst(pos1,roz1,std::string(std::to_string(Plansza.Rozmiar_y)),*window));
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

void SandboxChessboard::Akcje()
{
    while(window->pollEvent(*event))
    {
        mouse_position = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
        if(event->type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)||sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {::window=0;window->close();}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) ::window=2;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)) ::window=1;

    }
}
void SandboxChessboard::Zapisz()
{
    ZAPISZ=0;

    std::string Nazwa=Nazwa_pliku;
    if(Nazwa=="Szachy")return;
    std::string A="Pliki_tekstowe/Plansze/"+Nazwa;
    std::wstring C;
    std::filesystem::create_directories(A);
    //PLANSZA
    {
        C="Pliki_tekstowe/Plansze/"+Nazwa_pliku+L"/"+Nazwa_pliku+"Plansza.txt";

        wchar_t T[C.size()+1];
        for(int c=0;c<C.size();c++)
        {
            T[c]=C[c];
        }
        T[C.size()]='\0';
    C+=L'\0';
        std::ofstream New(T);
        if(New.is_open())
        {
            New<<Plansza.Rozmiar_x<<';'<<Plansza.Rozmiar_y<<';'<<(int)Plansza.Pole1.r<<','<<(int)Plansza.Pole1.g<<','<<(int)Plansza.Pole1.b<<','<<(int)Plansza.Pole1.a<<';'<<(int)Plansza.Pole2.r<<','<<(int)Plansza.Pole2.g<<','<<(int)Plansza.Pole2.b<<','<<(int)Plansza.Pole2.a<<';';
            New.close();
        }

    }
    //USTAWIENIE FIGUR
    std::map<sf::String,int> S;

    {
        C="Pliki_tekstowe/Plansze/"+Nazwa_pliku+L"/"+Nazwa_pliku+"UstawienieFigur.txt";

        wchar_t T[C.size()+1];
        for(int c=0;c<C.size();c++)
        {
            T[c]=C[c];
        }
        T[C.size()]='\0';
C+=L'\0';
        std::wofstream New(T);
        if(New.is_open())
        {
            for(int c=0;c<Plansza.Ruch.size();c++)for(int d=0;d<Plansza.Ruch[0].size();d++)
            {

                if(Plansza.Ruch[c][d].first.first=="") continue;
                S.emplace(Plansza.Ruch[c][d].first.first,1);
                std::wstring W=Plansza.Ruch[c][d].first.first;
                New<<','<<W<<','<<c<<','<<d<<','<<Plansza.Ruch[c][d].first.second.first<<','<<Plansza.Ruch[c][d].first.second.second<<",\n";
            }
            New.close();

        }
    }
    //FIGURY
    {
        C="Pliki_tekstowe/Plansze/"+Nazwa_pliku+L"/Figury.txt";

        wchar_t T[C.size()+1];
        for(int c=0;c<C.size();c++)
        {
            T[c]=C[c];
        }
        T[C.size()]='\0';
        C+=L'\0';
        std::wofstream New(T);
        C="Pliki_tekstowe/Plansze/"+Nazwa_pliku+L"/Figury_własne.txt";

        wchar_t D[C.size()+1];
        for(int c=0;c<C.size();c++)
        {
            D[c]=C[c];
        }
        D[C.size()]='\0';
        C+=L'\0';
        std::wofstream New1(D);

        if(New.is_open()&&New1.is_open())
        {
            for(auto &S:S)
            {
                std::wstring W=S.first;
                if(S.first.find('.')!=sf::String::InvalidPos)

                {
                    New1<<W<<"\n";
                }

                else

                {
                    New<<W<<"\n";
                }


            }
            New.close();
            New1.close();
        }
    }

    //Dodaj do plansz
    {
    std::fstream Plan(L"Pliki_tekstowe/Plansza/Plansze.txt", std::fstream::in);
    {
        if(Plan.is_open())
        {
            std::string ruch;
            while(std::getline(Plan, ruch))
            {
                if(ruch==Nazwa_pliku)return;
            }
        }
    }

    C=L"Pliki_tekstowe/Plansza/Plansze.txt";

    wchar_t T[C.size()+1];
    for(int c=0;c<C.size();c++)
    {
        T[c]=C[c];
    }
    T[C.size()]='\0';
C+=L'\0';
    std::wofstream New(T,std::ios::app);
    if(New.is_open())
    {
        std::wstring W=Nazwa_pliku;
        New<<'\n'<<W;
        New.close();
    }
    }
}
