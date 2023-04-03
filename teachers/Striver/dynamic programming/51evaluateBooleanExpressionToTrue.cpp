/*
Given a boolean expression with the following symbols.

Symbols
    'T' ---> true
    'F' ---> false
And following operators filled between symbols

Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
Let the input be in form of two arrays one contains the symbols (T and F) in order and the other contains operators (&, | and ^}

Examples:

Input: symbol[]    = {T, F, T}
       operator[]  = {^, &}
Output: 2
The given expression is "T ^ F & T", it evaluates true
in two ways "((T ^ F) & T)" and "(T ^ (F & T))"

Input: symbol[]    = {T, F, F}
       operator[]  = {^, |}
Output: 2
The given expression is "T ^ F | F", it evaluates true
in two ways "( (T ^ F) | F )" and "( T ^ (F | F) )".

Input: symbol[]    = {T, T, F, T}
       operator[]  = {|, &, ^}
Output: 4
The given expression is "T | T & F ^ T", it evaluates true
in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T)
and (T|((T&F)^T)). */

#include <bits/stdc++.h>
using namespace std;
int mod = 1003;
int mcm(string &s, int i, int j, bool isTrue, vector<vector<vector<int>>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue == 1)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    int ways = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        int leftTrue = mcm(s, i, k - 1, 1, dp);
        int leftFalse = mcm(s, i, k - 1, 0, dp);
        int rightTrue = mcm(s, k + 1, j, 1, dp);
        int rightFalse = mcm(s, k + 1, j, 0, dp);
        if (s[k] == '&')
        {
            if (isTrue)
                ways = (ways + (rightTrue * leftTrue) % mod) % mod;
            else
                ways = (ways + (rightTrue * leftFalse) % mod + (rightFalse * leftTrue) % mod + (rightFalse * leftFalse) % mod) % mod;
        }
        else if (s[k] == '|')
        {
            if (isTrue)
                ways = (ways + (rightTrue * leftFalse) % mod + (rightFalse * leftTrue) % mod + (rightTrue * leftTrue) % mod) % mod;
            else
                ways = (ways + (rightFalse * leftFalse) % mod) % mod;
        }
        else if (s[k] == '^')
        {
            if (isTrue)
                ways = (ways + (rightTrue * leftFalse) % mod + (leftTrue * rightFalse) % mod) % mod;
            else
                ways = (ways + (rightTrue * leftTrue) % mod + (leftFalse * rightFalse) % mod) % mod;
        }
    }
    return dp[i][j][isTrue] = ways % mod;
}
int countWays(int n, string s)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
    return mcm(s, 0, n - 1, 1, dp);
}
int main()
{
}