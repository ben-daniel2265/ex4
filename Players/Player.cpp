#ifndef HW4_PLAYER_source
#define HW4_PLAYER_source

#include "Player.h"
#include "../utilities.h"

#define BASE_HP 100
#define BASE_ATTACK 5


Player::Player(const std::string name, int baseMaxHP, int baseForce)
{
    this->m_name = name;
    this->m_level = 1;
    this->m_force = baseForce > 0 ? baseForce : BASE_ATTACK;
    this->m_maxHP = baseMaxHP > 0 ? baseMaxHP : BASE_HP;
    this->m_HP = baseMaxHP;
    this->m_coins = 10;
}

Player::Player(const Player& player)
{
    this->m_name = player.m_name;
    this->m_level = player.m_level;
    this->m_force = player.m_force;
    this->m_maxHP = player.m_maxHP;
    this->m_HP = player.m_HP;
    this->m_coins = player.m_coins;
}

Player& Player::operator=(const Player& player)
{
    if(this == &player){
        return *this;
    }

    this->m_name = player.m_name;
    this->m_level = player.m_level;
    this->m_force = player.m_force;
    this->m_maxHP = player.m_maxHP;
    this->m_HP = player.m_HP;
    this->m_coins = player.m_coins;

    return *this;
}

void Player::levelUp()
{
    if(m_level < 10){
        m_level++;
    }
}

int Player::getLevel() const
{
    return m_level;
}

int Player::getCoins() const
{
    return m_coins;
}

void Player::buff(int buffAmount)
{
    if(buffAmount > 0){
        this->m_force += buffAmount;
    }
}

void Player::debuff(int debuffAmount)
{
    if(debuffAmount > 0 && this->m_force > 0){
        this->m_force -= debuffAmount;
    }
}

void Player::heal(int healAmount)
{
    if(healAmount > 0){
        this->m_HP += healAmount;
        if(this->m_HP > this->m_maxHP){
            this->m_HP = this->m_maxHP;
        }
    }
}

void Player::damage(int damageAmount)
{
    if(damageAmount > 0){
        this->m_HP -= damageAmount;
        if(this->m_HP < 0){
            this->m_HP = 0;
        }
    }
}

bool Player::isKnockedOut() const
{
 return !this->m_HP;
}

void Player::addCoins(int coinAmount)
{
    if(coinAmount > 0){
        this->m_coins += coinAmount;
    }
}

bool Player::pay(int coinAmount)
{
    if(coinAmount <= this->m_coins){
        this->m_coins -= coinAmount > 0 ? coinAmount : 0;
        return true;
    }
    else{
        return false;
    }
}

int Player::getAttackStrength() const
{
    return this->m_force + this->m_level;
}

std::string Player::getName()
{
    return this->m_name;
}

void Player::knockOut()
{
    this->m_HP = 0;
}

std::ostream& operator<<(std::ostream &out, const Player& player)
{
    printPlayerDetails(out, player.m_name, player.getJob(), player.m_level, player.m_force, player.m_HP, player.m_coins);
    return out;
}


#endif // HW4_PLAYER_source