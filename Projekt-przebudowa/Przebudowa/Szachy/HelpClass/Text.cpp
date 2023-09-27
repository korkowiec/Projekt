#include <Szachy/HelpClass/Text.h>
#include <Szachy/HelpClass/RenderWindow.h>
#include <Szachy/HelpClass/Button.h>

void Text::Kalibrowanie(const ButtonActions &P)
{
    setColor(sf::Color::White);
    setStyle(Text::Regular);
    setCharacterSize(255);
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(10);
    float a=P.getScale().x*P.getLocalBounds().width*0.9/getLocalBounds().width;
    float b=P.getScale().y*P.getLocalBounds().height*0.9/getLocalBounds().height;
    setScale(b*window->getView().getSize().x/window->getView().getSize().y,b);
    setPosition(P.getPosition().x-getScale().x*getLocalBounds().left+P.getLocalBounds().width*P.getScale().x*0.5-getScale().x*getLocalBounds().width*0.5,
                P.getPosition().y-getScale().y*getLocalBounds().top+P.getLocalBounds().height*P.getScale().y*0.05);

    if(getLocalBounds().width*getScale().x>P.getLocalBounds().width*P.getScale().x*0.95)
    {
        setScale(a,a*window->getView().getSize().y/window->getView().getSize().x);
        setPosition(P.getPosition().x-getScale().x*getLocalBounds().left+P.getLocalBounds().width*P.getScale().x*0.05,
                    P.getPosition().y-getScale().y*getLocalBounds().top+P.getLocalBounds().height*P.getScale().y*0.5-getScale().y*getLocalBounds().height*0.5);
    }

}
void Text::Kalibrowanie()
{
    float a=przycisk->getScale().x*przycisk->getLocalBounds().width*0.9/getLocalBounds().width;
    float b=przycisk->getScale().y*przycisk->getLocalBounds().height*0.9/getLocalBounds().height;
    setScale(b*window->getView().getSize().x/window->getView().getSize().y,b);
    setPosition(przycisk->getPosition().x-getScale().x*getLocalBounds().left+przycisk->getLocalBounds().width*przycisk->getScale().x*0.5-getScale().x*getLocalBounds().width*0.5,
                przycisk->getPosition().y-getScale().y*getLocalBounds().top+przycisk->getLocalBounds().height*przycisk->getScale().y*0.05);

    if(getLocalBounds().width*getScale().x>przycisk->getLocalBounds().width*przycisk->getScale().x*0.95)
    {
        setScale(a,a*window->getView().getSize().y/window->getView().getSize().x);
        setPosition(przycisk->getPosition().x-getScale().x*getLocalBounds().left+przycisk->getLocalBounds().width*przycisk->getScale().x*0.05,
                    przycisk->getPosition().y-getScale().y*getLocalBounds().top+przycisk->getLocalBounds().height*przycisk->getScale().y*0.5-getScale().y*getLocalBounds().height*0.5);
    }

}
void Text::Dane_poczatek(RenderWindow &W,const ButtonActions &P,const std::string &S)
{
    przycisk=&P;
    window=&W;
    setColor(sf::Color::White);
    setStyle(sf::Text::Regular);
    setCharacterSize(255);
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(10);
    setString(sf::String::fromUtf8(S.begin(), S.end()));
    Kalibrowanie();

}
