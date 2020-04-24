#include "Animal.h"
#include "Herbivores.h"

Salmon::Salmon(int x, int y){
    token = 'H';
    name = "Salmon";
    asize = 1;
    speed = 5;
    eatCount = 1;
    cod.x = x;
    cod.y = y;
    hungerCount = 0;
    isAlive = 1;
    isHungry = 1;
}
