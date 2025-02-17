#ifndef EX4_Fairy_Source
#define EX4_Fairy_Source

#include "Fairy.h"


Fairy::Fairy() : Card("Fairy")
{}

void Fairy::applyEncounter(Player& player) const
{
    if(player.getJob() == "Wizard"){
        player.heal(healAmount);
        printFairyMessage(true);
    }
    else{
        printFairyMessage(false);
    }
}

void Fairy::printInfo(std::ostream &out) const
{
    printCardDetails(out, "Fairy");
    printEndOfCardDetails(out);
}


#endif //EX4_Dragon_Source