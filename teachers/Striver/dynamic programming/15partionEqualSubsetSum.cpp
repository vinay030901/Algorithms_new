#include <bits/stdc++.h>
using namespace std;
bool recur(vector<int> &arr, int ind, int target, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    else if (ind == 0)
        return arr[ind] == target;
    else if (dp[ind][target] != -1)
        return dp[ind][target];
    else
    {
        bool notTake = recur(arr, ind - 1, target, dp);
        bool take = false;
        if (arr[ind] <= target)
            take = recur(arr, ind - 1, target - arr[ind], dp);
        dp[ind][target] = take || notTake;
    }
}
bool partitionEqualSubsetSum(vector<int> &arr)
{
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum % 2 == 1)
        return false;
    sum /= 2;
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return recur(arr, n - 1, sum, dp);
}

// tabulation
bool partitionEqualSubsetSumTabulation(vector<int> &arr)
{
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum % 2 == 1)
        return false;
    sum /= 2;
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    if (arr[0] <= sum)
        dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
        for (int j = 0; j <= sum; j++)
        {
            bool notTake = dp[i - 1][j];
            bool take = false;
            if (arr[i] <= j)
                take = dp[i - 1][j - arr[i]];
            dp[i][j] = take || notTake;
        }
    return dp[n - 1][sum];
}

// space optimization
bool partitionEqualSubsetSumSpaceOptimization(vector<int> &arr)
{
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum % 2 == 1)
        return false;
    sum /= 2;
    vector<bool> prev(sum + 1, 0), cur(sum + 1, 0);
    prev[0] = cur[0] = true;
    if (arr[0] <= sum)
        prev[arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            bool notTake = prev[j];
            bool take = false;
            if (arr[i] <= j)
                take = prev[j - arr[i]];
            cur[j] = take || notTake;
        }
        prev = cur;
    }

    return prev[sum];
}
int main()
{
}