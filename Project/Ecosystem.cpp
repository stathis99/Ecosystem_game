#include <iostream>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
#include <list>
#include <iterator>

#include "Terrain.h"
#include "Ecosystem.h"

#include "Plant.h"
#include "Seedless.h"
#include "Seeded.h"

#include "Animal.h"
#include "Herbivores.h"
#include "Carnivores.h"

using namespace std;

int waterCount,valleyCount,hillCount;

Ecosystem::Ecosystem(){
    dayOfYear = 0;
    cout << "Insert terrain size: ";
    cin >> terrainSize ;
    terrain = new Terrain(terrainSize);

    MapGenerator();

    cout << "Terrain without animals has been constructed!" << endl;
    terrain->printTerrain(terrainSize);

    PlantGenerator();
    AnimalGenerator();

    cout<<"Ecosystem has been constructed with animals and plants!"<<endl;

    cout <<"Meadow tiles: " << valleyCount << endl;
    cout <<"Water tiles: " << waterCount << endl;
    cout <<"Hills tiles: " << hillCount << endl;

}

void Ecosystem::printAnimalList(){
    cout << "\nAnimals statistics" << endl;
    list <Animal *> :: iterator it;
    for(it = animals.begin(); it != animals.end(); it++)
        (*it)->printAnimal();

}

void Ecosystem::printPlantList(){
    cout << "\nPlant statistics" << endl;
    list <Plant *> :: iterator it;
    for(it = plants.begin(); it != plants.end(); it++)
        (*it)->printPlant();
}

//----------------------for map -------------------------------------------//

void Ecosystem::MapGenerator(){
    int lakeSize;
    int hillNum;

    this->GenerateRiver();  //First generate river

    cout << "Insert lake size: ";
    cin >> lakeSize ;
    this->GenerateLake(lakeSize);   //Then Lake

    cout << "Insert number of hills: ";
    cin >> hillNum;
    this->GenerateHills(hillNum);   //Afterwards hills

    this->GenerateMeadow(); //Finally fill with meadow

    cout <<"Terrain is Ready"<<endl;


   cout <<"Meadow tiles: " << valleyCount << endl;
   cout <<"Water tiles: " << waterCount << endl;
   cout <<"Hills tiles: " << hillCount << endl;

}

void Ecosystem::GenerateRiver(){
    int step, deviate, x, y; //step referes to the quantity of tiles th will be changed
                      //deviate 0-2 = 30%
    srand(time(0));
    x = 0;
    y = rand()%(terrainSize+1-10) + 4;      //Start in span[5,size-5]
                                            //Choices 10 less than the size of the terrain
                                            //(+1) because rand%b will return a number 1 less
                                            //than b at max

    terrain->modifyTile(x,y,'#'); //modifies the first tile
    do{
        step = rand()%2 + 1;
        deviate = rand()%10;

        if(deviate < 3){
            if (rand()%2 == 0){ //50% left 50% right
                y--; //turns left
                terrain->modifyTile(x,y,'#');
                if(step == 2 && y>0){
                    y--;
                    terrain->modifyTile(x,y,'#');
                }
            }else{
                y++; //turns left
                terrain->modifyTile(x,y,'#');
                if(step == 2 && y<(terrainSize-1)){
                    y++;

                    terrain->modifyTile(x,y,'#');
                }
            }
        }else{
            x++;
            terrain->modifyTile(x,y,'#');
            if(step == 2 && x<(terrainSize-1)){
                x++;
                terrain->modifyTile(x,y,'#');
            }
        }
    }while(y>0 && y<(terrainSize-1) && x<(terrainSize-1));

    //terrain->printTerrain(terrainSize);
   //  cout <<"River Generated" <<endl;//with " << waterCount << " tiles of water" << endl;

}

void Ecosystem::GenerateLake(int lakeSize){
    int x = rand()%(terrainSize - lakeSize + 1);
    int y = rand()%(terrainSize - lakeSize + 1); //starting point of lake
                                             // - lakesSize :: lake wont exceed terrain
    for(int i=x; i<(lakeSize+x) ;i++){
        for(int j=y; j<(lakeSize+y) ;j++){
            terrain->modifyTile(i,j,'#');
        }
    }
    //terrain->printTerrain(terrainSize);
    //cout <<"Lake Generated"<<endl; //. Sum of water tiles is: " << waterCount  << endl;
}

