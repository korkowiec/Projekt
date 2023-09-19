#include <Szachy/Okna/Zagraj_wlasna_plansze/Zagraj_wlasna_plansze.h>

Zagraj_wlasna_plansze::Zagraj_wlasna_plansze(RenderWindow &W,sf::Event &E):window(&W),event(&E)
{
    Czytaj();
    Twórz();
    Dzialanie();
    Graj();

}


void Zagraj_wlasna_plansze::Graj()
{

}

void Zagraj_wlasna_plansze::Czytaj()
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

void Zagraj_wlasna_plansze::Dzialanie()
{
    while(okienko==5)
    {
        window->clear();

        while(window->pollEvent(*event))
        {
            mouse_position = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
            if(event->type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)||sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {okienko=0;window->close();}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)) okienko=1;

        }

        for(std::unique_ptr<PrzyciskAkcje> &P:Plansze){window->Rysowanie(*P);P->Akcje();}
        if(aktualny)
        {
            Wybór=Nazwy[aktualny-1];
            okienko=2;
        }
        window->display();
    }
    while(okienko==2)
    {
        Plansza Plansza(*window,*event,Wybór);
        Plansza.Gra();
    }
}

void Zagraj_wlasna_plansze::Twórz()
{
    sf::Vector2f(pos);
    sf::Vector2f(roz);

    pos=sf::Vector2f(0.01,0.01);
    roz=sf::Vector2f(0.99,0.99);
    int C=1,D=3;

    while(C*D<Nazwy.size()+1)if((D+C)%2)D++;else C++;
    u_short Tablica2[6]={0,0,0,1,1,1};
    u_short *Tablica1[6]={&okienko,&okienko,&okienko,&Tablica2[3],&Tablica2[4],&Tablica2[5]};
    sf::Color C2[6]={sf::Color::Green,sf::Color::Green,sf::Color::Red,sf::Color::Red,sf::Color::Red,sf::Color::Red};
    pos=sf::Vector2f(0.00,0.00);
    roz=sf::Vector2f(0.00+0.99/C,0.00+0.99/D);
    Plansze.emplace_back(std::make_unique<Przycisk<u_short,u_short>>(*window,*event,okienko,
                                    Tablica1,1,pos,roz,"MENU"));

    for(int c=0;c<C;c++)for(int d=0;d<D&&c*D+d<Nazwy.size()+1;d++)

    {
        if(c==0&&d==0)continue;
        short Tablica1[6]={0,0,0,short(D*c+d),short(D*c+d),short(D*c+d)};
        short *Tablica[6]={&Tablica1[0],&Tablica1[1],&Tablica1[2],&Tablica1[3],&Tablica1[4],&Tablica1[5]};
        pos=sf::Vector2f(0.00+c*0.99/C,0.00+d*0.99/D);
        roz=sf::Vector2f(0.00+c*0.99/C+0.99/C,0.00+d*0.99/D+0.99/D);
        Plansze.emplace_back(std::make_unique<Przycisk<short,short>>(*window,*event,aktualny,
                                        Tablica,0,pos,roz,Nazwy[D*c+d-1]));
        Plansze.rbegin()->get()->Kolor(C2);
        //Plansze.rbegin()->Kolor(C2);
    }

}
