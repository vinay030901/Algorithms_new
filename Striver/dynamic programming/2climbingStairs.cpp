/*
1D problems:
1. count the total number of ways
2. find the minimum and maximum of multiple answers

we solve such type of questions using recursion only

whenever the concept of try all possible ways comes in, or figure out the best way-> recursion is applied

shortcut to find the answer in dp
1. try to represent the porblem in terms of indices.
2. do all possible stuffs on that index according to the problem statement
3. if the question says-
    a. count all the ways -> sum up all stuffs
    b. min of all sutffs -> find the minimum*/

#include <bits/stdc++.h>
using namespace std;
int recur(int n, vector<int> &dp)
{
    if (n<=2) return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = recur(n - 1, dp) + recur(n - 2, dp);
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    cout << recur(n, dp);
}