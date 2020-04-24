#include "Plant.h"
#include "Seedless.h"

Algae::Algae(int x1, int y1){
    name = "Algae";
    cod.x = x1;
    cod.y = y1;
    token = 'A';
    breedingProb = 25;
    illnessProb = 25;
    life = 5;
    lifeFactor = 2;
}
