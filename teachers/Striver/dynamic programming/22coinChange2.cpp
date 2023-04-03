/*
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make a change for value V using coins of denominations from D. Print 0, if a change isn't possible.
Input Format
The first line of input contains an integer N, representing the total number of denominations.

The second line of input contains N integers values separated by a single space. Each integer value represents the denomination value.

The third line of input contains the value of V, representing the value for which the change needs to be generated.
Output Format:
For each test case, print an integer denoting the total number of ways W, in which a change for V is possible.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints :
1 <= N <= 10
1 <= D[i] <=10^5
1 <= V <= 2 * 10^3

Where 'D[i]' represent the value of ith denomination.

Time Limit: 1sec*/
#include <bits/stdc++.h>
using namespace std;
int recur(vector<int> arr, int n, int k, vector<vector<int>> &dp)
{
    if (n == -1)
        return k == 0;
    // if(n==0) return k%arr[0]==0;
    if (dp[n][k] != -1)
        return dp[n][k];
    int notTake = recur(arr, n - 1, k, dp);
    int take = 0;
    if (arr[n] <= k)
        take = recur(arr, n, k - arr[n], dp);
    return dp[n][k] = take + notTake;
}
int change(int value, vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(value + 1, -1));
    return recur(arr, n - 1, value, dp);
}

int change2Tabulation(int value, vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(value + 1, 0));
    for (int i = 0; i <= value; i++)
        dp[0][i] = i % arr[0] == 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= value; j++)
        {
            int notTake = dp[i - 1][j];
            int take = 0;
            if (arr[i] <= j)
                take = dp[i][j - arr[i]];
            dp[i][j] = take + notTake;
        }
    }
    return dp[n - 1][value];
}

long countWaysToMakeChange(int *arr, int n, int value)
{
    vector<long> prev(value + 1, 0),cur(value+1,0);
    for (long i = 0; i <= value; i++)
        prev[i] = i % arr[0] == 0;

    for (long i = 1; i < n; i++)
    {
        for (long j = 0; j <=value; j++)
        {
            long notTake = prev[j];
            long take = 0;
            if (arr[i] <= j)
                take = cur[j - arr[i]];
            cur[j] = take + notTake;
        }
        prev=cur;
    }
    return prev[value];
}

int main()
{
}