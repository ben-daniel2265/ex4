#ifndef EX4_Dragon_Source
#define EX4_Dragon_Source

#include "Dragon.h"


Dragon::Dragon() : BattleCard("Dragon")
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

void Dragon::playerLost(Player&player) const
{
    player.knockOut();
    printLossBattle(player.getName(), "Dragon");
}

bool Dragon::fightResult(Player& player) const
{
    return player.getAttackStrength() >= dragonForce;
}

void Dragon::printInfo(std::ostream &out) const
{
    printCardDetails(out, "Dragon");
    printMonsterDetails(out, dragonForce, 0, dragonLoot, true);
    printEndOfCardDetails(out);
}


#endif //EX4_Dragon_Source