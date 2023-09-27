#include <Szachy/HelpClass/RenderWindow.h>
#include <Szachy/HelpClass/RotateAnimation.h>
#include <Szachy/HelpClass/FrameAnimation.h>
#include <Szachy/HelpClass/Button.h>
void RenderWindow::Rysowanie(const ButtonActions &P){draw(P);draw(P.tekst_przycisku);}
void RenderWindow::Rysowanie( FrameAnimation &A)
{
    A.Zmien();
    draw(A);
}
void RenderWindow::Rysowanie( RotateAnimation &A)
{

    A.Zmien();
    draw(A);
}
void RenderWindow::Rysowanie(const sf::VertexBuffer &vertexBuffer, std::size_t firstVertex, std::size_t vertexCount, const sf::RenderStates &states){draw(vertexBuffer,firstVertex,vertexCount,states);}
void RenderWindow::Rysowanie(const sf::VertexBuffer &vertexBuffer, const sf::RenderStates &states){draw(vertexBuffer,states);}
void RenderWindow::Rysowanie(const sf::Vertex *vertices, std::size_t vertexCount, sf::PrimitiveType type, const sf::RenderStates &states){draw(vertices,vertexCount,type,states);}
void RenderWindow::Rysowanie(const sf::Drawable &drawable, const sf::RenderStates &states) {draw(drawable,states);}
