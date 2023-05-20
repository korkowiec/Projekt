#include <Szachy/Okna/Piaskownica/piaskownica.h>

void Piaskownica::Dzialanie()
{

    //Tworzenie obiektów
//Plansza.Zmiana_Pola(2);

Plansza_gry P;

    //Działanie w pętli
    while(okienko==3)
    {
        //P.Zmiana_Pola(3);
        Plansza.Zmiana_ruch(2);
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
