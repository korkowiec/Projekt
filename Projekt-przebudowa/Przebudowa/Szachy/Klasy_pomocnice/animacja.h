#ifndef ANIMACJA_H
#define ANIMACJA_H

#include <Szachy/Dane_poczatkowe/Zdarzenia.h>
class Animacja : public sf::Sprite, public sf::Texture
{
private:
    std::vector<sf::IntRect> Pozycje;
public:
    Animacja(const sf::Texture &T): Texture(T){}
    Animacja(const std::string &S);
    void Usun(const int &P);
    void Usun(){Usun(Pozycje.size()-1);};
    void Dodaj(const int &P);
    void Dodaj(){Dodaj(Pozycje.size()-1);};


};

#endif // ANIMACJA_H
