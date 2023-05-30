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
        ~Dane_ruchu(){}
    };

    struct Plansza_gry
    {

        int Rozmiar;
        sf::Color Pole1=sf::Color(181,127,99);
        sf::Color Pole2=sf::Color(240,217,181);
        std::vector<std::vector<Dane_ruchu>> Ruch;
        ~Plansza_gry(){for(std::vector<Dane_ruchu> &A:Ruch)A.clear();Ruch.clear();}
        Plansza_gry(const int a=2):Rozmiar(2*a+1)
        {
           std::vector<Dane_ruchu> A(Rozmiar);
           Ruch.resize(Rozmiar,A);
        }
        void Zmiana_ruch(int a)
        {
            int NowyRozmiar=a*2+1;

            //NOWY
            std::vector<Dane_ruchu> A(NowyRozmiar);
            std::vector<std::vector<Dane_ruchu>> To(NowyRozmiar,A);

            //KOPIUJ
            for(int c=0;c<NowyRozmiar&&c<Rozmiar;c++)
            {
                for(int d=0;d<NowyRozmiar&&d<Rozmiar;d++)
                {
                   To[c][d]=Ruch[c][d];
                }
            }

            //Nowy rozmiar
            Ruch.clear();
            Ruch.resize(NowyRozmiar,A);


            //Kopiuj
            for(int c=0;c<NowyRozmiar&&c<Rozmiar;c++)
            {
                for(int d=0;d<NowyRozmiar&&c<Rozmiar;d++)
                {
                   Ruch[c][d]=To[c][d];
                }
            }

            Rozmiar=NowyRozmiar;
        }
    };

private:
    sf::Color Kolory[5]={sf::Color(181,127,99),sf::Color(240,217,181),sf::Color::Green,sf::Color::Red,sf::Color::Yellow};
    float Granica;//Wykorzystam do pamiętania końca planszy i początku interfejsu
    sf::Vector2f(Rozmiar);
    std::vector<Przycisk> Przyciski;
    RenderWindow *window;
    sf::Event *event;
    Dane_ruchu Aktualne_dane_ruchu;
    Plansza_gry *Plansza;//Statyczna wywala mi błąd przy wektorze Ruch, gdy chcę nim operować.
    sf::RectangleShape *Rysunek;
    void Zdarzenia_interfejs();
    void Zdarzenia_plansza();
    void Rysowanie_plansza();
    void Rysowanie_interfejs();

    bool STANIK_BRA=1;
public:
    Piaskownica(RenderWindow &W,sf::Event &E):window(&W),event(&E){}
    void Dzialanie();

    ~Piaskownica(){}
};

#endif // PIASKOWNICA_H
