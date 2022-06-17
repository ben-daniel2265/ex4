#ifndef EX4_Pitfall_Source
#define EX4_Pitfall_Source

#include "Barfight.h"


Barfight::Barfight() : Card("Barfight")
{}

void Barfight::applyEncounter(Player& player) const
{
    if(player.getJob() != "Fighter"){
        player.damage(damage_amount);
        printBarfightMessage(false);
    }
    else{
        printBarfightMessage(true);
    }
}

void Barfight::printInfo(std::ostream &out) const
{
    printCardDetails(out, "Barfight");
}


#endif //EX4_Dragon_Source