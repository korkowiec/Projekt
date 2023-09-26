#include <Szachy/Chess.h>
#include <Szachy/HelpClass/RenderWindow.h>
#include <Szachy/GlobalVariabies/GlobalFunctions.h>
#include <Szachy/GlobalVariabies/Variables.h>
#include <SFML/Window/Event.hpp>
#include <Szachy/Windows/BasicGame/BasicGame.h>
#include <Szachy/Windows/Menu/Menu.h>
#include <Szachy/Windows/SandboxChessboard/SandboxChessboard.h>
#include <Szachy/Windows/PlaySandbox/PlaySandbox.h>
#include <Szachy/Windows/SandboxChessman/SandboxChessman.h>

RenderWindow Window;
sf::Event Event;
Chess::Chess() : Window(::Window),Event(::Event)
{
    srand(time(NULL));
    Window.create(sf::VideoMode(1,1), "Szachy");
    SetDisplay(Window,sf::Vector2i(-8,-31),sf::Vector2u(sf::VideoMode::getDesktopMode().width,sf::VideoMode::getDesktopMode().height));
    if (!Dane_tekstu.loadFromFile("Czcionka/PolskaGurom.ttf")) Window.close();

    while(Window.isOpen())
    {

        switch (okienko)
        {
        case 1: //Menu
        {
            Menu Menu(Window,Event);
        }
        break;
        case 2://BasicGame
        {
            BasicGame BasicGame(Window,Event,"Szachy");
            BasicGame.Gra();
        }
        break;
        case 3://SandboxChessman
        {
            SandboxChessman SandboxChessman(Window,Event);
            SandboxChessman.Dzialanie();
        }
        break;
        case 4://SandboxChessboard
        {
            SandboxChessboard SandboxChessboard(Window,Event);
        }
        break;
        case 5://PlaySandbox
        {
            PlaySandbox PlaySandbox(Window,Event);
        }
        break;
        default: Window.close();
        }
    }

}
