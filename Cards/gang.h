#ifndef EX4_Gang_H
#define EX4_Gang_H

#include "Card.h"
#include "BattleCard.h"
#include <queue>


class Gang : public Card {
    std::queue<std::unique_ptr<BattleCard>> m_gang;
    int gangSize;

public:
    Gang();
    void applyEncounter(Player& player);
    void printInfo(std::ostream &out) const override;
    void addMember(BattleCard* battlecard);
};


#endif //EX4_Gang_H
