#ifndef HW4_PLAYER
#define HW4_PLAYER

#include <ostream>


#define BASE_HP 100
#define BASE_ATTACK 5

 
class Player{
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
    std::string m_job;


    public:
    /*
    *  Constractor 1:
    *  only name given
    */
    Player(const std::string name, std::string job, int baseMaxHP = BASE_HP, int baseForce = BASE_ATTACK);
    Player(const Player& player);
    ~Player() = default;
    Player& operator=(const Player& player);

    virtual void heal(int healAmount);
    virtual void addCoins(int coinAmount);
    virtual int getAttackStrength() const;
    void levelUp();
    int getLevel() const;
    int getCoins() const;
    std::string getJob() const;
    void buff(int buffAmount);
    void damage(int damageAmount);
    void knockOut();
    bool isKnockedOut() const;
    bool pay(int coinAmount);
    

    std::string getName();

    friend std::ostream& operator<<(std::ostream &out, Player& player);
};

#endif // HW4_PLAYER