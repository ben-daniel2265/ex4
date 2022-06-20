#ifndef EX4_Fairy_H
#define EX4_Fairy_H

#include "Card.h"

static int const healAmount = 10;

class Fairy : public Card {


public:
    Fairy();

    void applyEncounter(Player& player) const override;
    void printInfo(std::ostream &out) const override;

    Fairy(const Fairy&) = default;
    ~Fairy() = default;
    Fairy& operator=(const Fairy& other) = default;
};


#endif //EX4_Fairy_H
