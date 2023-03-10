#include <Szachy/Klasy_pomocnice/animacja.h>

Animacja::Animacja(const std::string &S,float C)
{
    okres=C;
    sf::Image I1,I2;
    I1.loadFromFile("C:/Users/kubas/Documents/GitHub/Projekt/Projekt-przebudowa/build-Przebudowa-Desktop_Qt_6_2_4_MinGW_64_bit-Debug/Grafika/Animacje/"+S+"/Grafika.png");
    I2.loadFromFile("C:/Users/kubas/Documents/GitHub/Projekt/Projekt-przebudowa/build-Przebudowa-Desktop_Qt_6_2_4_MinGW_64_bit-Debug/Grafika/Animacje/"+S+"/Ksztalt.png");
    I2.createMaskFromColor(sf::Color::Black);
    for(u_int c=1;c<I2.getSize().x;c++) for(u_int d=1;d<I2.getSize().y;d++)
    {
     if(I2.getPixel(c,d).a!=0)I2.setPixel(c,d,I1.getPixel(c,d));
    }
    this->texture.loadFromImage(I2);
    this->setTexture(texture);

    Czytaj(S);
    setTextureRect(Pozycje[0]);
}
Animacja::Animacja(const std::string &S,RenderWindow &W,float C)
{
    window=&W;
    okres=C;
    sf::Image I1,I2;
    I1.loadFromFile("C:/Users/kubas/Documents/GitHub/Projekt/Projekt-przebudowa/build-Przebudowa-Desktop_Qt_6_2_4_MinGW_64_bit-Debug/Grafika/Animacje/"+S+"/Grafika.png");
    I2.loadFromFile("C:/Users/kubas/Documents/GitHub/Projekt/Projekt-przebudowa/build-Przebudowa-Desktop_Qt_6_2_4_MinGW_64_bit-Debug/Grafika/Animacje/"+S+"/Ksztalt.png");
    I2.createMaskFromColor(sf::Color::Black);
    for(u_int c=1;c<I2.getSize().x;c++) for(u_int d=1;d<I2.getSize().y;d++)
    {
     if(I2.getPixel(c,d).a!=0)I2.setPixel(c,d,I1.getPixel(c,d));
    }
    this->texture.loadFromImage(I2);
    this->setTexture(texture);

    Czytaj(S);
    setTextureRect(Pozycje[0]);
}

void Animacja::Zmien()
{
    if(clock.getElapsedTime().asSeconds()>okres)
    {
        clock.restart();
        if(aktualny==Pozycje.size())aktualny=0;
        setTextureRect(Pozycje[++aktualny-1]);
    }
}

void Animacja::Czytaj(const std::string &S)
{
    std::fstream Plan("Pliki_tekstowe/Animacje/"+S+".txt", std::fstream::in);
    if(Plan.is_open())
    {
        std::string ruch;
        sf::IntRect R;
        while(std::getline(Plan, ruch,','))
        {
            R.left=stoi(ruch);
            std::getline(Plan, ruch,',');

            R.top=stoi(ruch);
            std::getline(Plan, ruch,',');

            R.width=stoi(ruch);
            std::getline(Plan, ruch,'\n');

            R.height=stoi(ruch);
            Pozycje.emplace_back(R);

        }
    }
}

void Animacja::Kalibrowanie(sf::Vector2f(pos),sf::Vector2f(roz))
{
    {
        if(window==nullptr)return;
        if(pos.x>roz.x)
        {
            float x=pos.x;
            pos.x=roz.x;
            roz.x=x-pos.x;
        }
        else roz.x-=pos.x;
        if(pos.y>roz.y)
        {
            float y=pos.y;
            pos.y=roz.y;
            roz.y=y-pos.y;
        }
        else roz.y-=pos.y;
        setPosition(window->getView().getSize().x*pos.x,window->getView().getSize().y*pos.y);
        setScale(roz.x*window->getView().getSize().x/getTextureRect().width,
                 roz.y*window->getView().getSize().y/getTextureRect().height);
 //       setSize(sf::Vector2f(window->getView().getSize().x*roz.x,window->getView().getSize().y*roz.y));


    }
}
void Animacja::Kalibrowanie(sf::Vector2f(pos),float scale)
{
    {
        if(window==nullptr)return;

        setPosition(window->getView().getSize().x*pos.x,window->getView().getSize().y*pos.y);
        setScale(scale*window->getView().getSize().x/window->getSize().x,
                 scale*window->getView().getSize().y/window->getSize().y);


    }
}
