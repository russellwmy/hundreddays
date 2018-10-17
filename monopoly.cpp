#include <iostream>
#include "monopoly.hpp"

float compute_probability(vector<float> p)
{
    float s = 0.0;
    int l = p.size();
    for (int i = l; i > l - 6; i--)
    {
        s += p[i];
    }
    return s / 6;
}

vector<float> probability(int n)
{
    vector<float> p = {0, 0, 0, 0, 0, 1};

    for (int i = 0; i < n; i++)
    {
        float v = compute_probability(p);
        p.push_back(v);
    }
    vector<float> r(p.begin() + 6, p.end());
    return r;
}
