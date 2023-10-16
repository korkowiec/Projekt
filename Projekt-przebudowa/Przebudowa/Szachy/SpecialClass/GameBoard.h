#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <SFML/System/String.hpp>
#include <SFML/Graphics/Color.hpp>
#include <fstream>
#include <Szachy/GlobalVariabies/Variables.h>
#include <Szachy/GlobalVariabies/GlobalFunctions.h>
struct GameBoard
{
    sf::String name;
    uint8_t boardX;
    uint8_t boardY;
    sf::Color square1;
    sf::Color square2;
    GameBoard(sf::String name = "Szachy") : name(name) {
        std::fstream LoardBoard(::loadFileToRead(L"Pliki_tekstowe/Plansze/"+name+'/'+name+"Plansza.txt"));
            if(LoardBoard.is_open())
            {
                std::string step;
                std::getline(LoardBoard, step,';');
                boardX=(uint8_t)stoi(step);
                std::getline(LoardBoard, step,';');
                boardY=(uint8_t)stoi(step);
                std::getline(LoardBoard, step,',');
                square1.r=(uint8_t)stoi(step);
                std::getline(LoardBoard, step,',');
                square1.g=(uint8_t)stoi(step);
                std::getline(LoardBoard, step,',');
                square1.b=(uint8_t)stoi(step);
                std::getline(LoardBoard, step,';');
                square1.a=(uint8_t)stoi(step);
                std::getline(LoardBoard, step,',');
                square2.r=(uint8_t)stoi(step);
                std::getline(LoardBoard, step,',');
                square2.g=(uint8_t)stoi(step);
                std::getline(LoardBoard, step,',');
                square2.b=(uint8_t)stoi(step);
                std::getline(LoardBoard, step,';');
                square2.a=(uint8_t)stoi(step);
            }
            else ::window=1;
    }
};

#endif // GAMEBOARD_H
