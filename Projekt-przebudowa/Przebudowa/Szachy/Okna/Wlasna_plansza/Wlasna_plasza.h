#ifndef WLASNA_PLASZA_H
#define WLASNA_PLASZA_H

#include <Szachy/Klasy_pomocnice/tekst.h>
#include <Szachy/Klasy_pomocnice/przycisk.h>
#include <Szachy/Klasy_pomocnice/animacja_plynna.h>
#include <Szachy/Klasy_pomocnice/animacja.h>
class Wlasna_plasza
{
protected:

    struct Plansza_gry
    {
        RenderWindow *window;
        u_short Rozmiar_x;
        u_short Rozmiar_y;
        u_short Rozmiar_x1;
        u_short Rozmiar_y1;
        sf::Color Pole1=sf::Color(181,127,99);
        sf::Color Pole2=sf::Color(240,217,181);
        std::vector<std::vector<std::pair<sf::String,sf::Sprite>>> Ruch;
        ~Plansza_gry(){for(std::vector<std::pair<sf::String,sf::Sprite>> &A:Ruch)A.clear();Ruch.clear();}
        Plansza_gry(RenderWindow &W,const int x=8,const int y=8):Rozmiar_x(x),Rozmiar_y(y),Rozmiar_x1(x),Rozmiar_y1(y),window(&W)
        {
           std::vector<std::pair<sf::String,sf::Sprite>> A(y);
           Ruch.resize(x,A);
           float wx=window->getSize().x,wy=window->getSize().y;
           if(wy<wx) wx=wy; else wy=wx;
           for(int c=0;c<Ruch.size();c++)
           {
               for(int d=0;d<A.size();d++)
               {

                  Ruch[c][d].second.setPosition((d%Rozmiar_x1)*window->getView().getSize().x*wx/Rozmiar_x1/window->getSize().x,(c%Rozmiar_y1)*window->getView().getSize().y*wy/Rozmiar_y1/window->getSize().y);

               }
           }

        }
        void Zmiana_rozmiaru()
        {
            if(Rozmiar_x1<1||Rozmiar_y1<1) {Rozmiar_x1=Rozmiar_x,Rozmiar_y1=Rozmiar_y;return;}


            //NOWY
            std::vector<std::pair<sf::String,sf::Sprite>> A(Rozmiar_y1);
            std::vector<std::vector<std::pair<sf::String,sf::Sprite>>> To(Rozmiar_x1,A);

            //KOPIUJ
            for(int c=0;c<Rozmiar_x1&&c<Rozmiar_x;c++)
            {
                for(int d=0;d<Rozmiar_y1&&d<Rozmiar_y;d++)
                {
                   To[c][d]=Ruch[c][d];
                }
            }

            //Nowy rozmiar
            Ruch.clear();
            Ruch.resize(Rozmiar_x1,A);

            float wx=window->getSize().x,wy=window->getSize().y;
            if(wy<wx) wx=wy; else wy=wx;


            //Kopiuj
            for(int c=0;c<Rozmiar_x1&&c<Rozmiar_x;c++)
            {
                for(int d=0;d<Rozmiar_y1&&c<Rozmiar_y;d++)
                {
                   Ruch[c][d]=To[c][d];
                   Ruch[c][d].second.setPosition((d%Rozmiar_x1)*window->getView().getSize().x*wx/Rozmiar_x1/window->getSize().x,(c%Rozmiar_y1)*window->getView().getSize().y*wy/Rozmiar_y1/window->getSize().y);

                }
            }

            Rozmiar_x=Rozmiar_x1;
            Rozmiar_y=Rozmiar_y1;
        }
    };


    RenderWindow *window;
    sf::Event *event;

private:
    std::vector<sf::Text> Teksty;
    sf::RectangleShape Rysunek;
    Plansza_gry Plansza;
    std::vector<Przycisk> Przyciski;
    std::vector<std::pair<sf::Sprite,Przycisk>> Wybór_figur;
    std::vector<std::pair<sf::String,sf::Texture>> Tekstury;
    std::pair<sf::Sprite,short> Aktualny_wybór;
    sf::String Aktualny="";
    //short Pamiętaj=0;
    sf::String Nazwa_pliku;
    bool TEAM;
    bool CzytajPlik=0;
    bool StanMyszki=0;
    void Dzialanie();
    void Rysowanie_plansza();
    void Rysowanie_interfejs();
    void Akcja_plansza();
    void Akcja_interfejs();
    void Tworzenie_obiektów();
    void Akcje();
    void Czytaj_plik();
public:
    Wlasna_plasza(RenderWindow &W,sf::Event &E);
    ~Wlasna_plasza(){NazwyFigur.clear();}
};

#endif // WLASNA_PLASZA_H
