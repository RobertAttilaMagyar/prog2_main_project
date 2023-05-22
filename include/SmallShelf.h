//Magyar R�bert Attila [BIXYQG]
#ifndef SMALLSHELF_H
#define SMALLSHELF_H
#include <iostream>
#include "Book.h"
#include "Shelf.h"

//A kis polc annyit tud a sima polchoz k�pest, hogy a felrak fv tud felrakni kicsi k�nyveket
class SmallShelf : public Shelf
{
    public:
    //Hozzunk l�tre neki egy konstruktort
    SmallShelf(const int n = 5):Shelf(n) {}
    //Inicializ�ljuk a felrak f�ggv�nyt
    void felrak(Book &b);
    ~SmallShelf(){delete []t;}
};

#endif // SMALLSHELF_H
