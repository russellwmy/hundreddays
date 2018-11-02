#include <iostream>
#include <vector>
double median(vector<int> numbers)
{
    size_t size = numbers.size();

    if (size == 0)
    {
        return 0; // Undefined, really.
    }
    else
    {
        sort(numbers.begin(), numbers.end());
        if (size % 2 == 0)
        {
            return (numbers[size / 2 - 1] + numbers[size / 2]) / 2;
        }
        else
        {
            return numbers[size / 2];
        }
    }
}