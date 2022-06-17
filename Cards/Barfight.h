#ifndef EX4_Barfight_H
#define EX4_Barfight_H

#include "Card.h"

class Barfight : public Card {
    static int const damage_amount = 10;

public:
    Barfight();

    void applyEncounter(Player& player) const override;
    void printInfo(std::ostream &out) const override;

    Barfight(const Barfight&) = default;
    ~Barfight() = default;
    Barfight& operator=(const Barfight& other) = default;
};


#endif //EX4_Fairy_H
