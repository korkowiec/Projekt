#include <Szachy/Windows/BasicGame/Console.h>
#include <Szachy/GlobalVariabies/Variables.h>
#include <Szachy/HelpClass/Button.h>
#include <Szachy/HelpClass/FrameAnimation.h>
#include <Szachy/HelpClass/RotateAnimation.h>
#include <memory>


Console::Console(){
    makeElements();
}
void Console::makeElements(){
    /*Buttons*/{
        uint8_t one=1,zero=0;
        uint8_t *Stan[6]={&::window,&::window,&::window,&one,&one,&one};
        buttons.emplace_back(std::make_unique<Button<uint8_t,uint8_t>>(::Window,::Event,
                                                                        ::window,Stan,1,
                                                                        sf::Vector2f(0,0),
                                                                        sf::Vector2f(0,0),
                                                                        std::string("Menu")));
        Stan[3]=&zero;
        Stan[4]=&zero;
        Stan[5]=&zero;
        buttons.emplace_back(std::make_unique<Button<uint8_t,uint8_t>>(::Window,::Event,
                                                                        ::window,Stan,1,
                                                                        sf::Vector2f(0,0),
                                                                        sf::Vector2f(0,0),
                                                                        std::string("Wyjście")));
    }
    /*Animations*/{
        std::unique_ptr<FrameAnimation> frameAnimation(std::make_unique<FrameAnimation>("Zegar",::Window));
        std::unique_ptr<RotateAnimation> rotateAnimation(std::make_unique<RotateAnimation>("Wzkazowka",::Window));
        animations.emplace_back(std::move(frameAnimation));
        animations.emplace_back(std::move(rotateAnimation));
    }
}

void Console::Koniec_gry()
{

    std::string S="Przegrał gracz "+std::to_string(Teraz+1);
                                        //    Texttekst(sf::String::fromUtf8(S.begin(),S.end()),Dane_tekstu);
                                        //    tekst.setColor(sf::Color::Red);
                                        //    tekst.setStyle(sf::Text::Regular);
                                        //    tekst.setOutlineColor(sf::Color::Black);
                                        //    tekst.setOutlineThickness(0);
                                        Rysunki.emplace_back(std::make_unique<Text>(sf::String::fromUtf8(S.begin(),S.end()),Dane_tekstu));

    for(uint8_t c=0;c<Rysunki.size();c++)

    {

        Text *przycisk=dynamic_cast<Text *>(Rysunki[c].get());
        if(przycisk != nullptr)
        {
            przycisk->setColor(sf::Color::Red);
            przycisk->setStyle(sf::Text::Regular);
            przycisk->setOutlineColor(sf::Color::Black);
            przycisk->setOutlineThickness(0);

        }

    }
}

void Console::scale(){
    if(::Window.getSize().x<200||::Window.getSize().y<200||abs((int)::Window.getSize().x-(int)::Window.getSize().y)<100){
        type=0;
        return;
    }
    if(::Window.getSize().x>::Window.getSize().y){
        type=1;
        setRight();
    }
    else {
        type=2;
        setDown();
    }

}
void Console::setDown(){
    float scale=::Window.getSize().y-::Window.getSize().x;
    sf::Vector2f(pos);
    sf::Vector2f(roz);
    for(std::unique_ptr<ButtonActions> &button:buttons){
        if(button->tekst_przycisku.getString()==L"Wyjście"){
            pos.x=0.6;
        pos.y=0.95;
        roz.x=0.95;
        roz.y=0.55;
        button->Zmiana(sf::Vector2f(((pos.x*(scale)+::Window.getSize().y)/::Window.getSize().x),pos.y),
                       sf::Vector2f(((roz.x*(scale)+::Window.getSize().y)/::Window.getSize().x),roz.y));

    }
    if(button->tekst_przycisku.getString()==L"Menu"){
        pos.x=0.05;
        pos.y=0.55;
        roz.x=0.4;
        roz.y=0.95;
        button->Zmiana(sf::Vector2f(((pos.x*(scale)+::Window.getSize().y)/::Window.getSize().x),pos.y),
                       sf::Vector2f(((roz.x*(scale)+::Window.getSize().y)/::Window.getSize().x),roz.y));
    }
}
for(std::unique_ptr<sf::Sprite> &animation:animations){
    FrameAnimation *A=dynamic_cast<FrameAnimation *>(animation.get());
    if(A!=nullptr){
        pos.x=0.1;
        pos.y=0.35;
        roz.x=0.3;
        roz.y=0.50;
        A->Kalibrowanie(sf::Vector2f(((pos.x*(scale)+::Window.getSize().y)/::Window.getSize().x),pos.y),
                        sf::Vector2f(((roz.x*(scale)+::Window.getSize().y)/::Window.getSize().x),roz.y));
    }
}
}

void Console::setRight(){
    float scale=::Window.getSize().x-::Window.getSize().y;
    sf::Vector2f(pos);
    sf::Vector2f(roz);
    for(std::unique_ptr<ButtonActions> &button:buttons){
        if(button->tekst_przycisku.getString()==L"Wyjście"){
            pos.x=0.6;
        pos.y=0.05;
        roz.x=0.95;
        roz.y=0.2;
        button->Zmiana(sf::Vector2f(((pos.x*(scale)+::Window.getSize().y)/::Window.getSize().x),pos.y),
                       sf::Vector2f(((roz.x*(scale)+::Window.getSize().y)/::Window.getSize().x),roz.y));

    }
    if(button->tekst_przycisku.getString()==L"Menu"){
        pos.x=0.05;
        pos.y=0.05;
        roz.x=0.4;
        roz.y=0.2;
        button->Zmiana(sf::Vector2f(((pos.x*(scale)+::Window.getSize().y)/::Window.getSize().x),pos.y),
                       sf::Vector2f(((roz.x*(scale)+::Window.getSize().y)/::Window.getSize().x),roz.y));
    }
}
for(std::unique_ptr<sf::Sprite> &animation:animations){
    FrameAnimation *A=dynamic_cast<FrameAnimation *>(animation.get());
    if(A!=nullptr){
        pos.x=0.1;
        pos.y=0.25;
        roz.x=0.3;
        roz.y=0.4;
        A->Kalibrowanie(sf::Vector2f(((pos.x*(scale)+::Window.getSize().y)/::Window.getSize().x),pos.y),
                        sf::Vector2f(((roz.x*(scale)+::Window.getSize().y)/::Window.getSize().x),roz.y));
    }
}
}

void Console::draw(){
    if(type==0){
        return;
    }
    for(std::unique_ptr<ButtonActions> &button:buttons){
        ::Window.Rysowanie(*button);
    }
    for(std::unique_ptr<sf::Sprite> &animation:animations){
        FrameAnimation *A=dynamic_cast<FrameAnimation *>(animation.get());
        if(A!=nullptr){
        ::Window.Rysowanie(*A);
        }
    }
}
