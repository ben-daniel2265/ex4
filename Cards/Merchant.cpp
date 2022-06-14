#ifndef EX4_Merchant_Source
#define EX4_Merchant_Source

#include "Merchant.h"


Merchant::Merchant(std::string name) : Card(name)
{}

void Merchant::applyEncounter(Player& player) const
{
    int choice = -1;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());

    try{
        std::cin >> choice;
    }
    catch(...){}

    while(choice < 0 and 2 < choice){
        printInvalidInput();
        try{
            std::cin >> choice;
        }
        catch(...){}
    }

    if(choice == 1){
        if(player.pay(hp_potion_cost)){
            player.heal(hp_potion_add_amount);
            printMerchantSummary(std::cout, player.getName(), choice, hp_potion_cost);
        }
        else{
            printMerchantInsufficientCoins(std::cout);
        }
    }
    else if(choice == 2){
        if(player.pay(force_boost_potion_cost)){
            player.buff(force_boost_potion_add_amount);
            printMerchantSummary(std::cout, player.getName(), choice, force_boost_potion_cost);
        }
        else{
            printMerchantInsufficientCoins(std::cout);
        }
    }
}

void Merchant::printInfo(std::ostream &out) const
{
    printCardDetails(out, "Merchant");
    printEndOfCardDetails(out);
}


#endif //EX4_Merchant_Source