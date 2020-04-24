#include "Plant.h"
#include "Seeded.h"

Pine::Pine(int x, int y){
    psize = 5;
    seeds = 20;
    foliage = 40;
    name = "Pine";
    cod.x = x;
    cod.y = y;
    token = 'P';
    breedingProb = 15;
    illnessProb = 15;
    life = seeds + foliage;
    lifeFactor = 20;
}
