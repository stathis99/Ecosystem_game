#include <iostream>
#include <list>
#include <iterator>

using namespace std;


class Terrain;
class Plant;
class Animal;

class Ecosystem{
   list <Plant *> plants;
   list <Animal *> animals;
   Terrain* terrain;
   int dayOfYear;
   int factor;
   int terrainSize;

   public:
        Ecosystem();
        ~Ecosystem();
        void MapGenerator();
        void PlantGenerator();
        void AnimalGenerator();
        void GenerateHills(int);
        void GenerateLake(int);
        void GenerateMeadow();
        void GenerateRiver();
        void GenerateSeedless(int, int);
        void GenerateSeeded(int, char);
        void GenerateAnimal(int , int);
        list <Plant *> :: iterator DeleteAndReplacePlant(list <Plant *> :: iterator);

        //---------After ecosystem generaion------------------------------//
        void RunEcosystem(int);
        void printAnimalList();
        void printPlantList();
        void ApplySeason(int);
        void PeriodAnimalChange(int,int,int);
        void PeriodPlantChange(int, int);
        void wakeAnimals();
        void hibernateAnimals();
        void DailyReset(int);
        void AnimalHungerReset();
        void AnimalGrow();
        void PlantGrow();
        void AnimalEating();
        void CarnivoreEatC(Animal *);
        void HerbivoresHungerCheck();
        void CheckDeadEntries();


        //-------------Movement---------------//
        void AnimalMovement();
        void findNextDest(Animal *);
        bool checkIfRight(int, int, struct coordinates2*, char *);
        void findNext(int *, int *, int);

        void printTerrain();
};
