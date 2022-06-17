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

    }
    if(line_num < 5){
        throw DeckFileInvalidSize();
    }
}
    
void Mtmchkin::playRound()
{

}

void Mtmchkin::printLeaderBoard() const
{

}

bool Mtmchkin::isGameOver() const
{

}

int Mtmchkin::getNumberOfRounds() const
{

}




#endif /* MTMCHKIN_Source */
