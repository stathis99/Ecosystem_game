#include <string>

using namespace std;

struct coordinates{
    int x;
    int y;
};

class Plant{
protected:
    string name;
    struct coordinates cod;
    char token;
    int breedingProb;
    int breedingRepPeriod;
    int growthPeriod;
    int illnessProb;
    int life;
    int lifeFactor;

public:
    Plant();
    ~Plant();
    void Raise();
    char getToken();
    string getName();
    coordinates getCord();
    int getLife();
    int getLifeFactor();
    void setCord(int, int);
    void printPlant();
    void setGrowthPeriod(int);
    int getGrowthPeriod();
    void setBreedingRepPeriod(int);



    virtual int getFoliage(){};
    virtual int getSeeds(){};
    virtual int getSize(){};
    virtual void modFoliage(int){};
    virtual void modSeeds(int){};
    virtual void modSize(int){};
    virtual void printExtra(){};
    virtual void loseLife(int){};
};
