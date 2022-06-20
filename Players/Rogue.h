#ifndef HW4_Rogue
#define HW4_Rogue

#include "Player.h"


class Rogue : public Player {
    public:
    Rogue(std::string name, int baseMaxHP = BASE_HP, int baseForce = BASE_ATTACK);

    void addCoins(int coinAmount) override;
    std::string getJob() const override;
};


#endif // HW4_Rogue 