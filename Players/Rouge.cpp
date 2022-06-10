#ifndef HW4_ROUGE_SOURCE
#define HW4_ROUGE_SOURCE

#include "Rouge.h"


Rouge::Rouge(const char* name, int baseMaxHP = BASE_HP, int baseForce = BASE_ATTACK) : 
    Player(name, baseMaxHP, baseForce){}

void Rouge::addCoins(int coinAmount)
{
    Player::addCoins(coinAmount*2);
}



#endif // HW4_ROUGE_SOURCE 