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

    public:
    /*
    *  Constractor 1:
    *  only name given
    */
    Player(const std::string name, int baseMaxHP = BASE_HP, int baseForce = BASE_ATTACK);
    Player(const Player& player);
    ~Player() = default;
    Player& operator=(const Player& player);

    virtual void heal(int healAmount);
    virtual void addCoins(int coinAmount);
    virtual int getAttackStrength() const;
    virtual std::string getJob() const = 0;
    void levelUp();
    int getLevel() const;
    int getCoins() const;
    void buff(int buffAmount);
    void debuff(int debuffAmount);
    void damage(int damageAmount);
    void knockOut();
    bool isKnockedOut() const;
    bool pay(int coinAmount);
    

    std::string getName();

    friend std::ostream& operator<<(std::ostream &out, const Player& player);
};

#endif // HW4_PLAYER