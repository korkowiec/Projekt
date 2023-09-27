#ifndef PLAYSANDBOX_H
#define PLAYSANDBOX_H

#include <Szachy/HelpClass/RenderWindow.h>

class PlaySandbox

{
protected:
    RenderWindow *window;
    sf::Event *event;
    std::vector<std::unique_ptr<ButtonActions>> Plansze;
    std::vector<std::string> Nazwy;
    std::string Wybór;
    short aktualny = 0;

private:
    void Dzialanie();
    void Czytaj();
    void Graj();
    void Twórz();

        public:
                 PlaySandbox(RenderWindow &W, sf::Event &E);
};

#endif // PLAYSANDBOX_H
