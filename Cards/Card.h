#ifndef EX4_Card_H
#define EX4_Card_H

#include "../Players/Player.h"
#include "../utilities.h"
#include <ostream>

class Card {
public:
    Card(std::string name);

    virtual void applyEncounter(Player& player) const;
    virtual void printInfo(std::ostream &out) const;
    friend std::ostream& operator<<(std::ostream &out, Card& card);

    Card(const Card&) = default;
    ~Card() = default;
    Card& operator=(const Card& other) = default;

private:
    std::string m_name;
};


#endif //EX4_Card_H
