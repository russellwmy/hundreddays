#include <iostream>
// #include "hanoi_tower.hpp"
// #include "mat_chain_mul.hpp"
// #include "next_permutation.hpp"
// #include "count_bits.hpp"
// #include "optimized_seive.hpp"
// #include "postfix_notation.hpp"
// #include "binary_addition.hpp"
// #include "binary_search.hpp"
// #include "monte_carlo_pi.hpp"
// #include "karatsuba_multiplication.hpp"
// #include "mc_carthy_91.hpp"
// #include "roots_polynomial.hpp"
// #include "extended_euclid.hpp"
// #include "huffman_codes.hpp"
// #include "breaking_otp.hpp"
// #include "swap.hpp"
// #include "perceptron.hpp"
// #include "monopoly.hpp"
// #include "count_inversions.hpp"
// #include "linearithmic_multiplication.hpp"
// #include "kmeans.hpp"
// #include "determinant.hpp"
// #include "sudoku.hpp"
// #include "closest_pair_points.hpp"
// #include "kargers_min_cut.hpp"
// #include "spiral_matrix.hpp"
// #include "convex_hull.hpp"

using namespace std;

// void day1()
// {
//     cout << "Day 1: Tower of Hanoi" << endl;
//     hanoi(3, 'A', 'B', 'C');
// }

// void day2()
// {
//     cout << "Day 2: Matrix Chain Multiplication" << endl;
//     int arr[] = {10, 20, 30, 40};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << "Minimum number of multiplications is " << matrix_chain_order(arr, n) << endl;
// }

// void day3()
// {
//     cout << "Day 3: Next Permutation" << endl;
//     string s = "FDAE";
//     bool val = next_permutation(s);
//     cout << "The Result is " << s << endl;
// }

// void day4()
// {
//     cout << "Day 4: Count Bits" << endl;
//     int bc = count_bits(99);
//     cout << "99 has " << bc << " bits." << endl;
// }

// void day5()
// {
//     cout << "Day 5: Eratosthenes sieve" << endl;
//     int n = 1000001;
//     long numOfPrime = optimized_seive(n);
//     cout << "Number of " << n << " primes is " << numOfPrime << endl;
// }

// void day6()
// {
//     cout << "Day 6: Postfix notation" << endl;
//     string exp = "1 2 + 4 3 - + 10 5 / *";
//     int expResult = evaluate_postfix(exp);
//     cout << exp << " is " << expResult << endl;
// }

// void day7()
// {
//     cout << "Day 7: Binary Addiotion" << endl;
//     string a = "1100100100100";
//     string b = "100100011000";
//     string binary_addiotion_result = add_binary(a, b);
//     cout << a << " + " << b << " = " << binary_addiotion_result << endl;
// }

// void day8()
// {
//     cout << "Day 8: Binary Search" << endl;
//     int arr[] = {2, 3, 4, 8, 10};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     for (int i = 0; i <= n - 1; i++)
//         cout << arr[i] << " ";
//     cout << endl;
//     int x = 0;
//     int result = binary_search(arr, 0, n - 1, x);
//     cout << "Element: " << x << " has result " << result << endl;
//     x = 8;
//     result = binary_search(arr, 0, n - 1, x);
//     cout << "Element: " << x << " has result " << result << endl;
// }

// void day9()
// {
//     cout << "Day 9: Monte Carlo Pi" << endl;
//     long n = 1000000000;
//     double pi = approximation_pi(n);
//     cout << "Approximation Pi is " << pi << " with in " << n << " iterations " << endl;
// }

// void day10()
// {
//     cout << "Day 10: Karatsuba multiplication" << endl;
//     long long a = 994759257;
//     long long b = 928607936;
//     cout << a << " x " << b << " = " << multiply(a, b) << endl;
// }

// void day11()
// {
//     cout << "Day 11: McCarthy 91" << endl;
//     int n = 80;
//     cout << "Result of " << n << " is " << mc_carthy_91(n) << endl;
// }

// double f(double x)
// {
//     return (
//         x * x * x * x * x +
//         x * x * x * x +
//         x * x * x +
//         x * x +
//         x +
//         1);
// }

// void day12()
// {
//     cout << "Day 12: Roots of polynomial" << endl;
//     double start = -5;
//     double stop = 5;
//     cout << "Finding root of x^5 + x^4 + x^3 + x^2 + x + 1 = 0  " << endl;
//     find_roots(f, start, stop);
// }

// void day13()
// {
//     cout << "Day 13: Extended euclidean algorithm" << endl;
//     int x, y;
//     int a = 151, b = 100;
//     int g = gcd_extended(a, b, x, y);
//     cout << "a: " << a << " b:" << b << endl;
//     cout << g << "," << x << "," << y << endl;
// }

