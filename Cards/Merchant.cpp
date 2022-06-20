#ifndef EX4_Merchant_Source
#define EX4_Merchant_Source

#include "Merchant.h"


Merchant::Merchant() : Card("Merchant")
{}

void Merchant::applyEncounter(Player& player) const
{
    std::string choice;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());

    std::getline(std::cin, choice);

    while(choice != "0" && choice != "1" && choice != "2"){
        printInvalidInput();
        std::getline(std::cin, choice);
    }

    if(choice == "1"){
        if(player.pay(hpPotionCost)){
            player.heal(hpPotionAddAmount);
            printMerchantSummary(std::cout, player.getName(), 1, hpPotionCost);
        }
        else{
            printMerchantInsufficientCoins(std::cout);
        }
    }
    else if(choice == "2"){
        if(player.pay(forceBoostPotionCost)){
            player.buff(forceBoostPotionAddAmount);
            printMerchantSummary(std::cout, player.getName(), 2, forceBoostPotionCost);
        }
        else{
            printMerchantInsufficientCoins(std::cout);
        }
    }
    else{
        printMerchantSummary(std::cout, player.getName(), 0, 0);
    }
}

void Merchant::printInfo(std::ostream &out) const
{
    printCardDetails(out, "Merchant");
    printEndOfCardDetails(out);
}


#endif //EX4_Merchant_Source