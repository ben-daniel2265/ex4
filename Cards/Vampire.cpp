#ifndef EX4_Vampire_Source
#define EX4_Vampire_Source

#include "Vampire.h"


Vampire::Vampire() : Card("Vampire")
{}

void Vampire::applyEncounter(Player& player) const
{
    if(player.getAttackStrength() >= vampire_force){
        player.levelUp();
        player.addCoins(vampire_loot);
        printWinBattle(player.getName(), "Vampire");
    }
    else{
        player.damage(vampire_damage);
        player.debuff(1);
        printLossBattle(player.getName(), "Vampire");
    }
}

void Vampire::printInfo(std::ostream &out) const
{
    printCardDetails(out, "Vampire");
    printMonsterDetails(out, vampire_force, vampire_damage, vampire_loot, false);
    printEndOfCardDetails(out);
}


#endif //EX4_Vampire_Source