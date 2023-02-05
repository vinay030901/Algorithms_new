#include <bits/stdc++.h>
using namespace std;
int recur(int i, int n, vector<int> &arr, vector<int> &dp)
{
    if (i >= n)
        return 0;
    if (i == n - 1)
        return arr[i];
    if (dp[i] != -1)
        return dp[i];
    return dp[i] = max(arr[i] + recur(i + 2, n, arr, dp), recur(i + 1, n, arr, dp));
}
int rob(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    vector<int> dp(n + 1, -1);
    int a1 = recur(0, n - 1, arr, dp);
    vector<int> p(n + 1, -1);
    int a2 = recur(1, n, arr, p);
    return max(a1, a2);
}
int main()
{
}