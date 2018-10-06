#include <iostream>
#include "hanoi_tower.hpp"
#include "mat_chain_mul.hpp"
#include "next_permutation.hpp"
#include "count_bits.hpp"
#include "optimized_seive.hpp"
#include "postfix_notation.hpp"

using namespace std;

int main(int argc, const char *argv[])
{
    cout << "Day 1: Tower of Hanoi" << endl;
    hanoi(3, 'A', 'B', 'C');

    cout << "Day 2: Matrix Chain Multiplication" << endl;
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of multiplications is " << matrix_chain_order(arr, n) << endl;

    cout << "Day 3: Next Permutation" << endl;
    string s = "FDAE";
    bool val = next_permutation(s);
    cout << "The Result is " << s << endl;

    cout << "Day 4: Count Bits" << endl;
    int bc = count_bits(99);
    cout << "99 has " << bc << " bits." << endl;

    cout << "Day 5: Eratosthenes sieve" << endl;
    int N = 1000001;
    long numOfPrime = optimized_seive(N);
    cout << "Number of " << N << " primes is " << numOfPrime << endl;
     
     cout << "Day 6: Postfix notation" << endl;
     string exp = "1 2 + 4 3 - + 10 5 / *";
    int expResult  = evaluate_postfix(exp);
    cout << exp << " is " << expResult << endl;

}