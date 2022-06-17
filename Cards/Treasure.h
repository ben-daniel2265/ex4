#ifndef EX4_Treasure_H
#define EX4_Treasure_H

#include "Card.h"

class Treasure : public Card {
    static int const coin_amount = 10;

public:
    Treasure();

    void applyEncounter(Player& player) const override;
    void printInfo(std::ostream &out) const override;

    Treasure(const Treasure&) = default;
    ~Treasure() = default;
    Treasure& operator=(const Treasure& other) = default;
};


#endif //EX4_Treasure_H
