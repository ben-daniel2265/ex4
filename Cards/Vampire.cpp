#ifndef EX4_Vampire_Source
#define EX4_Vampire_Source

#include "Vampire.h"


Vampire::Vampire() : BattleCard("Vampire")
{}

void Vampire::applyEncounter(Player& player) const
{
    if(player.getAttackStrength() >= vampireForce){
        player.levelUp();
        player.addCoins(vampireLoot);
        printWinBattle(player.getName(), "Vampire");
    }
    else{
        player.damage(vampireDamage);
        player.debuff(1);
        printLossBattle(player.getName(), "Vampire");
    }
}

void Vampire::playerLost(Player &player) const {
    player.damage(vampireDamage);
    player.debuff(1);
    printLossBattle(player.getName(), "Vampire");
}

void Vampire::playerWon(Player &player) const {
    player.addCoins(vampireLoot);
    printWinBattle(player.getName(), "Vampire");
}

bool Vampire::fightResult(Player& player) const
{
    return player.getAttackStrength() >= vampireForce;
}

void Vampire::printInfo(std::ostream &out) const
{
    printCardDetails(out, "Vampire");
    printMonsterDetails(out, vampireForce, vampireDamage, vampireLoot, false);
    printEndOfCardDetails(out);
}


#endif //EX4_Vampire_Source