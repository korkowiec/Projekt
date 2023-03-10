#include <Szachy/Klasy_pomocnice/animacja_plynna.h>

Animacja_plynna::Animacja_plynna(const std::string &S,float C)
{
    szybkosc=C;
    sf::Image I1,I2;
    I1.loadFromFile("Grafika/Animacje_plynne/"+S+"/Grafika.png");
    I2.loadFromFile("Grafika/Animacje_plynne/"+S+"/Ksztalt.png");
    I2.createMaskFromColor(sf::Color::Black);
    for(u_int c=1;c<I2.getSize().x;c++) for(u_int d=1;d<I2.getSize().y;d++)
    {
     if(I2.getPixel(c,d).a!=0)I2.setPixel(c,d,I1.getPixel(c,d));
    }
    this->texture.loadFromImage(I2);
    this->setTexture(texture);
}
Animacja_plynna::Animacja_plynna(const std::string &S,RenderWindow &W,float C)
{
    window=&W;
    szybkosc=C;
    sf::Image I1,I2;
    I1.loadFromFile("Grafika/Animacje_plynne/"+S+"/Grafika.png");
    I2.loadFromFile("Grafika/Animacje_plynne/"+S+"/Ksztalt.png");
    I2.createMaskFromColor(sf::Color::Black);
    for(u_int c=1;c<I2.getSize().x;c++) for(u_int d=1;d<I2.getSize().y;d++)
    {
     if(I2.getPixel(c,d).a!=0)I2.setPixel(c,d,I1.getPixel(c,d));
    }
    this->texture.loadFromImage(I2);
    this->setTexture(texture);
}
void Animacja_plynna::Zmien_1()
{
    //if(clock.getElapsedTime().asSeconds()<0.25) return;
   float kat1=this->getRotation();
    this->rotate(clock.getElapsedTime().asSeconds()*szybkosc*3.6);

    float kat;

    if(this->getPosition().x-this->pos.x>0&&this->pos.y-this->getPosition().y==0) kat=0;
    else if(this->getPosition().x-this->pos.x>0&&this->pos.y-this->getPosition().y>0) kat=abs(atan(pos.y-this->getPosition().y/this->getPosition().x-this->pos.x))*180/M_PI;
    else if (this->getPosition().x-this->pos.x==0&&this->pos.y-this->getPosition().y>0) kat=90;
    else if (this->getPosition().x-this->pos.x<0&&this->pos.y-this->getPosition().y>0) kat=90+abs(atan(pos.y-this->getPosition().y/this->getPosition().x-this->pos.x))*180/M_PI;
    else if (this->getPosition().x-this->pos.x<0&&this->pos.y-this->getPosition().y==0) kat=180;
    else if (this->getPosition().x-this->pos.x<0&&this->pos.y-this->getPosition().y<0) kat=180+abs(atan(pos.y-this->getPosition().y/this->getPosition().x-this->pos.x))*180/M_PI;
    else if (this->getPosition().x-this->pos.x==0&&this->pos.y-this->getPosition().y<0) kat=270;
    else if (this->getPosition().x-this->pos.x>0&&this->pos.y-this->getPosition().y<0) kat=270+abs(atan(pos.y-this->getPosition().y/this->getPosition().x-this->pos.x))*180/M_PI;

    float dlugosc=sqrt((this->pos.y-this->getPosition().y)*(this->pos.y-this->getPosition().y)+(this->pos.x-this->getPosition().x)*(this->pos.x-this->getPosition().x));
    float dlugosc2=sqrt(cos((kat-(this->getRotation()-kat1))*M_PI/180)*dlugosc*cos((kat-(this->getRotation()-kat1))*M_PI/180)*dlugosc+
                        sin((kat-(this->getRotation()-kat1))*M_PI/180)*dlugosc*sin((kat-(this->getRotation()-kat1))*M_PI/180)*dlugosc);

    using namespace std;
//    cout<<"odlegosc pos od srodka "<<dlugosc<<endl;
//    cout<<"odlegosc2 pos od srodka "<<dlugosc2<<endl;
//    cout<<"kat przed skokiem "<< kat1<<endl;
//    cout<<"kat po skoku "<< this->getRotation()<<endl;
//    cout<<"Roznica w katach "<<this->getRotation()-kat1<<endl;
//    cout<<"kat pozycja od srodka "<< kat<<endl;
//    cout<<"Nowy kat pozycji od srodka "<< kat-(this->getRotation()-kat1)<<endl;

    cout<<"Roznica X1 od Xpos "<<this->getPosition().x-this->pos.x<<endl;
    cout<<"Roznica Y1 od Ypos "<<this->getPosition().y-this->pos.y<<endl;

//    cout<<"Cos "<<cos((kat-(this->getRotation()-kat1))*M_PI/180)<<endl;
//    cout<<"Sin "<<sin((kat-(this->getRotation()-kat1))*M_PI/180)<<endl;

    cout<<"Roznica X2 od Xpos "<<cos((kat-(this->getRotation()-kat1))*M_PI/180)*dlugosc<<endl;
    cout<<"Roznica Y2 od Ypos "<<sin((kat-(this->getRotation()-kat1))*M_PI/180)*dlugosc<<endl;

    cout<<"Roznica X1 od X2 "<<cos((kat-(this->getRotation()-kat1))*M_PI/180)*dlugosc-(this->getPosition().x-this->pos.x)<<endl;
    cout<<"Roznica Y1 od Y2 "<<-sin((kat-(this->getRotation()-kat1))*M_PI/180)*dlugosc-(this->getPosition().y-this->pos.y)<<endl;

    this->move((cos((kat-(this->getRotation()-kat1))*M_PI/180)*dlugosc-(this->getPosition().x-this->pos.x)),
               (-sin((kat-(this->getRotation()-kat1))*M_PI/180)*dlugosc-(this->getPosition().y-this->pos.y)));
    clock.restart();
}

