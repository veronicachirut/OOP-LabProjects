#include <iostream>
using namespace std;

typedef int tip;

struct Item
{
    tip element;
    int count;
};

struct Nod
{
    Item value;
    Nod* next;
    Nod* previous;
};

template < class T >
class Multiset
{
    Nod* start;
    int counter;
public:
    Multiset();                                                             //Constructor fara parametri
    Multiset(const Multiset<T>&);                                           //Constructor de copiere
    Multiset<T> operator=(const Multiset<T>&);                              //Operatorul de atribuire
    int get(int, const tip&) const;                                         /*Daca 0<=i<elementeDistincte(), copiaza un element
                                                                                  in multiset și returneaza numarul de instanțe ale
                                                                                  acelui element in multiset*/
    void swap(Multiset&);                                                   //Schimba conținutul acestui multiset cu celălalt
    void insert(const tip&);                                                // Insereaza valoare in Multiset
    void sterge(const tip&);                                                // Sterge un element din Multiset, daca exista
    int nrAparitii(const tip&) const;                                       //Intoarce numarul de aparitii ale unui element
    bool verificare(const tip&) const;                                      //Verifica daca un element se afla in Multiset
    void stergeTot(const tip&);                                             // Elimina toate aparitiile unui element din Multiset
    int elementeDistincte() const;                                          //Intoarce nr de elemente distincte din Multiset
    friend ostream& operator<<(ostream&, const Multiset<T>&);               //Supraincarcarea operatorului de afisare, also da eroare
    ~Multiset();                                                            //Destructor
};

template < class T >
Multiset<T>::Multiset()
{
    start = NULL;
    counter = 0;
}

template < class T >
Multiset<T>::Multiset(const Multiset<T>& m)
{
    start = NULL;
    Multiset* r = new Multiset;
    for(int i = 0; i < m.elementeDistincte(); i++)
    {
        tip x;
        int a = m.get(i,x);
        for(int j = 0; j < a; j++)
        {
            r->insert(x);
        }
    }

    //Schimba datele curente cu r și apoi șterge r
    this->swap(*r);
    delete r;
}

template < class T >
Multiset<T> Multiset<T>::operator=(const Multiset<T>&m)
{
    if (&m == this)
    {
        return (*this);
    }
    delete start;
    start = NULL;

    //Creaza un nou Multiset pentru a-l umple cu date m
    counter = m.counter;
    Multiset *r = new Multiset;
    for(int i = 0; i < m.elementeDistincte(); i++)
    {
        int x;
        int a = m.get(i,x);
        for(int j = 0; j < a; j++)
        {
            r->insert(x);
        }
    }

    //Schimba datele curente cu r și apoi șterge r
    this->swap(*r);
    delete r;
    return (*this);
}

template < class T >
int Multiset<T>::get(int i, const tip& value) const
{
    if(i >= 0 && i < elementeDistincte())
    {
        int count = 0;
        Nod* p = start;
        while (p != NULL)
        {
            if(count == i)
            {
                value = p->value.element;
                return p->value.count;
            }
            count++;
            p = p->next;
        }
    }
    return 0;
}

template < class T >
void Multiset<T>::swap(Multiset<T>& m)
{
    Nod* temp = start;
    start = m.start;
    m.start = temp;

    int tempCount = counter;
    counter = m.counter;
    m.counter = tempCount;
}

template < class T >
void Multiset<T>::insert(const tip& value)
{
    if(start == NULL)
    {
        Nod* p = new Nod;
        p->value.element = value;
        p->value.count = 1;
        p->previous = p->next = NULL;
        start = p;
        counter++;
    }

    Nod *pp = start;

    while(pp != NULL)
    {
        if(value == pp->value.element)
            pp->value.count++;
        pp = pp->next;
    }


    //Adauga noua valoare daca nu exista, dar Multiset are alte elemente
    Nod* p = new Nod;
    p->value.element = value;
    p->value.count = 1;

    p->next = start;
    p->previous = NULL;
    if(p->next != NULL)
    {
        Nod* x = p->next;
        x->previous = p;
    }
    start = p;
    counter++;
}

template < class T >
void Multiset<T>::sterge(const tip& value)
{
    //Verifica daca lista e goala
    if(start == NULL)
    {
        return 0;
    }

    if(start->value.element == value && start->value.count == 1)
    {
        Nod* p = start;
        start = p->next;

        //Daca multisetul are mai mult de o valoare, seteaza precedentul NULL
        if(counter > 1)
            start->previous = NULL;
        delete p;
        counter--;
    }

        //Reduce nr de aparitii ale elementului, daca mai sunt elemente de acelasi fel
    else
    if (start->value.element == value && start->value.count > 1)
        start->value.count--;

    //Sterge aparitia oriarui altui element
    Nod *p = start;
    while(p != NULL)
    {
        if(p->next != NULL && p->next->value.element == value)
        {
            break;
        }
        p = p->next;
    }

    //Daca acea valoare nu mai are alte elemente de acelasi tip
    if(p != NULL && p->next->value.count == 1)
    {
        Nod* dest = p->next;
        p->next = dest->next;

        if(dest->next != NULL)
        {
            Nod* x = dest->next;
            x->previous = p;
        }
        delete dest;
        counter--;
    }

        //reduce nr de aparitii ale elementului daca mai exista si ale elemene de acelasi tip
    else
    if(p != nullptr && p->next->value.count > 1)
        p->next->value.count--;
}

template < class T >
int Multiset<T>::nrAparitii(const tip& value) const
{
    Nod *p = start;
    while (p != NULL)
    {
        if(value == p->value.element)
            return p->value.count;
        p = p->next;
    }
    return 0;
}

template < class T >
bool Multiset<T>::verificare(const tip& value) const
{
    Nod *p = start;
    while (p != NULL)
    {
        if(value == p->value.element)
            return true;
        p = p->next;
    }
    return false;
}

template < class T >
void Multiset<T>::stergeTot(const tip& value)
{
    Nod* p = start;
    while(p != NULL)
    {
        if(p->value.element == value)
        {
            int count = p->value.count;
            for(int i = 0; i < count; i++)
                sterge(p->value.element);
        }
        p = p->next;
    }
}

template < class T >
int Multiset<T>::elementeDistincte() const
{
    return counter;
}

template < class T >
ostream& operator<<(ostream &out, const Multiset<T>& m)                               //Imi da eroare aici
{
    Nod* p = m.start;
    if(p == NULL)
    {
        cout << "Lista vida";
        return out;
    }
    while(p != NULL)
    {
        cout << p->value.element << ' ';
        p = p->next;
    }
    cout<<"\b ";
    return out;
}

template < class T >
Multiset<T>::~Multiset()
{
    Nod* p = start;
    while (p != NULL)
    {
        Nod* x = p->next;
        delete p;
        p = x;
    }
}

int main()
{
    Multiset<int> m;
    m.insert(1);
    m.insert(2);
    cout << m;
    return 0;
}