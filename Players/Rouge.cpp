#ifndef HW4_ROUGE_SOURCE
#define HW4_ROUGE_SOURCE

#include "Rouge.h"


Rouge::Rouge(std::string name, int baseMaxHP = BASE_HP, int baseForce = BASE_ATTACK) : 
    Player(name, "Rogue", baseMaxHP, baseForce){}

void Rouge::addCoins(int coinAmount)
{
    Player::addCoins(coinAmount*2);
}



#endif // HW4_ROUGE_SOURCE 