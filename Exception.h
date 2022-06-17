#ifndef Exception_H
#define Exception_H

#include <ostream>

class DeckFileNotFound
{
    public:
    std::string what(){
        return "Deck File Error: File not found";
    }
};


class DeckFormatError
{
    int line;

    public:
    DeckFormatError(int line) : line(line) {};
    std::string what(){
        return "Deck File Error: File format error in line " + std::to_string(line);
    }
};



class DeckFileInvalidSize
{
    public:
    std::string what(){
        return "Deck File Error: Deck size is invalid";
    }
};

#endif