#ifndef PIASKOWNICA_H
#define PIASKOWNICA_H


#include <Szachy/Dane_poczatkowe/Zdarzenia.h>
#include <Szachy/Klasy_pomocnice/przycisk.h>
#include <Szachy/Klasy_pomocnice/animacja_plynna.h>
#include <Szachy/Klasy_pomocnice/animacja.h>


class Piaskownica
{
private:
    RenderWindow *window;
    sf::Event *Event;

    struct Dane_ruchu
    {
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
    {   std::vector<std::vector<Dane_ruchu>> Pole;
        sf::Color Pole1=sf::Color(181,127,99);
        sf::Color Pole2=sf::Color(240,217,181);
        Plansza_gry(const int &a=3){
            std::vector<Dane_ruchu> A;
            A.resize(a);
            Pole.resize(a,A);
        }
    };
public:
    Piaskownica(RenderWindow &W,sf::Event &E):window(&W),Event(&E){Dzialanie();}
    void Dzialanie();
    ~Piaskownica(){}
};

#endif // PIASKOWNICA_H
