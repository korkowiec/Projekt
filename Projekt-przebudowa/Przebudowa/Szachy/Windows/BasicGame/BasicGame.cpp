#include <Szachy/Windows/BasicGame/BasicGame.h>
#include <fstream>
#include <Szachy/GlobalVariabies/Variables.h>
#include <codecvt>

void BasicGame ::Parametry_Planszy() //rozmiar planszy, kolor pól
{

    std::fstream Plan("Pliki_tekstowe/Plansze/"+Plansza_gry.nazwa+'/'+Plansza_gry.nazwa+"Plansza.txt", std::fstream::in);
    if(Plan.is_open())
    {
        std::string ruch;
        while(std::getline(Plan, ruch,';'))
        {
            Plansza_gry.board_x=(short)stoi(ruch);
            std::getline(Plan, ruch,';');
            Plansza_gry.board_y=(short)stoi(ruch);
            std::getline(Plan, ruch,',');
            Plansza_gry.Pole1.r=(uint8_t)stoi(ruch);
            std::getline(Plan, ruch,',');
            Plansza_gry.Pole1.g=(uint8_t)stoi(ruch);
            std::getline(Plan, ruch,',');
            Plansza_gry.Pole1.b=(uint8_t)stoi(ruch);
            std::getline(Plan, ruch,';');
            Plansza_gry.Pole1.a=(uint8_t)stoi(ruch);
            std::getline(Plan, ruch,',');
            Plansza_gry.Pole2.r=(uint8_t)stoi(ruch);
            std::getline(Plan, ruch,',');
            Plansza_gry.Pole2.g=(uint8_t)stoi(ruch);
            std::getline(Plan, ruch,',');
            Plansza_gry.Pole2.b=(uint8_t)stoi(ruch);
            std::getline(Plan, ruch,';');
            Plansza_gry.Pole2.a=(uint8_t)stoi(ruch);
        }
    }

}
void BasicGame ::SetDisplay(sf::Vector2i(a),sf::Vector2u(c))
{
   window->setSize(c);
   window->setPosition(a);
}
void BasicGame ::Ustawienie_Figur()
{
std::fstream Ustawienie("Pliki_tekstowe/Plansze/"+Plansza_gry.nazwa+'/'+Plansza_gry.nazwa+"UstawienieFigur.txt", std::fstream::in);
if(Ustawienie.is_open())
{
        std::string nazwa;//jaka figura
        short x,y;//pozycja
        u_short t;//drużyna
        std::string Pozycja;//czytanie z pliku
        std::getline(Ustawienie, Pozycja,',');
        while(std::getline(Ustawienie, Pozycja,','))
        {
            if(Pozycja==""||Pozycja=="\n")continue;

            nazwa=Pozycja; //Nazwa figury
            std::getline(Ustawienie, Pozycja,',');

            x=(short)stoi(Pozycja); //pozycja z x (podany numer pola)
            std::getline(Ustawienie, Pozycja,',');

            y=(short)stoi(Pozycja);//pozycja z y (podany numer pola)
            std::getline(Ustawienie, Pozycja,',');

            t=(uint8_t)stoi(Pozycja); //Drużyna, do której należy
            std::getline(Ustawienie, Pozycja,',');
            if(Pozycja=="\n"||Pozycja=="")
            figury.emplace_back(*this,nazwa,x,y,t);
            else
            {
            figury.emplace_back(*this,nazwa,x,y,t,(bool)stoi(Pozycja));
            std::getline(Ustawienie, Pozycja,',');
            }

        }
    }
}
void BasicGame ::Ruch_Figur()
{
    for(auto &T:tekstury)
    {
        std::fstream Plik;
        if(T.name.find('.')==std::string::npos) Plik.open("Pliki_tekstowe/Ruchy_figur/"+T.name+".txt", std::fstream::in);
        else
        {
            std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
            std::wstring convertedWstr = converter.from_bytes(T.name);
            std::wstring C=L"Pliki_tekstowe/Ruchy_figur_własnych/"+convertedWstr;
            C+=L".txt";

            wchar_t T[C.size()+1];
            for(int c=0;c<C.size();c++)
            {
                T[c]=C[c];
            }
            T[C.size()]='\0';
            C+=L'\0';
            Plik.open(T, std::fstream::in);
        }
        //Ruch figury zależy od jego nazwy. Jak król biały, to ustawi ruch figury dla króla białego
        if(Plik.is_open())
        {
            std::string ruch;
            while(std::getline(Plik, ruch,','))
            {
                if(ruch=="\n") break;
                PoruszanieSie a; //Nowa struktura 'a'
                if(ruch[ruch.size()-1]!=';')
                {
                    a.x=(short)std::stoi(ruch);
                }
                else
                {
                    a.x=(short)std::stoi(ruch.erase(ruch.size()-1,1));
                    goto endloop;
                }
                std::getline(Plik, ruch,',');
                if(ruch[ruch.size()-1]!=';')
                {
                    a.y=(short)std::stoi(ruch);
                }
                else
                {
                    a.y=(short)std::stoi(ruch.erase(ruch.size()-1,1));
                    goto endloop;
                }
                std::getline(Plik, ruch,',');
                if(ruch[ruch.size()-1]!=';')
                {
                    a.EL=(u_short)std::stoi(ruch);
                }
                else
                {
                    a.EL=(u_short)std::stoi(ruch.erase(ruch.size()-1,1));
                    goto endloop;
                }
                std::getline(Plik, ruch,',');
                if(ruch[ruch.size()-1]!=';')
                {
                    a.US=(bool)std::stoi(ruch);
                }
                else
                {
                    a.US=(bool)std::stoi(ruch.erase(ruch.size()-1,1));
                    goto endloop;
                }
                std::getline(Plik, ruch,',');
                if(ruch[ruch.size()-1]!=';')
                {
                    a.UW=(bool)std::stoi(ruch);
                }
                else
                {
                    a.UW=(bool)std::stoi(ruch.erase(ruch.size()-1,1));
                    goto endloop;
                }
                std::getline(Plik, ruch,',');
                if(ruch[ruch.size()-1]!=';')
                {
                    a.Z=(bool)std::stoi(ruch);
                }
                else
                {
                    a.Z=(bool)std::stoi(ruch.erase(ruch.size()-1,1));
                    goto endloop;
                }
                std::getline(Plik, ruch,',');
                if(ruch[ruch.size()-1]!=';')
                {
                    a.ZE=(bool)std::stoi(ruch);
                }
                else
                {
                    a.ZE=(bool)std::stoi(ruch.erase(ruch.size()-1,1));
                    goto endloop;
                }
                std::getline(Plik, ruch,',');
                if(ruch[ruch.size()-1]!=';')
                {
                    a.S=(bool)std::stoi(ruch);
                }
                else
                {
                    a.S=(bool)std::stoi(ruch.erase(ruch.size()-1,1));
                    goto endloop;
                }
                std::getline(Plik, ruch,',');
                if(ruch[ruch.size()-1]!=';')
                {
                    a.SE=(bool)std::stoi(ruch);
                }
                else
                {
                    a.SE=(bool)std::stoi(ruch.erase(ruch.size()-1,1));
                    goto endloop;
                }
                std::getline(Plik, ruch,',');
                if(ruch[ruch.size()-1]!=';')
                {
                    a.M=(bool)std::stoi(ruch);
                }
                else
                {
                    a.M=(bool)std::stoi(ruch.erase(ruch.size()-1,1));
                    goto endloop;
                }
                std::getline(Plik, ruch,',');
                if(ruch[ruch.size()-1]!=';')
                {
                    a.T=(bool)std::stoi(ruch);
                }
                else
                {
                    a.T=(bool)std::stoi(ruch.erase(ruch.size()-1,1));
                }
             endloop:
                T.Dane.emplace_back(a);
            }
        }
    }
}
bool BasicGame ::Select ()//pozwoli przeszukiwać, czy jest jakaś figura wybrana
{ for(auto &F:figury) if(F.IsSelect==1) return 1;
    return 0;
}
void BasicGame ::Parametry()
{
    float wx=window->getSize().x,wy=window->getSize().y;
    Rysunek.setScale(window->getView().getSize().x/wx,window->getView().getSize().y/wy); //skaluje elementy do zmiany rozmiaru okna (View!=Size)
    if(wy<wx) wx=wy; else wy=wx; //rysowanie jest polem kwadratowym niezależnie od ilości na danym boku elementów
    Rysunek.setSize(sf::Vector2f(wx/Plansza_gry.board_x,wy/Plansza_gry.board_y));
}
void BasicGame ::Rysowanie_Plansza()
{
    float wx=window->getSize().x,wy=window->getSize().y;
    Rysunek.setScale(window->getView().getSize().x/wx,window->getView().getSize().y/wy); //skaluje elementy do zmiany rozmiaru okna (View!=Size)
    if(wy<wx) wx=wy; else wy=wx; //rysowanie jest polem kwadratowym niezależnie od ilości na danym boku elementów
    Rysunek.setPosition(0,0);
    Rysunek.setSize(sf::Vector2f(wx,wy));
    Rysunek.setFillColor(Plansza_gry.Pole1);
    window->draw(Rysunek);
    Rysunek.setFillColor(Plansza_gry.Pole2);
    Rysunek.setSize(sf::Vector2f(wx/Plansza_gry.board_x,wy/Plansza_gry.board_y));
    for (short c=0;c < Plansza_gry.board_y;c++ )
    {
        for(short d=0;d<Plansza_gry.board_x;d++)
        {
            if((c+d)%2==0)
            {
                Rysunek.setPosition((d%Plansza_gry.board_x)*window->getView().getSize().x*wx/Plansza_gry.board_x/window->getSize().x,(c%Plansza_gry.board_y)*window->getView().getSize().y*wy/Plansza_gry.board_y/window->getSize().y);
                window->draw(Rysunek);
            }
        }
    }
}
void BasicGame ::Zdarzenia_Podstawowe()
{

        if(event->type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {window->close(); ::window=0;}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) ::window=2;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) ::window=1;

}
void BasicGame ::Gra()
{
    //bool b=std::any_of(window->pollEvent(*event),window->pollEvent(*event),event->type==sf::Event::MouseButtonPressed&&event->mouseButton.button == sf::Mouse::Left);
    Zmiana_okna.x++;
    sf::Clock clock;
    while(::window==2)
    {

        //std::cout<<Stan()<<std::endl;

        while(window->pollEvent(*event))
        {
            mouse_position = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
            Zdarzenia_Podstawowe();
            akcja_gra_szachy();

        }

        if((window->hasFocus())||Zmiana_okna!=window->getSize()||window->hasFocus()!=HokusPokus)
        {
            window->clear();
            Console.Akcje_i_rysowanie();
            //std::cout<<window->getSize().x<<" "<<window->getSize().y<<std::endl;
            //std::cout<<interfejs.Rozmiar.x<<" "<<interfejs.Rozmiar.y<<std::endl;

//            if(clock.getElapsedTime().asSeconds()>=1)
//            {
//                Gracz_ma_figury_specjalne();
//                clock.restart();
//                std::string S="Przegrał gracz "+std::to_string(Teraz+1);
//                std::cout<<S<<std::endl;
//            }

            Rysowanie_Plansza();
            for(auto &Figury : figury)
            {
                Figury.Ustaw(*window,Plansza_gry.board_x,Plansza_gry.board_y,Figury.X,Figury.Y);
                if(Zmiana_okna!=window->getSize()){Figury.Skalowanie(*window,Plansza_gry.board_x,Plansza_gry.board_y); Console.Ustal_Pole();}

                window->draw(Figury);
            }

            for(auto &Figury : figury)
            {
                if(Figury.IsSelect) Figury.Posible_move();
            }

            if(!Gracz_ma_figury_specjalne())
            {
                //std::cout<<"JEBAC"<<std::endl;
                Console.Koniec_gry();
                break;
            }
            if(Zmiana_okna!=window->getSize()||HokusPokus!=window->hasFocus()){Zmiana_okna=window->getSize(); HokusPokus=window->hasFocus();}
            window->display();
        }
    }
    NazwyFigur.clear();
}
void BasicGame ::Koniec_gry()
{

}
void BasicGame ::akcja_gra_szachy()
{

      if (event->type == sf::Event::MouseButtonPressed)
        {


            if(event->mouseButton.button == sf::Mouse::Left) for(auto &Figury : figury)
            {
                if(Figury.getGlobalBounds().contains(mouse_position) && Select()==Figury.IsSelect &&Figury.team==Teraz)
                Figury.IsSelect=1-Figury.IsSelect%2 ;//Zmienia wartość na przeciwną.
                Figury.Ruch();//Ruch figury
            }

        }

}
void BasicGame ::Tworzenie_calosci()
{
    Ładuj_nazwy_figur();

    tekstury.resize(size(NazwyFigur));
    for(short c=0;c<short(size(NazwyFigur));c++)
    {
        tekstury[c].name=NazwyFigur[c];
        if(tekstury[c].texture.loadFromFile("Grafika/Figury/"+tekstury[c].name+".png"));

        else if(tekstury[c].texture.loadFromFile("Grafika/Figury_wlasne/"+tekstury[c].name));

        else
        {
            //std::string NazwaplikuUTF8 = std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(Nazwapliku);

            std::wstring filePath = L"Grafika/Figury_własne/";
            filePath+=std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>>().from_bytes(NazwyFigur[c]);
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

                if (tekstury[c].texture.loadFromMemory(&fileData1[0], fileSize)) continue;


                file.close();
            }

                ::window=1;
                return;
        }

    }

    Parametry_Planszy();

    //SetDisplay(sf::Vector2i(-8,-31));

    Ustawienie_Figur();
    Ruch_Figur();

    Teraz=0;
    HokusPokus=!window->hasFocus();
}
bool BasicGame ::Stan()
{
while(window->pollEvent(event_))
if(event_.type==sf::Event::MouseButtonPressed)
    if(event_.mouseButton.button == sf::Mouse::Left)return 1;
return 0;
}
bool BasicGame ::Gracz_ma_figury_specjalne()
{

    bool a=std::any_of(figury.cbegin(),figury.cend(),[](Chessman F){return F.team==Teraz&&F.King;});
        //std::cout<<a<<std::endl;
        return (std::any_of(figury.cbegin(),figury.cend(),[](Chessman F){return F.team==Teraz&&F.King;}));
}
void BasicGame ::Ładuj_nazwy_figur()
{
    std::fstream Plan("Pliki_tekstowe/Plansze/"+Plansza_gry.nazwa+"/Figury.txt", std::fstream::in);
    if(Plan.is_open())
    {
        std::string ruch;
        while(std::getline(Plan, ruch))
        {
            if(ruch=="\n"||ruch=="") continue;
            NazwyFigur.emplace_back(ruch);
        }
        Plan.close();
    }
    std::wstring C="Pliki_tekstowe/Plansze/"+sf::String(Plansza_gry.nazwa)+L"/Figury_własne.txt";

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
        while(std::getline(Plan1, ruch))
        {
            if(ruch=="\n"||ruch=="") continue;
            NazwyFigur.emplace_back(ruch);
        }
        Plan1.close();
    }

}
