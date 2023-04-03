// count subset with given sum
#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int recur(vector<int> &arr, int n, int k, vector<vector<int>> &dp)
{
    // extra to handle values with zero
    if (n == 0)
    {
        if (k == 0 and arr[0] == 0)
            return 2;
        else if (k == 0 or arr[0] == k)
            return 1;
        else
            return 0;
    }
    if (dp[n][k] != -1)
        return dp[n][k];
    int notTake = recur(arr, n - 1, k, dp) % mod;
    int take = 0;
    if (arr[n] <= k)
        take = recur(arr, n - 1, k - arr[n], dp) % mod;
    return dp[n][k] = (take + notTake) % mod;
}
int countSubset(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    int ans = recur(arr, n - 1, k, dp);
    return ans;
}

int countSubsetTabulation(vector<int> &arr, int target)
{
    int n = arr.size();
    int mod = 1e9 + 7;
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    for (int i = 0; i <= target; i++)
        if (i == 0 and arr[0] == 0)
            dp[0][i] = 2;
        else if (arr[0] == i or i == 0)
            dp[0][i] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 0; j <= target; j++)
        {
            int notTake = dp[i - 1][j];
            int take = 0;
            if (arr[i] <= j)
                take = dp[i - 1][j - arr[i]];
            dp[i][j] = (take + notTake) % mod;
        }
    return dp[n - 1][target];
}

// the above solutions will fail when we have zero in our array. So we need a solution for that
int perfectSum(int arr[], int N, int sum)
{
    int t[N + 1][sum + 1];

    for (int i = 0; i < sum + 1; i++)
        t[0][i] = false;
    for (int i = 0; i < N + 1; i++)
        t[i][0] = true;
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = ((long long)(t[i - 1][j - arr[i - 1]] + t[i - 1][j])) % 1000000007;
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[N][sum];
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << countSubsetTabulation(arr, 10) << endl;
    cout << countSubset(arr, 10);
}