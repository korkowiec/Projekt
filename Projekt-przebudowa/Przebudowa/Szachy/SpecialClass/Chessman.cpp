#include <Szachy/SpecialClass/Chessman.h>
#include <Szachy/Windows/BasicGame/BasicGame.h>
#include <Szachy/GlobalVariabies/Variables.h>
#include <Szachy/Windows/BasicGame/Game.h>
Chessman::Chessman(Game &game,const TypeChessman &Name, const uint8_t &X, const uint8_t &Y,const uint8_t &Team,const std::bitset<4> &Bools=std::bitset<4>("1100"))
    :Board(game),x(X),y(Y),team(Team),Texture(Name),bools(Bools){
    setTexture(Texture.texture);
    scale();
    emplace();
    for(sf::Color &C:Colors)C.a=128;
}

bool Chessman::select(){
    if(bools[1]){
        bools[1]=0;
        return 0;
    }
    bools[1]=1;
    return 1;
}

std::vector<std::shared_ptr<Chessman>> Chessman::makeVectorShared_ptrChessman(Game &P,const sf::String &name){
    std::fstream File(::loadFileToRead("Pliki_tekstowe/Plansze/"+name+'/'+name+"UstawienieFigur.txt"));
    if(File.is_open())
    {
        std::vector<std::shared_ptr<Chessman>> vec;
        sf::String nameChessman;//jaka figura
        uint8_t x,y;//step
        u_short t;//drużyna
        std::string step;//czytanie z pliku
        while(std::getline(File, step,','))
        {
            if(step==""||step=="\n")continue;
            std::bitset<4> bools=std::bitset<4>("1100");
            while(step.find('"')!=std::string::npos)step.replace(step.find('"'),1,",");
            nameChessman=step; //Nazwa figury
            std::getline(File, step,',');

            x=(uint8_t)stoi(step); //step z x (podany numer pola)
            std::getline(File, step,',');

            y=(uint8_t)stoi(step);//step z y (podany numer pola)
            std::getline(File, step,',');

            t=(uint8_t)stoi(step); //Drużyna, do której należy
            std::getline(File, step,',');
            if(!(step=="\n"||step=="")) bools[0]=(bool)stoi(step);
            vec.emplace_back(std::make_shared<Chessman>(P,
                             *std::find(P.typeChessman.begin(),P.typeChessman.end(),
                                                                   nameChessman),
                                              x,y,t,bools));
            P.boardChessman[x][y].second=*vec.rbegin();
        }
        File.close();
        return vec;
    }
    return std::vector<std::shared_ptr<Chessman>>();
}

void Chessman::posibleMove(){

    Board.posibleMoves.emplace_back(std::make_shared<PosibleMove>(x,y,0));
    Board.boardChessman[x][y].first=*Board.posibleMoves.rbegin();
    for(const ChessmanMove &Type:Texture.move){
        if(~bools[2]&Type.typeMove[6]) continue;
            uint8_t elapsed=Type.elapsed;
            if(((x+Type.x)<0)||((y+Type.y)<0))continue;
            uint8_t nextX=x,nextY=y;
            do{
            if(((nextX+Type.x)<0)||((nextY+Type.y)<0)||(nextX+Type.x)>=Board.GameBoard.boardX||(nextY+Type.y)>=Board.GameBoard.boardY)break;
                nextX+=Type.x;
                nextY+=Type.y;
                if(Board.boardChessman[nextX][nextY].second.lock()==nullptr){
                    if(Type.typeMove[7])continue;
                    Board.posibleMoves.emplace_back(std::make_shared<PosibleMove>(nextX,nextY,1));
                    Board.boardChessman[nextX][nextY].first=*Board.posibleMoves.rbegin();
                }
                else if(Board.boardChessman[nextX][nextY].second.lock()->team==team){
                    if(Type.typeMove[4]){
                        Board.posibleMoves.emplace_back(std::make_shared<PosibleMove>(nextX,nextY,2));
                        Board.boardChessman[nextX][nextY].first=*Board.posibleMoves.rbegin();
                    }
                    if(Type.typeMove[5])break;
                }
                else{
                    if(Type.typeMove[2]){
                        Board.posibleMoves.emplace_back(std::make_shared<PosibleMove>(nextX,nextY,2));
                        Board.boardChessman[nextX][nextY].first=*Board.posibleMoves.rbegin();
                    }
                    if(Type.typeMove[3])break;
                }
            }
            while(--elapsed!=0);
        }
}