// void day14()
// {
//     cout << "Day 14: Huffman codes" << endl;
//     char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
//     int freq[] = {5, 9, 12, 13, 16, 45};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     huffman_codes(arr, freq, size);
// }

// void day15()
// {
//     cout << "Day 15: Breaking OTP" << endl;
//     // key cscmhbpgflzqaiayfeda
//     string *ciphertext = new string[5]{
//         "krqcccynwghgfuxlmvxc", // "izoqvbjhrviqfmxnhruc";
//         "mysyqocsxnjzveafubic", // "kgqmjnnmsckjvwahpxfc";
//         "bwjrhsqgbwybcwfbbwrn", //"zehfarbawlzlcofdwson";
//         "iijldmbuagzsuasssica", //"gqhzwlmovvacussuneza";
//         "bgopnndxwsjbwtastvjw", //"zomdgmorrhklwlauorgw";
//     };
//     break_otp(ciphertext);
// }

// void day16()
// {
//     cout << "Day 16: No-condition swap" << endl;
//     int a = 15, b = 18;
//     cout << "before swap: "
//          << "a = " << a << " b = " << b << endl;
//     swap(a, b);
//     cout << "after swap: "
//          << "a = " << a << " b = " << b << endl;
// }

// void day17()
// {
//     cout << "Day 17: Perceptron" << endl;
//     vector<float> X{
//         0, 1, 1,
//         1, 0, 1,
//         1, 1, 1,
//         -1, 1, 1,
//         1, -1, 1};

//     vector<float> y{1, 1, 1, 0, 0};

//     vector<float> W{0, 0, 0};
//     learn(X, y, W);
// }

// void day18()
// {
//     cout << "Day 18: Monoploy" << endl;
//     vector<float> p = probability(24);
//     int l = p.size();
//     for (int i = 0; i < l; i++)
//     {
//         cout << p[i] << endl;
//     }
// }

// void day19()
// {
//     cout << "Day 19: Counting inversions" << endl;
//     int arr[] = {23, 6, 17, 0, 18, 28, 29, 4, 15, 11};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << "Number of inversions are " << merge_sort(arr, n) << endl;
// }

// void day20()
// {
//     cout << "Day 20: Linearithmic multiplication" << endl;
//     string x = "987324";
//     string y = "23487";
//     mult(x, y);
// }

// void day21()
// {
//     cout << "Day 21: K Means" << endl;
//     DataFrame data = generate_points(100);
//     DataFrame result = k_means(data, 3, 100);
//     int l = result.size();
//     for (int i = 0; i < l; i++)
//     {
//         cout << result[i].x << "," << result[i].y << endl;
//     }
// }

// void day22()
// {
//     cout << "Day 22: Determinant" << endl;
//     int mat[3][3] = {{4, 9, 2},
//                      {3, 5, 7},
//                      {8, 1, 6}};
//     cout << "Determinant of the matrix is: " << determinant(mat, 3) << endl;
// }

// void day23()
// {
//     cout << "Day 23: Sudoku" << endl;
//     int grid[N][N] = {{8, 0, 0, 1, 0, 9, 0, 7, 0},
//                       {0, 9, 0, 0, 0, 0, 8, 0, 0},
//                       {5, 0, 3, 0, 4, 0, 0, 0, 0},
//                       {0, 0, 0, 0, 0, 0, 7, 9, 0},
//                       {0, 0, 7, 2, 6, 5, 3, 0, 0},
//                       {0, 3, 8, 0, 0, 0, 0, 0, 0},
//                       {0, 0, 0, 0, 9, 0, 4, 0, 1},
//                       {0, 0, 6, 0, 0, 0, 0, 2, 0},
//                       {0, 5, 0, 4, 0, 2, 0, 0, 3}};
//     if (solve_sudoku(grid) == true)
//         print_grid(grid);
//     else
//         cout << "No solution exists" << endl;
// }
// void day_24()
// {
//     cout << "Day 24: Closest pair of points" << endl;
//     day24::Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
//     int n = sizeof(P) / sizeof(P[0]);
//     cout << "The smallest distance is " << day24::closest(P, n) << endl;
// }

// void day25()
// {
// }

// void day26()
// {
//     cout << "Day 26: Karger’s mincut" << endl;

//     int V = 4; // Number of vertices in graph
//     int E = 5; // Number of edges in graph
//     struct Graph *graph = create_graph(V, E);

//     // add edge 0-1
//     graph->edge[0].src = 0;
//     graph->edge[0].dest = 1;

//     // add edge 0-2
//     graph->edge[1].src = 0;
//     graph->edge[1].dest = 2;

//     // add edge 0-3
//     graph->edge[2].src = 0;
//     graph->edge[2].dest = 3;

//     // add edge 1-3
//     graph->edge[3].src = 1;
//     graph->edge[3].dest = 3;

