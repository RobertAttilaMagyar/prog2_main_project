//Magyar R�bert Attila [BIXYQG]
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
    Shelf* t[3]; //Lehetne bonyolitani, de a feladat szempontjabol teljesen j�, ha tudja, hogy 3 konyvespolc van
public:

    Szekreny(int n = 5); //Kell egy konstruktor
    void Pakol(Book &b); //Kell egy pakol f�ggv�ny, ez felel�s azert hogy ne �ssze vissza legyenek a k�nyvek
    //Legyen egy kiiro operator, hogy egyszer�bb legyen a tesztel�ben a dolgunk.
    friend ostream& operator <<(ostream& out,const Szekreny SZ)
     {
        out<<"A polcokon talalhato konyvek, fentrol\nlefele: (S,M,L)  meretu polcok: \n";
        for(int i = 0; i < 3; ++i)
            out << *SZ.t[i]<<'\n';

        return out;
    }
    //A konstruktor h�v�s sor�n mi hozunk l�tre �j polcokat, ez�rt gondoskodnunk kell a megsemmi�t�s�kr�l
    ~Szekreny(){
      for(int i = 0; i < 3; ++i)
        delete t[i];
    }

    //Az eg�sz t�m�rs�ge miatt lesz egy folyamat f�ggv�ny, ez v�gzi el igaz�b�l a feladatot, ennek kell a legokosabbnak lennie
    void folyamat(Book &b);
};
#endif // SZEKRENY_H
