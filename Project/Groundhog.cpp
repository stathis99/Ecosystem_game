#include "Animal.h"
#include "Herbivores.h"

Groundhog::Groundhog(int x, int y){
    token = 'H';
    name = "Groundhog";
    asize = 2;
    speed = 3;
    eatCount = 3;
    cod.x = x;
    cod.y = y;
    isHungry = 1;
    isAlive = 1;
}