//     // add edge 2-3
//     graph->edge[4].src = 2;
//     graph->edge[4].dest = 3;

//     srand(time(NULL));

//     cout << "Cut found by Karger's randomized algo is \n"
//          << karger_min_cut(graph) << endl;
// }

// void day27()
// {
//     cout << "Day 27: Spiral matrix" << endl;
//     int a[3][6] = {{1, 2, 3, 4, 5, 6},
//                    {7, 8, 9, 10, 11, 12},
//                    {13, 14, 15, 16, 17, 18}};

//     spiral_print(3, 6, a);
// }

// int main(int argc, const char *argv[])
// {
// day1();
// day2();
// day3();
// day4();
// day5();
// day6();
// day7();
// day8();
// day9();
// day10();
// day11();
// day12();
// day13();
// day14();
// day15();
// day16();
// day17();
// day18();
// day19();
// day20();
// day22();
// day23();
// day24();
// day25();
// day26();
// day27();
//     day28();
// }

// #include "convex_hull.hpp"
// void main(int argc, const char *argv[])
// {
// Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
// int n = sizeof(points) / sizeof(points[0]);
// cout << "Day 28: Convex hull" << endl;
// convex_hull(points, n);
// }

// #include "string_search.hpp"
// int main(int argc, const char *argv[])
// {
//     char* text = "A parabolic (or paraboloid or paraboloidal) reflector (or dish or mirror)";
//     char* pattern = "reflector";
//     cout << "Day 29: String Search" << endl;
//     search(text, pattern);
//     return 0;
// }

// #include "strassen.hpp"
// int main(int argc, const char *argv[])
// {
//     int n = 2;
//     vector<int> inner(n);
//     vector<vector<int>> A(n, inner), B(n, inner), C(n, inner);

//     A = {{1, 3}, {-2, 4}};
//     B = {{5, 7}, {1, -2}};
//     cout << "Day 30: Strassen multiplication" << endl;
//     strassen(A, B, C, n);
//     print_matrix(C, n);
//     return 0;
// }

// #include "timeit.hpp"

// int do_things(){
//    for (int i =0; i< 100000; i++) {

//    }
// }

// int main(int argc, const char *argv[])
// {
//     cout << "Day 31: Time it" << endl;
//     cout << measure(do_things) << endl;
//     return 0;
// }

// #include "pagerank.hpp"
// int main()
// {
//     graph g;
//     string pages[5] = {"Mspc", "Twtr", "Amzn", "Medm", "Fb"};
//     for (auto p : pages)
//         g.add_node(p);
//     cout << "Day 32: Page rank" << endl;
//     g.add_edge("Mspc", "Twtr");
//     g.add_edge("Twtr", "Medm");
//     g.add_edge("Amzn", "Twtr");
//     g.add_edge("Amzn", "Medm");
//     g.add_edge("Medm", "Twtr");
//     g.add_edge("Medm", "Mspc");
//     g.add_edge("Medm", "Amzn");
//     g.add_edge("Medm", "Fb");
//     g.add_edge("Fb", "Twtr");
//     g.add_edge("Fb", "Amzn");

//     page_rank(g);

//     g.print();
//     return 0;
// }

// #include "reservoir_sampling.hpp"

// int main()
// {
//     int stream[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
//     int n = sizeof(stream) / sizeof(stream[0]);
//     int k = 5;
//     cout << "Day 33: Reservoir sampling" << endl;
//     select_k_items(stream, n, k);
//     return 0;
// }

// #include "aho_corasick.hpp"

// int main()
// {
//     cout << "Day 34: Aho-Corasick" << endl;
//     vector<string> keywords;
//     keywords.push_back("he");
//     keywords.push_back("she");
//     keywords.push_back("hers");
//     keywords.push_back("his");
//     string text = "ahishers";
//     build_matching_machine(keywords, 'a', 'z');
//     int currentState = 0;
//     for (int i = 0; i < text.size(); ++i)
//     {
//         currentState = find_next_state(currentState, text[i], 'a');
//         if (out[currentState] == 0)
//             continue; // Nothing new, let's move on to the next character.
//         for (int j = 0; j < keywords.size(); ++j)
//         {
//             if (out[currentState] & (1 << j))
//             { // Matched keywords[j]
//                 cout << "Keyword " << keywords[j] << " appears from " << i - keywords[j].size() + 1 << " to " << i << endl;
//             }
//         }
//     }
//     return 0;
// }

#include "median.hpp"

int main(int argc, const char *argv[])
{
    cout << "Day 35: Median" << endl;
    vector<int> numbers;

    for (int i = 0; i < 10000; i++)
    {
        numbers.push_back(i);
    }
    cout << median(numbers) << endl;
    return 0;
}
