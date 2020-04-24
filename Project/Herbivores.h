class Animal;

class Herbivores: public Animal{
public:
    void cunClimb();
    void needFood();
    void eatenFood();
    void neededFood();
    void loseLife();


};

class Deer:public Herbivores{
public:
    Deer(int, int);

};

class Rabbit:public Herbivores{
public:
    Rabbit(int, int);


};


class Groundhog:public Herbivores{
public:
    Groundhog(int, int);

};


class Salmon:public Herbivores{
 public:
    Salmon(int, int);

};




