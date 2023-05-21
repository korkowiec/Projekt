#ifndef PIASKOWNICA_H
#define PIASKOWNICA_H


#include <Szachy/Dane_poczatkowe/Zdarzenia.h>
#include <Szachy/Klasy_pomocnice/przycisk.h>
#include <Szachy/Klasy_pomocnice/animacja_plynna.h>
#include <Szachy/Klasy_pomocnice/animacja.h>


class Piaskownica
{
protected:
    struct Dane_ruchu
    {
        ~Dane_ruchu(){}
        sf::RectangleShape rec;
        bool IsSelect=0;
        short x; //ruch w X
        short y; //ruch w Y
        u_short EL=1; // liczba pętli, 0==nieskończonośc
        bool US=0; //unikanie kolizji ze swoimi
        bool UW=0; //UwU unikanie kolizji z wrogami oba bool wykorzystywanie w ruchach w pętli
        bool Z=1; //możliwość zbijania wroga
        bool ZE=1; //możliwość zbicia wroga kończy pętle
        bool S=0; //możliwość zbicia swoich
        bool SE=1; //możliwość zbicia swojego kończy pętle
        bool M =0; //Czy musi być z pozycji początkowej
        bool T =0; //tylko bicie figur
        Dane_ruchu(short x=0,short y=0,u_short EL=1,bool US=0,bool UW=0,bool Z=1,bool ZE=1,bool S=0,bool SE=1,bool M =0,bool T=0):x(x),y(y),EL(EL),US(US),UW(UW),Z(Z),ZE(ZE),S(S),SE(SE),M(M),T(T){}
    };

    struct Plansza_gry
    {

        int Rozmiar=0;
        sf::Color Pole1=sf::Color(181,127,99);
        sf::Color Pole2=sf::Color(240,217,181);
        std::vector<std::vector<Dane_ruchu>> ruch;
        Plansza_gry()
        {
            Rozmiar=5;
            Pole1=sf::Color(181,127,99);
            Pole2=sf::Color(240,217,181);
            for(int c=0;c<Rozmiar;c++)
            {
                std::vector<Dane_ruchu> A;
                for(int c=0;c<Rozmiar;c++)
                {
                    A.emplace_back(Dane_ruchu());
                }
                //ruch.push_back(A);
                ruch.emplace_back(A);
                //ruch.insert(ruch.end(),A);
                //ruch.emplace_back(std::vector<Dane_ruchu>());
            }
        }
        void Zmiana_ruch(int a)
        {
            int NowyRozmiar=a*2+1;
            std::vector<std::vector<Dane_ruchu>> To;
            //NOWY
            for(int c=0;c<NowyRozmiar;c++)
            {
                std::vector<Dane_ruchu> A;
                for(int c=0;c<NowyRozmiar;c++)
                {
                    A.emplace_back(Dane_ruchu());
                }
                To.emplace_back(A);
            }
            //KOPIUJ
            for(int c=0;c<NowyRozmiar&&c<Rozmiar;c++)
            {
                for(int d=0;d<NowyRozmiar&&d<Rozmiar;d++)
                {
                   To[c][d]=ruch[c][d];
                }
            }

            //Nowy rozmiar
            ruch.clear();

            for(int c=0;c<NowyRozmiar;c++)
            {
                std::vector<Dane_ruchu> A;
                for(int c=0;c<NowyRozmiar;c++)
                {
                    A.emplace_back(Dane_ruchu());
                }
                ruch.emplace_back(A);
            }

            //Kopiuj
            for(int c=0;c<NowyRozmiar&&c<Rozmiar;c++)
            {
                for(int d=0;d<NowyRozmiar&&c<Rozmiar;d++)
                {
                   ruch[c][d]=To[c][d];
                }
            }

            Rozmiar=NowyRozmiar;
        }

    };

private:
    RenderWindow *window;
    sf::Event *Event;
    Dane_ruchu Aktualne_dane_ruchu;
    Plansza_gry *Plansza;
    float Granica;


    void Zdarzenia_interfejs();
    void Zdarzenia_plansza();
    void Rysowanie_plansza();
    void Rysowanie_interfejs();
public:
    Piaskownica(RenderWindow &W,sf::Event &E):window(&W),Event(&E){Dzialanie();}
    void Dzialanie();
    ~Piaskownica(){}
};

#endif // PIASKOWNICA_H
