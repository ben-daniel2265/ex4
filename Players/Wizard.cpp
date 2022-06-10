#ifndef HW4_WIZARD_SOURCE
#define HW4_WIZARD_SOURCE

#include "Wizard.h"


Wizard::Wizard(const char* name, int baseMaxHP = BASE_HP, int baseForce = BASE_ATTACK) : 
    Player(name, baseMaxHP, baseForce){}

void Wizard::heal(int healAmount)
{
    Player::addCoins(healAmount*2);
}



#endif // HW4_WIZARD_SOURCE 