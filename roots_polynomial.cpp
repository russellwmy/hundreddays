#include <iostream>
#include "roots_polynomial.hpp"

double find_roots(function<double(double)> f, double start, double stop)
{
    double step = 0.001;
    double value = f(start);
    double sign = (value > 0);

    if (0 == value)
        cout << "Root found at " << start << endl;

    for (double x = start + step;
         x <= stop;
         x += step)
    {
        value = f(x);

        if ((value > 0) != sign)
            cout << "Root found near " << x << endl;
        else if (0 == value)
            cout << "Root found at " << x << endl;
        sign = (value > 0);
    }
}