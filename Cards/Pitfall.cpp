#ifndef EX4_Pitfall_Source
#define EX4_Pitfall_Source

#include "Pitfall.h"


Pitfall::Pitfall() : Card("Pitfall")
{}

void Pitfall::applyEncounter(Player& player) const
{
    if(player.getJob() != "Rogue"){
        player.damage(damageAmount);
        printPitfallMessage(false);
    }
    else{
        printPitfallMessage(true);
    }
}

void Pitfall::printInfo(std::ostream &out) const
{
    printCardDetails(out, "Pitfall");
}


#endif //EX4_Dragon_Source