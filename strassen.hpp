#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int leafsize=1;

using namespace std;

void strassen(vector<vector<int>> &A,
              vector<vector<int>> &B,
              vector<vector<int>> &C, unsigned int tam);
unsigned int next_power_of_two(int n);
void strassen_r(vector<vector<int>> &A,
                vector<vector<int>> &B,
                vector<vector<int>> &C,
                int tam);
void sum(vector<vector<int>> &A,
         vector<vector<int>> &B,
         vector<vector<int>> &C, int tam);
void subtract(vector<vector<int>> &A,
              vector<vector<int>> &B,
              vector<vector<int>> &C, int tam);

void print_matrix(vector<vector<int>> matrix, int n);

void ikjalgorithm(vector<vector<int>> A,
                  vector<vector<int>> B,
                  vector<vector<int>> &C, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            for (int j = 0; j < n; j++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void strassen_r(vector<vector<int>> &A,
                vector<vector<int>> &B,
                vector<vector<int>> &C, int tam)
{
    if (tam <= leafsize)
    {
        ikjalgorithm(A, B, C, tam);
        return;
    }

    // other cases are treated here:
    else
    {
        int new_tam = tam / 2;
        vector<int> inner(new_tam);
        vector<vector<int>>
            a11(new_tam, inner), a12(new_tam, inner), a21(new_tam, inner), a22(new_tam, inner),
            b11(new_tam, inner), b12(new_tam, inner), b21(new_tam, inner), b22(new_tam, inner),
            c11(new_tam, inner), c12(new_tam, inner), c21(new_tam, inner), c22(new_tam, inner),
            p1(new_tam, inner), p2(new_tam, inner), p3(new_tam, inner), p4(new_tam, inner),
            p5(new_tam, inner), p6(new_tam, inner), p7(new_tam, inner),
            aResult(new_tam, inner), bResult(new_tam, inner);

        int i, j;

        //dividing the matrices in 4 sub-matrices:
        for (i = 0; i < new_tam; i++)
        {
            for (j = 0; j < new_tam; j++)
            {
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][j + new_tam];
                a21[i][j] = A[i + new_tam][j];
                a22[i][j] = A[i + new_tam][j + new_tam];

                b11[i][j] = B[i][j];
                b12[i][j] = B[i][j + new_tam];
                b21[i][j] = B[i + new_tam][j];
                b22[i][j] = B[i + new_tam][j + new_tam];
            }
        }

        // Calculating p1 to p7:

        sum(a11, a22, aResult, new_tam);           // a11 + a22
        sum(b11, b22, bResult, new_tam);           // b11 + b22
        strassen_r(aResult, bResult, p1, new_tam); // p1 = (a11+a22) * (b11+b22)

        sum(a21, a22, aResult, new_tam);       // a21 + a22
        strassen_r(aResult, b11, p2, new_tam); // p2 = (a21+a22) * (b11)

        subtract(b12, b22, bResult, new_tam);  // b12 - b22
        strassen_r(a11, bResult, p3, new_tam); // p3 = (a11) * (b12 - b22)

        subtract(b21, b11, bResult, new_tam);  // b21 - b11
        strassen_r(a22, bResult, p4, new_tam); // p4 = (a22) * (b21 - b11)

        sum(a11, a12, aResult, new_tam);       // a11 + a12
        strassen_r(aResult, b22, p5, new_tam); // p5 = (a11+a12) * (b22)

        subtract(a21, a11, aResult, new_tam);      // a21 - a11
        sum(b11, b12, bResult, new_tam);           // b11 + b12
        strassen_r(aResult, bResult, p6, new_tam); // p6 = (a21-a11) * (b11+b12)

        subtract(a12, a22, aResult, new_tam);      // a12 - a22
        sum(b21, b22, bResult, new_tam);           // b21 + b22
        strassen_r(aResult, bResult, p7, new_tam); // p7 = (a12-a22) * (b21+b22)

        // calculating c21, c21, c11 e c22:

        sum(p3, p5, c12, new_tam); // c12 = p3 + p5
        sum(p2, p4, c21, new_tam); // c21 = p2 + p4

        sum(p1, p4, aResult, new_tam);       // p1 + p4
        sum(aResult, p7, bResult, new_tam);  // p1 + p4 + p7
        subtract(bResult, p5, c11, new_tam); // c11 = p1 + p4 - p5 + p7

        sum(p1, p3, aResult, new_tam);       // p1 + p3
        sum(aResult, p6, bResult, new_tam);  // p1 + p3 + p6
        subtract(bResult, p2, c22, new_tam); // c22 = p1 + p3 - p2 + p6

        // Grouping the results obtained in a single matrix:
        for (i = 0; i < new_tam; i++)
        {
            for (j = 0; j < new_tam; j++)
            {
                C[i][j] = c11[i][j];
                C[i][j + new_tam] = c12[i][j];
                C[i + new_tam][j] = c21[i][j];
                C[i + new_tam][j + new_tam] = c22[i][j];
            }
        }
    }
}

unsigned int next_power_of_two(int n)
{
    return pow(2, int(ceil(log2(n))));
}

void strassen(vector<vector<int>> &A,
              vector<vector<int>> &B,
              vector<vector<int>> &C, unsigned int n)
{
    //unsigned int n = tam;
    unsigned int m = next_power_of_two(n);
    vector<int> inner(m);
    vector<vector<int>> APrep(m, inner), BPrep(m, inner), CPrep(m, inner);

    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            APrep[i][j] = A[i][j];
            BPrep[i][j] = B[i][j];
        }
    }

    strassen_r(APrep, BPrep, CPrep, m);
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            C[i][j] = CPrep[i][j];
        }
    }
}

void sum(vector<vector<int>> &A,
         vector<vector<int>> &B,
         vector<vector<int>> &C, int tam)
{
    int i, j;

    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract(vector<vector<int>> &A,
              vector<vector<int>> &B,
              vector<vector<int>> &C, int tam)
{
    int i, j;

    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void print_matrix(vector<vector<int>> matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != 0)
            {
                cout << "\t";
            }
            cout << matrix[i][j];
        }
        cout << endl;
    }
}
