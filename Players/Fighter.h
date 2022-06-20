#ifndef HW4_FIGHTER
#define HW4_FIGHTER

#include "Player.h"


class Fighter : public Player {
    public:
    Fighter(std::string name, int baseMaxHP = BASE_HP, int baseForce = BASE_ATTACK);

    int getAttackStrength() const override;
    std::string getJob() const override;
};


#endif // HW4_FIGHTER 