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
    std::string result;

    public:
    DeckFileFormatError(int line) 
    {
        this->result = "Deck File Error: File format error in line " + std::to_string(line);
    };
    const char* what() const{
        return this->result.data();
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