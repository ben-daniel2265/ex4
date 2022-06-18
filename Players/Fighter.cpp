#ifndef HW4_FIGHTER_SOURCE
#define HW4_FIGHTER_SOURCE

#include "Fighter.h"


Fighter::Fighter(std::string name, int baseMaxHP, int baseForce) : 
    Player(name,"Fighter", baseMaxHP, baseForce){}

int Fighter::getAttackStrength() const
{
    return Player::getAttackStrength()*2 - Player::getLevel();
}


#endif // HW4_FIGHTER_SOURCE 