#ifndef GAME_H
#define GAME_H
#include <Szachy/GlobalVariabies/Variables.h>
#include <Szachy/HelpClass/RenderWindow.h>
#include <Szachy/SpecialClass/Chessman.h>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <Szachy/Windows/BasicGame/Console.h>
#include <SFML/Window/Event.hpp>
#include <Szachy/SpecialClass/TypeChessman.h>
#include <Szachy/SpecialClass/GameBoard.h>
#include <Szachy/SpecialClass/Chessman.h>
#include <Szachy/SpecialClass/TypeChessman.h>
#include <memory>
class Game
{
private:

    struct Select{
        bool select=0;
        uint8_t boardX=0;
        uint8_t boardY=0;
        Select(){}
    };


    Console Console;


    void drawBoard();
    bool checkKings(uint8_t team);
    void game();
    void squartScale();
    void gameActions();
    void drawAll();

public:
    Game(sf::String boardName = "Szachy"):
        GameBoard(boardName),
        boardChessman(GameBoard.boardX,std::vector<std::pair<std::weak_ptr<PosibleMove>,std::weak_ptr<Chessman>>>(GameBoard.boardY,std::pair<std::weak_ptr<PosibleMove>,std::weak_ptr<Chessman>>())),
        typeChessman(TypeChessman::makeVectorTypeChessman(GameBoard.name)),
        chessman(Chessman::makeVectorShared_ptrChessman(*this,GameBoard.name)){
        makeAll();
    }

    void makeAll();
    GameBoard GameBoard;
    std::vector<std::vector<std::pair<std::weak_ptr<PosibleMove>,std::weak_ptr<Chessman>>>> boardChessman;
    std::vector<TypeChessman> typeChessman; //Przechowywanie figur, które są w czasie gry
    std::vector<std::shared_ptr<Chessman>> chessman;
    ~Game(){
        ::Teraz=0;
    }
    sf::RectangleShape squart;
    Select select;
    std::vector<std::shared_ptr<PosibleMove>> posibleMoves;
    RenderWindow &Window=::Window;
    sf::Event &Event=::Event;
    sf::Color colorsActions[3]={sf::Color(0, 0, 255, 128),sf::Color(255, 0, 0, 128),sf::Color(0, 255, 0, 128)};


};
#endif // GAME_H
