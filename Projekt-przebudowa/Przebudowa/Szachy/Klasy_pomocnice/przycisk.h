#ifndef PRZYCISK_H
#define PRZYCISK_H
#include <Szachy/Klasy_pomocnice/tekst.h>


class Przycisk :public sf::RectangleShape
{
public:

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
    virtual ~Przycisk() = default;
    Tekst tekst_przycisku;
private:

        bool IsSelect=0;
        bool IsPressed=0;
        bool PrzyjechalemNieWcisniety=0;

        RenderWindow *window;
        sf::Event *event;

        std::string Zawartosc_tekstu="";


        bool *Zmieniabool=nullptr;
        u_short *Zmieniau_short=nullptr;
        int *Zmieniaint=nullptr;

        bool UstawboolTablica[6];
        u_short Ustawu_shortTablica[6];
        int UstawintTablica[6];

        bool *ZmieniaboolTablica[6]={nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};
        u_short *Zmieniau_shortTablica[6]={nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};
        int *ZmieniaintTablica[6]={nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};

        void Setbool(bool &B);
        void Setu_short(u_short &S);
        void Setint(int &I);

        void Zmienbool(bool B);
        void Zmienu_short(u_short S);
        void Zmienint(int I);
        void ZmienStan(u_short To);
        void Przycisk_podstawy(RenderWindow &W,sf::Event &E,
             sf::Vector2f (pos)=sf::Vector2f(0,0),
             sf::Vector2f (roz)=sf::Vector2f(0,0),
             std::string S="",
             sf::Color C=sf::Color::Green);

};

#endif // PRZYCISK_H
