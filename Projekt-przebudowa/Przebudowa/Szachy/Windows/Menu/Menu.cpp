#include <Szachy/Windows/Menu/Menu.h>
#include <Szachy/GlobalVariabies/Variables.h>
#include <wtypes.h>
#include <Szachy/HelpClass/Button.h>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Sprite.hpp>

Menu::Menu(RenderWindow &W, sf::Event &E):Window(W),Event(E){

    makeObjects();
    work();
}

void Menu::makeButtons(){

    uint8_t *Value[6]={&::window,&::window,&::window};

    /* __1__ BASIC GAME */ {

    uint8_t two=2;
    Value[3]=&(two);
    Value[4]=&(two);
    Value[5]=&(two);
    Buttons.emplace_back(std::make_unique<Button<uint8_t,uint8_t>>(Window,Event,
                                                                        ::window,Value,1,
                                                                        sf::Vector2f(0.4,0.3),
                                                                        sf::Vector2f(0.6,0.45),
                                                                        std::string("Gra")));
    }

    /* __0__ EXIT */ {

    uint8_t zero=0;
    Value[3]=&(zero);
    Value[4]=&(zero);
    Value[5]=&(zero);
    Buttons.emplace_back(std::make_unique<Button<uint8_t,uint8_t>>(Window,Event,
                                                                        ::window,Value,1,
                                                                        sf::Vector2f(0.4,0.55),
                                                                        sf::Vector2f(0.6,0.7),
                                                                        std::string("Wyjście")));
    }

    /* __3__ SANDBOX */ {

    uint8_t three=3;
    Value[3]=&(three);
    Value[4]=&(three);
    Value[5]=&(three);
    Buttons.emplace_back(std::make_unique<Button<uint8_t,uint8_t>>(Window,Event,
                                                                        ::window,Value,1,
                                                                        sf::Vector2f(0.1,0.20),
                                                                        sf::Vector2f(0.2,0.40),
                                                                        std::string("Piasek")));
    }

    /* __4__ MAKE BOARD */ {

    uint8_t four=4;
    Value[3]=&(four);
    Value[4]=&(four);
    Value[5]=&(four);
    Buttons.emplace_back(std::make_unique<Button<uint8_t,uint8_t>>(Window,Event,
                                                                        ::window,Value,1,
                                                                        sf::Vector2f(0.1,0.41),
                                                                        sf::Vector2f(0.3,0.60),
                                                                        std::string("Stwórz_plansze")));
    }

    /* __5__ PLAY YOUR BOARD */ {

    uint8_t five=5;
    Value[3]=&(five);
    Value[4]=&(five);
    Value[5]=&(five);
    Buttons.emplace_back(std::make_unique<Button<uint8_t,uint8_t>>(Window,Event,
                                                                        ::window,Value,1,
                                                                        sf::Vector2f(0.8,0.40),
                                                                        sf::Vector2f(0.99,0.60),
                                                                        std::string("Zagraj_własną\nplanszę")));
    }
}

void Menu::makeObjects(){

    makeBackgrouds();
    makeButtons();
    //makeTexts();
}

void Menu::makeBackgrouds(){

    if (!BackgroudTexture.loadFromFile("Grafika/Tla/Menu/Okienko_startowe.png")) {

        ::window=0, Menu::~Menu();
    }

    std::unique_ptr<sf::Sprite> tlo = std::make_unique<sf::Sprite>(BackgroudTexture);
    tlo->setPosition(0,0);
    tlo->setScale(Window.getView().getSize().x/BackgroudTexture.getSize().x,
                  Window.getView().getSize().y/BackgroudTexture.getSize().y);
    Buttons.emplace_back(std::move(tlo));
}

void Menu::work(){

    while(::window==1){

        action();
        display();
    }
}

void Menu::display(){

    for(uint8_t c=0;c<Buttons.size();c++){

        ButtonActions *przycisk=dynamic_cast<ButtonActions *>(Buttons[c].get());

        if(przycisk !=nullptr) przycisk->Akcje(), Window.Rysowanie(*przycisk);

        else Window.Rysowanie(*Buttons[c].get());
    }

    Window.display();
}

void Menu::action(){

    while(Window.pollEvent(Event)){

        mouse_position = Window.mapPixelToCoords(sf::Mouse::getPosition(Window));

        if(Event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) Window.close();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) ::window=2;
    }
}

