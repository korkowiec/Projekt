#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include <SFML/Graphics/RenderWindow.hpp>

class ButtonActions;
class FrameAnimation;
class RotateAnimation;

class RenderWindow : public sf::RenderWindow
{
public:
    RenderWindow() : sf::RenderWindow() {}
    RenderWindow(sf::VideoMode mode, const sf::String &title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings &settings = sf::ContextSettings())
        : sf::RenderWindow(mode, title, style, settings) {}
    RenderWindow(sf::WindowHandle handle, const sf::ContextSettings &settings = sf::ContextSettings())
        : sf::RenderWindow(handle, settings) {}

    void Rysowanie(const ButtonActions &P);
    void Rysowanie(FrameAnimation &A);
    void Rysowanie(RotateAnimation &A);
    void Rysowanie(const sf::VertexBuffer &vertexBuffer, std::size_t firstVertex, std::size_t vertexCount, const sf::RenderStates &states = sf::RenderStates::Default);
    void Rysowanie(const sf::VertexBuffer &vertexBuffer, const sf::RenderStates &states = sf::RenderStates::Default);
    void Rysowanie(const sf::Vertex *vertices, std::size_t vertexCount, sf::PrimitiveType type, const sf::RenderStates &states = sf::RenderStates::Default);
    void Rysowanie(const sf::Drawable &drawable, const sf::RenderStates &states = sf::RenderStates::Default);
};
#endif // RENDERWINDOW_H