void Ecosystem::GenerateHills(int hillNum){
    int flag, hillSize;

    for(int i=0; i<hillNum; i++){
        do{
            flag = 0;
            hillSize = rand()%3 + 2;
            int x = rand()%(terrainSize - hillSize+1);
            int y = rand()%(terrainSize - hillSize+1);

            for(int i=x;i<(hillSize+x);i++){ //check if their is no water in this area
                for(int j=y;j<(hillSize+y);j++){
                    if (terrain->getTile(i,j) == '#' || terrain->getTile(i,j) == '^'){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1) break;
            }
            if(flag == 0){
                for(int i=x;i<(hillSize+x);i++){
                    for(int j=y;j<(hillSize+y);j++){
                        terrain->modifyTile(i,j,'^');
                    }
                }
            }
       }while(flag == 1);
    }

    //terrain->printTerrain(terrainSize);
    //cout <<"Hills Generated" <<endl; //with " << hillCount << " tiles" << endl;

}

void Ecosystem::GenerateMeadow(){
    for(int i=0; i<terrainSize; i++)
        for(int j=0; j<terrainSize; j++){
            if(terrain->getTile(i,j) != '#' && terrain->getTile(i,j) != '^'){
                terrain->modifyTile(i,j,'"');
            }
        }
}

//---------for plants--------//

void Ecosystem::PlantGenerator(){
    int grass, algae, maple, oak, pine;
    cout << "Insert number of grass tiles: ";
    cin >> grass;
    GenerateSeedless(grass,0);
    cout << "Insert number of algae tiles: ";
    cin >> algae;
    GenerateSeedless(algae,1);
    cout << "Insert number of maple tiles: ";
    cin >> maple;
    GenerateSeeded(maple, 'M');
    cout << "Insert number of oak tiles: ";
    cin >> oak;
    GenerateSeeded(oak, 'O');
    cout << "Insert number of pine tiles: ";
    cin >> pine;
    GenerateSeeded(pine, 'P');
}

void Ecosystem::GenerateSeedless(int tilesNum,int choice){
    int x, y, flag, limit;
    Plant* pl;
    limit = (choice == 0) ? valleyCount : waterCount;   //Limit dependent on choice

    for(int i=0; i<tilesNum && i<limit; i++){
            flag = 0;
            while(flag != 1){
                x = rand()%terrainSize;
                y = rand()%terrainSize;
                if(terrain->getTile(x,y) == '"' && choice == 0){
                    pl = new Grass(x,y);
                    flag = 1;
                }
                if(terrain->getTile(x,y) == '#' && choice == 1){
                    pl = new Algae(x,y);
                    flag = 1;
                }
                if(flag == 1){
                    plants.push_back(pl);
                    terrain->setplants(x, y, pl);
                    break;
                }
            }
    }
}

void Ecosystem::GenerateSeeded(int tileNum, char ch){
    int limit, flag, x, y;
    Plant *pl;
    for(int i=0; i<tileNum; i++){
        flag = 0;
        while(flag != 1){
            x = rand()%terrainSize;
            y = rand()%terrainSize;

            switch(ch){
            case 'M':
                if(i < (limit=valleyCount+hillCount) && (terrain->getTile(x,y) == '"' || terrain->getTile(x,y) == '^')){
                    pl = new Maple(x,y);
                    terrain->setplants(x, y, pl);
                    flag = 1;
                    break;
                }else
                    break;
            case 'O':
                if(i < (limit=valleyCount) && terrain->getTile(x,y) == '"'){
                    pl = new Oak(x,y);
                    terrain->setplants(x, y, pl);
                    flag = 1;
                    break;
                }else
                    break;
            case 'P':
                if(i < (limit=hillCount) && terrain->getTile(x,y) == '^'){
                    pl = new Pine(x,y);
                    terrain->setplants(x, y, pl);
                    flag = 1;
                    break;
                }else
                    break;
            }
            if (flag == 1)
                plants.push_back(pl);
            if(i >= limit)
                return;
        }
    }


}

//-----------for animals---------------------------------------------//


void Ecosystem::AnimalGenerator(){
    int deer, rabbit, groundhog, salmon, fox, bear , wolf ;
    cout << "Insert number of deers: ";
    cin >> deer;
    GenerateAnimal(deer,0);
    cout << "Insert number of rabbits: ";
    cin >> rabbit;
    GenerateAnimal(rabbit,1);
    cout << "Insert number of groundhogs: ";
    cin >> groundhog;
    GenerateAnimal(groundhog,2);
    cout << "Insert number of salmons: ";
    cin >> salmon;
    GenerateAnimal(salmon,4);
    cout << "Insert number of foxes: ";
    cin >> fox;
    GenerateAnimal(fox,3);
    cout << "Insert number of bears: ";
    cin >> bear;
    GenerateAnimal(bear,6);
    cout << "Insert number of wolves: ";
    cin >> wolf;
    GenerateAnimal(wolf,5);
    cout << "Animals Generated" << endl;
}

void Ecosystem::GenerateAnimal(int num,int choice){
int x,y,flag = 0,i = 0;
Animal* anl;
//is a deer or Rabbit or Groundhog or Fox
    if(choice <= 3){
        do{
            do{
                x = rand()%terrainSize;
                y = rand()%terrainSize;
                if(terrain->getTile(x,y) == '"'){
                    flag = 1;
                    if(choice == 0){
                       anl = new Deer(x,y);
                    }else if(choice == 1){
                        anl = new Rabbit(x,y);
                    }else if(choice == 2){
                        anl = new Groundhog(x,y);
                    }else if (choice == 3){
                        anl = new Fox(x,y);
                    }
                    animals.push_back(anl);
                }
             }while(flag == 0);
            flag = 0;
            i++;
        }while(i<num);
        //is a salmon
     } else if(choice == 4){
        do{
                do{
                x = rand()%terrainSize;
                y = rand()%terrainSize;
                if(terrain->getTile(x,y) == '#'){
                    flag = 1;
                    anl  = new Salmon(x,y);
                    animals.push_back(anl);
                }
             }while(flag == 0);
            flag = 0;
            i++;
        }while(i<num);
      //is a Wolf
    }else if(choice == 5){
         do{
                do{
                x = rand()%terrainSize;
                y = rand()%terrainSize;
                if(terrain->getTile(x,y) != '#'){
                    flag = 1;
                    anl  = new Wolf(x,y);
                    animals.push_back(anl);
                }
             }while(flag == 0);
            flag = 0;
            i++;
        }while(i<num);

    //is a Bear
    }else if (choice == 6 && hillCount > 0 ){
         do{
                do{
                x = rand()%terrainSize;
                y = rand()%terrainSize;
                if(terrain->getTile(x,y) == '^'){
                    flag = 1;
                    anl  = new Bear(x,y);
                    animals.push_back(anl);
                }
             }while(flag == 0);
            flag = 0;
            i++;
        }while(i<num);
    }
}






//-------------Ecosystem running------------------------------//






void Ecosystem::RunEcosystem(int x){
    int n;
    ApplySeason(0);
    for(int dayOfYear=1; dayOfYear<=x ;dayOfYear++){
        if(dayOfYear%90 == 0){
            n = dayOfYear/90;
            ApplySeason(n%4);
        }
        DailyReset(n%4);
        for(int i=1;i<=24;i++){
            AnimalMovement();
            AnimalEating();

        }
        CheckDeadEntries();
    }
}







void Ecosystem::ApplySeason(int x){
    switch(x){
    case 0:
        PeriodPlantChange(5,10);
        PeriodAnimalChange(20,12,11);
        wakeAnimals();

        break;
    case 1:
        PeriodAnimalChange(30,8,9);
        PeriodPlantChange(10,10);
        break;
    case 2:
        PeriodAnimalChange(15,5,9);
        PeriodPlantChange(0,20);
        break;
    case 3:
        PeriodPlantChange(10,0);
        break;
    }
}
//--------------functions for Apply season------------------------------------------------------///
void Ecosystem::PeriodAnimalChange(int x,int y,int z){
    list <Animal *> :: iterator it;

    for(it = animals.begin(); it != animals.end(); it++){
        (*it)->setGrowthPeriod(x);
            if((*it)->getToken() == 'H'){
                (*it)->setBreedingRepPeriod(y);
            }else{
                (*it)->setBreedingRepPeriod(z);
            }
        }
}
void Ecosystem::wakeAnimals(){
    list <Animal *> :: iterator it;
    for(it = animals.begin(); it != animals.end(); it++){
         if((*it)->getInHibernation() == 1){
            (*it)->setInHibernation(0);
         }

    }
}
void Ecosystem::hibernateAnimals(){
    list <Animal *> :: iterator it;
    for(it = animals.begin(); it != animals.end(); it++){

               //edw tha ginontai hibernate tyxaia animals
    }
}
void Ecosystem::PeriodPlantChange(int x, int y){
    list <Plant *> :: iterator it;
    for(it = plants.begin(); it != plants.end(); it++){
        (*it)->setGrowthPeriod(x);
        (*it)->setBreedingRepPeriod(y);
    }
}
//------------------------------------------------------------------------------//


void Ecosystem::DailyReset(int season){
    AnimalHungerReset();
    AnimalGrow();
    PlantGrow();
}

//----------------------functions for Daily Reset-----------------------------//

void Ecosystem::AnimalHungerReset(){
    list <Animal *> :: iterator it;
    for(it = animals.begin(); it != animals.end(); it++){
       if((*it)->getIsHungry() == 1 || (*it)->getNoFoodCounter() == 7){
         (*it)->setEatenFood(0);
        }else{
            (*it)->incNFC();
        }
    }
}

void Ecosystem::AnimalGrow(){
    list <Animal *> :: iterator it;

    for(it = animals.begin(); it != animals.end(); it++){
            if(dayOfYear % (*it)->getGrowthPeriod() == 0)
                (*it)->Raise();
    }
}

void Ecosystem::PlantGrow(){
    list <Plant *> :: iterator it;

    for(it = plants.begin(); it != plants.end(); it++){
            if((*it)->getGrowthPeriod() != 0)
                if(dayOfYear % (*it)->getGrowthPeriod() == 0)
                    (*it)->Raise();
    }
}
//-----------------------------------------------------------------------------//


void Ecosystem::AnimalMovement(){
    list <Animal *> :: iterator it;
    for(it = animals.begin(); it != animals.end(); it++){
        findNextDest(*it);
    }
}

void Ecosystem::findNextDest(Animal *animal){
    int step,direction;
    bool flag;
    char acceptableTiles[] = {'#', '^', '"', 'G', 'A', 'O', 'P', 'M'};  //nero bouno pediada

    switch(animal->getName0()){
        case 'D':
            do{
                findNext(&step, &direction, animal->getSize());
                flag = checkIfRight(step, direction, animal->getCordP(), acceptableTiles);
            }while(!flag);
            break;
        case 'R':{
            acceptableTiles[1] = acceptableTiles[6] = '-';   //den paei voyno
            do{
                findNext(&step, &direction, animal->getSize());
                flag = checkIfRight(step, direction, animal->getCordP(), acceptableTiles);
            }while(!flag);

            break;
        }
        case 'G':{
            acceptableTiles[0] = acceptableTiles[4] = '-';   //den paei sto nero
            do{
                findNext(&step, &direction, animal->getSize());
                flag = checkIfRight(step, direction, animal->getCordP(), acceptableTiles);
            }while(!flag);
            break;
        }
        case 'S':{
            acceptableTiles[1] = acceptableTiles[2] = acceptableTiles[3] = acceptableTiles[5] = acceptableTiles[6] = acceptableTiles[7] = '-';  //can go only in water
            do{
                findNext(&step, &direction, animal->getSize());
                flag = checkIfRight(step, direction, animal->getCordP(), acceptableTiles);
            }while(!flag);
            break;
        }
        case 'F':{
            do{
                findNext(&step, &direction, animal->getSize());
                flag = checkIfRight(step, direction, animal->getCordP(), acceptableTiles);
            }while(!flag);
            break;
        }
        case 'B':{
            do{
                findNext(&step, &direction, animal->getSize());
                flag = checkIfRight(step, direction, animal->getCordP(), acceptableTiles);
            }while(!flag);
            break;
        }
        case 'W':{
            do{
                findNext(&step, &direction, animal->getSize());
                flag = checkIfRight(step, direction, animal->getCordP(), acceptableTiles);
            }while(!flag);
            break;
        }
    }

}

bool Ecosystem::checkIfRight(int step, int direction, struct coordinates2 *cod, char *arr){

    int arrSize = sizeof(arr) / sizeof(char);
    switch(direction){
        case 0:{ //up
                if(cod->x-step >=0){
                    char *flag = find(arr, arr+8, terrain->getTile(cod->x-step,cod->y));
                    // When the element is not found, std::find returns the end of the range
                    if (flag != arr+8){
                        cod->x = (cod->x)-step;
                        return true;
                    }else{
                        return false;
                    }
                }
            break;
        }
        case 1:{ //right
            if(cod->y+step < terrainSize){

                char *flag = find(arr, arr+8, terrain->getTile(cod->x,cod->y+step));
                // When the element is not found, std::find returns the end of the range
                if (flag != arr+8){
                    cod->y = cod->y+step;
                    return true;
                }else
                    return false;
            }
            break;
        }
        case 2:{ //down
            if(cod->x+step < terrainSize){
                char *flag = find(arr, arr+8, terrain->getTile(cod->x+step,cod->y));
                // When the element is not found, std::find returns the end of the range
                if (flag != arr+8){
                    cod->x = cod->x+step;
                    return true;
                }else{
                    return false;
                }
            }
            break;
        }
        break;
        case 3:{ //left
            if(cod->y-step >= 0){
                char *flag = find(arr, arr+8, terrain->getTile(cod->x,cod->y-step));
                // When the element is not found, std::find returns the end of the range
                if (flag != arr+8){
                    cod->y = cod->y-step;
                    return true;
                }else{
                    return false;
                }
            }
            break;
        }
    }
}

void Ecosystem::findNext(int *step, int *dir, int asize){
    *step = rand()%(asize+1);
    *dir = rand()%4; //panw-deksia-katw-aristera
}
//--------------------function for animal movement-------------------------------//

void Ecosystem::AnimalEating(){

    list <Animal *> :: iterator it;
    for(it = animals.begin(); it != animals.end(); it++){

            int x = (*it)->getX();
            int y = (*it)->getY();

            if(terrain->plantExists(x,y) == 1){

                if((*it)->getName() == "Deer" && (*it)->getIsHungry() == 1 && (terrain->getPlant(x,y)->getToken() == 'G' || terrain->getPlant(x,y)->getToken() == 'A')) {
                    terrain->getPlant(x,y)->loseLife(2);
                    (*it)->Eat(2);

                }else if((*it)->getName() == "Rabbit" && (*it)->getIsHungry() == 1 && terrain->getPlant(x,y)->getToken() != 'A'){

                      int flag = 1;
                      if(terrain->getPlant(x,y)->getToken() != 'G'){
                        if((*it)->getSize() < terrain->getPlant(x,y)->getSize()){
                                flag = 0; //if the plant is seedes but is bigger than the animal don eat
                            }
                      }
                      if(flag == 1){
                        terrain->getPlant(x,y)->loseLife(1);
                        (*it)->Eat(1);
                      }

                 }else if((*it)->getName() == "Salmon" && (*it)->getIsHungry() == 1 && terrain->getPlant(x,y)->getToken() == 'A'){

                          terrain->getPlant(x,y)->loseLife(1);
                          (*it)->Eat(1);

                  }else if((*it)->getName() == "Groundhog" && (*it)->getIsHungry() == 1 && terrain->getPlant(x,y)->getToken() != 'A'){

                            int flag = 1;
                            if(terrain->getPlant(x,y)->getToken() != 'G'){
                                if((*it)->getSize() < terrain->getPlant(x,y)->getSize()){
                                   flag = 0; //if the plant is seedes but is bigger than the animal don eat
                               }
                            }
                            if(flag == 1){
                                terrain->getPlant(x,y)->loseLife(1);
                                (*it)->Eat(1);
                            }
                  }
        }
          else{
                if((*it)->getName() == "Fox"){
                    CarnivoreEatC((*it));
                }else if((*it)->getName() == "Wolf"){
                    CarnivoreEatC((*it));
                }else if((*it)->getName() == "Bear"){
                    CarnivoreEatC((*it));
                }
            }

}
}

void Ecosystem::CarnivoreEatC(Animal *anml){
    list <Animal *> :: iterator it;
    for(it = animals.begin(); it != animals.end(); it++){
        if((*it)->getToken() != 'C'){
            if(((*anml).getName() == "Fox" || (*anml).getName() == "Wolf") && ((*it)->getName() != "Salmon")){
                if((*anml).getX() == (*it)->getX() && (*anml).getY() == (*it)->getY()){ //if they aren in the same tile
                    if((*anml).getSize() > (*it)->getSize() && (*anml).getSpeed() > (*it)->getSpeed()){
                        (*anml).EatC();
                        (*it)->Die();
                    }
                }
            }else if((*anml).getName() == "Bear"){
                if((*anml).getX() == (*it)->getX() && (*anml).getY() == (*it)->getY()){
                (*anml).EatC();
                (*it)->Die();
            }
           }
        }else if((*anml).getHungerCount() >= 8){ //an exei na faei panw apo 8 meres
            if(((*anml).getName() == "Fox" || (*anml).getName() == "Wolf")){
                if((*anml).getX() == (*it)->getX() && (*anml).getY() == (*it)->getY()){
                    if((*anml).getSize() > (*it)->getSize()){
                        (*anml).EatC();
                        (*it)->Die();
                    }else if((*anml).getSize() == (*it)->getSize()){
                        if((*anml).getAttack() > (*it)->getDefence()){
                           (*anml).EatC();
                           (*it)->Die();
                        }
                    }
                 }
              }else if((*anml).getName() == "Bear" ){
                  (*anml).EatC();
                  (*it)->Die();
              }
          }
      }
}

void Ecosystem::CheckDeadEntries(){
    list <Animal *> :: iterator animal_it;
    list <Plant *> :: iterator plant_it, plt;

    for(animal_it = animals.begin(); animal_it != animals.end(); animal_it++){
        if(!(*animal_it)->is_Alive()){
            cout << "\n\nAnimal deleted " << endl;
            (*animal_it)->printAnimal();
            animals.erase(animal_it);
            animal_it--;
        }
    }

    for(plant_it = plants.begin(); plant_it != plants.end(); plant_it++){
        if((*plant_it)->getLife() == 0)
            plant_it = DeleteAndReplacePlant(plant_it);
    }
}

list <Plant *> :: iterator Ecosystem::DeleteAndReplacePlant(list <Plant *> :: iterator plt){
    int x, y;

    x = (*plt)->getCord().x;
    y = (*plt)->getCord().y;

    switch((*plt)->getToken()){
    case 'G':
        terrain->modifyTile(x,y,'"');
        return plt--;
        break;
    case 'A':
        terrain->modifyTile(x,y,'#');
        return plt--;
        break;
    case 'M':
        terrain->modifyTile(x,y,'"');
        return plt--;
        break;
    case 'O':
        terrain->modifyTile(x,y,'"');
        return plt--;
        break;
    case 'P':
        terrain->modifyTile(x,y,'^');
        return plt--;
        break;
    }

}

Ecosystem::~Ecosystem(){
    list <Animal *> :: iterator animal_it;
    list <Plant *> :: iterator plant_it;

    for(plant_it = plants.begin(); plant_it != plants.end(); plant_it++){
        delete (*plant_it);
    }

    for(animal_it = animals.begin(); animal_it != animals.end(); animal_it++){
        delete (*animal_it);
    }

    delete terrain;

}

void Ecosystem::printTerrain(){
    terrain->printTerrain(terrainSize);
    return;
}
