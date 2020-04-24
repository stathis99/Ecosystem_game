class Seedless: public Plant{
public:
    Seedless();
    void loseLife(int);
};

class Grass:public Seedless{
public:
    Grass(int, int);
};

class Algae:public Seedless{
public:
    Algae(int, int);
};
