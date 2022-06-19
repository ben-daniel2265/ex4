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
        if(player.pay(hp_potion_cost)){
            player.heal(hp_potion_add_amount);
            printMerchantSummary(std::cout, player.getName(), 1, hp_potion_cost);
        }
        else{
            printMerchantInsufficientCoins(std::cout);
        }
    }
    else if(choice == "2"){
        if(player.pay(force_boost_potion_cost)){
            player.buff(force_boost_potion_add_amount);
            printMerchantSummary(std::cout, player.getName(), 2, force_boost_potion_cost);
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