#ifndef TEKST_H
#define TEKST_H

#include <Szachy/Dane_poczatkowe/Zdarzenia.h>
class Przycisk;
class Tekst: public sf::Text
{
public:
    Tekst(const sf::String &string, const sf::Font &font):sf::Text(string,font,255){}
    Tekst(const std::string &S):sf::Text(sf::String::fromUtf8(S.begin(), S.end()),Dane_tekstu,255){}
    Tekst(const sf::String &string):sf::Text(string,Dane_tekstu,255){}
    Tekst():sf::Text(" ",Dane_tekstu){}
    //Tekst(const Przycisk &P,const std::string &S=""):sf::Text(sf::String::fromUtf8(S.begin(), S.end()),Dane_tekstu),przycisk(&P){}
    //Tekst(const Przycisk &P, RenderWindow &W,const std::string &S=""):sf::Text(sf::String::fromUtf8(S.begin(), S.end()),Dane_tekstu),przycisk(&P),window(&W){Kalibrowanie(); }
    void Kalibrowanie(const Przycisk &P);
    void Kalibrowanie();
    void Dane_poczatek(RenderWindow &W,const Przycisk &P,const std::string &S="");
private:
    const Przycisk *przycisk;
    RenderWindow *window;


};

#endif // TEKST_H
