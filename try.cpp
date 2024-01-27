#include <bits/stdc++.h>
using namespace std;
int recur(int i, int j, int N, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == N)
        return 0;
    if (dp[i][j] != -10001)
        return dp[i][j];
    if (j == 0)
    {
        return dp[i][j] = max(arr[i] * 2 + recur(i + 1, 1, N, arr, dp), arr[i] / 2 + recur(i + 1, 2, N, arr, dp));
    }
    else if (j == 1)
    {
        return dp[i][j] = max(arr[i] + 2 + recur(i + 1, 0, N, arr, dp), arr[i] / 2 + recur(i + 1, 2, N, arr, dp));
    }
    return dp[i][j] = max(arr[i] + 2 + recur(i + 1, 0, N, arr, dp), arr[i] * 2 + recur(i + 1, 1, N, arr, dp));
}
int solve(int N, vector<int> A)
{
    vector<vector<int>> dp(N + 1, vector<int>(4, -10001));
    int add = A[0] + 2 + recur(1, 0, N, A, dp);
    int mul = A[0] * 2 + recur(1, 1, N, A, dp);
    int div = A[0] / 2 + recur(1, 2, N, A, dp);
    return max(add, max(div, mul));
}
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << solve(n, A) << endl;
    return 0;
}
