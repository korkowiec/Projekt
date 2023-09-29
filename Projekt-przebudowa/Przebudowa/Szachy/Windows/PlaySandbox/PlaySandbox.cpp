#include <Szachy/Windows/PlaySandbox/PlaySandbox.h>
#include <Szachy/GlobalVariabies/Variables.h>
#include <fstream>
#include <Szachy/HelpClass/Button.h>
#include <wtypes.h>
#include <SFML/Window/Event.hpp>
#include <Szachy/Windows/BasicGame/BasicGame.h>
#include <memory>

PlaySandbox::PlaySandbox(RenderWindow &W,sf::Event &E):window(&W),event(&E)
{
    Czytaj();
    Twórz();
    Dzialanie();
    Graj();

}


void PlaySandbox::Graj()
{

}

void PlaySandbox::Czytaj()
{

    std::ifstream inputFile(L"Pliki_tekstowe/Plansza/Plansze.txt");

        if (inputFile.is_open())
        {
            std::string line;


            while (std::getline(inputFile, line))
            {
                if(line=="\n"||line=="")continue;
                else if(line[line.size()-1]=='\n')line.erase(line.size()-1);
                Nazwy.emplace_back(line);
            }

            inputFile.close(); // Zamknij plik
        } else
        {
            //std::cout << "Nie można otworzyć pliku" << std::endl;
        }
}

void PlaySandbox::Dzialanie()
{
    while(::window==5)
    {
        window->clear();

        while(window->pollEvent(*event))
        {
            mouse_position = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
            if(event->type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)||sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {::window=0;window->close();}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)) ::window=1;

        }

        for(std::unique_ptr<ButtonActions> &P:Plansze){window->Rysowanie(*P);P->Akcje();}
        if(aktualny)
        {
            Wybór=Nazwy[aktualny-1];
            ::window=2;
        }
        window->display();
    }
    while(::window==2)
    {
        BasicGame BasicGame(*window,*event,Wybór);
        BasicGame.Gra();
    }
}

void PlaySandbox::Twórz()
{
    sf::Vector2f(pos);
    sf::Vector2f(roz);

    pos=sf::Vector2f(0.01,0.01);
    roz=sf::Vector2f(0.99,0.99);
    int C=1,D=3;

    while(C*D<Nazwy.size()+1)if((D+C)%2)D++;else C++;
    uint8_t jeden=1;
    uint8_t *Tablica1[6]={&::window,&::window,&::window,&jeden,&jeden,&jeden};
    sf::Color C2[6]={sf::Color::Green,sf::Color::Green,sf::Color::Red,sf::Color::Red,sf::Color::Red,sf::Color::Red};
    pos=sf::Vector2f(0.00,0.00);
    roz=sf::Vector2f(0.00+0.99/C,0.00+0.99/D);
<<<<<<< HEAD
    Plansze.emplace_back(std::make_unique<Button<u_short,u_short>>(*window,*event,okienko,
=======
    Plansze.emplace_back(std::make_unique<Button<uint8_t,uint8_t>>(*window,*event,::window,
>>>>>>> d38428a08613b6cd75bbff3990ee966472ba2f9b
                                    Tablica1,1,pos,roz,"MENU"));

    for(int c=0;c<C;c++)for(int d=0;d<D&&c*D+d<Nazwy.size()+1;d++)

    {
        if(c==0&&d==0)continue;
        std::unique_ptr<short> Tablica12=std::make_unique<short>(0);
        std::unique_ptr<short> Tablica1=std::make_unique<short>(D*c+d);
        short *Tablica[6]={&(*Tablica12),&(*Tablica12),&(*Tablica12),&(*Tablica1),&(*Tablica1),&(*Tablica1)};
        pos=sf::Vector2f(0.00+c*0.99/C,0.00+d*0.99/D);
        roz=sf::Vector2f(0.00+c*0.99/C+0.99/C,0.00+d*0.99/D+0.99/D);
        Plansze.emplace_back(std::make_unique<Button<short,short>>(*window,*event,aktualny,
                                        Tablica,0,pos,roz,Nazwy[D*c+d-1]));
        Plansze.rbegin()->get()->Kolor(C2);
        //Plansze.rbegin()->Kolor(C2);
    }

}
