#ifndef EX4_Vampire_H
#define EX4_Vampire_H

#include "BattleCard.h"

static int const vampireForce = 10;
static int const vampireDamage = 10;
static int const vampireLoot = 2;

class Vampire : public BattleCard {

public:
    Vampire();

    void applyEncounter(Player& player) const override;
    void printInfo(std::ostream &out) const override;
    void playerLost(Player& player) const override;
    bool fightResult(Player& player) const override;


    Vampire(const Vampire&) = default;
    ~Vampire() = default;
    Vampire& operator=(const Vampire& other) = default;
};


#endif //EX4_Vampire_H
