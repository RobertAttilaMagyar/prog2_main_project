//Magyar Róbert Attila [BIXYQG]
#ifndef SZEKRENY_H
#define SZEKRENY_H
#include <iostream>
#include "Book.h"
#include "Shelf.h"
#include "SmallShelf.h"
#include "MediumShelf.h"
#include "LargeShelf.h"

using namespace std;

//Csinaljunk egy szekreny osztalyt, ez lesz az okos aki hasznalja az elozoekben definialt kepessegeket
class Szekreny
{
private:
    Shelf* t[3]; //Lehetne bonyolitani, de a feladat szempontjabol teljesen jó, ha tudja, hogy 3 konyvespolc van
public:

    Szekreny(int n = 5); //Kell egy konstruktor
    void Pakol(Book &b); //Kell egy pakol függvény, ez felelõs azert hogy ne össze vissza legyenek a könyvek
    //Legyen egy kiiro operator, hogy egyszerûbb legyen a tesztelõben a dolgunk.
    friend ostream& operator <<(ostream& out,const Szekreny SZ)
     {
        out<<"A polcokon talalhato konyvek, fentrol\nlefele: (S,M,L)  meretu polcok: \n";
        for(int i = 0; i < 3; ++i)
            out << *SZ.t[i]<<'\n';

        return out;
    }
    //A konstruktor hívás során mi hozunk létre új polcokat, ezért gondoskodnunk kell a megsemmiítésükrõl
    ~Szekreny(){
      for(int i = 0; i < 3; ++i)
        delete t[i];
    }

    //Az egész tömörsége miatt lesz egy folyamat függvény, ez végzi el igazából a feladatot, ennek kell a legokosabbnak lennie
    void folyamat(Book &b);
};
#endif // SZEKRENY_H
