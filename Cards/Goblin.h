#ifndef EX4_Goblin_H
#define EX4_Goblin_H

#include "BattleCard.h"

static int const goblinForce = 6;
static int const goblinLoot = 2;
static int const goblinDamage = 10;

class Goblin : public BattleCard {

public:
    Goblin();

    void applyEncounter(Player& player) const override;
    void printInfo(std::ostream &out) const override;
    void playerLost(Player& player) const override;
    void playerWon(Player& player) const override;
    bool fightResult(Player& player) const override;

    Goblin(const Goblin&) = default;
    ~Goblin() = default;
    Goblin& operator=(const Goblin& other) = default;
};


#endif //EX4_Goblin_H
