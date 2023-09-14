#ifndef ANIMACJA_PLYNNA_H
#define ANIMACJA_PLYNNA_H

#include <Szachy/Dane_poczatkowe/Zdarzenia.h>
#include <fstream>

class Animacja_plynna : public sf::Sprite
{
private:
    RenderWindow *window;
    sf::Texture texture;
    sf::Clock clock;
    float rotacja;
    float rotacja_poczatek = 0;
    float dlugosc;
    sf::Vector2f pos = sf::Vector2f(0, 0); // Punkt obrotu
    sf::Vector2f pos_poz; // Narożnik prostokąta

    void ustaw_rotacja_poczatkowa();

public:
    int szybkosc = 100; // Wyrażone w procentach, 100% == 1 sekunda całego obrotu

    Animacja_plynna(const sf::Texture &T, float C = 100) : texture(T), szybkosc(C)
    {
        setTexture(texture);
    }
    Animacja_plynna(const sf::Texture &T, RenderWindow &W, float C = 100) : window(&W), texture(T), szybkosc(C)
    {
        setTexture(texture);
    }
    Animacja_plynna(const std::string &S, float C = 100);
    Animacja_plynna(const std::string &S, RenderWindow &W, float C = 100);
    void Zmien();
    void Zmien_1();
    void Set_pos(sf::Vector2f pos1); // Wokół punktu
    void Set_pos_poz(sf::Vector2f pos1); // Początek tekstury
    void Kalibrowanie(sf::Vector2f pos, sf::Vector2f roz);
    void Kalibrowanie(sf::Vector2f pos, float scale = 1);
    void Kalibrowanie_Zmien();
    void Kalibrowanie();
};

#endif // ANIMACJA_PLYNNA_H
