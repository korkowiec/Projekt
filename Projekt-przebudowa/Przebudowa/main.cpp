#include <szachy.h>

int main()
{
//Szachy Szachy;
    RenderWindow window(sf::VideoMode(1000,1000), "Szachy");

    sf::Texture T1;
    sf::Texture T2;
    sf::Image I1;
    sf::Image I2;
    if(!T1.loadFromFile("Grafika/Animacje/zegar/wadsworth.gif")||!T2.loadFromFile("Grafika/Animacje/zegar/_wadsworth.gif")) return 0;
    I1.loadFromFile("Grafika/Animacje/zegar/wadsworth.gif"),I2.loadFromFile("Grafika/Animacje/zegar/_wadsworth.gif");
    I2.createMaskFromColor(sf::Color::Black);
    for(u_int c=1;c<I2.getSize().x;c++) for(u_int d=1;d<I2.getSize().y;d++)
    {
        if(I2.getPixel(c,d).a!=0)I2.setPixel(c,d,I1.getPixel(c,d));
    }
    //I1.copy(I2,80,80,sf::IntRect(80,00,480,40),1);
    T2.loadFromImage(I2);
    T1.loadFromImage(I1);
    sf::Sprite S1,S2;
    S1.setTexture(T1),S2.setTexture(T2);
    u_int x=0,y=0;
    S2.setTextureRect(sf::IntRect(x,y,80,80));
    sf::Clock clock;
    while(window.isOpen())
    {
        window.clear(sf::Color::Red);
         sf::Event event;
         while(window.pollEvent(event))
         {
             mouse_position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
             if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) okienko=2;
         }
         if(clock.getElapsedTime().asSeconds()>=0.1)
         {
             if(x<720)
             {
                 x+=80;
             }
            else
             {
                 if(y<160)
                 {
                     y+=80;
                     x=0;
                 }
                 else
                 {
                     y=0,x=0;

                 }
             }
             clock.restart();
             S2.setTextureRect(sf::IntRect(x,y,80,80));
         }
         window.draw(S2);
         window.display();
         std::cout<<clock.getElapsedTime().asSeconds()<<std::endl;


    }
}
