//Magyar R�bert Attila [BIXYQG]
#include "SmallShelf.h"

void SmallShelf::felrak(Book &b)
    {
        //Csak akkor fusson le ha az adott polc nincs tele
        if(!this->tele())
        {
            //Itt igaz�b�l egy �res '0' helyet kell kicser�lnie egy 's' m�ret�re
            //Ez igazabol felesleges, de sokkal �tl�that�bb, meg egyszer�bb ha nem mindenhova this->iter() megy
            int k = this->iter();
            //Fontos, hogy ez csak 's' m�ret�t tudjon felrakni
            if( b.getsize() == 's')
            {
                t[k].SWAP(b);
                EMPTY--; //Az �res helyek sz�ma ilyenkor 1-el cs�kken
            }
        }
    }
