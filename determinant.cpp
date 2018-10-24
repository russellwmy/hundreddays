#include "determinant.hpp"

using namespace std;

void cofactor(int mat[3][3], int temp[3][3], int p, int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(int mat[3][3], int n)
{
    int D = 0;
    if (n == 1)
        return mat[0][0];
    int temp[3][3];
    int sign = 1;
    for (int f = 0; f < n; f++)
    {
        cofactor(mat, temp, 0, f, n);
        D += sign * mat[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }
    return D;
}