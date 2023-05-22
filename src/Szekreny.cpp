//Magyar Róbert Attila [BIXYQG]
#include "Szekreny.h"

//A konstruktor létrehoz 3 polcot, egy kicsit, egy közepeset és egy nagyot.
Szekreny::Szekreny(int n)
{
    //A sorrend fontos, a Pakol függvény ugyanis nem mindegy milyen sorrendben kapja meg ezeket
    t[0] = new SmallShelf(n);
    t[1] = new MediumShelf(n);
    t[2] = new LargeShelf(n);
}

//A pakol függvény felelõs azért, hogy jól helyezzük el a könyveket
void Szekreny::Pakol(Book &b)
{
    try
    {
        //Ha megfelelõ mértû könyv érkezik, akkor megpróbálja felrakni
        if(b.getsize() == 's' || b.getsize() == 'm'|| b.getsize() == 'l')
        {
            //Végigmegy a polcokon növekvõ sorrendben, ahova elõször befér egy könyv oda rakja
            for(int i = 0; i < 3; ++i)
                t[i]->felrak(b);
            //A folyamat eldönti hogy szabalyos e a meret, ha nem sikerült sehol üresre cserélni, akkor ki kell írnia, hogy ez nem megvalositható
            if(b.getsize() != '0')
                cout<<"Nem lehet tobb '" << b.getsize() << "' meretu konyvet felhelyezni!" << endl;
        }
        //Ha nem érvényes könyvméret érkezik, akkor kivételt kell dobni.
        else
        {
            throw b.getsize();
        }
    }

    //Az érvénytelen karaktert itt kell elkapnunk
    catch(char c)
    {
        cout << "'"<<c<<"'"<< " nem ervenyes konyvmeret\n";
    }
}

//Ez a függvény alapvetõen a tesztelõbe is kerülhetett volna, csak oda igazán kevés dolgot szerettem volna írni
void Szekreny::folyamat(Book &b)
{
    //Elõször bekérjük a könyveket, vagyis jobban mondva az elsõt, a többit majd a ciklusban
    cout<<"Adja meg a beerkezo konyvek meretet (s,m,l)!\nA beolvasast a '0' karakterrel terminalhatja \n";
    cin>>b;

    try
    {
        while(b.getsize() != '0') //Alap esetben a termináló jelig olvas
        {
            this->Pakol(b);
            //Ha megtelt az összes polc kivételt dob és ekkor kilép a ciklusból
            if(t[0]->tele() && t[1]->tele() && t[2] -> tele())
            {
                throw true;
            }
            cin>>b;
        }
    }
    //Ha tele van az összes polc akkor itt kapja el a kivételt, a cikluson kívül, hogy ilyenkor már ne kérjen be új könyvet
    catch(bool b)
    {
        if(b)cout<<"A polcrendszer megtelt!\n";
    }
    catch(...) //Az egyéb hibát továbbdobjuk
    {
        throw;
    }

    //A folyamat végén mindenképp írja ki a polcok állását
    cout<<*this;
}
