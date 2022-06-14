#ifndef HW4_ROUGE
#define HW4_ROUGE

#include "Player.h"


class Rouge : public Player {
    public:
    Rouge(std::string name, int baseMaxHP = BASE_HP, int baseForce = BASE_ATTACK);

    void addCoins(int coinAmount) override;
};


#endif // HW4_ROUGE 