void Chessman::drawSquare(sf::Color color,uint8_t X, uint8_t Y){
    Board.squart.setFillColor(color);
    ::Window.getSize().y<::Window.getSize().x?
        Board.squart.setPosition((X%Board.GameBoard.boardX)*::Window.getView().getSize().x*::Window.getSize().y/Board.GameBoard.boardX/::Window.getSize().x,
                                 (Y%Board.GameBoard.boardY)*::Window.getView().getSize().y*::Window.getSize().y/Board.GameBoard.boardY/::Window.getSize().y):
        Board.squart.setPosition((X%Board.GameBoard.boardX)*::Window.getView().getSize().x*::Window.getSize().x/Board.GameBoard.boardX/::Window.getSize().x,
                                 (Y%Board.GameBoard.boardY)*::Window.getView().getSize().y*::Window.getSize().x/Board.GameBoard.boardY/::Window.getSize().y);
    ::Window.draw(Board.squart);
}

void Chessman::drawSquare(uint8_t Type,uint8_t X, uint8_t Y){
    Board.squart.setFillColor(Colors[Type]);
    ::Window.getSize().y<::Window.getSize().x?
        Board.squart.setPosition((X%Board.GameBoard.boardX)*::Window.getView().getSize().x*::Window.getSize().y/Board.GameBoard.boardX/::Window.getSize().x,
                                 (Y%Board.GameBoard.boardY)*::Window.getView().getSize().y*::Window.getSize().y/Board.GameBoard.boardY/::Window.getSize().y):
        Board.squart.setPosition((X%Board.GameBoard.boardX)*::Window.getView().getSize().x*::Window.getSize().x/Board.GameBoard.boardX/::Window.getSize().x,
                                 (Y%Board.GameBoard.boardY)*::Window.getView().getSize().y*::Window.getSize().x/Board.GameBoard.boardY/::Window.getSize().y);
    ::Window.draw(Board.squart);
}
void Chessman::scale()
{
    ::Window.getSize().y<::Window.getSize().x?
        setScale(::Window.getView().getSize().x/Texture.texture.getSize().x*::Window.getSize().y/(Board.GameBoard.boardX*::Window.getSize().x),
                 ::Window.getView().getSize().y/Texture.texture.getSize().y*::Window.getSize().y/(Board.GameBoard.boardY*::Window.getSize().y)):
        setScale(::Window.getView().getSize().x/Texture.texture.getSize().x*::Window.getSize().x/(Board.GameBoard.boardX*::Window.getSize().x),
                 ::Window.getView().getSize().y/Texture.texture.getSize().y*::Window.getSize().x/(Board.GameBoard.boardY*::Window.getSize().y));

}

void Chessman::emplace(){
    ::Window.getSize().y<::Window.getSize().x?
        setPosition((x%Board.GameBoard.boardX)*::Window.getView().getSize().x*::Window.getSize().y/Board.GameBoard.boardX/::Window.getSize().x,
                    (y%Board.GameBoard.boardY)*::Window.getView().getSize().y*::Window.getSize().y/Board.GameBoard.boardY/::Window.getSize().y):
        setPosition((x%Board.GameBoard.boardX)*::Window.getView().getSize().x*::Window.getSize().x/Board.GameBoard.boardX/::Window.getSize().x,
                    (y%Board.GameBoard.boardY)*::Window.getView().getSize().y*::Window.getSize().x/Board.GameBoard.boardY/::Window.getSize().y);
}

void Chessman::emplace(uint8_t X,uint8_t Y){
    ::Window.getSize().y<::Window.getSize().x?
        setPosition((X%Board.GameBoard.boardX)*::Window.getView().getSize().x*::Window.getSize().y/Board.GameBoard.boardX/::Window.getSize().x,
                    (Y%Board.GameBoard.boardY)*::Window.getView().getSize().y*::Window.getSize().y/Board.GameBoard.boardY/::Window.getSize().y):
        setPosition((X%Board.GameBoard.boardX)*::Window.getView().getSize().x*::Window.getSize().x/Board.GameBoard.boardX/::Window.getSize().x,
                    (Y%Board.GameBoard.boardY)*::Window.getView().getSize().y*::Window.getSize().x/Board.GameBoard.boardY/::Window.getSize().y);

}

