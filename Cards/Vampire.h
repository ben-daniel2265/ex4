#ifndef EX4_Goblin_H
#define EX4_Goblin_H

#include "Card.h"

class Vampire : public Card {
    static int const vampire_force = 10;
    static int const vampire_damage = 10;
    static int const vampire_loot = 2;

public:
    Vampire(std::string name);

    void applyEncounter(Player& player) const override;
    void printInfo(std::ostream &out) const override;

    Vampire(const Vampire&) = default;
    ~Vampire() = default;
    Vampire& operator=(const Vampire& other) = default;
};


#endif //EX4_Card_H
