#include "extended_euclid.hpp"

int gcd_extended(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd_extended(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}