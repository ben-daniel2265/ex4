#ifndef HW4_Rogue_SOURCE
#define HW4_Rogue_SOURCE

#include "Rogue.h"


Rogue::Rogue(std::string name, int baseMaxHP, int baseForce) : 
    Player(name, baseMaxHP, baseForce){}

void Rogue::addCoins(int coinAmount)
{
    Player::addCoins(coinAmount*2);
}

std::string Rogue::getJob() const
{
    return "Rogue";
}



#endif // HW4_Rogue_SOURCE 