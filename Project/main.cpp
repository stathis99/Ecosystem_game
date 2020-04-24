#include <iostream>
#include "Ecosystem.h"

using namespace std;

int main()
{
    int days;
    int choice;

    Ecosystem ecosystem;

    cout << "\nIn order to print the ecosystem enter 1." << endl;
    cout << "If you want to run the ecosystem enter 2."<< endl;
    cout << "Enter 3 to print animal's statistics or 4 to print plant's statistics!"<< endl;
    cout << "Otherwise enter 5 to quit!" << endl;

    while(true){
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch(choice){
        case 1:
            ecosystem.printTerrain();
            break;
        case 2:
            cout << "Insert ecosystem days : " << endl;
            cin >> days ;
            ecosystem.RunEcosystem(days);
            break;
        case 3:
            ecosystem.printAnimalList();
            break;
        case 4:
            ecosystem.printPlantList();
            break;
        case 5:
            return 0;
            break;
        }
    }
}
