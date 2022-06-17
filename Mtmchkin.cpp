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
        else if(!strcmp(line, "Dragon")){
            this->m_deck.push(std::unique_ptr<Card>(new Dragon()));
        }
        else if(!strcmp(line, "Dragon")){
            this->m_deck.push(std::unique_ptr<Card>(new Dragon()));
        }
        else if(!strcmp(line, "Dragon")){
            this->m_deck.push(std::unique_ptr<Card>(new Dragon()));
        }
        else if(!strcmp(line, "Dragon")){
            this->m_deck.push(std::unique_ptr<Card>(new Dragon()));
        }
        else if(!strcmp(line, "Dragon")){
            this->m_deck.push(std::unique_ptr<Card>(new Dragon()));
        }
        else if(!strcmp(line, "Dragon")){
            this->m_deck.push(std::unique_ptr<Card>(new Dragon()));
        }
        else if(!strcmp(line, "Dragon")){
            this->m_deck.push(std::unique_ptr<Card>(new Dragon()));
        }
        else{
            throw DeckFormatError(line_num);
        }

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
