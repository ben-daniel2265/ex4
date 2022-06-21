//
// Created by Yonatan Elbaz on 21/06/2022.
//

#ifndef EX4_Gang_Source
#define EX4_Gang_Source

#include "Gang.h"

Gang::Gang() : Card("Gang"), gangSize(0)
{}

void Gang::applyEncounter(Player& player)
{
    bool lost = false;
    for(int i = 0; i < this->gangSize; i++){
        std::unique_ptr<BattleCard> currentCard;
        currentCard = move(this->m_gang.front());
        if(!lost){
            currentCard.get()->applyEncounter(player);
            if(!currentCard.get()->fightResult(player)){
                lost = true;
            }
            currentCard = move(this->m_gang.front());

            this->m_gang.pop();
            this->m_gang.push(move(currentCard));
        }
        else{
            currentCard.get()->playerLost(player);
        }
    }
}

void Gang::addMember(BattleCard* battlecard)
{
    this->m_gang.push(std::unique_ptr<BattleCard>(battlecard));
    this->gangSize++;
}

void Gang::printInfo(std::ostream &out) const
{
    printCardDetails(out, "Gang");
    printEndOfCardDetails(out);
}


#endif //EX4_Gang_Source