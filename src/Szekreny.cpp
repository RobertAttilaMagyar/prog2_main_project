//Magyar R�bert Attila [BIXYQG]
#include "Szekreny.h"

//A konstruktor l�trehoz 3 polcot, egy kicsit, egy k�zepeset �s egy nagyot.
Szekreny::Szekreny(int n)
{
    //A sorrend fontos, a Pakol f�ggv�ny ugyanis nem mindegy milyen sorrendben kapja meg ezeket
    t[0] = new SmallShelf(n);
    t[1] = new MediumShelf(n);
    t[2] = new LargeShelf(n);
}

//A pakol f�ggv�ny felel�s az�rt, hogy j�l helyezz�k el a k�nyveket
void Szekreny::Pakol(Book &b)
{
    try
    {
        //Ha megfelel� m�rt� k�nyv �rkezik, akkor megpr�b�lja felrakni
        if(b.getsize() == 's' || b.getsize() == 'm'|| b.getsize() == 'l')
        {
            //V�gigmegy a polcokon n�vekv� sorrendben, ahova el�sz�r bef�r egy k�nyv oda rakja
            for(int i = 0; i < 3; ++i)
                t[i]->felrak(b);
            //A folyamat eld�nti hogy szabalyos e a meret, ha nem siker�lt sehol �resre cser�lni, akkor ki kell �rnia, hogy ez nem megvalosithat�
            if(b.getsize() != '0')
                cout<<"Nem lehet tobb '" << b.getsize() << "' meretu konyvet felhelyezni!" << endl;
        }
        //Ha nem �rv�nyes k�nyvm�ret �rkezik, akkor kiv�telt kell dobni.
        else
        {
            throw b.getsize();
        }
    }

    //Az �rv�nytelen karaktert itt kell elkapnunk
    catch(char c)
    {
        cout << "'"<<c<<"'"<< " nem ervenyes konyvmeret\n";
    }
}

//Ez a f�ggv�ny alapvet�en a tesztel�be is ker�lhetett volna, csak oda igaz�n kev�s dolgot szerettem volna �rni
void Szekreny::folyamat(Book &b)
{
    //El�sz�r bek�rj�k a k�nyveket, vagyis jobban mondva az els�t, a t�bbit majd a ciklusban
    cout<<"Adja meg a beerkezo konyvek meretet (s,m,l)!\nA beolvasast a '0' karakterrel terminalhatja \n";
    cin>>b;

    try
    {
        while(b.getsize() != '0') //Alap esetben a termin�l� jelig olvas
        {
            this->Pakol(b);
            //Ha megtelt az �sszes polc kiv�telt dob �s ekkor kil�p a ciklusb�l
            if(t[0]->tele() && t[1]->tele() && t[2] -> tele())
            {
                throw true;
            }
            cin>>b;
        }
    }
    //Ha tele van az �sszes polc akkor itt kapja el a kiv�telt, a cikluson k�v�l, hogy ilyenkor m�r ne k�rjen be �j k�nyvet
    catch(bool b)
    {
        if(b)cout<<"A polcrendszer megtelt!\n";
    }
    catch(...) //Az egy�b hib�t tov�bbdobjuk
    {
        throw;
    }

    //A folyamat v�g�n mindenk�pp �rja ki a polcok �ll�s�t
    cout<<*this;
}
