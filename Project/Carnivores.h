class Animal;

class Carnivores: public Animal{
protected:
    int attack;
    int defence;
public:
    int getAttack();
    int getDefence();
    void increaseAttack(int);
    void increaseDefence(int);
};

class Fox:public Carnivores{
 public:
    Fox(int, int);

};

class Bear:public Carnivores{
public:
    Bear(int, int);

};

class Wolf:public Carnivores{
public:
    Wolf(int, int);

};
