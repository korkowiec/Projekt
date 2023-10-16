#ifndef CHESSMANMOVE_H
#define CHESSMANMOVE_H

#include <bitset>
#include <Szachy/GlobalVariabies/GlobalFunctions.h>
#include <fstream>
#include <sstream>
struct ChessmanMove{
    int8_t x; // ruch w X
    int8_t y; // ruch w Y
    uint8_t elapsed = 1; // liczba pętli, 0 == nieskończoność
    // dodgeAllien = 0; // unikanie kolizji ze swoimi
    // dodgeEnemy = 0; // UwU unikanie kolizji z wrogami oba bool wykorzystywanie w ruchach w pętli
    // hitEnemy = 1; // możliwość zbijania wroga
    // hitEnemyEndElapsed = 1; // możliwość zbicia wroga kończy pętle
    // hitAllien = 0; // możliwość zbicia swoich
    // hitAllienEndElapsed = 1; // możliwość zbicia swojego kończy pętle
    // onlyWhenNotMove = 0; // Czy musi być z pozycji początkowej
    // onlyHit = 0; // tylko bicie figur

    std::bitset<8> typeMove;
    ChessmanMove(const int8_t &x, const int8_t &y,const uint8_t &elapsed=1,
                 const bool &dodgeAllien=0, const bool &dodgeEnemy=0 ,
                 const bool &hitEnemy=1, const bool &hitEnemyEndElapsed=1,
                 const bool &hitAllien=0,const bool &hitAllienEndElapsed=1,
                 const bool &OnlyWhenNotMove=0,const  bool &onlyHit=0):
        x(x),y(y),elapsed(elapsed),typeMove(::boolToChar(onlyHit)+
                   ::boolToChar(OnlyWhenNotMove)+
                   ::boolToChar(hitAllienEndElapsed)+
                   ::boolToChar(hitAllien)+
                   ::boolToChar(hitEnemyEndElapsed)+
                   ::boolToChar(hitEnemy)+
                   ::boolToChar(dodgeEnemy)+
                   ::boolToChar(dodgeAllien)){}
    ChessmanMove(const int8_t &x, const int8_t &y,const uint8_t &elapsed,std::bitset<8> bools):
        x(x),y(y),elapsed(elapsed),typeMove(bools){}

    static std::vector<ChessmanMove> makeVectorChessmanMove(const sf::String &name){
        std::vector<ChessmanMove> This;
        std::fstream File;
        if(name.find('.')==std::string::npos) File.open("Pliki_tekstowe/Ruchy_figur/"+name+".txt", std::fstream::in);
        else File=::loadFileToRead(L"Pliki_tekstowe/Ruchy_figur_własnych/"+name+L".txt");

        std::string line;
        if(File.is_open()) while(std::getline(File, line)){
                int8_t x=0,y=0;
                uint8_t elapsed=1;
                std::bitset<8> bools("00101100");
                std::istringstream line2(line);
                std::string value;

                for (int i = 0; std::getline(line2, value, ','); i++) {
                    switch (i) {
                    case 0:
                        x = std::stoi(value);
                        break;
                    case 1:
                        y = std::stoi(value);
                        break;
                    case 2:
                        elapsed = std::stoi(value);
                        break;
                    case 3:
                        bools[0]=std::stoi(value);
                        break;
                    case 4:
                        bools[1]=std::stoi(value);
                        break;
                    case 5:
                        bools[2]=std::stoi(value);
                        break;
                    case 6:
                        bools[3]=std::stoi(value);
                        break;
                    case 7:
                        bools[4]=std::stoi(value);
                        break;
                    case 8:
                        bools[5]=std::stoi(value);
                        break;
                    case 9:
                        bools[6]=std::stoi(value);
                        break;
                    case 10:
                        bools[7]=std::stoi(value);
                        break;
                    }
                }

                This.emplace_back(x,y,elapsed,bools);
            }
        return This;
    }
};
#endif // CHESSMANMOVE_H
