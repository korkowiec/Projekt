#ifndef ANIMACJA_H
#define ANIMACJA_H

#include <Szachy/Dane_poczatkowe/Zdarzenia.h>
#include<fstream>
class Animacja : public sf::Sprite
{
private:
    RenderWindow *window;
    sf::Texture texture;
    std::vector<sf::IntRect> Pozycje;
    u_short aktualny=1;
    sf::Clock clock;
    void Czytaj(const std::string &S);

public:
    float okres=1;

    Animacja(const sf::Texture &T,float C=1): texture(T),okres(C){setTexture(texture);}
    Animacja(const sf::Texture &T,RenderWindow &W,float C=1):window(&W), texture(T),okres(C){setTexture(texture);}
    Animacja(const std::string &S,float C=1);
    Animacja(const std::string &S,RenderWindow &W,float C=1);
    void Zmien();
    void Usun(const int &P);
    void Usun(){Usun(Pozycje.size()-1);};
    void Dodaj(const int &P);
    void Dodaj(){Dodaj(Pozycje.size()-1);};
    void Kalibrowanie(sf::Vector2f(pos),sf::Vector2f(roz));
    void Kalibrowanie(sf::Vector2f(pos),float scale=1);

};

#endif // ANIMACJA_H
