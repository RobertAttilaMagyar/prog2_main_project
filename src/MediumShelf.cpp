//Magyar R�bert Attila [BIXYQG]
#include "MediumShelf.h"

void MediumShelf::felrak(Book &b)
{
        if(!this->tele())
        {
            int k = this->iter();
            //Mivel 's'et is fel tudja rakni ezert el�sz�r SmallShelf felrak f�ggv�nye fut le
            SmallShelf::felrak(b);
            //Ha 'm' m�ret�, kkor itt is megcsinalja a cser�t
            if( b.getsize() == 'm')
            {
                t[k].SWAP(b);
                EMPTY--;
            }
        }
}
