#ifndef BASICLOADFILECLASS_H
#define BASICLOADFILECLASS_H
#include <SFML/System/FileInputStream.hpp>
#include <Szachy/HelpClass/RenderWindow.h>
#include <fstream>
#include <SFML/Config.hpp>
#include <SFML/System/Export.hpp>
class BasicLoadFileClass : public std::fstream, public sf::FileInputStream
{

public:
    BasicLoadFileClass(const std::wstring &string){
        wchar_t* wcharArray = new wchar_t[string.length() + 1];
        std::wcscpy(wcharArray, string.c_str());
        std::fstream File(wcharArray,std::ios::in);
        swap(File);
        delete[] wcharArray;
        File.close();
    }
    ~BasicLoadFileClass(){
        if(is_open())close();
    }
    //bool open(std::wstring &filename);



};

#endif // BASICLOADFILECLASS_H
