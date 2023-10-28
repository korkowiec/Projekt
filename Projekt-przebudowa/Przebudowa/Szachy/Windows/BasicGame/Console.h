#ifndef CONSOLE_H
#define CONSOLE_H

#include <Szachy/HelpClass/RenderWindow.h>
#include <wtypes.h>
#include <Szachy/HelpClass/Button.h>
#include <SFML/Graphics/Sprite.hpp>
class Console
{
public:
    Console();
    void losePlayer(uint8_t team);
    void actionsEvents();
    void actions();
    void draw();
    void scale();

private:
    void setDown();
    void setRight();
    void makeElements();
    std::vector<std::unique_ptr<sf::Drawable>> Rysunki;
    std::vector<std::unique_ptr<ButtonActions>> buttons;
    std::vector<std::unique_ptr<sf::Sprite>> animations;
    uint8_t type = 0; // 0-nic, 1-bok, 2-dol
};

#endif // CONSOLE_H
