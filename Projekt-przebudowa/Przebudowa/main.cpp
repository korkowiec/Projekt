#include  <szachy.h>
int main()
{
    Szachy Szachy;
    return 0;
    RenderWindow window(sf::VideoMode(1000,400), "Szachy");
    //SetDisplay(window,sf::Vector2i(50,50),sf::Vector2u(sf::VideoMode::getDesktopMode().width-100,sf::VideoMode::getDesktopMode().height-100));



    Animacja_plynna A_P("Wzkazowka",window);
    A_P.Set_pos(sf::Vector2f(40,20));

    sf::Vector2f(roz)=sf::Vector2f(0.4,0.4);
    float b=5;
    sf::Clock clock;
    float moc=2;

    Animacja A("Zegar",window);

    while(window.isOpen())
    {

    A_P.Kalibrowanie();
    A.Kalibrowanie(sf::Vector2f(0.5,0.5),sf::Vector2f(0.6,0.6));





       // A_P.move(0,moc*clock.getElapsedTime().asMilliseconds());

        sf::Event event;
        while(window.pollEvent(event))
        {
            mouse_position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) A_P.move(-moc*clock.getElapsedTime().asSeconds(),0);
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) A_P.move(moc*clock.getElapsedTime().asSeconds(),0);
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) A_P.move(0,-moc*clock.getElapsedTime().asSeconds());
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) A_P.move(0,moc*clock.getElapsedTime().asSeconds());
        }
        //std::cout<<A_P.getPosition().x<<" "<<A_P.getPosition().y<<std::endl;

        window.clear();
    //    window.Rysowanie(A);
        window.Rysowanie(A_P);

        window.display();
    }
}
