#ifndef EX4_Goblin_Source
#define EX4_Goblin_Source

#include "Goblin.h"


Goblin::Goblin() : Card("Goblin")
{}

void Goblin::applyEncounter(Player& player) const
{
    if(player.getAttackStrength() >= goblinForce){
        player.levelUp();
        player.addCoins(goblinLoot);
        printWinBattle(player.getName(), "Goblin");
    }
    else{
        player.damage(goblinDamage);
        printLossBattle(player.getName(), "Goblin");
    }
}

void Goblin::printInfo(std::ostream &out) const
{
    printCardDetails(out, "Goblin");
    printMonsterDetails(out, goblinForce, goblinDamage, goblinLoot, false);
    printEndOfCardDetails(out);
}


#endif //EX4_Goblin_Source