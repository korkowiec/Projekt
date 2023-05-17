#include <Szachy/Klasy_pomocnice/przycisk.h>


Przycisk::Przycisk(RenderWindow &W,sf::Event &E,
                   u_short &Zmieniacz,u_short Stany[6],
                   sf::Vector2f (pos),
                   sf::Vector2f (roz),
                   std::string S,
                   sf::Color C)
{
    Zmieniau_short=&Zmieniacz;
    for(u_short c=0;c<6;c++) Ustawu_shortTablica[c]=Stany[c];
    Przycisk_podstawy(W,E,pos,roz,S,C);
}
Przycisk::Przycisk(RenderWindow &W,sf::Event &E,
                   bool &Zmieniacz,bool Stany[6],
                   sf::Vector2f (pos),
                   sf::Vector2f (roz),
                   std::string S,
                   sf::Color C)
{
    Zmieniabool=&Zmieniacz;
    for(u_short c=0;c<6;c++) UstawboolTablica[c]=Stany[c];
    Przycisk_podstawy(W,E,pos,roz,S,C);
}
Przycisk::Przycisk(RenderWindow &W,sf::Event &E,
                   int &Zmieniacz,int Stany[6],
                   sf::Vector2f (pos),
                   sf::Vector2f (roz),
                   std::string S,
                   sf::Color C)
{
    Zmieniaint=&Zmieniacz;
    for(u_short c=0;c<6;c++) UstawintTablica[c]=Stany[c];
    Przycisk_podstawy(W,E,pos,roz,S,C);
}
Przycisk::Przycisk(RenderWindow &W,sf::Event &E,
                   u_short &Zmieniacz,u_short *Stany[6],
                   sf::Vector2f (pos),
                   sf::Vector2f (roz),
                   std::string S,
                   sf::Color C)
{
    Zmieniau_short=&Zmieniacz;
    for(u_short c=0;c<6;c++) Zmieniau_shortTablica[c]=Stany[c];
    Przycisk_podstawy(W,E,pos,roz,S,C);
}
Przycisk::Przycisk(RenderWindow &W,sf::Event &E,
                   bool &Zmieniacz,bool *Stany[6],
                   sf::Vector2f (pos),
                   sf::Vector2f (roz),
                   std::string S,
                   sf::Color C)
{
    Zmieniabool=&Zmieniacz;
    for(u_short c=0;c<6;c++) ZmieniaboolTablica[c]=Stany[c];
    Przycisk_podstawy(W,E,pos,roz,S,C);
}
Przycisk::Przycisk(RenderWindow &W,sf::Event &E,
                   int &Zmieniacz,int *Stany[6],
                   sf::Vector2f (pos),
                   sf::Vector2f (roz),
                   std::string S,
                   sf::Color C)
{
    Zmieniaint=&Zmieniacz;
    for(u_short c=0;c<6;c++) ZmieniaintTablica[c]=Stany[c];
    Przycisk_podstawy(W,E,pos,roz,S,C);
}
void Przycisk::Przycisk_podstawy(RenderWindow &W,sf::Event &E,
                   sf::Vector2f (pos),
                   sf::Vector2f (roz),
                   std::string S,
                   sf::Color C)
{
    window=&W;
    event=&E;
    if(pos.x>roz.x)
    {
        float x=pos.x;
        pos.x=roz.x;
        roz.x=x-pos.x;
    }
    else roz.x-=pos.x;
    if(pos.y>roz.y)
    {
        float y=pos.y;
        pos.y=roz.y;
        roz.y=y-pos.y;
    }
    else roz.y-=pos.y;
    setPosition(W.getView().getSize().x*pos.x,W.getView().getSize().y*pos.y);
    setSize(sf::Vector2f(W.getView().getSize().x*roz.x,W.getView().getSize().y*roz.y));
    setFillColor(C);
    Zawartosc_tekstu=S;
    tekst_przycisku.Dane_poczatek(*window,*this,Zawartosc_tekstu);

}
void Przycisk::Akcje()
{

   if((sf::Mouse::isButtonPressed(sf::Mouse::Left)&&PrzyjechalemNieWcisniety)||!getGlobalBounds().contains(mouse_position))PrzyjechalemNieWcisniety=1;
    else PrzyjechalemNieWcisniety=0;

        if(!PrzyjechalemNieWcisniety&&getGlobalBounds().contains(mouse_position))
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
               IsPressed=1;
               if(IsSelect)
               {
                   setFillColor(sf::Color::Red);
                   ZmienStan(5);
               }
               else
               {
                   setFillColor(sf::Color::White);
                   ZmienStan(2);
               }
            }
            else
            {
                if(IsPressed)
                {
                    IsPressed=0;
                    IsSelect=!IsSelect;
                }
                if(IsSelect)
                {
                    setFillColor(sf::Color::Cyan);
                    ZmienStan(4);
                }
                else
                {
                    setFillColor(sf::Color::Yellow);
                    ZmienStan(1);
                }

            }
        }
        else
        {
            IsPressed=0;
            if(IsSelect)
            {
                setFillColor(sf::Color::Blue);
                ZmienStan(3);
            }
            else
            {
                setFillColor(sf::Color::Green);
                ZmienStan(0);
            }
        }
        //Zmiana();

}
void Przycisk::Zmiana(sf::Vector2f (pos),sf::Vector2f (pos1))
{
    if(pos.x>pos1.x)
    {
        float x=pos.x;
        pos.x=pos1.x;
        pos1.x=x-pos.x;
    }
    else pos1.x-=pos.x;
    if(pos.y>pos1.y)
    {
        float y=pos.y;
        pos.y=pos1.y;
        pos1.y=y-pos.y;
    }
    else pos1.y-=pos.y;
    setPosition(window->getView().getSize().x*pos.x,window->getView().getSize().y*pos.y);
    setSize(sf::Vector2f(window->getView().getSize().x*pos1.x,window->getView().getSize().y*pos1.y));
}
void Przycisk::ZmienStan(const u_short &to)
{
    if(Stan==to)return;
    if (ZmieniaboolTablica[to]!=nullptr)Setbool(*ZmieniaboolTablica[to]);
    else if (Zmieniau_shortTablica[to]!=nullptr)Setu_short(*Zmieniau_shortTablica[to]);
    else if (ZmieniaintTablica[to]!=nullptr)Setint(*ZmieniaintTablica[to]);
    else if(Zmieniabool!=nullptr)Zmienbool(UstawboolTablica[to]);
    else if (Zmieniaint!=nullptr)Zmienint(UstawintTablica[to]);
    else if (Zmieniau_short!=nullptr)Zmienu_short(Ustawu_shortTablica[to]);
    Stan=to;
}
void Przycisk::Zmienbool(const bool &B)
{
    *Zmieniabool+=B;
}
void Przycisk::Zmienu_short(const u_short &S)
{
    *Zmieniau_short+=S;
}
void Przycisk::Zmienint(const int &I)
{
    *Zmieniaint+=I;
}
void Przycisk::Setbool(const bool &B)
{
    *Zmieniabool-=*Zmieniabool;
    *Zmieniabool+=B;
    Tutajbool=*Zmieniabool;
}
void Przycisk::Setu_short(const u_short &S)
{
    *Zmieniau_short-=*Zmieniau_short;
    *Zmieniau_short+=S;
    Tutaju_short=*Zmieniau_short;
}
void Przycisk::Setint(const int &I)
{
    *Zmieniaint-=*Zmieniaint;
    *Zmieniaint+=I;
    Tutajint=*Zmieniaint;
}
