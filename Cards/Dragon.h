#ifndef EX4_Dragon_H
#define EX4_Dragon_H

#include "Card.h"

static int const dragonForce = 25;
static int const dragonLoot = 1000;

class Dragon : public Card {

public:
    Dragon();

    void applyEncounter(Player& player) const override;
    void printInfo(std::ostream &out) const override;

    Dragon(const Dragon&) = default;
    ~Dragon() = default;
    Dragon& operator=(const Dragon& other) = default;
};


#endif //EX4_Dragon_H
