#include <Szachy/Windows/SandboxChessman/SandboxChessman.h>
#include <Szachy/HelpClass/Button.h>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Clipboard.hpp>
#include <Szachy/GlobalVariabies/GlobalFunctions.h>
#include <filesystem>
#include <fstream>
void SandboxChessman::Dzialanie()
{

    //Tworzenie obiektów

    //Plansza

        Plansza_gry P;
        Plansza=&P;
        sf::RectangleShape rec;
        Rysunek=&rec;
        Tekstura_figury.create(0,0);

    Utwórz_przyciski_i_tekst();
    //Działanie w pętli
    while(::window==3)
    {
        window->clear();


        //Plansza->Zmiana_ruch(2);
        while(window->pollEvent(*event))
        {
            mouse_position = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
            if(event->type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)||sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {::window=0;window->close();}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) ::window=2;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)) ::window=1;



        }

            Zdarzenia_interfejs();

        if(CzytajPlik) Czytaj_plik();
        if(Zapisz_figure&&Tekstura_figury.getSize().x&&Tekstura_figury.getSize().y)Zapisz_figurę();

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

void SandboxChessman::Zapisz_figurę()
{
    Zapisz_figure=0;
    if(Nazwapliku[Nazwapliku.getSize()-1]=='\n')
    {
        Nazwapliku.erase(Nazwapliku.getSize()-1);
    }
    //Dodaj do pliku tekstowego figurę
    {
    std::ofstream outputFile(L"Pliki_tekstowe/Figury_własne/Figury.txt",std::ios::app);
     if (outputFile.is_open()) {  // Sprawdzenie, czy plik został poprawnie otwarty
         std::wstring A(Nazwapliku);
         std::string NazwaplikuUTF8 = std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(Nazwapliku);

           outputFile <<'\n'<< NazwaplikuUTF8;

          outputFile.close();  // Zamknięcie pliku

         //  std::cout << "Zmieniono zawartość pliku." << std::endl;
       } else {

       }
    }
    //Dodaj do tekstur figurę
    //NIE DZIALA DLA ZNAKOW SPOZA ASCII


        //std::locale loc( ".1250" );
        sf::Image image = Tekstura_figury.copyToImage();

        sf::String As=L"Grafika/Figury_wlasne/";
        sf::String Asd=Nazwapliku;
        if(As[As.getSize()-1]=='\n')
        {
            As.erase(As.getSize()-1);
        }
    std::string ABC(As.begin(),As.end());
     std::string NazwaplikuUTF9 = std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(As);
     if(Asd[Asd.getSize()-1]=='\n')
     {
         Asd.erase(Asd.getSize()-1);
     }


     if(0)
     {
      if (!image.saveToFile(Asd))
      {

      }
     }

     else
     {
         std::wstring destinationPath=L"Grafika/Figury_własne/"+Nazwapliku;
             std::filesystem::path sourceFilePath(Lokalizacja_pliku);
             std::filesystem::path destinationFilePath(destinationPath);

             if (!std::filesystem::exists(sourceFilePath)) {

                 return;
             }

             // Kopiowanie ścieżki bezwzględnej
             std::wstring absoluteSourcePath = std::filesystem::absolute(sourceFilePath).wstring();
             std::wstring absoluteDestinationPath = std::filesystem::absolute(destinationFilePath).wstring();



             // Otwieranie plików
             std::wifstream sourceFile(sourceFilePath, std::ios::binary);
             std::wofstream destinationFile(destinationFilePath, std::ios::binary);

             if (!sourceFile) {

                 return;
             }

             if (!destinationFile) {

                 return;
             }

             // Kopiowanie zawartości pliku
             destinationFile << sourceFile.rdbuf();

             // Zamykanie plików
             sourceFile.close();
             destinationFile.close();


         }




     // Zapisz obraz do pliku

     //Pozostałości śmieci



    //Dodaj definicję ruchu
    {

    std::string Ab= std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(Nazwapliku);
    std::wstring A=L"Pliki_tekstowe/Ruchy_figur_własnych/";
    std::string b=std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(A);
    std::string c=b+Ab+".txt";
    std::wstring C=L"Pliki_tekstowe/Ruchy_figur_własnych/"+Nazwapliku+".txt";
                     C+=L'\0';
    std::vector<wchar_t> t;
    for(wchar_t &D:C)
    {
        t.emplace_back(D);
    }
    wchar_t T[t.size()];
    for(uint8_t c=0;c<t.size();c++)
    {
        T[c]=t[c];
    }
    wchar_t *T1=new wchar_t[t.size()+1];
    for(uint8_t c=0;c<t.size();c++)
    {
        T1[c]=t[c];
    }
    T1[t.size()]='\0';
    //wchar_t ok=T[t.size()-1];
    std::ofstream outputFile(T1);

    if (outputFile.is_open()) {  // Sprawdzenie, czy plik został poprawnie otwarty

;
        for(const std::vector<Dane_ruchu> &Ruch:Plansza->Ruch)
        for(const Dane_ruchu &Ruch:Ruch)
        {
            if(Ruch.IsSelect==0)continue;

            outputFile << Ruch.x<<','<<Ruch.y<<','<<Ruch.EL<<','<<
                          Ruch.US<<','<<Ruch.UW<<','<<Ruch.Z<<','<<
                         Ruch.ZE<<','<<Ruch.S<<','<<Ruch.SE<<','<<
                          Ruch.M<<','<<Ruch.T<<";,\n";
        }





        outputFile.close();  // Zamknięcie pliku


        }
    else
        {

        }

    }

}

