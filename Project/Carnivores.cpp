#include "Animal.h"
#include "Carnivores.h"

int Carnivores::getAttack(){
        return attack;
}

int Carnivores::getDefence(){
    return defence;
}
void Carnivores::increaseAttack(int x){
    attack = attack + x;
}
void Carnivores::increaseDefence(int x){
    defence = defence + x;
}

