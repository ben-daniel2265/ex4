#ifndef EX4_Merchant_H
#define EX4_Merchant_H

#include "Card.h"

static int const hpPotionCost = 5;
static int const forceBoostPotionCost = 10;
static int const hpPotionAddAmount = 1;
static int const forceBoostPotionAddAmount = 1;

class Merchant : public Card {
    
public:
    Merchant();

    void applyEncounter(Player& player) const override;
    void printInfo(std::ostream &out) const override;

    Merchant(const Merchant&) = default;
    ~Merchant() = default;
    Merchant& operator=(const Merchant& other) = default;
};


#endif //EX4_Merchant_H
