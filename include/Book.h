//Magyar Róbert Attila [BIXYQG]
#ifndef BOOK_H
#define BOOK_H
#include <iostream>

using namespace std;
class Book
{

private:
    //A könyvnek kell, hogy legyen egy mérete
    char SIZE;

public:
    //A rend kevéért kell egy konstruktor
    Book(const char c = '0')
    {
        SIZE = c;
    }
    //A kiíráshoz kell egy getter
    char getsize()const
    {
        return SIZE;
    }
    //Beolvasó operátor felülírása, hogy a felhasználó tudja megadni a könyvespolcok méretét
    friend istream& operator >>(istream &in, Book &b)
    {
        in>>b.SIZE;
        if(b.SIZE != 's' && b.SIZE != 'm' && b.SIZE != 'l');
        return in;
    }
    //A könyvek beolvasásához a szetter:
    void setsize(const char c)
    {
        SIZE = c;
    }

    void operator&=(Book &b){
        this->SIZE = b.SIZE;
    }
    ~Book(){ }

    //Készítsünk egy olyan függvényt, amely kicserél két könyvet
    void SWAP(Book &b)
    {
        Book temp = *this;
        *this = b;
        b = temp;
    }
};

#endif // BOOK_H
