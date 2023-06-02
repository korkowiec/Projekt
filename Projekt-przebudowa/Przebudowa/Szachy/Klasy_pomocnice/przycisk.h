#ifndef PRZYCISK_H
#define PRZYCISK_H
#include <Szachy/Klasy_pomocnice/tekst.h>


class Przycisk :public sf::RectangleShape
{
public:
    Przycisk(RenderWindow &W,sf::Event &E,
                       u_short &Zmieniacz,short Stany[6]=0,
    sf::Vector2f (pos)=sf::Vector2f(0,0),
    sf::Vector2f (roz)=sf::Vector2f(0,0),
    std::string S="",
    sf::Color C=sf::Color::Green
   );

    Przycisk(RenderWindow &W,sf::Event &E,
             bool &Zmieniacz,bool Stany[6]=0,
             sf::Vector2f (pos)=sf::Vector2f(0,0),
             sf::Vector2f (roz)=sf::Vector2f(0,0),
             std::string S="",
             sf::Color C=sf::Color::Green
            );
    Przycisk(RenderWindow &W,sf::Event &E,
             bool &Zmieniacz,bool *Stany[6]=0,
             sf::Vector2f (pos)=sf::Vector2f(0,0),
             sf::Vector2f (roz)=sf::Vector2f(0,0),
             std::string S="",
             sf::Color C=sf::Color::Green
             );
    Przycisk(RenderWindow &W,sf::Event &E,
             short &Zmieniacz,short Stany[6]=0,
             sf::Vector2f (pos)=sf::Vector2f(0,0),
             sf::Vector2f (roz)=sf::Vector2f(0,0),
             std::string S="",
             sf::Color C=sf::Color::Green
            );
    Przycisk(RenderWindow &W,sf::Event &E,
             short &Zmieniacz,short *Stany[6]=0,
             sf::Vector2f (pos)=sf::Vector2f(0,0),
             sf::Vector2f (roz)=sf::Vector2f(0,0),
             std::string S="",
             sf::Color C=sf::Color::Green
             );
    Przycisk(RenderWindow &W,sf::Event &E,
             u_short &Zmieniacz,u_short Stany[6]=0,
             sf::Vector2f (pos)=sf::Vector2f(0,0),
             sf::Vector2f (roz)=sf::Vector2f(0,0),
             std::string S="",
             sf::Color C=sf::Color::Green
             );
    Przycisk(RenderWindow &W,sf::Event &E,
             u_short &Zmieniacz,u_short *Stany[6]=0,
             sf::Vector2f (pos)=sf::Vector2f(0,0),
             sf::Vector2f (roz)=sf::Vector2f(0,0),
             std::string S="",
             sf::Color C=sf::Color::Green
             );
    Przycisk(RenderWindow &W,sf::Event &E,
             int &Zmieniacz,int Stany[6]=0,
             sf::Vector2f (pos)=sf::Vector2f(0,0),
             sf::Vector2f (roz)=sf::Vector2f(0,0),
             std::string S="",
             sf::Color C=sf::Color::Green
            );
    Przycisk(RenderWindow &W,sf::Event &E,
             int &Zmieniacz,int *Stany[6]=0,
             sf::Vector2f (pos)=sf::Vector2f(0,0),
             sf::Vector2f (roz)=sf::Vector2f(0,0),
             std::string S="",
             sf::Color C=sf::Color::Green
            );

    void Akcje();


    void Zmiana(sf::Vector2f (pos),sf::Vector2f (pos1));
    //~Przycisk(){Kolory.clear();}

    //To klasa do wypisywania
    Tekst tekst_przycisku;
private:

        //std::vector<std::unique_ptr<sf::Color>> Kolory;
    sf::Color Kolory[6]={sf::Color::Green,sf::Color::Yellow,sf::Color::White,sf::Color::Blue,sf::Color::Cyan,sf::Color::Red};
        //Do kontroli stanu
        bool IsSelect=0;
        bool IsPressed=0;
        bool PrzyjechalemNieWcisniety=0;

        //Dane wejściowe
        RenderWindow *window;
        sf::Event *event;

        //Nazwa tekstu
        std::string Zawartosc_tekstu="";

        //Wzkaźniki na wartości, które przycisk ma zmieniać
        bool *Zmieniabool=nullptr;
        u_short *Zmieniau_short=nullptr;
        short *Zmieniashort=nullptr;
        int *Zmieniaint=nullptr;

        //Tablica wartości- zmienia o wartość z tablicy
        bool UstawboolTablica[6];
        short UstawshortTablica[6];
        u_short Ustawu_shortTablica[6];
        int UstawintTablica[6];

        //Tablica wartości- zmienia NA wartość z tablicy
        bool *ZmieniaboolTablica[6]={nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};
        short *ZmieniashortTablica[6]={nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};
        u_short *Zmieniau_shortTablica[6]={nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};
        int *ZmieniaintTablica[6]={nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};

        //Aktualny stan(potrzebne przy zmien
        u_short Stan=0;

        void Setbool(const bool &B);
        void Setshort(const short &S);
        void Setu_short(const u_short &S);
        void Setint(const int &I);


        void Zmienbool(const bool &B);
        void Zmienshort(const short &S);
        void Zmienu_short(const u_short &S);
        void Zmienint(const int &I);

        void ZmienStan(const u_short &to);

        void Przycisk_podstawy(RenderWindow &W,sf::Event &E,
             sf::Vector2f (pos)=sf::Vector2f(0,0),
             sf::Vector2f (roz)=sf::Vector2f(0,0),
             std::string S="",
             sf::Color C=sf::Color::Green);

};

#endif // PRZYCISK_H
