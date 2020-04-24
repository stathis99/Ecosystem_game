class Seeded:public Plant{
protected:
    int psize;
    int seeds;
    int foliage;
public:
    int getFoliage();
    int getSeeds();
    int getSize();
    void modFoliage(int);
    void modSeeds(int);
    void modSize(int);
    void printExtra();
    void loseLife(int);
};

class Maple:public Seeded{
public:
    Maple(int, int);

};

class Oak:public Seeded{
public:
    Oak(int, int);

};

class Pine:public Seeded{
public:
    Pine(int, int);

};
