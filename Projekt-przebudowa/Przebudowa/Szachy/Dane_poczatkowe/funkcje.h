#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <Szachy/Dane_poczatkowe/daneliczbowe.h>

void SetDisplay(sf::RenderWindow &window, sf::Vector2i a = sf::Vector2i(0, 0),
                sf::Vector2u c = sf::Vector2u(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height));

class Przycisk;
class Animacja;
class Animacja_plynna;

class RenderWindow : public sf::RenderWindow
{
public:
    RenderWindow() : sf::RenderWindow() {}
    RenderWindow(sf::VideoMode mode, const sf::String &title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings &settings = sf::ContextSettings())
        : sf::RenderWindow(mode, title, style, settings) {}
    RenderWindow(sf::WindowHandle handle, const sf::ContextSettings &settings = sf::ContextSettings())
        : sf::RenderWindow(handle, settings) {}

    void Rysowanie(const Przycisk &P);
    void Rysowanie(Animacja &A);
    void Rysowanie(Animacja_plynna &A);
    void Rysowanie(const sf::VertexBuffer &vertexBuffer, std::size_t firstVertex, std::size_t vertexCount, const sf::RenderStates &states = sf::RenderStates::Default);
    void Rysowanie(const sf::VertexBuffer &vertexBuffer, const sf::RenderStates &states = sf::RenderStates::Default);
    void Rysowanie(const sf::Vertex *vertices, std::size_t vertexCount, sf::PrimitiveType type, const sf::RenderStates &states = sf::RenderStates::Default);
    void Rysowanie(const sf::Drawable &drawable, const sf::RenderStates &states = sf::RenderStates::Default);
};

#endif // FUNKCJE_H
