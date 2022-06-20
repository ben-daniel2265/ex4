#ifndef HW4_WIZARD
#define HW4_WIZARD

#include "Player.h"


class Wizard : public Player {
    public:
    Wizard(std::string name, int baseMaxHP = BASE_HP, int baseForce = BASE_ATTACK);

    void heal(int healAmount) override;
    std::string getJob() const override;
};


#endif // HW4_ROUGE 