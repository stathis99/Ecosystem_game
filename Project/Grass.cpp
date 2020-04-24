#include "Plant.h"
#include "Seedless.h"

Grass::Grass(int x, int y){
    name = "Grass";
    cod.x = x;
    cod.y = y;
    token = 'G';
    breedingProb = 15;
    illnessProb = 15;
    life = 5;
    lifeFactor = 4;
}
