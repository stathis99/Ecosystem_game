#include <iostream>
#include "Plant.h"
#include <ctime>
#include <stdlib.h>

Plant::Plant(){

}

string Plant::getName(){
    return name;
}

coordinates Plant::getCord(){
    return cod;
}

char Plant::getToken(){
    return token;
}

int Plant::getLife(){
    return life;
}

int Plant::getLifeFactor(){
    return lifeFactor;
}

void Plant::setGrowthPeriod(int x){
    growthPeriod = x;
}

int Plant::getGrowthPeriod(){
    return growthPeriod;
}

void Plant::setBreedingRepPeriod(int x){
    breedingRepPeriod = x;
}

void Plant::setCord(int x, int y){
    cod.x = x;
    cod.y = y;
    return;
}

void Plant::printPlant(){
    cout << name <<"("<< cod.x <<","<< cod.y << ")" << " life " << life << " lf " << lifeFactor;
    printExtra();
    cout << "\n";
}

void Plant::Raise(){
    int chance = rand()%100;
    if(token == 'G' || token == 'A'){
        if(chance >= illnessProb)
            life = life + lifeFactor;
    }else{
        if(chance >= illnessProb){
            modFoliage(lifeFactor);
            modSeeds(lifeFactor*2);
        }else{
            modFoliage(-lifeFactor);
            modSeeds(-lifeFactor*2);
        }
    }
}

Plant::~Plant(){
    cout << "Plant deleted!" << endl;
}


