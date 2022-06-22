#ifndef EX4_BATTLECARD_H
#define EX4_BATTLECARD_H

#include "Card.h"

class BattleCard : public Card{

public:
    BattleCard(std::string name);
    virtual void playerLost(Player& player) const = 0;
    virtual void playerWon(Player& player) const = 0;
    virtual bool fightResult(Player& player) const = 0;
 };
#endif //EX4_BATTLECARD_H
