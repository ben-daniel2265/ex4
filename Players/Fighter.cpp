#ifndef HW4_FIGHTER_SOURCE
#define HW4_FIGHTER_SOURCE

#include "Fighter.h"


Fighter::Fighter(std::string name, int baseMaxHP, int baseForce) : 
    Player(name, baseMaxHP, baseForce){}

int Fighter::getAttackStrength() const
{
    return Player::getAttackStrength()*2 - Player::getLevel();
}

std::string Fighter::getJob() const
{
    return "Fighter";
}

#endif // HW4_FIGHTER_SOURCE 