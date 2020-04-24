#include "Plant.h"
#include "Seeded.h"

Oak::Oak(int x, int y){
    psize = 5;
    seeds = 15;
    foliage = 30;
    name = "Oak";
    cod.x = x;
    cod.y = y;
    token = 'O';
    breedingProb = 20;
    illnessProb = 20;
    life = seeds + foliage;
    lifeFactor = 15;
}
