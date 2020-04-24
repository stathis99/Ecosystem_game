#include "Plant.h"
#include "Seedless.h"

Seedless::Seedless(){

}

void Seedless::loseLife(int x){
    if(life - x >= 0)
        life = life - x;
    else
        life = 0;
    return;
}
