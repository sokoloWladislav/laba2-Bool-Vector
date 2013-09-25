#include "boolvector.h"
#include <iostream>

using namespace std;

BoolVector::BoolVector():
    n(0),
    array(0)
{}

BoolVector::BoolVector(int x):
    n(x),array(new Data[n])
{
    for(int i=0; i<n; ++i)
        array[i]=0;
}

/*BoolVector::BoolVector(int x, Data *ar):
    n(x), array(new Data[n])
{
    for(int i=0; i<n; ++i)
        array[i]=ar[i];
}*/

BoolVector::~BoolVector()
{
    for(int i=0; i<n; ++i)
        array[i]=0;
    delete []array;
    array=0;
}

BoolVector::BoolVector(const BoolVector& other)
{
    n=other.n;
    array=new Data[n];
    for(int i=0; i<n; ++i)
        array[i]=other.array[i];
}

BoolVector& BoolVector::operator=(const BoolVector &other)
{
    if(this!=&other)
    {
        delete[] array;
        n=other.n;
        array=new Data[n];
        for(int i=0; i<n; ++i)
            array[i]=other.array[i];
    }
    return *this;
}

void BoolVector::displayVector()
{
    for(int i=0; i<get_n(); ++i)
        cout << getVector()[i] << ' ';
    cout << endl;
}

void BoolVector::inputVector()
{
    for(int i=0; i<n; ++i)
        cin >> array[i];
}

BoolVector BoolVector::conunction(BoolVector A)
{
    BoolVector C=*this;
    if(n==A.n)
    {
        for(int i=0; i<n; ++i)
            if(array[i])
            {
                if(!A.array[i])
                    C.array[i]=0;
            }
    }
    return C;
}

BoolVector BoolVector::disunction(BoolVector A)
{
    BoolVector C=*this;
    if(n==A.n)
    {
        for(int i=0; i<n; ++i)
            if(!array[i])
            {
                if(A.array[i])
                    C.array[i]=1;
            }
    }
    return C;
}

BoolVector BoolVector::notVector()          //отрицание вектора
{
    for(int i=0; i<n; ++i)
        array[i]=!array[i];
    return *this;
}

int BoolVector::numberOf(Data x)        //число цифр х в векторе(1 и 0 в нашем случае)
{
    int k=0;
    for(int i=0; i<n; ++i)
        if(array[i]==x)
            ++k;
    return k;
}

BoolVector::BoolVector(BoolVector& other):      //конструктор перемещения
    n(0), array(0)
{
    n=other.n;
    array=new Data[n];
    for(int i=0; i<n; ++i)
        array[i]=other.array[i];
    array=other.array;
    for(int i=0; i<n; ++i)
        other.array[i]=0;
    delete[] other.array;
    other.n=0;
    other.array=0;
}

BoolVector& BoolVector::operator=(BoolVector& other)        //оператор перемеўения
{
    if(this!=&other)
    {
        delete[] array;
        n=other.n;
        array=new Data[n];
        array=other.array;
        other.n=0;
        delete[] other.array;
        other.array=0;
    }
    return *this;
}
