#include "Animal.h"
#include "Herbivores.h"

Deer::Deer(int x, int y){
    name = "Deer";
    token  = 'H';
    asize = 2;
    speed = 4;
    eatCount = 4;
    cod.x = x;
    cod.y = y;
    hungerCount = 0;
    isAlive = 1;
    isHungry = 1;
}
