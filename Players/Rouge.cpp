#ifndef HW4_ROUGE_SOURCE
#define HW4_ROUGE_SOURCE

#include "Rouge.h"


Rouge::Rouge(std::string name, int baseMaxHP, int baseForce) : 
    Player(name, "Rogue", baseMaxHP, baseForce){}

void Rouge::addCoins(int coinAmount)
{
    Player::addCoins(coinAmount*2);
}



#endif // HW4_ROUGE_SOURCE 