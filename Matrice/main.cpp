#include <iostream>
#include "Matrice.h"

using namespace std;

int main()
{
    // Constructor fara parametri, care va citi numar linii, coloane si elementele matricei
    Matrice a;
    cin >> a;

    // Constructor cu parametri care va citi doar elementele matricei
    Matrice b(3,3);
    cin >> b;

    // Constructor de copiere
    Matrice c(b);
    cout << "C is obtained from c(b):"<< endl << c;

    // Supraincarcarea operatorului =
    Matrice d = a;
    cout << endl << "D is obtained from d = a:" << endl << d;

    // Supraincarcarea operatorului + pentru adunarea a doua matrici
    cout << endl << "C + D:" << endl << c + d;

    // Supraincarcarea operatorului [] pentru obtinerea liniei i
    cout << endl << "C[0]:" << endl << c[0];

    // Supraincarcarea operatorului - pentru scaderea a doua matrici
    cout << endl << "D - C:" << endl << d - c;

    // Supraincarcarea operatorului * pentru inmultirea a doua matrici
    cout << endl << "C * D:" << endl << c * d;

    // Supraincarcarea operatorului * pentru inmultirea cu un scalar
    cout << endl << "2 * C:" << endl << 2 * c;

    // Determinantul unei matrici
    cout << endl << "The determinant of C is: ";
    c.getDeterminant();
    cout << endl;

    // Determinarea inversabilitatii unei matrici
    cout << endl << "Is C invertible?" << endl;
    c.invertible();
    cout << endl;

    // Eliminarea unei linii - prin copierea in alta matrice
    cout << endl << "C without its first row" << endl << c.remove_onTheSurface("row", 1);

    // Eliminarea unei coloane - prin copierea in alta matrice
    cout << endl << "C without its third column" << endl << c.remove_onTheSurface("column", 3);

    // Eliminarea unei linii si a unei coloane - prin copierea in alta matrice
    cout << endl << "D without its second row and first column: " << endl << d.remove_onTheSurface("both", 2, 1);

    // Eliminarea unei linii
    cout << endl << "A without its first row: " << endl;
    a.remove_forReal("row", 1);
    cout << a;

    // Eliminarea unei coloane
    cout << endl << "A without its second column: " << endl;
    a.remove_forReal("column", 2);
    cout << a;

    // Eliminarea unei linii si a unei coloane
    cout << endl << "A without its first row and first column: " << endl;
    a.remove_forReal("both", 1, 1);
    cout << a;

    // Numarul de linii al unei matrici
    cout << endl << "B's no of rows: " << b.getRows() << endl;

    // Numarul de coloane al unei matrici
    cout << endl << "A's no of columns: " << a.getColumns();
    return 0;
}
