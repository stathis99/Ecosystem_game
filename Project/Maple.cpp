#include "Plant.h"
#include "Seeded.h"

Maple::Maple(int x, int y){
    psize = 2;
    seeds = 10;
    foliage = 20;
    name = "Maple";
    cod.x = x;
    cod.y = y;
    token = 'M';
    breedingProb = 5;
    illnessProb = 5;
    life = seeds + foliage;
    lifeFactor = 10;
}
