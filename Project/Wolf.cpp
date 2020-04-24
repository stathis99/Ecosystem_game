#include "Animal.h"
#include "Carnivores.h"

Wolf::Wolf(int x, int y){
    token = 'C';
    name = "Wolf";
    asize = 1;
    attack = 2;
    defence = 2;
    speed = 2;
    eatCount = 2;
    cod.x = x;
    cod.y = y;
    hungerCount = 0;
    isAlive = 1;
    isHungry = 1;
}
