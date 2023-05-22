//Magyar Róbert Attila [BIXYQG]
#include "MediumShelf.h"

void MediumShelf::felrak(Book &b)
{
        if(!this->tele())
        {
            int k = this->iter();
            //Mivel 's'et is fel tudja rakni ezert elõször SmallShelf felrak függvénye fut le
            SmallShelf::felrak(b);
            //Ha 'm' méretû, kkor itt is megcsinalja a cserét
            if( b.getsize() == 'm')
            {
                t[k].SWAP(b);
                EMPTY--;
            }
        }
}
