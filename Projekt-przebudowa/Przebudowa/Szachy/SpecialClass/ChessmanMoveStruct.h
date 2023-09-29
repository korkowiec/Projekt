#ifndef CHESSMANMOVESTRUCT_H
#define CHESSMANMOVESTRUCT_H
#include <bitset>
#include <Szachy/GlobalVariabies/GlobalFunctions.h>
struct ChessmanMoveStruct{
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

    std::bitset<8> _typeMove;
    ChessmanMoveStruct(int8_t x,int8_t y, uint8_t elapsed=1,
                       bool dodgeAllien=0, bool dodgeEnemy=0 , bool hitEnemy=1, bool hitEnemyEndElapsed=1,
                       bool hitAllien=0, bool hitAllienEndElapsed=1, bool OnlyWhenNotMove=0, bool onlyHit=0):
              x(x),y(y),elapsed(elapsed),_typeMove(::boolToChar(dodgeAllien)+
                                                  ::boolToChar(dodgeEnemy)+
                                                  ::boolToChar(hitEnemy)+
                                                  ::boolToChar(hitEnemyEndElapsed)+
                                                  ::boolToChar(hitAllien)+
                                                  ::boolToChar(hitAllienEndElapsed)+
                                                  ::boolToChar(OnlyWhenNotMove)+
                                                  ::boolToChar(onlyHit)){}
};

#endif // CHESSMANMOVESTRUCT_H
