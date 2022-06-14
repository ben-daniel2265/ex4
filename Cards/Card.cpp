#ifndef EX4_Card_SOURCE
#define EX4_Card_SOURCE

#include "Card.h"

Card::Card(std::string name): m_name(name)
{}


std::ostream& operator<<(std::ostream &out, Card& card)
{
    card.printInfo(out);
    return out;
}


#endif //EX4_Card_SOURCE