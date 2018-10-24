#include "monte_carlo_pi.hpp"
#include <time.h>
#include <stdlib.h>

double approximation_pi(int n)
{
    double x, y, pi;
    int i, in = 0;
    srand(time(NULL));

    for (i = 1; i <= n; i++)
    {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        if (x * x + y * y <= 1)
            in++;
    }
    pi = (double)4 * in / n;
    return pi;
}
