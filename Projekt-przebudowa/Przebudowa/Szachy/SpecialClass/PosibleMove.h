#ifndef POSIBLEMOVE_H
#define POSIBLEMOVE_H
#include <iostream>
struct PosibleMove{
    const uint8_t x;
    const uint8_t y;
    const uint8_t type; // 0-select 1-move 2-hit
    PosibleMove(uint8_t X, uint8_t Y, uint8_t Type):x(X),y(Y),type(Type){}
};
#endif // POSIBLEMOVE_H
