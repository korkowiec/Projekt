#ifndef PIASKOWNICA_H
#define PIASKOWNICA_H
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <Szachy/Dane_poczatkowe/Zdarzenia.h>
#include <Szachy/Klasy_pomocnice/przycisk.h>
#include <Szachy/Klasy_pomocnice/animacja_plynna.h>
#include <Szachy/Klasy_pomocnice/animacja.h>



class Piaskownica
{
protected:
    struct Dane_ruchu
    {

        bool IsSelect=0;
        short x; //ruch w X
        short y; //ruch w Y
        u_short EL=0; // liczba pętli, 0==nieskończonośc
        bool US=0; //unikanie kolizji ze swoimi
        bool UW=0; //UwU unikanie kolizji z wrogami oba bool wykorzystywanie w ruchach w pętli
        bool Z=0; //możliwość zbijania wroga
        bool ZE=0; //możliwość zbicia wroga kończy pętle
        bool S=0; //możliwość zbicia swoich
        bool SE=0; //możliwość zbicia swojego kończy pętle
        bool M =0; //Czy musi być z pozycji początkowej
        bool T =0; //tylko bicie figur
        Dane_ruchu(short x=0,short y=0,u_short EL=1,bool US=0,bool UW=0,bool Z=0,bool ZE=0,bool S=0,bool SE=0,bool M =0,bool T=0):x(x),y(y),EL(EL),US(US),UW(UW),Z(Z),ZE(ZE),S(S),SE(SE),M(M),T(T){}
        ~Dane_ruchu(){}
    };

    struct Plansza_gry
    {

        int Rozmiar;
        sf::Color Pole1=sf::Color(181,127,99);
        sf::Color Pole2=sf::Color(240,217,181);
        std::vector<std::vector<Dane_ruchu>> Ruch;
        ~Plansza_gry(){for(std::vector<Dane_ruchu> &A:Ruch)A.clear();Ruch.clear();}
        Plansza_gry(const int a=2):Rozmiar(2*a+1)
        {
           std::vector<Dane_ruchu> A(Rozmiar);
           Ruch.resize(Rozmiar,A);
        }
        void Zmiana_ruch(int a)
        {
            int NowyRozmiar=a*2+1;

            //NOWY
            std::vector<Dane_ruchu> A(NowyRozmiar);
            std::vector<std::vector<Dane_ruchu>> To(NowyRozmiar,A);

            //KOPIUJ
            for(int c=0;c<NowyRozmiar&&c<Rozmiar;c++)
            {
                for(int d=0;d<NowyRozmiar&&d<Rozmiar;d++)
                {
                   To[c][d]=Ruch[c][d];
                }
            }

            //Nowy rozmiar
            Ruch.clear();
            Ruch.resize(NowyRozmiar,A);


            //Kopiuj
            for(int c=0;c<NowyRozmiar&&c<Rozmiar;c++)
            {
                for(int d=0;d<NowyRozmiar&&c<Rozmiar;d++)
                {
                   Ruch[c][d]=To[c][d];
                }
            }

            Rozmiar=NowyRozmiar;
        }
    };

    bool saveImageToFile(const std::string& filename, const std::vector<sf::Uint8>& pixels, const sf::Vector2u& size,const wchar_t *I)
    {




        // Make sure the image is not empty
        if (!pixels.empty() && (size.x > 0) && (size.y > 0))
        {

            // Deduce the image type from its extension
            struct A{
            static std::string toLower(std::string str)
            {
                for (std::string::iterator i = str.begin(); i != str.end(); ++i)
                    *i = static_cast<char>(std::tolower(*i));
                return str;
            }};
            // Extract the extension
            const std::size_t dot = filename.find_last_of('.');
            const std::string extension = dot != std::string::npos ? A::toLower(filename.substr(dot + 1)) : "";
  // std::ofstream outputFile(T1);
            if (extension == "bmp")
            {
                stbi_write_tga(filename.c_str(),size.x,size.y,4,&pixels[0],I);
                // BMP format
                if (stbi_write_bmp(filename.c_str(), size.x, size.y, 4, &pixels[0],I))
                    return true;
            }
            else if (extension == "tga")
            {
                // TGA format
                if (stbi_write_tga(filename.c_str(), size.x, size.y, 4, &pixels[0],I))
                    return true;
            }
            else if (extension == "png")
            {
                // PNG format
                if (stbi_write_png(filename.c_str(), size.x, size.y, 4, &pixels[0], 0,I))
                    return true;
            }
            else if (extension == "jpg" || extension == "jpeg")
            {
                // JPG format
                if (stbi_write_jpg(filename.c_str(), size.x, size.y, 4, &pixels[0], 90,I))
                    return true;
            }
        }


        return false;
    }

private:
    sf::Color Kolory[5]={sf::Color(181,127,99),sf::Color(240,217,181),sf::Color::Green,sf::Color::Red,sf::Color::Yellow};
    float Granica;//Wykorzystam do pamiętania końca planszy i początku interfejsu
    sf::Vector2f(Rozmiar);
    std::vector<Przycisk> Przyciski;
    RenderWindow *window;
    sf::Event *event;
    Dane_ruchu Aktualne_dane_ruchu;
    Plansza_gry *Plansza;//Statyczna wywala mi błąd przy wektorze Ruch, gdy chcę nim operować.
    sf::RectangleShape *Rysunek;
    std::vector<sf::Text> Teksty;
    sf::Text TEXTY[8];
    void Zdarzenia_interfejs();
    void Zdarzenia_plansza();
    void Rysowanie_plansza();
    void Rysowanie_interfejs();
    void Utwórz_przyciski_i_tekst();
    void Rysowanie_tektsu_i_przycisków();
    void Czytaj_plik();
    void Zapisz_figurę();
    bool Zapisz_figure=0;
    bool CzytajPlik=0;
    sf::String Lokalizacja_pliku;
    sf::Sprite Figura;
    sf::Texture Tekstura_figury;
    sf::String Nazwapliku="IŚWINIA";
    bool STANIK_BRA=1;

public:
    Piaskownica(RenderWindow &W,sf::Event &E):window(&W),event(&E){}
    void Dzialanie();

    ~Piaskownica(){}
};

#endif // PIASKOWNICA_H
