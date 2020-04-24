#include "Animal.h"
#include "Herbivores.h"

Rabbit::Rabbit(int x,int y){
    token = 'H';
    name = "Rabbit";
    asize = 1;
    speed = 2;
    eatCount = 2;
    cod.x = x;
    cod.y = y;
    hungerCount = 0;
    isAlive = 1;
    isHungry = 1;
}
