#include <bits/stdc++.h>
using namespace std;
int kthGrammar(int n, int k)
{
    // https://leetcode.com/problems/k-th-symbol-in-grammar/solutions/626939/c-beats-100-different-solution-recursion-based/?orderBy=most_votes
    if (n == 1 && k == 1)
        return 0;
    if (k <= pow(2, n - 2))
        return kthGrammar(n - 1, k);
    else
        return !kthGrammar(n - 1, k - pow(2, n - 2));
}