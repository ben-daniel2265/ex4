#ifndef HW4_PLAYER
#define HW4_PLAYER

#include <ostream>
#include <stdbool.h>


#define BASE_HP 100
#define BASE_ATTACK 5
 
class Player{
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;


    public:
    /*
    *  Constractor 1:
    *  only name given
    */
    Player(const std::string name, int baseMaxHP = BASE_HP, int baseForce = BASE_ATTACK);
    Player(const Player& player);
    ~Player();
    Player& operator=(const Player& player);

    virtual void printInfo() const;
    void levelUp();
    int getLevel() const;
    void buff(int buffAmount);
    virtual void heal(int healAmount);
    void damage(int damageAmount);
    bool isKnockedOut() const;
    virtual void addCoins(int coinAmount);
    bool pay(int coinAmount);
    virtual int getAttackStrength() const;
    std::string getName();
};

#endif // HW4_PLAYER