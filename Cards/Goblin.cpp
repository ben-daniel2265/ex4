#ifndef EX4_Goblin_Source
#define EX4_Goblin_Source

#include "Goblin.h"


Goblin::Goblin() : BattleCard("Goblin")
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

void Goblin::playerLost(Player &player) const {
    player.damage(goblinDamage);
    printLossBattle(player.getName(), "Goblin");
}

bool Goblin::fightResult(Player& player) const
{
    return player.getAttackStrength() >= goblinForce;
}

void Goblin::printInfo(std::ostream &out) const
{
    printCardDetails(out, "Goblin");
    printMonsterDetails(out, goblinForce, goblinDamage, goblinLoot, false);
    printEndOfCardDetails(out);
}


#endif //EX4_Goblin_Source