#include <iostream>


#include "Terrain.h"
#include "Plant.h"
#include "Animal.h"

using namespace std;

extern int waterCount,valleyCount,hillCount;

Terrain::Terrain(int x):sizze(x){
    tiles = new tile*[x];   //Creating a two dimension array of struct's tiles
    for(int i=0;i<x;i++){
        tiles[i] = new tile[x];
    }
}

void Terrain::printTerrain(int x){
  for(int i=0;i<x;i++){
    for(int j=0;j<x;j++){
      cout << tiles[i][j].token << " ";
    }
    cout << "\n";
  }
}

char Terrain::getTile(int x,int y){
    return tiles[x][y].token;
}


void Terrain::modifyTile(int x, int y ,char symbol){
    if(getTile(x,y) != '|')    //If there is something else except |
        switch(getTile(x,y)){   //Decrease because it will be removed
            case '#':
                waterCount--; break;
            case '^':
                hillCount--; break;
            case '"':
                valleyCount--; break;
            default:
                delete tiles[x][y].P;
                break;
        }
    switch(symbol){     //Whatever the case may be previously increase the one that you will insert
        case '#':
            tiles[x][y].P = NULL;
            waterCount++; break;
        case '^':
            tiles[x][y].P = NULL;
            hillCount++; break;
        case '"':
            tiles[x][y].P = NULL;
            valleyCount++; break;
    }

    tiles[x][y].token = symbol;
}

//--------------------plants--------------//

void Terrain::setplants(int x, int y, Plant* plt){
    tiles[x][y].P = plt;
    modifyTile(x,y,plt->getToken());

}

Plant* Terrain::getPlant(int x,int y){
    return tiles[x][y].P;
}

int Terrain::plantExists(int x,int y){
    if(tiles[x][y].P != NULL){
        return 1;
    }
    return 0;

}

Terrain::~Terrain(){
    for(int i=0;i<sizze;i++){
        for(int j=0;j<sizze;j++)
            delete tiles[i][j].P;
        delete tiles[i];
    }

    delete tiles;
}


