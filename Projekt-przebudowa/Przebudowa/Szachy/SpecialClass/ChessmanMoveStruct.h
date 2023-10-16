#ifndef CHESSMANMOVESTRUCT_H
#define CHESSMANMOVESTRUCT_H

#include <wtypes.h>
#include <bitset>

class ChessmanMove2
{
private:
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
    char boolToChar(bool number){if(number)return'1'; return '0';}
public:
    ChessmanMove2(int8_t x,int8_t y, uint8_t elapsed=1,
                  bool dodgeAllien=0, bool dodgeEnemy=0 , bool hitEnemy=1, bool hitEnemyEndElapsed=1,
                  bool hitAllien=0, bool hitAllienEndElapsed=1, bool OnlyWhenNotMove=0, bool onlyHit=0):
        x(x),y(y),elapsed(elapsed),_typeMove(boolToChar(dodgeAllien)+
                    boolToChar(dodgeEnemy)+
                    boolToChar(hitEnemy)+
                    boolToChar(hitEnemyEndElapsed)+
                    boolToChar(hitAllien)+
                    boolToChar(hitAllienEndElapsed)+
                    boolToChar(OnlyWhenNotMove)+
                    boolToChar(onlyHit)){}
    const std::bitset<8> &typeMove=_typeMove;
    bool dodgeAllien(){return _typeMove[0];}
    bool dodgeEnemy(){return _typeMove[1];}
    bool hitEnemy(){return _typeMove[2];}
    bool HitEnemyEndElapsed(){return _typeMove[3];}
    bool hitAllien(){return _typeMove[4];}
    bool hitAllienEndElapsed(){return _typeMove[5];}
    bool OnlyWhenNotMove(){return _typeMove[6];}
    bool onlyHit(){return _typeMove[7];}
    void dodgeAllien(bool dodgeAllien){_typeMove[0]=dodgeAllien;}
    void dodgeEnemy(bool dodgeEnemy){_typeMove[1]=dodgeEnemy;}
    void hitEnemy(bool hitEnemy){_typeMove[2]=hitEnemy;}
    void HitEnemyEndElapsed(bool HitEnemyEndElapsed){_typeMove[3]=HitEnemyEndElapsed;}
    void hitAllien(bool hitAllien){_typeMove[4]=hitAllien;}
    void hitAllienEndElapsed(bool hitAllienEndElapsed){_typeMove[5]=hitAllienEndElapsed;}
    void OnlyWhenNotMove(bool OnlyWhenNotMove){_typeMove[6]=OnlyWhenNotMove;}
    void onlyHit(bool onlyHit){_typeMove[7]=onlyHit;}
};

#endif // CHESSMANMOVESTRUCT_H
