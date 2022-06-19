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
#include "Players\Rogue.h"
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
    return str == "Wizard" || str == "Fighter" || str == "Rogue";
}

bool isOut(Player &player){
    return player.isKnockedOut() || player.getLevel() == 10;
}

void addWinner(std::vector<std::unique_ptr<Player>> players, int place){
    while(place != 0 && players.at(place - 1)->getLevel() != 10){
        std::swap(players[place], players[place - 1]);
        place--;
    }
}

void addLoser(std::vector<std::unique_ptr<Player>> players, int place){
    while(place < players.size() - 1 && !players.at(place + 1)->isKnockedOut()){
        std::swap(players[place], players[place - 1]);
        place++;
    }
}

Mtmchkin::Mtmchkin(const std::string fileName) : m_round(0), m_out_players(0)
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
            throw DeckFileFormatError(line_num);
        }
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

    this->m_player_num = num_of_players;

    printInsertPlayerMessage();
    while(num_of_players > 0){
        std::cin >> name;
        std::cin >> job;

        if(validName(name) && isRealJob(job)){
            if(job == "Wizard"){
                this->m_players.push_back(std::unique_ptr<Player>(new Wizard(name)));
            }
            else if(job == "Rogue"){
                this->m_players.push_back(std::unique_ptr<Player>(new Rogue(name)));
            }
            else if(job == "Fighter"){
                this->m_players.push_back(std::unique_ptr<Player>(new Fighter(name)));
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
    this->m_round++;
    printRoundStartMessage(this->m_round);
    std::unique_ptr<Card> current_card;

    for(int i = 0; i < m_player_num; i++){
        if(!isOut(*(this->m_players.at(i).get()))){
            current_card = move(this->m_deck.front());

            printTurnStartMessage(this->m_players.at(i)->getName());
            current_card->applyEncounter(*(this->m_players.at(i).get()));
            if(isOut(*(this->m_players.at(i).get()))){
                this->m_out_players++;

                if(this->m_players.at(i).get()->getLevel() == 10){
                    int place = i;
                    while(place >= 1 && m_players.at(place - 1)->getLevel() != 10){
                        std::swap(m_players[place], m_players[place - 1]);
                        place--;
                    }                    //addWinner(this->m_players, i);
                }
                else if (this->m_players.at(i).get()->isKnockedOut()) {
                    int place = i;
                    if(place < m_players.size() - 1 && !m_players.at(place + 1)->isKnockedOut()){
                        i--;
                    }
                    while(place < m_players.size() - 1 && !m_players.at(place + 1)->isKnockedOut()){
                        std::swap(m_players[place], m_players[place + 1]);
                        place++;
                    }
                                //addLoser(this->m_players, i);
                }
            } 
            this->m_deck.pop();
            this->m_deck.push(move(current_card));
        }

    }

    if(isGameOver()){
        printGameEndMessage();
    }
}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    for(int i = 0; i < this->m_player_num; i++){
        printPlayerLeaderBoard(i+1, *(this->m_players.at(i).get()));
    }
}

bool Mtmchkin::isGameOver() const
{
    return this->m_out_players == this->m_player_num;
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_round;
}




#endif /* MTMCHKIN_Source */
