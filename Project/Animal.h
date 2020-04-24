#include <string>

using namespace std;

struct coordinates2{
    int x;
    int y;
};

class Animal{
protected:
    char token;
    string name;
    int asize;
    int hungerCount;
    int eatenFood;
    int eatCount;
    struct coordinates2 cod;
    bool isAlive;
    bool isHungry;
    bool inHeat;
    int speed;
    bool hibernates;
    bool inHibernation;

    int growthPeriod;
    int breedingRepPeriod;
    int noFoodCounter; //counts days herbivores has not eaten
public:
    ~Animal();
    void printAnimal();
    void Move();
    void Eat(int);
    void EatC();
    void Raise();
    void Die();

    char getToken();
    bool getInHibernation();
    bool getHibernates();
    int  getEatenFood();
    int getGrowthPeriod();
    bool getIsHungry();
    int getSpeed();
    int getSize();
    string getName();
    int getX();
    int getY();
    char getName0();
    struct coordinates2 *getCordP();
    int getNoFoodCounter();
    int getHungerCount();

    bool is_Alive();
    virtual int getAttack(){};
    virtual int getDefence(){};
    virtual void increaseAttack(int){};
    virtual void increaseDefence(int){};
    void incNFC();

    void setGrowthPeriod(int);
    void setBreedingRepPeriod(int);
    void setInHibernation(int);
    void setEatenFood(int);
    void setCord(int,int);
    void setNoFoodCounter();

};
