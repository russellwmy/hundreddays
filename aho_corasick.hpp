using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define foreach(x, v) for (typeof(v).begin() x = (v).begin(); x != (v).end(); ++x)
#define For(i, a, b) for (int i = (a); i < (b); ++i)
#define D(x) cout << #x " is " << x << endl

const int MAXS = 6 * 50 + 10;
const int MAXC = 26;

int out[MAXS];
int f[MAXS];
int g[MAXS][MAXC];

int build_matching_machine(const vector<string> &words, char lowestChar = 'a',
                         char highestChar = 'z')
{
    memset(out, 0, sizeof out);
    memset(f, -1, sizeof f);
    memset(g, -1, sizeof g);
    int states = 1;
    for (int i = 0; i < words.size(); ++i)
    {
        const string &keyword = words[i];
        int currentState = 0;
        for (int j = 0; j < keyword.size(); ++j)
        {
            int c = keyword[j] - lowestChar;
            if (g[currentState][c] == -1)
            {
                g[currentState][c] = states++;
            }
            currentState = g[currentState][c];
        }
        out[currentState] |= (1 << i);
    }
    for (int c = 0; c < MAXC; ++c)
    {
        if (g[0][c] == -1)
        {
            g[0][c] = 0;
        }
    }

    queue<int> q;
    for (int c = 0; c <= highestChar - lowestChar; ++c)
    {
        if (g[0][c] != -1 and g[0][c] != 0)
        {
            f[g[0][c]] = 0;
            q.push(g[0][c]);
        }
    }
    while (q.size())
    {
        int state = q.front();
        q.pop();
        for (int c = 0; c <= highestChar - lowestChar; ++c)
        {
            if (g[state][c] != -1)
            {
                int failure = f[state];
                while (g[failure][c] == -1)
                {
                    failure = f[failure];
                }
                failure = g[failure][c];
                f[g[state][c]] = failure;
                out[g[state][c]] |= out[failure];
                q.push(g[state][c]);
            }
        }
    }

    return states;
}
int find_next_state(int currentState, char nextInput, char lowestChar = 'a')
{
    int answer = currentState;
    int c = nextInput - lowestChar;
    while (g[answer][c] == -1)
        answer = f[answer];
    return g[answer][c];
}