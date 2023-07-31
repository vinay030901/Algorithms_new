#include <bits/stdc++.h>
using namespace std;
int length(int ind, int prev, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == arr.size())
        return 0;
    if (dp[prev + 1][ind] != -1)
        return dp[prev + 1][ind];
    if (prev == -1 || arr[prev] < arr[ind])
        return dp[prev + 1][ind] = max(1 + length(ind + 1, ind, arr, dp), length(ind + 1, prev, arr, dp));
    else
        return dp[prev + 1][ind] = length(ind + 1, prev, arr, dp);
}
int lengthOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return length(0, -1, arr, dp);
}

int lengthOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> lis(n, 1);
    int mx = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
                mx = max(mx, lis[i]);
            }
    }
    return mx;
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