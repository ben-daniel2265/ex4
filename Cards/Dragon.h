#ifndef EX4_Dragon_H
#define EX4_Dragon_H

#include "Card.h"

class Dragon : public Card {
    static int const dragon_force = 25;
    static int const dragon_loot = 1000;

public:
    Dragon();

    void applyEncounter(Player& player) const override;
    void printInfo(std::ostream &out) const override;

    Dragon(const Dragon&) = default;
    ~Dragon() = default;
    Dragon& operator=(const Dragon& other) = default;
};


#endif //EX4_Dragon_H
