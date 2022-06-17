#ifndef EX4_Treasure_Source
#define EX4_Treasure_Source

#include "Treasure.h"


Treasure::Treasure() : Card("Treasure")
{}

void Treasure::applyEncounter(Player& player) const
{
    player.addCoins(coin_amount);
    printTreasureMessage();
}

void Treasure::printInfo(std::ostream &out) const
{
    printCardDetails(out, "Treasure");
}


#endif //EX4_Dragon_Source