#ifndef EX4_Vampire_Source
#define EX4_Vampire_Source

#include "Vampire.h"


Vampire::Vampire() : Card("Vampire")
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

void Vampire::printInfo(std::ostream &out) const
{
    printCardDetails(out, "Vampire");
    printMonsterDetails(out, vampireForce, vampireDamage, vampireLoot, false);
    printEndOfCardDetails(out);
}


#endif //EX4_Vampire_Source