#ifndef EX4_Pitfall_H
#define EX4_Pitfall_H

#include "Card.h"

static int const damageAmount = 10;

class Pitfall : public Card {

public:
    Pitfall();

    void applyEncounter(Player& player) const override;
    void printInfo(std::ostream &out) const override;

    Pitfall(const Pitfall&) = default;
    ~Pitfall() = default;
    Pitfall& operator=(const Pitfall& other) = default;
};


#endif //EX4_Pitfall_H
