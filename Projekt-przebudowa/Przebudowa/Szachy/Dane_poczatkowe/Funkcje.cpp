#include <Szachy/Dane_poczatkowe/funkcje.h>
#include <Szachy/Klasy_pomocnice/przycisk.h>
#include <Szachy/Klasy_pomocnice/animacja.h>
#include <Szachy/Klasy_pomocnice/animacja_plynna.h>
using namespace std;
void SetDisplay(sf::RenderWindow &window,sf::Vector2i (a) ,sf::Vector2u(c)) //pozwala ustawić okno do rozmiarów ekranu
{
   window.setSize(c);
   window.setPosition(a);
}

void RenderWindow::Rysowanie(const PrzyciskAkcje &P){draw(P);draw(P.tekst_przycisku);}
void RenderWindow::Rysowanie( Animacja &A)
{
    A.Zmien();
    draw(A);
}
void RenderWindow::Rysowanie( Animacja_plynna &A)
{

    A.Zmien();
    draw(A);
}
void RenderWindow::Rysowanie(const sf::VertexBuffer &vertexBuffer, std::size_t firstVertex, std::size_t vertexCount, const sf::RenderStates &states){draw(vertexBuffer,firstVertex,vertexCount,states);}
void RenderWindow::Rysowanie(const sf::VertexBuffer &vertexBuffer, const sf::RenderStates &states){draw(vertexBuffer,states);}
void RenderWindow::Rysowanie(const sf::Vertex *vertices, std::size_t vertexCount, sf::PrimitiveType type, const sf::RenderStates &states){draw(vertices,vertexCount,type,states);}
void RenderWindow::Rysowanie(const sf::Drawable &drawable, const sf::RenderStates &states) {draw(drawable,states);}
