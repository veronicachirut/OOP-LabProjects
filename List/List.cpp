#include "List.h"
#include "Nod.h"

using namespace std;

//Constructor fara parametri
List::List()
{
    start = end = NULL;
    size = 0;
}

//Constructor cu parametri
List::List( int x )
{
    start = end = new Nod( x, NULL );
    size = 1;
}

//Constructoe de copiere
List::List( List& l )
{
    start = end = NULL;
    size = 0;
    Nod* p = l.start;
    while( p != NULL )
    {
        insert( p->getInfo() );
        p = p->getNext();
    }
}

//Inserarea elementului x pe pozitia i in lista
void List::insertAt( int x, int i )
{
    if( start == NULL )
    {
        start = end = new Nod(x, NULL);
        size = 1;
        return;
    }
    Nod* p = new Nod(x, NULL);

    //Tratez cazurile in care pozitia < 0 sau depaseste numarul curent de elemente ale listei
    if(i < 0 || i > size)
    {
        p->setNext(start);
        start = p; //Aduc elementele pe prima pozitie
        size++;
        return;
    }
    Nod* o = start;
    for( int j = i; j > 1; j--)
        o = o->getNext();
    p->setNext( o->getNext() );
    o->setNext(p);
    size++;
}

//Inserarea unui element la inceputul listei
void List::insert( int x )
{
    insertAt(x, size + 1);
}

//Stergerea unui element din lista
void List::remove_element( int x )
{
    Nod* p = start;
    if(p == NULL)
    {
        std::cout << "Lista vida";
        std::cout << endl;
        return;
    }
    Nod* last = NULL;
    while(p != NULL && p->getInfo()!= x)
    {
        last = p;
        p = p->getNext();
    }
    if(p == NULL)
    {
        std::cout << "Acest element nu se gaseste";
        std::cout << endl;
        return;
    }
    if(p == start)
    {
        start = start->getNext();
        if(start == end)
            end = NULL;
        delete p;
        return;
    }
    if(p == end)
    {
        last->setNext(NULL);
        end = last;
        delete p;
        return;
    }
    last->setNext(p->getNext());
    delete p;
}

//Stergerea unui element de pe o anumita pozitie
void List::remove_pozitie( int i )
{
    int k = 1;
    Nod* p = start;
    if(p == NULL)
    {
        std::cout << "Lista vida";
        std::cout << endl;
        return;
    }
    Nod* last = NULL;
    while(p != NULL && k != i)
    {
        k++;
        last = p;
        p = p->getNext();
    }
    if(p == NULL || i < 0)
    {
        std::cout << "Something is wrong";
        std::cout << endl;
        return;
    }
    if(p == start)
    {
        start = start->getNext();
        delete p;
        return;
    }
    if(p == end)
    {
        end->setNext(NULL);
        end = last;
        delete p;
        return;
    }
    last->setNext( p->getNext() );
    delete p;
}

//Cauta pozitia unui element in lista
int List::get_pozitie( int x )
{
    int k = 0;
    Nod* p = start;
    if(p == NULL)
    {
        std::cout << "Lista vida";
        std::cout << endl;
        return 0;
    }
    while(p != NULL)
    {
        k++;
        if(p->getInfo() == x)
            return k;
        p = p->getNext();
    }
    return -1; //Daca elementul nu se afla in lista returnez -1
}

//Cauta un element de pe o anumita pozitie
int List::get_element( int i )
{
    int k = 0;
    Nod* p = start;
    if(p == NULL)
    {
        std::cout << "Lista vida";
        std::cout << endl;
        return 0;
    }
    while(p != NULL && k <= i)
    {
        k++;
        if(k == i)
            return p->getInfo();
        p = p->getNext();
    }
    return -1;
}

