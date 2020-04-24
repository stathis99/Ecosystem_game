#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Animal.h"

using namespace std;
class Carnivores;

void Animal::printAnimal(){
    cout << name <<"("<< cod.x <<","<< cod.y << ") "<<eatenFood <<" is Alive = " << isAlive;
     if(token == 'C'){
         cout <<" atck " << getAttack() <<" def "<<getDefence() ;
     }
     cout << endl;


}

void Animal::Raise(){
    if(name == "Deer"){
        if(asize < 5)
            asize++;
        if(speed < 8)
            speed = speed + 2;
        if(eatCount < 8)
            eatCount = eatCount + 2;
    }else if(name == "Rabbit"){
        if(asize < 2)
            asize++;
        if(speed < 6)
            eatCount++;
        if(eatCount < 4)
            speed = speed + 2;
    }else if(name == "Groundhog"){
        if(asize < 3)
            asize++;
        if(speed < 5)
            speed++;
        if(eatCount < 5)
            eatCount++;
    }else if(name == "Salmon"){

    }else if (name == "Fox"){
        if(asize < 4)
            asize++;
        if(speed < 6)
            speed++;
        if(eatCount < 4)
            eatCount++;
        if(getAttack() < 5)
            increaseAttack(1);
        if(getDefence() <5)
            increaseDefence(1);
    }else if (name == "Bear"){
        if(asize < 10)
            asize = asize + 2;
        if(speed < 4)
            speed = speed + 2;
        if(eatCount < 10)
            eatCount = eatCount + 2;
        if(getAttack() < 10)
            increaseAttack(2);
        if(getDefence() < 10)
            increaseDefence(2);
    }else if (name == "Wolf"){
        if(asize < 7)
            asize++;
        if(speed < 8)
            speed = speed + 2;
        if(eatCount < 8)
            eatCount = eatCount + 2;
        if(getAttack() < 8)
            increaseAttack(2);
        if(getDefence() <6)
            increaseDefence(2);
    }

}

void Animal::Eat(int x){
    eatenFood = eatenFood + x;
    if(eatenFood == eatCount){
         isHungry = 0;
         setNoFoodCounter();
    }

}

void Animal::EatC(){
   eatenFood = eatCount;
}

void Animal::Die(){
    isAlive = 0;
}

void Animal::incNFC(){
        noFoodCounter++;
}





//GETTERS
struct coordinates2 * Animal::getCordP(){
    return &cod;
}

char Animal::getName0(){
    return name[0];
}

char Animal::getToken(){
    return token;
}
bool Animal::getInHibernation(){
    return inHibernation;
}
bool Animal::getHibernates(){
    return hibernates;

}

int Animal::getEatenFood(){
    return eatenFood;
}

int Animal::getGrowthPeriod(){
    return growthPeriod;
}
bool Animal::getIsHungry(){
    return isHungry;
}
int Animal::getSpeed(){
    return speed;
}
int Animal::getSize(){
    return asize;
}
string Animal::getName(){
    return name;
}
int Animal::getX(){
    return cod.x;
}
int Animal::getY(){
    return cod.y;
}
int Animal::getNoFoodCounter(){
    return noFoodCounter;
}
int Animal::getHungerCount(){
    return hungerCount;
}






//SETTERS

void Animal::setGrowthPeriod(int x){
    growthPeriod = x;
}

void Animal::setBreedingRepPeriod(int x){
    breedingRepPeriod = x;
}

void Animal::setInHibernation(int x){
    inHibernation = x;
}

void Animal::setEatenFood(int x){
    eatenFood = x;
}
void Animal::setCord(int x,int y){
    cod.x = x;
    cod.y = y;
}
void Animal::setNoFoodCounter(){
    noFoodCounter = 0;
}

bool Animal::is_Alive(){
    if(isAlive)
        return true;
    return false;
}

Animal::~Animal(){
    cout << "Animal deleted!" << endl;
}
