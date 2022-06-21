#ifndef MTMCHKIN_Source
#define MTMCHKIN_Source 

static int const maxLevel =  10;
static int const maxStringLength = 15;
static int const maxTeamSize = 6;
static int const minTeamSize = 2;

#include "Mtmchkin.h"
#include "Cards/Dragon.h"
#include "Cards/Goblin.h"
#include "Cards/Vampire.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Barfight.h"
#include "Cards/Fairy.h"
#include "Cards/Treasure.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include <fstream>
#include <memory>
#include "Exception.h"


bool validName(std::string const &str) {
    return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") ==
        std::string::npos && str.length() <= maxStringLength;
}

bool validNum(std::string const &str) {
    return str != "" && str.find_first_not_of("0123456789") == std::string::npos;
}

bool isRealJob(std::string const &str) {
    return str == "Wizard" || str == "Fighter" || str == "Rogue";
}

bool isOut(Player &player){
    return player.isKnockedOut() || player.getLevel() == maxLevel;
}


Card* getTypeCard(std::string card, int lineNum){
    if(card == "Dragon"){
        return new Dragon();
    }
    else if(card == "Goblin"){
        return new Goblin();
    }
    else if(card == "Vampire"){
        return new Vampire();
    }
    else if(card == "Merchant"){
        return new Merchant();
    }
    else if(card == "Treasure"){
        return new Treasure();
    }
    else if(card == "Pitfall"){
        return new Pitfall();
    }
    else if(card == "Barfight"){
       return new Barfight();
    }
    else if(card == "Fairy"){
        return new Fairy();
    }
    else{
        throw DeckFileFormatError(lineNum);
    }
}

Player* getTypePlayer(std::string playerName, std::string playerClass){
    if(playerClass == "Wizard"){
        return new Wizard(playerName);
    }
    else if(playerClass == "Rogue"){
        return new Rogue(playerName);
    }
    else{
        return new Fighter(playerName);
    }
}


void getNumOfPlayers(int &numOfPlayers){
    std::string numInput;
    getline(std::cin, numInput);
    if(validNum(numInput)){
        numOfPlayers = std::stoi(numInput);
    }

    while(numOfPlayers < minTeamSize || numOfPlayers > maxTeamSize){
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        getline(std::cin, numInput);
        if(validNum(numInput)){
            numOfPlayers = std::stoi(numInput);
        }  
    }
}


Mtmchkin::Mtmchkin(const std::string fileName) : m_round(0), m_out_players(0)
{
    printStartGameMessage();
    std::ifstream file(fileName);
    if(!file){
        throw DeckFileNotFound();
    }

    std::string line;
    int line_num = 0;
    while(getline(file, line)){
        this->m_deck.push(std::unique_ptr<Card>(getTypeCard(line, ++line_num)));
    }
    if(line_num < 5){
        throw DeckFileInvalidSize();
    }

    int numOfPlayers = 0;
    std::string nameAndJob;
    std::string name;
    std::string job;

    printEnterTeamSizeMessage();

    getNumOfPlayers(numOfPlayers);

    this->m_player_num = numOfPlayers;

    printInsertPlayerMessage();

    while(numOfPlayers > 0 && getline(std::cin, nameAndJob)){
        name = nameAndJob.substr(0, nameAndJob.find(" "));
        job = nameAndJob.substr(nameAndJob.find(" ") + 1);;

        if(validName(name) && isRealJob(job)){
            this->m_players.push_back(std::unique_ptr<Player>(getTypePlayer(name, job)));
            numOfPlayers--;
            if(numOfPlayers > 0){
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

                if(this->m_players.at(i).get()->getLevel() == maxLevel){
                    int place = i;
                    while(place >= 1 && m_players.at(place - 1)->getLevel() != maxLevel){
                        std::swap(m_players[place], m_players[place - 1]);
                        place--;
                    }                    //addWinner(this->m_players, i);
                }
                else if (this->m_players.at(i).get()->isKnockedOut()) {
                    int place = i;
                    if(place < (int)(m_players.size() - 1) && !m_players.at(place + 1)->isKnockedOut()){
                        i--;
                    }
                    while(place < (int)(m_players.size() - 1) && !m_players.at(place + 1)->isKnockedOut()){
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
