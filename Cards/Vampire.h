#ifndef EX4_Vampire_H
#define EX4_Vampire_H

#include "Card.h"

class Vampire : public Card {
    static int const vampire_force = 10;
    static int const vampire_damage = 10;
    static int const vampire_loot = 2;

public:
    Vampire();

    void applyEncounter(Player& player) const override;
    void printInfo(std::ostream &out) const override;

    Vampire(const Vampire&) = default;
    ~Vampire() = default;
    Vampire& operator=(const Vampire& other) = default;
};


#endif //EX4_Vampire_H
