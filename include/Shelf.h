//Magyar Róbert Attila [BIXYQG]
#ifndef SHELF_H
#define SHELF_H
#include <iostream>
#include "Book.h"

using namespace std;

//Készítsünk egy default shelf osztalyt
class Shelf
{
public:
    //A könyvespolcoknak szüksége van egy könyvek számára létrehozott memóriacíra
    Book* t;
    //Ezen felül van egy maximális méret, illetve jellemzi még, hogy hány üres hely van rajta.
    int MAXSIZE;
    int EMPTY;

    //Konstruktor:
    Shelf(const int n = 5)
    {
        //Itt létrehozunk a "t" memóriacímre egy n méretû tömböt és meghatározzuk a maximalis meretet
        t = new Book[n];
        MAXSIZE = n;
        //Kezdetben az összes hely üres
        EMPTY = n;
    }

    //Készítsünk egy indexelõ operátort.
    Book operator[](int k)const
    {
        return t[k];
    }
    //Itt kérszítsünk egy kiíró operátort
    friend ostream& operator <<(ostream& out,const Shelf s)
    {
        //Ez a könyvek méretét tudja csak kiírni
        for(int i = 0; i<s.MAXSIZE; ++i)
            out<<s[i].getsize();

        return out;
    }
    //A felrak függvénynek virtuálisnak kell lennie a késõbbiek miatt
    //Majd a leszármazottakban meghatározzuk a mûködését
    virtual void felrak(Book &b) { }

    //Rakok bele egy bool mértéket, mert ha megtelik az összes polc akkor szeretném hogy arról értesüljön a felhasználó
    bool tele()
    {
        return (EMPTY == 0);
    }
    //Kéne egy iterátor mennyiség, ami megmondja, hogy éppen melyik helyre kell felrakni a polcon a könyvet
    int iter()
    {
        return (MAXSIZE - EMPTY);
    }

    //A helyes memóriakezelés érdekében virtuális destruktor szükséges
    virtual ~Shelf() {delete []t;}
};

#endif // SHELF_H
