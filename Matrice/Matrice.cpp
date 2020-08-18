#include "Matrice.h"
#include <math.h>

//  Constructor fara parametri
Matrice::Matrice()
{
    this->rows = 0;
    this->columns = 0;
    this->bidarray = NULL;
}

//  Constructor cu parametri
Matrice::Matrice(int rows, int columns)
{
    this->rows = rows;
    this->columns = columns;
    this->bidarray = new int*[rows]();
    for(int i = 0; i < rows; i++)
    {
        this->bidarray[i] = new int[columns]();
        for(int j = 0; j < columns; j++)
            this->bidarray[i][j] = 0;
    }
}

//  Constructor de copiere
Matrice::Matrice(const Matrice& matrice)
{
    this->rows = matrice.rows;
    this->columns = matrice.columns;
    this->bidarray = new int*[matrice.rows]();
    for(int i = 0; i < matrice.rows; i++)
    {
        this->bidarray[i] = new int[matrice.columns]();
        for(int j = 0; j < matrice.columns; j++)
            this->bidarray[i][j] = matrice.bidarray[i][j];
    }
}

//  Supraincarcarea operatorului =
Matrice& Matrice::operator = (const Matrice& matrice)
{
    //  Verificare self-assignment
    if(&matrice == this)
        return *this;

    //  Stergere continut vechi
    delete[] this->bidarray;

    this->rows = matrice.rows;
    this->columns = matrice.columns;
    this->bidarray = new int*[this->rows];
    for(int i = 0; i < this->rows; i++)
    {
        this->bidarray[i] = new int[this->columns];
        for(int j = 0; j < this->columns; j++)
            this->bidarray[i][j] = matrice.bidarray[i][j];
    }
    return *this;
}

//  Supraincarcarea operatorului de citire
istream& operator >> (istream& in, Matrice& matrice)
{
    delete[] matrice.bidarray;

    //  Daca am declarat matricea folosind costructorul cu parametri si am deja valori
    //  pentru linii si coloane introduc doar valorile din matrice
    cout << "A new object!" << endl;
    if(matrice.rows == 0 || matrice.columns == 0)
    {
        cout << "Set no. of rows and columns: ";
        int r, c;
        in >> r;
        matrice.rows = r;
        in >> c;
        matrice.columns = c;
    }
    else
        cout << "No. of rows: " << matrice.rows << " and no. of columns: " << matrice.columns << "." << endl;

    cout << "Set the values of the 2D array: " << endl;
    matrice.bidarray = new int*[matrice.rows];
    for(int i = 0; i < matrice.rows; i++)
    {
        matrice.bidarray[i] = new int[matrice.columns];
        for(int j = 0; j < matrice.columns; j++)
        {
            int nr;
            in >> nr;
            matrice.bidarray[i][j] = nr;
        }
    }
    cout << endl;
    return in;
}

//  Supraincarcarea operatorului de afisare
ostream& operator << (ostream& out, const Matrice& matrice)
{
    for(int i = 0; i < matrice.rows; i++)
    {
        for(int j = 0; j < matrice.columns; j++)
            out << matrice.bidarray[i][j] << ' ';
        out << endl;
    }
    return out;
}

//  Supraincarcarea operatorului + pentru adunarea a doua matrici
Matrice Matrice::operator + (const Matrice& matrice) const
{
    if(matrice.rows != this->rows || matrice.columns != this->columns)
        throw domain_error("The dimensions of the two 2D arrays must be the same");

    //  Construiesc o noua matrice in care sa retin rezultatul
    Matrice new_one(this->rows, this->columns);
    new_one.rows = this->rows;
    new_one.columns = this->columns;

    //  Adun un elementt din prima matrice cu elementul corepunzator aceleasi pozitii din a doua matrice
    for(int i = 0; i < this->rows; i++)
        for(int j = 0; j < this->columns; j++)
            new_one.bidarray[i][j] = matrice.bidarray[i][j] + this->bidarray[i][j];
    return new_one;
}