void SandboxChessman::Czytaj_plik()
{
    CzytajPlik=0;

    Lokalizacja_pliku =sf::Clipboard::getString();
    //reinterpret_cast<const char*> (&value);
    std::string Dzialaj;
    for(unsigned int &D:Lokalizacja_pliku)
    {
        Dzialaj+=reinterpret_cast<const char*> (&D);
    }
    Lokalizacja_pliku.replace(sf::String(L"\\"),sf::String(L"/"));
    //if(Lokalizacja_pliku[1]!=':') std::cout<<"CHUJ"<<std::endl;
    if(Tekstura_figury.loadFromFile(Dzialaj))
    {
        //std::cout<<"PIZDA NAD GŁOWĄ"<<std::endl;

        Figura.setTexture(Tekstura_figury,1);
        sf::String::Iterator It[2];
        for(sf::String::Iterator first=Lokalizacja_pliku.end();first!=Lokalizacja_pliku.begin();first--)
        {
            if(*first=='.') It[0]=first;
            else if(*first=='/')
            {
                It[1]=first;
                break;
            }
        }
        Nazwapliku.clear();
        It[1]++;
        for(sf::String::Iterator first=It[1];first!=Lokalizacja_pliku.end();first++)
        {
            Nazwapliku+=*first;
        }
        Nazwapliku+="\n";
    }
    else
    {
        //std::wcout<<"CO SI POPSUO"<<std::endl;
        std::wstring filePath = Lokalizacja_pliku;

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

            if (Tekstura_figury.loadFromMemory(&fileData1[0], fileSize))
            {

                Figura.setTexture(Tekstura_figury,1);
                sf::String::Iterator It[2];
                for(sf::String::Iterator first=Lokalizacja_pliku.end();first!=Lokalizacja_pliku.begin();first--)
                {
                    if(*first=='.') It[0]=first;
                    else if(*first=='/')
                    {
                        It[1]=first;
                        break;
                    }
                }
                Nazwapliku.clear();
                It[1]++;
                for(sf::String::Iterator first=It[1];first!=Lokalizacja_pliku.end();first++)
                {
                    Nazwapliku+=*first;
                }
                Nazwapliku+="\n";
            }
            else
            {
                //std::cout<<"Co kurwa?"<<std::endl;
            }
            file.close();
        }
        else ;//std::cout<<"PSP JEBAC PSA"<<std::endl;

    }
}

