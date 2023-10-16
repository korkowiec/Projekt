#ifndef BUTTON_H
#define BUTTON_H

#include <Szachy/HelpClass/RenderWindow.h>
#include <Szachy/HelpClass/Text.h>
#include <SFML/Graphics/RectangleShape.hpp>
#include <Szachy/GlobalVariabies/Variables.h>
#include <SFML/Window/Mouse.hpp>
#include <memory>

class ButtonActions: public sf::RectangleShape
{
protected:

    RenderWindow &window;
    sf::Event &event;

    // Do kontroli stanu
    bool IsSelect = 0;
    bool IsPressed = 0;
    bool PrzyjechalemNieWcisniety = 0;


    uint8_t Stan = 0;


    sf::Color Kolory[6] = {sf::Color::Green, sf::Color::Yellow, sf::Color::White, sf::Color::Blue, sf::Color::Cyan, sf::Color::Red};
public:
    Text tekst_przycisku;
    void Kolor(const sf::Color &D, const uint8_t &gdzie) { if(gdzie<=5)Kolory[gdzie] = D; }
    void Kolor(sf::Color D[6]) { for (uint8_t c = 0; c < 6; c++) Kolory[c] = D[c]; }
    virtual ~ButtonActions() {}
    ButtonActions(RenderWindow &W, sf::Event &E,
                  sf::Vector2f pos = sf::Vector2f(0, 0),
                  sf::Vector2f roz = sf::Vector2f(0, 0),
                  std::string S = "",
                  sf::Color C = sf::Color::Green)
        :window(W),event(E){tekst_przycisku.Dane_poczatek(window,*this,S);Zmiana(pos,roz),setFillColor(C);tekst_przycisku.Dane_poczatek(window,*this,S);}
    void Zmiana(sf::Vector2f pos, sf::Vector2f pos1){
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
        setPosition(window.getView().getSize().x*pos.x,window.getView().getSize().y*pos.y);
        setSize(sf::Vector2f(window.getView().getSize().x*pos1.x,window.getView().getSize().y*pos1.y));
        tekst_przycisku.Kalibrowanie();
    }
    virtual void Akcje() {

        if((sf::Mouse::isButtonPressed(sf::Mouse::Left)&&PrzyjechalemNieWcisniety)||!getGlobalBounds().contains(mouse_position))PrzyjechalemNieWcisniety=1;
        else PrzyjechalemNieWcisniety=0;

        if(!PrzyjechalemNieWcisniety&&getGlobalBounds().contains(mouse_position))
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                IsPressed=1;
                if(IsSelect)
                {
                    setFillColor(Kolory[5]);
                    //ZmienStan(5);
                }
                else
                {
                    setFillColor(Kolory[2]);
                    //ZmienStan(2);
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
                    setFillColor(Kolory[4]);
                    //ZmienStan(4);
                }
                else
                {
                    setFillColor(Kolory[1]);
                    //ZmienStan(1);
                }

            }
        }
        else
        {
            IsPressed=0;
            if(IsSelect)
            {
                setFillColor(Kolory[3]);
                //ZmienStan(3);
            }
            else
            {
                setFillColor(Kolory[0]);
                //ZmienStan(0);
            }
        }
        //Zmiana();

    }
};


template <typename Base, typename Change>
class Button: public ButtonActions
{
public:
    Button(RenderWindow &W, sf::Event &E, Base &Zmieniacz, Change* Stany[6] = 0,bool How=0,
             sf::Vector2f pos = sf::Vector2f(0, 0),
             sf::Vector2f roz = sf::Vector2f(0, 0),
             std::string S = "",
             sf::Color C = sf::Color::Green
             ):Zmienna(Zmieniacz),Zastap(How),ButtonActions(W,E,pos,roz,S,C){
        for(int c=0;c<6;c++)if((reinterpret_cast<void*>(Stany[c]) == reinterpret_cast<void*>(&Zmieniacz)))ZmianyZmiennej[c]=Stany[c];
            else  WartosciZmiennej[c]=*Stany[c],ZmianyZmiennej[c]=&WartosciZmiennej[c];
    }


    void Akcje() override
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
                    setFillColor(Kolory[5]);
                    ZmienStan(5);
                }
                else
                {
                    setFillColor(Kolory[2]);
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
                    setFillColor(Kolory[4]);
                    ZmienStan(4);
                }
                else
                {
                    setFillColor(Kolory[1]);
                    ZmienStan(1);
                }

            }
        }
        else
        {
            IsPressed=0;
            if(IsSelect)
            {
                setFillColor(Kolory[3]);
                ZmienStan(3);
            }
            else
            {
                setFillColor(Kolory[0]);
                ZmienStan(0);
            }
        }
        //Zmiana();

    }



private:
    Base& Zmienna;
    Change* ZmianyZmiennej[6];
    Change  WartosciZmiennej[6];
    bool Zastap;
    uint8_t previous=255;
    void ZmienStan(const uint8_t &to){
        if(previous==to)return;
        previous=to;
        if(Zastap) Zmienna=(*ZmianyZmiennej[to]);
        else Zmienna+=(*ZmianyZmiennej[to]);

    }


};

#endif // BUTTON_H