//  Supraincarcarea operatorului - pentru scaderea a doua matrici
Matrice Matrice::operator - (const Matrice& matrice) const
{
    if(matrice.rows != this->rows || matrice.columns != this->columns)
        throw domain_error("The dimensions of the two 2D arrays must be the same");

    //  Construiesc o noua matrice in care sa retin rezultatul
    Matrice new_one(this->rows, this->columns);
    new_one.rows = this->rows;
    new_one.columns = this->columns;

    //  Scad din fiecare element din prima matrice elementul din a doua matrice de pe aceeasi pozitie
    for(int i = 0; i < this->rows; i++)
        for(int j = 0; j < this->columns; j++)
            new_one.bidarray[i][j] = this->bidarray[i][j] - matrice.bidarray[i][j];
    return new_one;
}

//  Supraincarcarea operatorului [] pentru obtinerea liniei i
Matrice Matrice::operator [] (int index)
{
    if(index < 0 || index > this->rows)
        throw domain_error("Index out of range");

    //  Memorez intr-o matrice noua cu o singura linie, linia cu indexul dorit
    Matrice row_of_index(1, this->columns);
    for(int i = 0; i < this->columns; i++)
        row_of_index.bidarray[0][i] = this->bidarray[index][i];
    return row_of_index;
}

//  Supraincarcarea operatorului * pentru inmultirea a doua matrici
Matrice operator * (const Matrice& left, const Matrice& right)
{
    if(left.columns != right.rows)
        throw domain_error("The no. of columns of the first 2D array must be equal to the no. of rows of the second 2D array");

    //  In new_one memorez rezultatul
    Matrice new_one(left.columns, right.rows);
    new_one.rows = left.rows;
    new_one.columns = right.columns;

    //  Imnultesc fiecare linie a primei matrice cu fiecare coloana a celei de-a doua matrice
    //  Rezultatul il trec in cate o casuta a matricei nou costruite
    for(int i = 0; i < left.rows; i++)
        for(int j = 0; j < right.columns; j++)
            for(int k = 0; k < left.columns; k++)
                new_one.bidarray[i][j] += left.bidarray[i][k] * right.bidarray[k][j];
    return new_one;
}

// Supraincarcarea operatorului * pentru inmultirea unei matrici cu un scalar
Matrice operator * (int scalar, const Matrice& matrice)
{
    // Imnultesc fiecare element al matricei cu scalarul dat
    Matrice new_one(matrice.rows, matrice.columns);
    for(int i = 0; i < matrice.rows; i++)
        for(int j = 0; j < matrice.columns; j++)
            new_one.bidarray[i][j] = scalar * matrice.bidarray[i][j];
    return new_one;
}

//  Afiseaza determinantul matricei
void Matrice::getDeterminant()
{
    if(rows != columns)
        throw domain_error("Rows must be equal to columns");
    int determinant(int** bidarray, int rows);
    cout << determinant(bidarray, rows);
}

//Calculez determinantul recursiv
int determinant(int **bidarray, int rows)
{
    int det = 0;
    if(rows == 1)
        return bidarray[0][0];
    int **subarray = new int*[rows];
    for(int i = 0; i < rows; i++)
        subarray[i] = new int[rows];
    for(int f = 0; f < rows; f++)
    {
        //  Determinantul obtinut prin stergerea liniei si coloanei unui element
        //  Stergerea liniei 0 si a coloanei f si punerea rezultatului in subarray
        int i = 0, j = 0;
        for (int row = 0; row < rows; row++)
            for (int col = 0; col < rows; col++)
            {
                //  Copiez in subarray doar acele elemente care nu se afla
                //  pe linia si coloana precizate
                if (row != 0 && col != f)
                {
                    subarray[i][j++] = bidarray[row][col];

                    //  Completez urmatorul rand, incepand de la 0
                    if (j == rows - 1)
                    {
                        j = 0;
                        i++;
                    }
                }
            }
        det += pow(-1, f) * bidarray[0][f] * determinant(subarray, rows - 1);
    }
    return det;
}

//  Verifica daca matricea este inversabila
//  Si afiseaza un mesaj corespunzator
int Matrice::invertible()
{
    if(rows != columns)
    {
        cout << "Rows must be equal to columns in order to be invertible";
        return 0;
    }

    //  Pnetru ca matricea sa fie inversabila, determinantul trebuie sa fie nenul
    int det = determinant(bidarray, rows);
    if(det == 0)
    {
        cout << "Not invertible";
        return 0;
    }
    cout << "Invertible :>";
    return 0;
}

