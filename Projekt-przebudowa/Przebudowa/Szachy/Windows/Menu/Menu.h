#ifndef MENU_H
#define MENU_H

#include <Szachy/HelpClass/RenderWindow.h>
#include <SFML/Graphics/Texture.hpp>

class Menu
{
public:
    Menu(RenderWindow &W, sf::Event &E);

private:
    void display();
    void action();
    void work();
    void makeObjects();
    void makeButtons();
    void makeBackgrouds();
    //void makeTexts();

    RenderWindow &Window;
    sf::Event &Event;
    std::vector<std::unique_ptr<sf::Drawable>> Buttons;
    sf::Texture BackgroudTexture;
};

#endif // MENU_H