void Animacja_plynna::Zmien()
{

    this->rotate(clock.getElapsedTime().asSeconds()*szybkosc*3.6);
     clock.restart();

     this->setPosition(this->pos.x+cos((rotacja_poczatek-this->getRotation())*M_PI/180)*dlugosc,
                 this->pos.y-sin((rotacja_poczatek-this->getRotation())*M_PI/180)*dlugosc);

}
void Animacja_plynna::Kalibrowanie(sf::Vector2f(pos),sf::Vector2f(roz))
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
void Animacja_plynna::Kalibrowanie(sf::Vector2f(pos),float scale)
{
    {
        if(window==nullptr)return;

        setPosition(window->getView().getSize().x*pos.x,window->getView().getSize().y*pos.y);
        setScale(scale*window->getView().getSize().x/window->getSize().x,
                 scale*window->getView().getSize().y/window->getSize().y);
        ustaw_rotacja_poczatkowa();

    }
}
void Animacja_plynna::Kalibrowanie()
{
    {
        if(window==nullptr)return;
        pos_poz=getPosition();
        setPosition(window->getView().getSize().x*pos_poz.x,window->getView().getSize().y*pos_poz.y);
        setScale(window->getView().getSize().x/window->getSize().x,
                 window->getView().getSize().y/window->getSize().y);
        //ustaw_rotacja_poczatkowa();

    }
}
void Animacja_plynna::Set_pos(sf::Vector2f(pos1))
{

    pos=pos1;
    dlugosc=sqrt((this->pos.y-this->getPosition().y)*(this->pos.y-this->getPosition().y)+(this->pos.x-this->getPosition().x)*(this->pos.x-this->getPosition().x));
    ustaw_rotacja_poczatkowa();
}
void Animacja_plynna::Set_pos_poz(sf::Vector2f(pos1))
{
    this->setPosition(pos1);
    pos_poz=pos1;
    ustaw_rotacja_poczatkowa();

}
void Animacja_plynna::ustaw_rotacja_poczatkowa()
 {
     if(this->pos_poz.x-this->pos.x>0&&this->pos.y-this->pos_poz.y==0) rotacja_poczatek=0;
     else if(this->pos_poz.x-this->pos.x>0&&this->pos.y-this->pos_poz.y>0) rotacja_poczatek=abs(atan((pos.y-this->pos_poz.y)/(this->pos_poz.x-this->pos.x))*180/M_PI);
     else if (this->pos_poz.x-this->pos.x==0&&this->pos.y-this->pos_poz.y>0) rotacja_poczatek=90;
     else if (this->pos_poz.x-this->pos.x<0&&this->pos.y-this->pos_poz.y>0) rotacja_poczatek=90+abs(atan((pos.y-this->pos_poz.y)/(this->pos_poz.x-this->pos.x))*180/M_PI);
     else if (this->pos_poz.x-this->pos.x<0&&this->pos.y-this->pos_poz.y==0) rotacja_poczatek=180;
     else if (this->pos_poz.x-this->pos.x<0&&this->pos.y-this->pos_poz.y<0) rotacja_poczatek=180+abs(atan((pos.y-this->pos_poz.y)/(this->pos_poz.x-this->pos.x))*180/M_PI);
     else if (this->pos_poz.x-this->pos.x==0&&this->pos.y-this->pos_poz.y<0) rotacja_poczatek=270;
     else if (this->pos_poz.x-this->pos.x>0&&this->pos.y-this->pos_poz.y<0) rotacja_poczatek=270+abs(atan((pos.y-this->pos_poz.y)/(this->pos_poz.x-this->pos.x))*180/M_PI);
 }
void Animacja_plynna::Kalibrowanie_Zmien()
{
    if(window==nullptr)return;

    setPosition(window->getView().getSize().x*pos.x,window->getView().getSize().y*pos.y);
    setScale(window->getView().getSize().x/getTextureRect().width,
             window->getView().getSize().y/getTextureRect().height);


}
