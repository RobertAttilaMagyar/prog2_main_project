//Magyar Róbert Attila [BIXYQG]
#include "SmallShelf.h"

void SmallShelf::felrak(Book &b)
    {
        //Csak akkor fusson le ha az adott polc nincs tele
        if(!this->tele())
        {
            //Itt igazából egy üres '0' helyet kell kicserélnie egy 's' méretûre
            //Ez igazabol felesleges, de sokkal átláthatóbb, meg egyszerûbb ha nem mindenhova this->iter() megy
            int k = this->iter();
            //Fontos, hogy ez csak 's' méretût tudjon felrakni
            if( b.getsize() == 's')
            {
                t[k].SWAP(b);
                EMPTY--; //Az üres helyek száma ilyenkor 1-el csökken
            }
        }
    }
