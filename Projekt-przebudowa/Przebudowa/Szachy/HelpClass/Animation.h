#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/String.hpp>
class RenderWindow;
class Animation : public sf::Sprite
{
private:
    RenderWindow &Window;
    sf::Texture texture;
    sf::Clock clock;
public:
    Animation(const sf::Texture &texture, RenderWindow &W);
    Animation(const sf::String &S, RenderWindow &W);
    virtual void action(){}
    void Kalibrowanie(sf::Vector2f pos, sf::Vector2f roz){}
};

#endif // ANIMATION_H
