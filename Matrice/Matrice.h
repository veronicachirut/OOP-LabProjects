#ifndef MATRICE_H
#define MATRICE_H
#include <iostream>
using namespace std;

class Matrice
{
    int rows, columns;
    int **bidarray;
    public:
        Matrice();
        Matrice(int, int);
        Matrice(const Matrice&);
        Matrice& operator = (const Matrice&);
        friend istream& operator >> (istream&, Matrice&);
        friend ostream& operator << (ostream&, const Matrice&);
        Matrice operator + (const Matrice&) const;
        Matrice operator - (const Matrice&) const;
        Matrice operator [] (int);
        friend Matrice operator * (const Matrice&, const Matrice&);
        friend Matrice operator * (int, const Matrice&);
        void getDeterminant();
        int invertible();
        Matrice remove_onTheSurface(string, int);
        Matrice remove_onTheSurface(string, int, int);
        void remove_forReal(string, int);
        void remove_forReal(string, int, int);
        int getRows();
        int getColumns();
        virtual ~Matrice();
};

#endif // MATRICE_H
