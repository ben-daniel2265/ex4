#ifndef MTMCHKIN_Source
#define MTMCHKIN_Source

#include "Mtmchkin.h"
#include "Cards\Card.h"
#include "Cards\Dragon.h"
#include "Cards\Goblin.h"
#include "Cards\Vampire.h"
#include "Cards\Merchant.h"
#include "Cards\Pitfall.h"
#include "Cards\Barfight.h"
#include "Cards\Fairy.h"
#include "Cards\Treasure.h"
#include "Players\player.h"
#include "Players\Rouge.h"
#include "Players\Wizard.h"
#include "Players\Fighter.h"
#include <fstream>
#include <memory>
#include "Exception.h"


bool validName(std::string const &str) {
    return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") ==
        std::string::npos && str.length() <= 15;
}

bool isRealJob(std::string const &str) {
    return str == "Wizard" || str == "Fighter" || str == "Rouge";
}


Mtmchkin::Mtmchkin(const std::string fileName)
{
    std::ifstream file(fileName);
    if(!file){
        throw DeckFileNotFound();
    }

    char line[256];
    int line_num = 0;
    while(file.getline(line, sizeof(line))){
        line_num++;
        if(!strcmp(line, "Dragon")){
            this->m_deck.push(std::unique_ptr<Card>(new Dragon()));
        }
        else if(!strcmp(line, "Goblin")){
            this->m_deck.push(std::unique_ptr<Card>(new Goblin()));
        }
        else if(!strcmp(line, "Vampire")){
            this->m_deck.push(std::unique_ptr<Card>(new Vampire()));
        }
        else if(!strcmp(line, "Merchant")){
            this->m_deck.push(std::unique_ptr<Card>(new Merchant()));
        }
        else if(!strcmp(line, "Treasure")){
            this->m_deck.push(std::unique_ptr<Card>(new Treasure()));
        }
        else if(!strcmp(line, "Pitfall")){
            this->m_deck.push(std::unique_ptr<Card>(new Pitfall()));
        }
        else if(!strcmp(line, "Barfight")){
            this->m_deck.push(std::unique_ptr<Card>(new Barfight()));
        }
        else if(!strcmp(line, "Fairy")){
            this->m_deck.push(std::unique_ptr<Card>(new Fairy()));
        }
        else{
            throw DeckFormatError(line_num);
        }
        this->m_deck.front()->printInfo(std::cout);
    }
    if(line_num < 5){
        throw DeckFileInvalidSize();
    }

    printStartGameMessage();

    int num_of_players = 0;
    std::string name;
    std::string job;
    printEnterTeamSizeMessage();

    std::cin >> num_of_players;

    while(num_of_players < 2 || num_of_players > 6){
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        std::cin >> num_of_players;    
    }

    printInsertPlayerMessage();
    while(num_of_players > 0){
        std::cin >> name;
        std::cin >> job;

        if(validName(name) && isRealJob(job)){
            if(job == "Wizard"){
                this->m_players.push(std::unique_ptr<Player>(new Wizard(name)));
            }
            else if(job == "Rouge"){
                this->m_players.push(std::unique_ptr<Player>(new Rouge(name)));
            }
            else if(job == "Fighter"){
                this->m_players.push(std::unique_ptr<Player>(new Fighter(name)));
            }
            num_of_players--;
            if(num_of_players > 0){
                printInsertPlayerMessage();
            }
        }
        else if(!validName(name)){
            printInvalidName();
        }
        else{
            printInvalidClass();
        }

    }
}
    
void Mtmchkin::playRound()
{
    printRoundStartMessage();
    
}

void Mtmchkin::printLeaderBoard() const
{

}

bool Mtmchkin::isGameOver() const
{
    return true;
}

int Mtmchkin::getNumberOfRounds() const
{
    return 1;
}




#endif /* MTMCHKIN_Source */
