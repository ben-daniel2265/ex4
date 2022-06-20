#ifndef EX4_Dragon_Source
#define EX4_Dragon_Source

#include "Dragon.h"


Dragon::Dragon() : Card("Dragon")
{}

void Dragon::applyEncounter(Player& player) const
{
    if(player.getAttackStrength() >= dragonForce){
        player.levelUp();
        player.addCoins(dragonLoot);
        printWinBattle(player.getName(), "Dragon");
    }
    else{
        player.knockOut();
        printLossBattle(player.getName(), "Dragon");
    }
}

void Dragon::printInfo(std::ostream &out) const
{
    printCardDetails(out, "Dragon");
    printMonsterDetails(out, dragonForce, 0, dragonLoot, true);
    printEndOfCardDetails(out);
}


#endif //EX4_Dragon_Source