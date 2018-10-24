#include <iostream>
#ifndef CLOSEST_POINT_PAIR_H_ /* Include guard */
#define CLOSEST_POINT_PAIR_H_

#include <float.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
namespace day24
{
struct Point
{
    int x, y;
};

int compare_x(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compare_y(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

float brute_force(Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

float min(float x, float y)
{
    return (x < y) ? x : y;
}

float strip_closest(Point strip[], int size, float d)
{
    float min = d;
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i], strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}

float closest_util(Point Px[], Point Py[], int n)
{
    if (n <= 3)
        return brute_force(Px, n);

    int mid = n / 2;
    Point midPoint = Px[mid];

    Point Pyl[mid + 1];
    Point Pyr[n - mid - 1];
    int li = 0, ri = 0;
    for (int i = 0; i < n; i++)
    {
        if (Py[i].x <= midPoint.x)
            Pyl[li++] = Py[i];
        else
            Pyr[ri++] = Py[i];
    }
    float dl = closest_util(Px, Pyl, mid);
    float dr = closest_util(Px + mid, Pyr, n - mid);

    float d = min(dl, dr);

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j] = Py[i], j++;

    return min(d, strip_closest(strip, j, d));
}

float closest(Point P[], int n)
{
    Point Px[n];
    Point Py[n];
    for (int i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }

    qsort(Px, n, sizeof(Point), compare_x);
    qsort(Py, n, sizeof(Point), compare_y);
    return closest_util(Px, Py, n);
}
} // namespace day24

#endif // CLOSEST_POINT_PAIR_H_