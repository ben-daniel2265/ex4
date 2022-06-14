#ifndef EX4_Goblin_Source
#define EX4_Goblin_Source

#include "Goblin.h"


Goblin::Goblin(std::string name) : Card(name)
{}

void Goblin::applyEncounter(Player& player) const
{
    if(player.getAttackStrength() >= goblin_force){
        player.levelUp();
        player.addCoins(goblin_loot);
        printWinBattle(player.)
    }
    else{
        player.damage(goblin_damage);
    }
}

void Goblin::printInfo(std::ostream &out) const
{
    printCardDetails(out, "Goblin");
    printMonsterDetails(out, 6, 10, 2, false);
    printEndOfCardDetails(out);
}


#endif //EX4_Goblin_Source