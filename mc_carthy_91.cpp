#include <iostream>

using namespace std;

int mc_carthy_91(int n)
{
    if (n > 100)
        return (n - 10);
    else
        return (mc_carthy_91(mc_carthy_91(n + 11))); //answer is 91 upto 101
}