void SandboxChessman::Utwórz_przyciski_i_tekst()
{


    Rozmiar=sf::Vector2f((1-window->getSize().y/window->getSize().x)*window->getView().getSize().x,window->getView().getSize().y);
    sf::Vector2f(pos)=sf::Vector2f(0.01,0.01);
    sf::Vector2f(roz)=sf::Vector2f(0.1,0.1);
    sf::Vector2f(pos1)=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    sf::Vector2f(roz2)=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    //___________PRZYCISKI___________
    {
    //bool *Stan[6]={&bool_0,&bool_0,&bool_0,&bool_1,&bool_1,&bool_1};



    //MENU
    {
            uint8_t one=1;
    uint8_t *Stan[6]={&::window,&::window,&::window,&one,&one,&one};

    pos=sf::Vector2f(0.81,0.01);
    roz=sf::Vector2f(1,0.1);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

<<<<<<< HEAD
    Przyciski.emplace_back(std::make_unique<Button<u_short,u_short>>(*window,*event,okienko,
=======
    Przyciski.emplace_back(std::make_unique<Button<uint8_t,uint8_t>>(*window,*event,::window,
>>>>>>> d38428a08613b6cd75bbff3990ee966472ba2f9b
                                    Stan,1,pos1,roz2,std::string("MENU")));
    }

    //ZAPISZ
    {
            bool zero=0, one=1;
            bool *Stan[6]={&zero,&zero,&one,
                               &zero,&zero,&one};

    pos=sf::Vector2f(0.81,0.11);
    roz=sf::Vector2f(1,0.2);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Przyciski.emplace_back(std::make_unique<Button<bool,bool>>(*window,*event,Zapisz_figure,
<<<<<<< HEAD
                                    stanik,1,pos1,roz2,std::string("ZAPISZ")));
=======
                                    Stan,1,pos1,roz2,std::string("ZAPISZ")));
>>>>>>> d38428a08613b6cd75bbff3990ee966472ba2f9b
    }

    //Załaduj teksture
    {
        //bool *Stan[6]={&bool_0,&bool_0,&bool_1,&bool_0,&bool_0,&bool_1};

            bool zero=0, one=1;
            bool *Stan[6]={&zero,&zero,&one,
                               &zero,&zero,&one};
            pos=sf::Vector2f(0.31,0.15);
    roz=sf::Vector2f(0.80,0.11);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Przyciski.emplace_back(std::make_unique<Button<bool,bool>>(*window,*event,CzytajPlik,
<<<<<<< HEAD
                                    stanik,1,pos1,roz2,std::string("Wczytaj teksturę")));
=======
                                    Stan,1,pos1,roz2,std::string("Wczytaj teksturę")));
>>>>>>> d38428a08613b6cd75bbff3990ee966472ba2f9b
    }

    //Załaduj nazwę tekstury
//    if(0)
//    {
//    pos=sf::Vector2f(0.31,0.01);
//    roz=sf::Vector2f(0.80,0.05);
//    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
//    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

