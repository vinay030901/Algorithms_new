#include <bits/stdc++.h>
using namespace std;
int recur(vector<int> &arr, int n, int target, vector<vector<int>> dp)
{
    if (target == 0)
        return true;
    else if (n == 0)
        return target == arr[n];
    else if (dp[n][target] != -1)
        return dp[n][target];
    bool notTake = recur(arr, n - 1, target, dp);
    bool take = false;
    if (arr[n] <= target)
        take = recur(arr, n - 1, target - arr[n], dp);
    return notTake || take;
}
bool subsetSumToK(vector<int> arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return recur(arr, n - 1, target, dp);
}
bool subsetSumToKTabulation(vector<int> arr, int target)
{
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= target; j++)
        {
            bool notTake = dp[i - 1][j];
            bool take = false;
            if (arr[i] <= j)
                take = dp[i - 1][j - arr[i]];
            dp[i][j] = take || notTake;
        }

    return dp[n - 1][target];
}

// space optimization
bool subsetSumToKTabulation(vector<int> arr, int target)
{
    int n = arr.size();
    vector<bool> prev(target + 1, 0), cur(target + 1, 0);
    prev[0] = cur[0] = true;
    prev[arr[0]] = true;
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= target; j++)

        {
            bool notTake = prev[j];
            bool take = false;
            if (arr[i] <= j)
                take = prev[j - arr[i]];
            cur[j] = take || notTake;
        }

    return prev[target];
}
int main()
{
    vector<int> arr = {};
}