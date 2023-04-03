#include <bits/stdc++.h>
using namespace std;
int recur(vector<int> &arr, int prev, int ind, vector<vector<int>> &dp)
{
    if (ind == arr.size())
        return 0;
    if (dp[prev + 1][ind] != -1)
        return dp[prev + 1][ind];
    if (prev == -1 || arr[prev] < arr[ind])
        return dp[prev + 1][ind] = max(1 + recur(arr, ind, ind + 1, dp), recur(arr, prev, ind + 1, dp));
    else
        return dp[prev + 1][ind] = recur(arr, prev, ind + 1, dp);
}
int lengthOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return recur(arr, -1, 0, dp);
}

int lengthOfLIS(vector<int> &arr)
{
    int n = arr.size(), len = 1;
    vector<int> temp;
    temp.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
            len++;
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return len;
}
int main()
{
}