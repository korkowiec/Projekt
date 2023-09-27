#ifndef TEXT_H
#define TEXT_H

#include<SFML/Graphics/Text.hpp>

extern sf::Font Dane_tekstu;
class ButtonActions;
class RenderWindow;

class Text : public sf::Text
{
public:
    Text(const sf::String &string, const sf::Font &font) : sf::Text(string, font, 255) {}
    Text(const std::string &S) : sf::Text(sf::String::fromUtf8(S.begin(), S.end()), Dane_tekstu, 255) {}
    Text(const sf::String &string) : sf::Text(string, Dane_tekstu, 255) {}
    Text() : sf::Text(" ", Dane_tekstu) {}

    void Kalibrowanie(const ButtonActions &P);
    void Kalibrowanie();
    void Dane_poczatek(RenderWindow &W, const ButtonActions &P, const std::string &S = "");

private:
    const ButtonActions *przycisk;
    RenderWindow *window;
};


#endif // TEXT_H
