#ifndef EX4_Vampire_H
#define EX4_Vampire_H

#include "Card.h"

static int const vampireForce = 10;
static int const vampireDamage = 10;
static int const vampireLoot = 2;

class Vampire : public Card {

public:
    Vampire();

    void applyEncounter(Player& player) const override;
    void printInfo(std::ostream &out) const override;

    Vampire(const Vampire&) = default;
    ~Vampire() = default;
    Vampire& operator=(const Vampire& other) = default;
};


#endif //EX4_Vampire_H
