#include "Animal.h"
#include "Carnivores.h"

Fox::Fox(int x, int y){
    token = 'C';
    name = "Fox";
    asize = 1;
    attack = 1;
    defence = 1;
    speed = 1;
    eatCount = 2;
    cod.x = x;
    cod.y = y;
    hungerCount = 0;
    isAlive = 1;
    isHungry = 1;
}
