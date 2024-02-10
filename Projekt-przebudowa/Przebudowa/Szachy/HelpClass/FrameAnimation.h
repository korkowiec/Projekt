#ifndef FRAMEANIMATION_H
#define FRAMEANIMATION_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>

class RenderWindow;

class FrameAnimation : public sf::Sprite
{
private:
    RenderWindow *window;
    sf::Texture texture;
    std::vector<sf::IntRect> Pozycje;
    uint8_t aktualny = 1;
    sf::Clock clock;

    void readTextFile(const std::string &S);

public:
    float okres = 1;

    FrameAnimation(const sf::Texture &T, float C = 1) : texture(T), okres(C)
    {
        setTexture(texture);
    }
    FrameAnimation(const sf::Texture &T, RenderWindow &W, float C = 1) : window(&W), texture(T), okres(C)
    {
        setTexture(texture);
    }
    FrameAnimation(const std::string &S, float C = 1);
    FrameAnimation(const std::string &S, RenderWindow &W, float C = 1);
    void Zmien();
    void Usun(const int &P);
    void Usun()
    {
        Usun(Pozycje.size() - 1);
    }
    void Dodaj(const int &P);
    void Dodaj()
    {
        Dodaj(Pozycje.size() - 1);
    }
    void Kalibrowanie(sf::Vector2f pos, sf::Vector2f roz);
    void Kalibrowanie(sf::Vector2f pos, float scale = 1);
};

#endif // FRAMEANIMATION_H
