#ifndef EX4_Barfight_Source
#define EX4_Barfight_Source

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
    printEndOfCardDetails(out);
}


#endif //EX4_Dragon_Source