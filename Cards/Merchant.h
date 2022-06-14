#ifndef EX4_Merchant_H
#define EX4_Merchant_H

#include "Card.h"

class Merchant : public Card {
    static int const hp_potion_cost = 5;
    static int const force_boost_potion_cost = 10;
    static int const hp_potion_add_amount = 1;
    static int const force_boost_potion_add_amount = 1;
    
public:
    Merchant(std::string name);

    void applyEncounter(Player& player) const override;
    void printInfo(std::ostream &out) const override;

    Merchant(const Merchant&) = default;
    ~Merchant() = default;
    Merchant& operator=(const Merchant& other) = default;
};


#endif //EX4_Merchant_H