//Supraincarcarea operatorului <<
ostream& operator<<(ostream& out, List& l)
{
    Nod* p = l.start;
    if(p == NULL)
    {
        std::cout << "Lista vida";
        std::cout << endl;
        return out;
    }
    while(p != NULL)
    {
        std::cout << p->getInfo() << ' ';
        p=p->getNext();
    }
    std::cout<<"\b ";
    return out;
}

//Supraincarcarea operatorului >>
istream& operator>>(istream& in, List& l)
{
    int x, m, j;
    std::cout << "Numarul de elemente: ";
    std::cin >> m;
    std::cout << "Elementele: ";
    for(j = 0; j < m; j++)
    {
        std::cin >> x;
        l.insertAt(x, j);
    }
    return in;
}

//Supraıncarcarea operatorului [ ] pentru accesarea elementului de pe pozitia i
int List::operator[]( int i )
{
    return get_element(i);
}

//Supraıncarcarea operatorului + care sa efectueze reuniunea a doua liste
List operator + ( List& l1, List& l2 )
{
    List l;
    Nod* p = l1.start;
    int k = 0;
    while(p != NULL)
    {
        l.insertAt(p->getInfo(), k);
        k++;
        p = p->getNext();
    }
    p = l2.start;
    while(p != NULL)
    {
        l.insertAt(p->getInfo(), k);
        k++;
        p = p->getNext();
    }
        return l;
}

//Obtinerea sumei elementelor din lista
int List::suma()
{
    int S = 0;
    Nod* p = start;
    if(p == NULL)
    {
        std::cout << "Lista vida";
        std::cout << endl;
        return 0;
    }
    while(p != NULL)
    {
        S = S + p->getInfo();
        p = p->getNext();
    }
    return S;
}

//Inversarea elementelor din lista
List List::reverse()
{
	List l;
	Nod *p = start;
	while (p != NULL)
    {
		l.insert(p->getInfo());
		p = p->getNext();
	}
	return l;
}

//Supraıncarcarea operatorului < care compara doua liste
List operator < ( List& l1, List& l2 )
{
    if(l1.suma() < l2.suma())
    {
        l1 = l1.reverse(); // Inversez lista pentru ca, aparent, mi-o retureaza pe dos si nu am gasit explicatia
        return l1;
    }
    else
    {
        l2 = l2.reverse();
        return l2;
    }
}

//Supraıncarcarea operatorului > care compara doua liste
List operator > ( List& l1, List& l2 )
{
    if(l1.suma() > l2.suma())
    {
        l1 = l1.reverse();
        return l1;
    }
    else
    {
        l2 = l2.reverse();
        return l2;
    }
}

//Supraıncarcarea operatorului * pentru ınmultirea cu un scalar
List operator * ( List& l1, int& a )
{
    List l;
    Nod *p = l1.start;
	while (p != NULL)
    {
		l.insert(p->getInfo() * a);
		p = p->getNext();
	}
	l = l.reverse();
	return l;
}

//Obtinerea numarului de elemente din lista
int List::numar_elemente()
{
    int nr = 0;
	Nod *p = start;
	if(p == NULL)
    {
        std::cout << "Lista vida";
        std::cout << endl;
        return 0;
    }
	while (p != NULL)
    {
		nr++;
		p = p->getNext();
	}
	return nr;
}

//Determinarea elementului minim si maxim din lista
void List::maxim_minim()
{
	int min = start->getInfo(), max = start->getInfo();
	Nod *p = start;
	if(p == NULL)
    {
        std::cout << "Lista vida";
        std::cout << endl;
        return;
    }
    p = p->getNext();
	while (p != NULL)
    {
		if(p->getInfo() < min)
            min = p->getInfo();
        else
            if(p->getInfo() > max)
            max = p->getInfo();
		p = p->getNext();
	}
	std::cout << "Minimul: " << min << endl << "Maximul: " << max;
}

//Destructor
List::~List()
{
	Nod *p = start, *o;
	while (p != NULL)
    {
		o = p;
		p = p->getNext();
		delete o;
	}
	start = end = NULL;
	size = 0;
}
