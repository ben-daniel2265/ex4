#ifndef HW4_WIZARD
#define HW4_WIZARD

#include "Player.h"


class Wizard : public Player {
    public:
    Wizard(const char* name, int baseMaxHP = BASE_HP, int baseForce = BASE_ATTACK);

    void heal(int healAmount) override;
};


#endif // HW4_ROUGE 