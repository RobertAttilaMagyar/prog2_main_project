//Magyar R�bert Attila [BIXYQG]
#include "LargeShelf.h"

void LargeShelf::felrak(Book &b)
{
    if(!this->tele())
        {
            int k = this->iter();
            //Eloszor SS �s MS fut le, mert ha 's' vagy 'm' meretu a cucc akkor fel lehet rakni ide is
            SmallShelf::felrak(b);
            MediumShelf::felrak(b);
            //�s ugye ez az 'l' m�ret� k�nyveket is fel tudja rakni
            if( b.getsize() == 'l')
            {
                t[k].SWAP(b);
                EMPTY--;
            }
        }
}
