class Plant;


struct tile{
    char token = '|';
    Plant *P = NULL;

};


class Terrain{
    int sizze;
    tile **tiles;

  public:
    Terrain(int x);
    ~Terrain();
    void printTerrain(int x);
    void modifyTile(int x,int y,char symbol);
    char getTile(int x,int y);
    void setplants(int, int, Plant*);
    Plant* getPlant(int,int);
    int plantExists(int,int);
};

