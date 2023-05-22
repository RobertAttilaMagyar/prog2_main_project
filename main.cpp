//Magyar R�bert Attila [BIXYQG]
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
    //El�sz�r kezdj�k az alapokkal, hozzuk l�tre a k�nyvesszekrenyt
    std::cout<<"Adja meg a konyvespolcok meretet!"<<std::endl;
    int n;
    cin>>n;
    Szekreny s(n);

    //Sz�ks�ges lesz egy k�nyv objektum is a folyamat sor�n
    Book b;

    //Inditsuk el a folyamat ciklust ami terminalasig/megtelesig olvassa be a konyvek meretet
    try
    {
        s.folyamat(b);
    }

    //Ez a resz feelos azert, hogy ha esetleg valami rosszul s�l el akkor elkapja a kiv�telt
    catch(...){cout<<"ERROR";}

    return 0;
}
