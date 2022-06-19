#ifndef Exception_H
#define Exception_H

#include <ostream>

class DeckFileNotFound
{
    public:
    const char* what() const{
        return "Deck File Error: File not found";
    }
};


class DeckFileFormatError
{
    int line;

    public:
    DeckFileFormatError(int line) : line(line) {};
    const char* what() const{
        return ("Deck File Error: File format error in line " + std::to_string(line)).c_str();
    }
};



class DeckFileInvalidSize
{
    public:
    const char* what() const{
        return "Deck File Error: Deck size is invalid";
    }
};

#endif