#ifndef EX4_Goblin_H
#define EX4_Goblin_H

#include "Card.h"

class Goblin : public Card {
    static int const goblinForce = 6;
    static int const goblinLoot = 2;
    static int const goblinDamage = 10;

public:
    Goblin();

    void applyEncounter(Player& player) const override;
    void printInfo(std::ostream &out) const override;

    Goblin(const Goblin&) = default;
    ~Goblin() = default;
    Goblin& operator=(const Goblin& other) = default;
};


#endif //EX4_Card_H
