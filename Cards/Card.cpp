#ifndef EX2_Card_SOURCE
#define EX2_Card_SOURCE

#include "Card.h"

Card::Card(std::string name): m_name(name)
{}


std::ostream& operator<<(std::ostream &out, Card& card)
{
    card.printInfo(out);
    return out;
}


#endif //EX2_Card_SOURCE