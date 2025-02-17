#ifndef HW4_WIZARD_SOURCE
#define HW4_WIZARD_SOURCE

#include "Wizard.h"


Wizard::Wizard(std::string name, int baseMaxHP, int baseForce) : 
    Player(name, baseMaxHP, baseForce){}

void Wizard::heal(int healAmount)
{
    Player::heal(healAmount*2);
}

std::string Wizard::getJob() const
{
    return "Wizard";
}

#endif // HW4_WIZARD_SOURCE 