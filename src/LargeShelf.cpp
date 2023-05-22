//Magyar Róbert Attila [BIXYQG]
#include "LargeShelf.h"

void LargeShelf::felrak(Book &b)
{
    if(!this->tele())
        {
            int k = this->iter();
            //Eloszor SS és MS fut le, mert ha 's' vagy 'm' meretu a cucc akkor fel lehet rakni ide is
            SmallShelf::felrak(b);
            MediumShelf::felrak(b);
            //És ugye ez az 'l' méretû könyveket is fel tudja rakni
            if( b.getsize() == 'l')
            {
                t[k].SWAP(b);
                EMPTY--;
            }
        }
}
