#include <bits/stdc++.h>
using namespace std;
int recur(vector<int> &arr, int n, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return arr[0];
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = max(arr[n] + recur(arr, n - 2, dp), recur(arr, n - 1, dp));
}
int rob(vector<int> &arr)
{
    vector<int> dp(arr.size() + 1, -1);
    return recur(arr, arr.size() - 1, dp);
}
int main()
{
}