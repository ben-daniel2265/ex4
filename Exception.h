#ifndef Exception_H
#define Exception_H

class DeckFileNotFound : public std::exception
{
    public:
    const char* what() const noexcept override{
        return "Deck File Error: File not found";
    }
};


class DeckFileFormatError : public std::exception
{
    std::string result;

    public:
    DeckFileFormatError(int line) 
    {
        this->result = "Deck File Error: File format error in line " + std::to_string(line);
    };
    const char* what() const noexcept override{
        return this->result.c_str();
    }
};



class DeckFileInvalidSize : public std::exception
{
    public:
    const char* what() const noexcept override{
        return "Deck File Error: Deck size is invalid";
    }
};

#endif