//  Eliminarea unei linii sau a unei coloane prin copierea in alta matrice
//  Primul parametru zice ce anume vrem sa dam la o parte, linia sau coloana
//  Input: "row" => stergem un rand, "column" => stergem o coloana
Matrice Matrice::remove_onTheSurface(string what, int the_what)
{
    //  Daca primul parametru este "row", atunci vom sterge randul the_what
    if(what == "row")
    {
        //  Rezultatul il memoram intr-o matrice noua, cu nr ul de randul cu 1 mai putin
        Matrice new_one(this->rows - 1, this->columns);
        new_one.rows = this->rows - 1;
        new_one.columns = this->columns;
        int row = 0;
        for(int i = 0; i < this->rows; i++)
        {
            if(i != the_what - 1)
            {
                for(int j = 0; j < this->columns; j++)
                    new_one.bidarray[row][j] = this->bidarray[i][j];
                row++;
            }
        }
        return new_one;
    }
    else
        //  Daca primul parametru este "column", atunci vom steerge coloana the_what
        if(what == "column")
        {
            //  Rezultatul il memoram intr-o matrice noua cu nr ul de coloane cu 1 mai putin
            Matrice new_one(this->rows, this->columns - 1);
            new_one.rows = this->rows;
            new_one.columns = this->columns - 1;
            for(int i = 0; i < this->rows; i++)
            {
                int column = 0;
                for(int j = 0; j < this->columns; j++)
                {
                    if(j != the_what - 1)
                    {
                        new_one.bidarray[i][column] = this->bidarray[i][j];
                        column++;
                    }
                }
            }
            return new_one;
        }
        else
            //  Daca cuvantul introdus nu este nici "row" si nici "column"
            //  nu stim ce sa stergem asa ca oprim programul
            throw domain_error("Incorrect word");
}

//  Eliminarea unei linii si a unei coloane prin copierea in alta matrice
//  Primul parametru ne spune ca vrem sa ignoram si un rand si o coloana
//  Input: "both" si linia si coloana dorite
Matrice Matrice::remove_onTheSurface(string what, int the_row, int the_column)
{
    if(what == "both")
    {
        Matrice new_one(this->rows - 1, this->columns - 1);
        new_one.rows = this->rows - 1;
        new_one.columns = this->columns - 1;
        int row = 0;
        for(int i = 0; i < this->rows; i++)
        {
            if(i != the_row - 1)
            {
                int column = 0;
                for(int j = 0; j < this->columns; j++)
                    if(j != the_column - 1)
                    {
                        new_one.bidarray[row][column] = this->bidarray[i][j];
                        column++;
                    }
                row++;
            }
        }
        return new_one;
    }
    else
        throw domain_error("Incorrect word");
}

//  Functie care sterge o linie sau o coloana, in functie de primul parametru
//  Primul parametru va primi valoarea "row" daca vrem sa stergem un rand
//  sau valoarea "column" daca vrem sa stergem o anumita coloana
//  Modificarile se fac pe matricea initiala
void Matrice::remove_forReal(string what, int the_what)
{
    if(what == "row")
    {
        if(the_what == this->rows)
            this->rows--;
        for(int i = the_what; i < this->rows; i++)
            for(int j = 0; j < this->columns; j++)
                bidarray[i - 1][j] = bidarray[i][j];
        this->rows--;
    }
    else
        if(what == "column")
        {
            if(the_what == this->columns)
                this->columns--;
            for(int j = the_what; j < this->columns; j++)
                for(int i = 0; i < this->rows; i++)
                    bidarray[i][j - 1] = bidarray[i][j];
            this->columns--;
        }
        else
            throw domain_error("Incorrect word");
}

//  In cazul in care ne dorim sa stergem si o linie si o coloana
//  introducem ca prim parametru cuvantul "both", iar
//  urmatorii doi numarul liniei si al coloanei
void Matrice::remove_forReal(string what, int the_row, int the_column)
{
    if(what == "both")
    {
        this->remove_forReal("row", the_row);
        this->remove_forReal("column", the_column);
    }
    else
        throw domain_error("Incorrect word");
}
//  Functie care intoarce numarul de linii
int Matrice::getRows()
{
    return this->rows;
}

//  Functie care intoarce numarul de coloane
int Matrice::getColumns()
{
    return this->columns;
}

//  Destructorul
Matrice::~Matrice()
{
    delete[] bidarray;
    rows = columns = 0;
}
