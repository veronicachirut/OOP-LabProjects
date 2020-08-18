#include <iostream>
#include "Nod.h"
#include "List.h"

using namespace std;

int main()
{
    List *l;
    int n, i, x, p;
    cout << "Numarul de liste: ";
    cin >> n;
    l = new List[n];
    cout << endl;

    //Citire liste
    for(i = 0; i < n; i++)
    {
        cout << "Lista " << i + 1 << endl;
        cin >> l[i];
        cout << endl;
    }
    cout << endl;

    //Afisare liste
    for(i = 0; i < n; i++)
    {
        cout << "Lista "<< i + 1 << ": ";
        cout << l[i] << endl;
    }
    cout << endl;

    //Inserare element
    cout << "In care lista vrei sa inserezi? ";
    cin >> i;
    cout << "Ce element vrei sa inserezi? ";
    cin >> x;
    cout << "Pe ce pozitie vrei sa inserezi? ";
    cin >> p;
    l[i-1].insertAt(x, p-1);
    cout << "Lista dupa inserare: " << l[i-1] << endl;

    //Stergerea unui element
    cout << endl << "Din care lista vrei sa stergi? ";
    cin >> i;
    cout << "Ce element vrei sa stergi? ";
    cin >> x;
    l[i-1].remove_element(x);
    cout << "Lista dupa stergere: ";
    cout << l[i-1] << endl;

    //Stergerea unui element de pe pozitie
    cout << endl << "Din care lista vrei sa stergi? ";
    cin >> i;
    cout << "De pe ce pozitie vrei sa stergi? ";
    cin >> x;
    l[i-1].remove_pozitie(x);
    cout << "Lista dupa stergere: ";
    cout << l[i-1] << endl;

    //Afisare liste
    cout << endl;
    for(i = 0; i < n; i++)
    {
        cout << "Lista "<< i + 1 << ": ";
        cout << l[i] << endl;
    }
    //cout << endl;

    //Cautarea pozitiei unui element
    cout << endl << "Din care lista vrei sa cauti? ";
    cin >> i;
    cout << "Introdu un element: ";
    cin >> x;
    cout << "Pozitia elementului " << x << " este: " << l[i-1].get_pozitie(x);
    cout << endl;

    //Cautarea unui element dupa pozitie
    cout << endl << "Din care lista vrei sa cauti? ";
    cin >> i;
    cout << "De pe ce pozitie? ";
    cin >> x;
    cout << "Elementul de pe pozitia " << x << " din lista " << i << " este: " << l[i - 1].get_element(x);
    cout << endl;

    //Supraıncarcarea operatorului [ ] pentru accesarea elementului de pe pozitia i
    cout << endl;
    cout << "Lista dorita: ";
    cin >> i;
    cout << "Pozitia dorita: ";
    cin >> x;
    cout << "l[" << i << "][" << x << "]=" << l[i - 1][x] << endl;

    //Supraıncarcarea operatorului + care sa efectueze reuniunea a doua liste
    cout << endl;
    List lista;
    cout << "Care sunt cele 2 liste pe care vrei sa le reunesti? ";
    cin >> i >> x;
    cout << "Reuniunea: ";
    lista = l[i - 1] + l[x - 1];
    cout << lista << endl;

    //Suma elementelor listei
    cout << endl;
    cout << "Din ce lista vrei sa obtii suma? ";
    cin >> i;
    cout << "Suma elementelor este: " << l[i - 1].suma() << endl;

    //Compararea a doua liste
    cout << endl;
    cout << "Ce liste vrei sa compari? ";
    cin >> i >> x;
    lista = l[i - 1] < l[x - 1];
    cout << "Lista cu suma mai mica este: " << lista << endl;

    //Compararea a doua liste
    cout << endl;
    cout << "Ce liste vrei sa compari? ";
    cin >> i >> x;
    lista = l[i - 1] > l[x - 1];
    cout << "Lista cu suma mai mare este: " << lista << endl;

    //Inmultirea cu un scalar
    cout << endl;
    cout << "Cu ce numar vrei sa inmultesti? ";
    cin >> x;
    cout << "Ce lista vrei sa o inmultesti cu " << x << "? ";
    cin >> i;
    lista = l[i-1] * x;
    cout << "Lista va arata asa: " << lista << endl;

    //Numarul de elemente din lista
    cout << endl;
    cout << "Din ce lista vrei sa aflii numerul de elemente? ";
    cin >> i;
    cout << "Are " << l[i - 1].numar_elemente() << " elemente" << endl;

    //Maximul/minimul din lista
    cout << endl;
    cout << "Din ce lista vrei sa aflii maximul/minimul? ";
    cin >> i;
    l[i - 1].maxim_minim();
    return 0;
}
