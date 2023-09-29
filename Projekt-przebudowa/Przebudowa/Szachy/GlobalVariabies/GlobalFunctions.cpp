#include <Szachy/GlobalVariabies/GlobalFunctions.h>
#include <SFML/Graphics/RectangleShape.hpp>
#include <Szachy/GlobalVariabies/Variables.h>
void Zdarzenia_window(sf::RenderWindow &W, sf::Event &E)
{

}

void Popraw_tekst(sf::Vector2f(pos1),sf::Vector2f(pos2),sf::Text &text,RenderWindow &window)
{
    sf::RectangleShape przycisk;
    if(pos2.x>pos1.x)
    {
        float x=pos2.x;
        pos2.x=pos1.x;
        pos1.x=x-pos2.x;
    }
    else pos1.x-=pos2.x;
    if(pos2.y>pos1.y)
    {
        float y=pos2.y;
        pos2.y=pos1.y;
        pos1.y=y-pos2.y;
    }
    else pos1.y-=pos2.y;
    przycisk.setPosition(window.getView().getSize().x*pos2.x,window.getView().getSize().y*pos2.y);
    przycisk.setSize(sf::Vector2f(window.getView().getSize().x*pos1.x,window.getView().getSize().y*pos1.y));





    float a=przycisk.getScale().x*przycisk.getLocalBounds().width*0.9/text.getLocalBounds().width;
    float b=przycisk.getScale().y*przycisk.getLocalBounds().height*0.9/text.getLocalBounds().height;
    text.setScale(b*window.getView().getSize().x/window.getView().getSize().y,b);
    text.setPosition(przycisk.getPosition().x-text.getScale().x*text.getLocalBounds().left+przycisk.getLocalBounds().width*przycisk.getScale().x*0.5-text.getScale().x*text.getLocalBounds().width*0.5,
                     przycisk.getPosition().y-text.getScale().y*text.getLocalBounds().top+przycisk.getLocalBounds().height*przycisk.getScale().y*0.05);

    if(text.getLocalBounds().width*text.getScale().x>przycisk.getLocalBounds().width*przycisk.getScale().x*0.95)
    {
        text.setScale(a,a*window.getView().getSize().y/window.getView().getSize().x);
        text.setPosition(przycisk.getPosition().x-text.getScale().x*text.getLocalBounds().left+przycisk.getLocalBounds().width*przycisk.getScale().x*0.05,
                         przycisk.getPosition().y-text.getScale().y*text.getLocalBounds().top+przycisk.getLocalBounds().height*przycisk.getScale().y*0.5-text.getScale().y*text.getLocalBounds().height*0.5);
    }

}

sf::Text Tworzymy_tekst(sf::Vector2f(pos1),sf::Vector2f(pos2),std::string S,RenderWindow &W)
{
    sf::Text text(sf::String::fromUtf8(S.begin(), S.end()),Dane_tekstu,255);
    text.setColor(sf::Color::White);
    text.setStyle(sf::Text::Regular);
    text.setCharacterSize(255);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(10);
    Popraw_tekst(pos1,pos2,text,W);
    return text;
}

void SetDisplay(sf::RenderWindow &window,sf::Vector2i (a) ,sf::Vector2u(c)) //pozwala ustawić okno do rozmiarów ekranu
{
    window.setSize(c);
    window.setPosition(a);
}

char boolToChar(bool number){
    if(number)return'1'; return '0';}
