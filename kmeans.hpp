#include <iostream>
#include <vector>

#ifndef KMEANS_H_ /* Include guard */
#define KMEANS_H_
struct Point
{
    double x{0}, y{0};
};
using DataFrame = std::vector<Point>;
DataFrame generate_points(int n);
DataFrame k_means(const DataFrame &data,
                  size_t k,
                  size_t number_of_iterations);
#endif // KMEANS_H_
