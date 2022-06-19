#ifndef HW4_Rogue_SOURCE
#define HW4_Rogue_SOURCE

#include "Rogue.h"


Rogue::Rogue(std::string name, int baseMaxHP, int baseForce) : 
    Player(name, "Rogue", baseMaxHP, baseForce){}

void Rogue::addCoins(int coinAmount)
{
    Player::addCoins(coinAmount*2);
}



#endif // HW4_Rogue_SOURCE 