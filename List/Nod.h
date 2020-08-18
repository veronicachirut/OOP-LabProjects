#ifndef NOD_H
#define NOD_H


class Nod
{
    int info;
    Nod* next;
    public:
        Nod();
        Nod(int, Nod*);
        void setInfo(int);
        void setNext(Nod*);
        int getInfo();
        Nod* getNext();

};

#endif // NOD_H
