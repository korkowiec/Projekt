#include "Animation.h"

Animation::Animation(const sf::Texture &texture, RenderWindow &W):
    Window(W),texture(texture){}
Animation::Animation(const sf::String &S, RenderWindow &W):Window(W){
        sf::Image I1,I2;
        I1.loadFromFile("Grafika/Animacje_plynne/"+S+"/Grafika.png");
        I2.loadFromFile("Grafika/Animacje_plynne/"+S+"/Ksztalt.png");
        I2.createMaskFromColor(sf::Color::Black);
        for(uint8_t c=1;c<I2.getSize().x;c++) for(uint8_t d=1;d<I2.getSize().y;d++)
            {
                if(I2.getPixel(c,d).a!=0)I2.setPixel(c,d,I1.getPixel(c,d));
            }
        this->texture.loadFromImage(I2);
        this->setTexture(texture);
    }
