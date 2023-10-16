#ifndef CHESSMAN_H
#define CHESSMAN_H

#include <Szachy/SpecialClass/PosibleMove.h>
#include <Szachy/HelpClass/RenderWindow.h>
#include <SFML/Graphics/RectangleShape.hpp>
#include <wtypes.h>
#include <SFML/Graphics/Sprite.hpp>
#include <Szachy/GlobalVariabies/Variables.h>
#include <Szachy/SpecialClass/TypeChessman.h>
#include <memory>
class Game;

class Chessman : public sf::Sprite
{
private:
    Game &Board;
public:
    Chessman(Game &game,const TypeChessman &Name, const uint8_t &X, const uint8_t &Y,const uint8_t &Team,const std::bitset<4> &Bools);

    void move();
    void posibleMove();
    void drawActions(const sf::Color &C, const short &X1, const short &Y1);
    void scale();
    void emplace();
    void emplace(     uint8_t X,uint8_t Y);
    bool select();
    void drawSquare(sf::Color color,uint8_t X, uint8_t Y);
    void drawSquare(uint8_t Type,uint8_t X, uint8_t Y);
    static std::vector<std::shared_ptr<Chessman>> makeVectorShared_ptrChessman(Game &P,const sf::String &name);
    std::vector<std::shared_ptr<PosibleMove>> posible_move();



    uint8_t x, y;                   // pozycja XY względem planszy
    const uint8_t team;                 // do jakiej drużyny należy
    const TypeChessman &Texture; // na podstawie nazwy będzie wiadomo, jaka to jest figura i względem tej figury będzie czytane vector<struct> z możliwymi ruchami
    //bool king = 0, canDestroy = 1, notWasMoved = 1, isSelect = 0;
    std::bitset<4> bools=std::bitset<4>("1100");
    sf::Color Colors[3]={sf::Color::Blue,sf::Color::Green,sf::Color::Red};
    //bools[3] - canDestroy 1 unused
    //bools[2] - notWasMoved 1
    //bools[1] - isSelect 0
    //bools[0] - king 0

};

#endif // CHESSMAN_H
