//Magyar Róbert Attila [BIXYQG]
#ifndef MEDIUMSHELF_H
#define MEDIUMSHELF_H
#include "Book.h"
#include "Shelf.h"
#include "SmallShelf.h"

//Azért a SmallShelf leszarmazottja, mert tud 's' méretû könyvet is felrakni, azaz tud mindent amis SmallShelf, csak ez 'm'-et is
class MediumShelf: public SmallShelf
{
    public:
    MediumShelf(const int n):SmallShelf(n) {}
    void felrak(Book &b);
    ~MediumShelf(){delete []t; }
};

#endif // MEDIUMSHELF_H
