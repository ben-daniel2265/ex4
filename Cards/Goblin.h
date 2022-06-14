#ifndef EX4_Goblin_H
#define EX4_Goblin_H

#include "Card.h"

class Goblin : public Card {
    static int const goblin_force = 6;
    static int const goblin_loot = 2;
    static int const goblin_damage = 10;

public:
    Goblin(std::string name);

    void applyEncounter(Player& player) const override;
    void printInfo(std::ostream &out) const override;

    Goblin(const Goblin&) = default;
    ~Goblin() = default;
    Goblin& operator=(const Goblin& other) = default;
};


#endif //EX4_Card_H
