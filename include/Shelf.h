//Magyar R�bert Attila [BIXYQG]
#ifndef SHELF_H
#define SHELF_H
#include <iostream>
#include "Book.h"

using namespace std;

//K�sz�ts�nk egy default shelf osztalyt
class Shelf
{
public:
    //A k�nyvespolcoknak sz�ks�ge van egy k�nyvek sz�m�ra l�trehozott mem�riac�ra
    Book* t;
    //Ezen fel�l van egy maxim�lis m�ret, illetve jellemzi m�g, hogy h�ny �res hely van rajta.
    int MAXSIZE;
    int EMPTY;

    //Konstruktor:
    Shelf(const int n = 5)
    {
        //Itt l�trehozunk a "t" mem�riac�mre egy n m�ret� t�mb�t �s meghat�rozzuk a maximalis meretet
        t = new Book[n];
        MAXSIZE = n;
        //Kezdetben az �sszes hely �res
        EMPTY = n;
    }

    //K�sz�ts�nk egy indexel� oper�tort.
    Book operator[](int k)const
    {
        return t[k];
    }
    //Itt k�rsz�ts�nk egy ki�r� oper�tort
    friend ostream& operator <<(ostream& out,const Shelf s)
    {
        //Ez a k�nyvek m�ret�t tudja csak ki�rni
        for(int i = 0; i<s.MAXSIZE; ++i)
            out<<s[i].getsize();

        return out;
    }
    //A felrak f�ggv�nynek virtu�lisnak kell lennie a k�s�bbiek miatt
    //Majd a lesz�rmazottakban meghat�rozzuk a m�k�d�s�t
    virtual void felrak(Book &b) { }

    //Rakok bele egy bool m�rt�ket, mert ha megtelik az �sszes polc akkor szeretn�m hogy arr�l �rtes�lj�n a felhaszn�l�
    bool tele()
    {
        return (EMPTY == 0);
    }
    //K�ne egy iter�tor mennyis�g, ami megmondja, hogy �ppen melyik helyre kell felrakni a polcon a k�nyvet
    int iter()
    {
        return (MAXSIZE - EMPTY);
    }

    //A helyes mem�riakezel�s �rdek�ben virtu�lis destruktor sz�ks�ges
    virtual ~Shelf() {delete []t;}
};

#endif // SHELF_H
