//Magyar Róbert Attila [BIXYQG]
#ifndef LARGESHELF_H
#define LARGESHELF_H
#include "Book.h"
#include "Shelf.h"
#include "SmallShelf.h"
#include "MediumShelf.h"

//Mindent tud amit MS, csak l-et is fel lehet rakni ---> MS leszarmazottja lesz
class LargeShelf:public MediumShelf
{
    public:
    LargeShelf(const int n):MediumShelf(n) {}
    void felrak(Book &b);
    ~LargeShelf(){delete []t;}
};

#endif // LARGESHELF_H
