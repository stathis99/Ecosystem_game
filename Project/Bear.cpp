#include "Animal.h"
#include "Carnivores.h"

Bear::Bear(int x, int y){
    token = 'C';
    name = "Bear";
    asize = 3;
    attack = 6;
    defence = 6;
    speed = 4;
    eatCount = 5;
    cod.x = x;
    cod.y = y;
    hungerCount = 0;
    isAlive = 1;
    isHungry = 1;
}
