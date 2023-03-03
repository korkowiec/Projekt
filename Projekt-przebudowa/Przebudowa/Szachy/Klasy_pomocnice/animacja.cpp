#include <Szachy/Klasy_pomocnice/animacja.h>

Animacja::Animacja(const std::string &S)
{
sf::Image I1,I2;
I1.loadFromFile("Grafika/Animacje/"+S+"/Grafika.png"),I2.loadFromFile("Grafika/Animacje/"+S+"/Ksztalt.png");
I2.createMaskFromColor(sf::Color::Black);
for(u_int c=1;c<I2.getSize().x;c++) for(u_int d=1;d<I2.getSize().y;d++)
{
    if(I2.getPixel(c,d).a!=0)I2.setPixel(c,d,I1.getPixel(c,d));
}
this->loadFromImage(I2);


}