//    Przyciski.emplace_back(Przycisk(*window,*event,Tutajbool,
//                                    Stan,pos1,roz2,std::string("Załaduj nazwę tekstury")));
//    }

    //+R
    {

    uint8_t zero=0;
    uint8_t one=1;
    uint8_t *stanik[6]={&zero,&zero,&one,
                       &zero,&zero,&one};
    pos=sf::Vector2f(0.31,0.01);
    roz=sf::Vector2f(0.4,0.05);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

<<<<<<< HEAD
    Przyciski.emplace_back(std::make_unique<Button<u_short,u_short>>(*window,*event,aktualny_rozmiar,
=======
    Przyciski.emplace_back(std::make_unique<Button<u_short,uint8_t>>(*window,*event,aktualny_rozmiar,
>>>>>>> d38428a08613b6cd75bbff3990ee966472ba2f9b
                                    stanik,0,pos1,roz2,std::string("R+")));
    }

    //-R
    {
    int8_t zero=0;
    int8_t _one=-1;
    int8_t *stanik[6]={&zero,&zero,&_one,
                       &zero,&zero,&_one};
    pos=sf::Vector2f(0.71,0.01);
    roz=sf::Vector2f(0.8,0.05);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);



<<<<<<< HEAD
    Przyciski.emplace_back(std::make_unique<Button<u_short,short>>(*window,*event,aktualny_rozmiar,
=======
    Przyciski.emplace_back(std::make_unique<Button<u_short,int8_t>>(*window,*event,aktualny_rozmiar,
>>>>>>> d38428a08613b6cd75bbff3990ee966472ba2f9b
                                    stanik,0,pos1,roz2,std::string("R-")));
    }
    //US
    {
            bool zero=0, one=1;
            bool *Stan[6]={&zero,&zero,&zero,
                               &one,&one,&one};
    pos=sf::Vector2f(0.01,0.41);
    roz=sf::Vector2f(0.9,0.5);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Przyciski.emplace_back(std::make_unique<Button<bool,bool>>(*window,*event,Aktualne_dane_ruchu.US,
                                    Stan,1,pos1,roz2,std::string("Unika swoje")));
    }

    //UW
    {
            bool zero=0, one=1;
            bool *Stan[6]={&zero,&zero,&zero,
                               &one,&one,&one};
    pos=sf::Vector2f(0.01,0.31);
    roz=sf::Vector2f(0.9,0.4);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Przyciski.emplace_back(std::make_unique<Button<bool,bool>>(*window,*event,Aktualne_dane_ruchu.UW,
                                    Stan,1,pos1,roz2,std::string("Unika wroga")));
    }

    //Z
    {
            bool zero=0, one=1;
            bool *Stan[6]={&zero,&zero,&zero,
                               &one,&one,&one};
    pos=sf::Vector2f(0.01,0.21);
    roz=sf::Vector2f(0.9,0.3);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Przyciski.emplace_back(std::make_unique<Button<bool,bool>>(*window,*event,Aktualne_dane_ruchu.Z,
                                    Stan,1,pos1,roz2,std::string("Zbicie wroga")));
    }

    //ZE
    {
            bool zero=0, one=1;
            bool *Stan[6]={&zero,&zero,&zero,
                               &one,&one,&one};
    pos=sf::Vector2f(0.01,0.91);
    roz=sf::Vector2f(0.9,1);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Przyciski.emplace_back(std::make_unique<Button<bool,bool>>(*window,*event,Aktualne_dane_ruchu.ZE,
                                    Stan,1,pos1,roz2,std::string("Po zbiciu enemy dalej możesz się ruszać")));
    }

    //S
    {
            bool zero=0, one=1;
            bool *Stan[6]={&zero,&zero,&zero,
                               &one,&one,&one};
    pos=sf::Vector2f(0.01,0.51);
    roz=sf::Vector2f(0.9,0.6);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Przyciski.emplace_back(std::make_unique<Button<bool,bool>>(*window,*event,Aktualne_dane_ruchu.S,
                                    Stan,1,pos1,roz2,std::string("Możliwość zbicia swoich")));
    }

    //SE
    {
            bool zero=0, one=1;
            bool *Stan[6]={&zero,&zero,&zero,
                               &one,&one,&one};
    pos=sf::Vector2f(0.01,0.81);
    roz=sf::Vector2f(0.9,0.9);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Przyciski.emplace_back(std::make_unique<Button<bool,bool>>(*window,*event,Aktualne_dane_ruchu.SE,
                                    Stan,1,pos1,roz2,std::string("Po zbiciu sojusznika dalej możesz się ruszać")));
    }

    //M
    {
            bool zero=0, one=1;
            bool *Stan[6]={&zero,&zero,&zero,
                               &one,&one,&one};
    pos=sf::Vector2f(0.01,0.71);
    roz=sf::Vector2f(0.9,0.8);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Przyciski.emplace_back(std::make_unique<Button<bool,bool>>(*window,*event,Aktualne_dane_ruchu.M,
                                    Stan,1,pos1,roz2,std::string("Musi być w pozycji początkowej")));
    }

    //T
    {
            bool zero=0, one=1;
            bool *Stan[6]={&zero,&zero,&zero,
                               &one,&one,&one};
    pos=sf::Vector2f(0.01,0.61);
    roz=sf::Vector2f(0.9,0.7);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Przyciski.emplace_back(std::make_unique<Button<bool,bool>>(*window,*event,Aktualne_dane_ruchu.T,
                                    Stan,1,pos1,roz2,std::string("Ruch tylko do bicia")));
    }

    //+EL
    {
    uint8_t zero=0, one=1;
    uint8_t *stanik[6]={&zero,&zero,&one,
                          &zero,&zero,&one};

    pos=sf::Vector2f(0.01,0.01);
    roz=sf::Vector2f(0.1,0.1);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

<<<<<<< HEAD
    Przyciski.emplace_back(std::make_unique<Button<u_short,u_short>>(*window,*event,Aktualne_dane_ruchu.EL,
=======
    Przyciski.emplace_back(std::make_unique<Button<u_short,uint8_t>>(*window,*event,Aktualne_dane_ruchu.EL,
>>>>>>> d38428a08613b6cd75bbff3990ee966472ba2f9b
                                    stanik,0,pos1,roz2,std::string("+")));
    }

    //-EL
    {
    int8_t zero=0, _one=-1;
    int8_t *stanik[6]={&zero,&zero,&_one,
                          &zero,&zero,&_one};
    pos=sf::Vector2f(0.21,0.01);
    roz=sf::Vector2f(0.3,0.1);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);



<<<<<<< HEAD
    Przyciski.emplace_back(std::make_unique<Button<u_short,short>>(*window,*event,Aktualne_dane_ruchu.EL,
=======
    Przyciski.emplace_back(std::make_unique<Button<u_short,int8_t>>(*window,*event,Aktualne_dane_ruchu.EL,
>>>>>>> d38428a08613b6cd75bbff3990ee966472ba2f9b
                                    stanik,0,pos1,roz2,std::string("-")));
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
    //Teksty
    {
    pos=sf::Vector2f(0.31,0.11);
    roz=sf::Vector2f(0.8,0.2);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Teksty.emplace_back(Tworzymy_tekst(pos1,roz2,Lokalizacja_pliku,*window));
    }

    //Rozmiar

    {


    pos=sf::Vector2f(0.41,0.01);
    roz=sf::Vector2f(0.7,0.05);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    Teksty.emplace_back(Tworzymy_tekst(pos1,roz2,std::to_string(aktualny_rozmiar*2+1),*window));
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

void SandboxChessman::Rysowanie_tektsu_i_przycisków()
{

    sf::Vector2f(pos)=sf::Vector2f(0.01,0.01);
    sf::Vector2f(roz)=sf::Vector2f(0.1,0.1);
    sf::Vector2f(pos1)=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    sf::Vector2f(roz2)=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);





    //---------TEKSTY----------------
    //Teskt zmienny
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

    //TEKSTY
    {
        pos=sf::Vector2f(0.31,0.11);
        roz=sf::Vector2f(0.8,0.2);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    window->Rysowanie(Teksty[9]);
    Teksty[9].setString(Lokalizacja_pliku);
    Popraw_tekst(pos1,roz2,Teksty[9],*window);
    }

    //ROZMIAR
    {


    pos=sf::Vector2f(0.41,0.01);
    roz=sf::Vector2f(0.7,0.05);
    pos1=sf::Vector2f(((pos.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),pos.y);
    roz2=sf::Vector2f(((roz.x*(window->getSize().x-window->getSize().y)+window->getSize().y)/window->getSize().x),roz.y);

    window->Rysowanie(Teksty[10]);
    Teksty[10].setString(std::to_string(aktualny_rozmiar*2+1));
    Popraw_tekst(pos1,roz2,Teksty[10],*window);
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

        window->Rysowanie(Teksty[11]);
        Popraw_tekst(pos1,roz2,Teksty[11],*window);
        }
    }
}

void SandboxChessman::Rysowanie_plansza()
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
    if(Tekstura_figury.getSize().x&&Tekstura_figury.getSize().y)
    {

    Figura.setScale(window->getView().getSize().x/Figura.getTexture()->getSize().x*wx/(Plansza->Rozmiar*window->getSize().x),
             window->getView().getSize().y/Figura.getTexture()->getSize().y*wy/(Plansza->Rozmiar*window->getSize().y));
    Figura.setPosition((((Plansza->Rozmiar-1)/2)%Plansza->Rozmiar)*window->getView().getSize().x*wx/Plansza->Rozmiar/window->getSize().x,
                       (((Plansza->Rozmiar-1)/2)%Plansza->Rozmiar)*window->getView().getSize().y*wy/Plansza->Rozmiar/window->getSize().y);
    window->draw(Figura);
    }
}

void SandboxChessman::Rysowanie_interfejs()
{
    Rysowanie_tektsu_i_przycisków();

        for(std::unique_ptr<ButtonActions> &P:Przyciski)
    {
        window->Rysowanie(*P);
    }

}

void SandboxChessman::Zdarzenia_interfejs()
{

    for(std::unique_ptr<ButtonActions> &P:Przyciski)
    {
        P->Akcje();
    }
    if(aktualny_rozmiar==0)aktualny_rozmiar=1;
    else if(aktualny_rozmiar*2+1!=Plansza->Rozmiar)Plansza->Zmiana_ruch(aktualny_rozmiar);
}

void SandboxChessman::Zdarzenia_plansza()
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
