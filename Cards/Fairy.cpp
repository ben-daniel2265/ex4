#ifndef EX4_Fairy_Source
#define EX4_Fairy_Source

#include "Fairy.h"


Fairy::Fairy() : Card("Fairy")
{}

void Fairy::applyEncounter(Player& player) const
{
    if(player.getJob() == "Wizard"){
        player.heal(heal_amount);
        printFairyMessage(true);
    }
    else{
        printFairyMessage(false);
    }
}

void Fairy::printInfo(std::ostream &out) const
{
    printCardDetails(out, "Fairy");
}


#endif //EX4_Dragon_Source