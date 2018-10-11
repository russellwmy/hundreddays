#include <iostream>
#include "hanoi_tower.hpp"
#include "mat_chain_mul.hpp"
#include "next_permutation.hpp"
#include "count_bits.hpp"
#include "optimized_seive.hpp"
#include "postfix_notation.hpp"
#include "binary_addition.hpp"
#include "binary_search.hpp"
#include "monte_carlo_pi.hpp"
#include "karatsuba_multiplication.hpp"
#include "mc_carthy_91.hpp"

using namespace std;

void day1()
{
    cout << "Day 1: Tower of Hanoi" << endl;
    hanoi(3, 'A', 'B', 'C');
}

void day2()
{
    cout << "Day 2: Matrix Chain Multiplication" << endl;
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of multiplications is " << matrix_chain_order(arr, n) << endl;
}

void day3()
{
    cout << "Day 3: Next Permutation" << endl;
    string s = "FDAE";
    bool val = next_permutation(s);
    cout << "The Result is " << s << endl;
}

void day4()
{
    cout << "Day 4: Count Bits" << endl;
    int bc = count_bits(99);
    cout << "99 has " << bc << " bits." << endl;
}

void day5()
{
    cout << "Day 5: Eratosthenes sieve" << endl;
    int N = 1000001;
    long numOfPrime = optimized_seive(N);
    cout << "Number of " << N << " primes is " << numOfPrime << endl;
}

void day6()
{
    cout << "Day 6: Postfix notation" << endl;
    string exp = "1 2 + 4 3 - + 10 5 / *";
    int expResult = evaluate_postfix(exp);
    cout << exp << " is " << expResult << endl;
}

void day7()
{
    cout << "Day 7: Binary Addiotion" << endl;
    string a = "1100100100100";
    string b = "100100011000";
    string binary_addiotion_result = add_binary(a, b);
    cout << a << " + " << b << " = " << binary_addiotion_result << endl;
}

void day8()
{
    cout << "Day 8: Binary Search" << endl;
    int arr[] = {2, 3, 4, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i <= n - 1; i++)
        cout << arr[i] << " ";
    cout << endl;
    int x = 0;
    int result = binary_search(arr, 0, n - 1, x);
    cout << "Element: " << x << " has result " << result << endl;
    x = 8;
    result = binary_search(arr, 0, n - 1, x);
    cout << "Element: " << x << " has result " << result << endl;
}

void day9()
{
    cout << "Day 9: Monte Carlo Pi" << endl;
    long N = 1000000000;
    double pi = approximation_pi(1000000000);
    cout << "Approximation Pi is " << pi << " with in " << N << " iterations " << endl;
}

void day10()
{
    cout << "Day 10: Karatsuba multiplication" << endl;
    long long a = 994759257;
    long long b = 928607936;
    cout << a << " x " << b << " = " << multiply(a, b) << endl;
}

void day11()
{
    cout << "Day 11: McCarthy 91" << endl;
    int n = 80;
    cout << "Result of " << n << " is " << mc_carthy_91(n) << endl;
}

int main(int argc, const char *argv[])
{
    day1();
    day2();
    day3();
    day4();
    day5();
    day6();
    day7();
    day8();
    day9();
    day10();
    day11();
}