#include "optimized_seive.hpp"

const long long MAX_SIZE = 1000001;
vector<long long> prime;
vector<long long> isprime(MAX_SIZE, true);
vector<long long> SPF(MAX_SIZE);

long optimized_seive(int N)
{
    isprime[0] = isprime[1] = false;
    for (long long int i = 2; i < N; i++)
    {
        if (isprime[i])
        {
            prime.push_back(i);
            SPF[i] = i;
        }
        for (long long int j = 0;
             j < (int)prime.size() &&
             i * prime[j] < N && prime[j] <= SPF[i];
             j++)
        {
            isprime[i * prime[j]] = false;
            SPF[i * prime[j]] = prime[j];
        }
    }
    return prime.size();
}