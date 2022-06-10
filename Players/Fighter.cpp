#ifndef HW4_FIGHTER_SOURCE
#define HW4_FIGHTER_SOURCE

#include "Fighter.h"


Fighter::Fighter(const char* name, int baseMaxHP = BASE_HP, int baseForce = BASE_ATTACK) : 
    Player(name, baseMaxHP, baseForce){}

int Fighter::getAttackStrength() const
{
    return Player::getAttackStrength()*2 - Player::getLevel();
}



#endif // HW4_FIGHTER_SOURCE 