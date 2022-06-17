#ifndef EX4_Goblin_Source
#define EX4_Goblin_Source

#include "Goblin.h"


Goblin::Goblin() : Card("Goblin")
{}

void Goblin::applyEncounter(Player& player) const
{
    if(player.getAttackStrength() >= goblin_force){
        player.levelUp();
        player.addCoins(goblin_loot);
        printWinBattle(player.getName(), "Goblin");
    }
    else{
        player.damage(goblin_damage);
        printLossBattle(player.getName(), "Goblin");
    }
}

void Goblin::printInfo(std::ostream &out) const
{
    printCardDetails(out, "Goblin");
    printMonsterDetails(out, goblin_force, goblin_damage, goblin_loot, false);
    printEndOfCardDetails(out);
}


#endif //EX4_Goblin_Source