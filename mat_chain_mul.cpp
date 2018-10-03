#include "mat_chain_mul.hpp"

int matrixChainOrder(int p[], int n)
{
    int m[n][n];

    int i, j, k, L, q;

    // cost is zero when multiplying single matrix. 
    for (i = 1; i < n; i++)
        m[i][i] = 0;
    
    // L is chain length
    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                // compute the cost
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                // compare the cost
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }
    return m[1][n - 1];
}