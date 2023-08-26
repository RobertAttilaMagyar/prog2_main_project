//Magyar Róbert Attila [BIXYQG]
#include <iostream>
#include "Book.h"
#include "Shelf.h"
#include "SmallShelf.h"
#include "MediumShelf.h"
#include "LargeShelf.h"
#include "Szekreny.h"

using namespace std;

int main()
{
    std::cout<<"Hello World"<<std::endl;
    //Először kezdjük az alapokkal, hozzuk létre a könyvesszekrenyt
    std::cout<<"Adja meg a konyvespolcok meretet!"<<std::endl;
    int n;
    cin>>n;
    Szekreny s(n);

    //Szükséges lesz egy könyv objektum is a folyamat során
    Book b;

    //Inditsuk el a folyamat ciklust ami terminalasig/megtelesig olvassa be a konyvek meretet
    try
    {
        s.folyamat(b);
    }

    //Ez a resz feelos azert, hogy ha esetleg valami rosszul sül el akkor elkapja a kivételt
    catch(...){cout<<"ERROR";}

    return 0;
}
