#include <iostream>

#include "Plant.h"
#include "Seeded.h"

using namespace std;

int Seeded::getFoliage(){
    return foliage;
}

int Seeded::getSeeds(){
    return seeds;
}

int Seeded::getSize(){
    return psize;
}

void Seeded::modFoliage(int x){
    int lf = this->getLifeFactor();
    int prevFol = foliage;

    foliage = foliage + x;

    if(foliage < 0)
        foliage = 0;

    if(prevFol/lf > foliage/lf)
        psize--;
    if(prevFol/lf < foliage/lf)
        psize++;
    return;
}

void Seeded::modSeeds(int x){
    seeds = seeds + x;
    if(seeds < 0)
        seeds = 0;
}

void Seeded::printExtra(){
    cout << " foliage " << foliage << " seeds " << seeds << " size " << psize;
}

void Seeded::modSize(int x){
    psize = psize + x;
}

void Seeded::loseLife(int x){
    if(seeds > 0){
        seeds = seeds - x;
    }else if(foliage > 0){
        foliage = foliage - x;
    }else{
        if(life - x >= 0)
            life = life - x;
        else
            life = 0;
    }
}


