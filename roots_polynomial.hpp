#ifndef ROOTS_POLYNOMIAL_H_ /* Include guard */
#define ROOTS_POLYNOMIAL_H_
#include <functional>
using namespace std;

double find_roots(function<double(double)> f, double start, double stop);

#endif // ROOTS_POLYNOMIAL_H_