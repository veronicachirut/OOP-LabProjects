#ifndef LIST_H
#define LIST_H
#include "Nod.h"
#include <iostream>
using namespace std;

class List:public Nod
{
    Nod *start, *end;
    int size;
    public:
        List();
        List(int);
        List(List&);
        void insertAt(int, int);
        void insert(int);
        void remove_element(int);
        void remove_pozitie(int);
        int get_pozitie(int);
        int get_element(int);
        friend ostream& operator<<(ostream&, List&);
        friend istream& operator>>(istream&, List&);
        int operator[](int);
        friend List operator+(List&, List&);
        int suma();
        List reverse();
        friend List operator<(List&, List&);
        friend List operator>(List&, List&);
        friend List operator*(List&, int&);
        int numar_elemente();
        void maxim_minim();
        ~List();
};

#endif // LIST_H
