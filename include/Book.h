//Magyar R�bert Attila [BIXYQG]
#ifndef BOOK_H
#define BOOK_H
#include <iostream>

using namespace std;
class Book
{

private:
    //A k�nyvnek kell, hogy legyen egy m�rete
    char SIZE;

public:
    //A rend kev��rt kell egy konstruktor
    Book(const char c = '0')
    {
        SIZE = c;
    }
    //A ki�r�shoz kell egy getter
    char getsize()const
    {
        return SIZE;
    }
    //Beolvas� oper�tor fel�l�r�sa, hogy a felhaszn�l� tudja megadni a k�nyvespolcok m�ret�t
    friend istream& operator >>(istream &in, Book &b)
    {
        in>>b.SIZE;
        if(b.SIZE != 's' && b.SIZE != 'm' && b.SIZE != 'l');
        return in;
    }
    //A k�nyvek beolvas�s�hoz a szetter:
    void setsize(const char c)
    {
        SIZE = c;
    }

    void operator&=(Book &b){
        this->SIZE = b.SIZE;
    }
    ~Book(){ }

    //K�sz�ts�nk egy olyan f�ggv�nyt, amely kicser�l k�t k�nyvet
    void SWAP(Book &b)
    {
        Book temp = *this;
        *this = b;
        b = temp;
    }
};

#endif // BOOK_H
