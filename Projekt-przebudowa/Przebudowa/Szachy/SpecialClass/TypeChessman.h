#ifndef TYPECHESSMAN_H
#define TYPECHESSMAN_H

#include <Szachy/SpecialClass/ChessmanMove.h>
#include <fstream>
#include <codecvt>
struct TypeChessman{
    sf::Texture texture;
    sf::String name;
    std::vector<ChessmanMove> move;

    static std::vector<TypeChessman> makeVectorTypeChessman(sf::String name){
        std::vector<TypeChessman> vec;
        std::fstream FirstFile(::loadFileToRead(L"Pliki_tekstowe/Plansze/"+name+L"/Figury.txt"));
        if(FirstFile.is_open()){
            TypeChessman typeChessman;
            std::string step;
            while(std::getline(FirstFile, step)){
                if(step=="\n"||step=="") continue;
                typeChessman.move=ChessmanMove::makeVectorChessmanMove(step);
                typeChessman.name=step;
                typeChessman.texture.loadFromFile("Grafika/Figury/"+step+".png");
                vec.emplace_back(typeChessman);
            }
            FirstFile.close();
        }

        std::fstream SecondFile(::loadFileToRead(L"Pliki_tekstowe/Plansze/"+name+L"/Figury_własne.txt"));
        if(SecondFile.is_open()){
            TypeChessman typeChessman;
            std::string step;
            while(std::getline(SecondFile, step)){
                if(step=="\n"||step=="") continue;
                typeChessman.move=ChessmanMove::makeVectorChessmanMove(step);
                typeChessman.name=step;
                if(step.find('.')==std::string::npos) typeChessman.texture.loadFromFile("Grafika/Figury/"+step+".png");
                else if(typeChessman.texture.loadFromFile("Grafika/Figury_wlasne/"+step));
                else{
                    std::wstring filePath = L"Grafika/Figury_własne/";
                    filePath+=std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>>().from_bytes(step);
                    std::wifstream File(filePath.data(), std::ios::binary);
                    if(File) typeChessman.texture.loadFromMemory(&File.seekg(0, std::ios::beg),File.tellg()),File.close();
                }
                vec.emplace_back(typeChessman);
            }
            SecondFile.close();
        }
        return vec;
    }
    bool operator==(const sf::String &name){
        return this->name==name;
    }

private:
    TypeChessman(){}

};

#endif // TYPECHESSMAN_H
