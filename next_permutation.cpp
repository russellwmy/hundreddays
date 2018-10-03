#include "next_permutation.hpp"

// Swap two character
void swap(char *a, char *b)
{
    if (*a == *b)
        return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

// reverse string
void reverse(string &s, int l, int r)
{
    while (l < r)
        swap(&s[l++], &s[r--]);
}

// binary search
int bsearch(string &s, int l, int r, int key)
{
    int index = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (s[mid] <= key)
            r = mid - 1;
        else
        {
            l = mid + 1;
            if (index = -1 || s[index] <= s[mid])
                index = mid;
        }
    }
    return index;
}


bool next_permutation(string &s)
{
    int len = s.length(), i = len - 2;
    while (i >= 0 && s[i] >= s[i + 1])
        --i;
    if (i < 0)
        return false;
    else
    {
        int index = bsearch(s, i + 1, len - 1, s[i]);
        swap(&s[i], &s[index]);
        reverse(s, i + 1, len - 1);
        return true;
    }
}