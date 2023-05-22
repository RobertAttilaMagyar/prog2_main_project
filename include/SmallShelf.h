//Magyar Róbert Attila [BIXYQG]
#ifndef SMALLSHELF_H
#define SMALLSHELF_H
#include <iostream>
#include "Book.h"
#include "Shelf.h"

//A kis polc annyit tud a sima polchoz képest, hogy a felrak fv tud felrakni kicsi könyveket
class SmallShelf : public Shelf
{
    public:
    //Hozzunk létre neki egy konstruktort
    SmallShelf(const int n = 5):Shelf(n) {}
    //Inicializáljuk a felrak függvényt
    void felrak(Book &b);
    ~SmallShelf(){delete []t;}
};

#endif // SMALLSHELF_H
