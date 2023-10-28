#include <Szachy/Windows/BasicGame/Game.h>

void Game::game(){
    for(uint8_t i=0;i<::Team;i++){
        if(std::none_of(chessman.begin(),chessman.end(),
                        [i](const std::shared_ptr<Chessman> &figure){
                            if(figure->team==i)
                                return (bool)figure->bools[0];
                            return false;

                        })){
            ::window=1;
            break;
        }

        }
    Console.scale();
    while(::window==2){
        ::mouse_position = ::Window.mapPixelToCoords(sf::Mouse::getPosition(::Window));
        while(::Window.pollEvent(::Event)){
            ::globalActions();
            if((::Event.type == sf::Event::MouseButtonPressed)&&(::Event.mouseButton.button == sf::Mouse::Left)){
                gameActions();
            }
            if(::Event.type==sf::Event::Resized) {
                Console.scale();
                for(std::shared_ptr<Chessman> &chessman:chessman){
                    chessman->scale();
                    chessman->emplace(chessman->x,chessman->y);
                }
            }
        }
        drawAll();
    }
}
void Game::squartScale(){
    squart.setScale(::Window.getView().getSize().x/::Window.getSize().x,
                    ::Window.getView().getSize().y/::Window.getSize().y);
    ::Window.getSize().y<::Window.getSize().x?
        squart.setSize(sf::Vector2f(::Window.getSize().y/GameBoard.boardX,::Window.getSize().y/GameBoard.boardY)):
        squart.setSize(sf::Vector2f(::Window.getSize().x/GameBoard.boardX,::Window.getSize().x/GameBoard.boardY));
}

void Game::drawBoard(){

    float wx=::Window.getSize().x,wy=::Window.getSize().y;
    squart.setScale(::Window.getView().getSize().x/wx,::Window.getView().getSize().y/wy); //skaluje elementy do zmiany rozmiaru okna (View!=Size)
    if(wy<wx) wx=wy; else wy=wx; //rysowanie jest polem kwadratowym niezależnie od ilości na danym boku elementów
    squart.setPosition(0,0);
    squart.setSize(sf::Vector2f(wx,wy));
    squart.setFillColor(GameBoard.square1);
    ::Window.draw(squart);
    squart.setFillColor(GameBoard.square2);
    squart.setSize(sf::Vector2f(wx/GameBoard.boardX,wy/GameBoard.boardY));
    for (short c=0;c < GameBoard.boardY;c++ )
    {
        for(short d=0;d<GameBoard.boardX;d++)
        {
            if((c+d)%2==0)
            {
                squart.setPosition((d%GameBoard.boardX)*::Window.getView().getSize().x*wx/GameBoard.boardX/::Window.getSize().x,
                                    (c%GameBoard.boardY)*::Window.getView().getSize().y*wy/GameBoard.boardY/::Window.getSize().y);
                ::Window.draw(squart);
            }
        }
    }
}

void Game::gameActions(){
    int X,Y;
    if(::Window.getSize().y<::Window.getSize().x){
        X=mouse_position.x/(::Window.getView().getSize().x*::Window.getSize().y/::Window.getSize().x/GameBoard.boardX);
        Y=mouse_position.y/(::Window.getView().getSize().y/GameBoard.boardY);
    }
    else{
        X=mouse_position.x/(::Window.getView().getSize().x/GameBoard.boardX);
        Y=mouse_position.y/(::Window.getView().getSize().y*::Window.getSize().x/::Window.getSize().y/GameBoard.boardY);
    }
    if(!(Y>=GameBoard.boardY||X>=GameBoard.boardX||X<0||Y<0)){
        if(select.select){
            if(boardChessman[X][Y].first.lock()!=nullptr){
                if(boardChessman[X][Y].second.lock()==nullptr){
                    boardChessman[X][Y].second=boardChessman[select.boardX][select.boardY].second;
                    boardChessman[select.boardX][select.boardY].second.lock()->bools[2]=0;
                    boardChessman[select.boardX][select.boardY].second.reset();
                }
                else{
                    if(!(select.boardX==X&&select.boardY==Y)){
                        chessman.erase(std::find(chessman.begin(),chessman.end(),boardChessman[X][Y].second.lock()));
                        boardChessman[X][Y].second=boardChessman[select.boardX][select.boardY].second;
                        boardChessman[select.boardX][select.boardY].second.lock()->bools[2]=0;
                        boardChessman[select.boardX][select.boardY].second.reset();
                    }
                }
                if(!(select.boardX==X&&select.boardY==Y))::Teraz==::Team-1?::Teraz=0: ::Teraz++;
                boardChessman[X][Y].second.lock()->x=X,boardChessman[X][Y].second.lock()->y=Y;
                boardChessman[X][Y].second.lock()->emplace();
                select=Select();
                posibleMoves.clear();
                for(uint8_t i=0;i<::Team;i++){
                    if(std::none_of(chessman.begin(),chessman.end(),
                                    [i](const std::shared_ptr<Chessman> &figure){
                            if(figure->team==i)
                                return (bool)figure->bools[0];
                            return false;

                        })){
                        Console.losePlayer(i);
                        break;
                    }

                }
            }
        }
        else{
            if(boardChessman[X][Y].second.lock()!=nullptr){
                if(boardChessman[X][Y].second.lock()->team==::Teraz){
                    select.select=1;
                    select.boardX=X;
                    select.boardY=Y;
                    boardChessman[X][Y].second.lock()->posibleMove();
                }
            }
        }

    }
}

void Game::drawAll(){
    ::Window.clear(sf::Color::Black);
    Console.draw();
    drawBoard();
    //Console.Akcje_i_rysowanie();
    for(std::shared_ptr<Chessman> &chessman:chessman){
        ::Window.draw(*chessman);
    }
    for(std::shared_ptr<PosibleMove> &posibleMoves:posibleMoves){
        boardChessman[select.boardX][select.boardY].second.lock()->drawSquare(posibleMoves->type,posibleMoves->x,posibleMoves->y);
    }
    ::Window.display();
}

void Game::makeAll(){
    squartScale();
    game();
}

