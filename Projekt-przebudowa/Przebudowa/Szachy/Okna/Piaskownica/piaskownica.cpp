#include <Szachy/Okna/Piaskownica/piaskownica.h>

void Piaskownica::Dzialanie()
{

    //Tworzenie obiektów

    //Plansza
        Plansza_gry P;
        Plansza=&P;
    //
    //Działanie w pętli
    while(okienko==3)
    {

        Zdarzenia_interfejs();

        Zdarzenia_plansza();

        Rysowanie_plansza();

        Rysowanie_interfejs();

    }
}



void Piaskownica::Rysowanie_plansza()
{



}

void Piaskownica::Rysowanie_interfejs()
{

}

void Piaskownica::Zdarzenia_interfejs()
{

}

void Piaskownica::Zdarzenia_plansza()
{

}
