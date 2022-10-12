/*
You are given ‘N’ items with certain ‘PROFIT’ and ‘WEIGHT’ and a knapsack with weight capacity ‘W’. You need to fill the knapsack with the items in such a way that you get the maximum profit. You are allowed to take one item multiple times.
For Example
Let us say we have 'N' = 3 items and a knapsack of capacity 'W' =  10
'PROFIT' = { 5, 11, 13 }
'WEIGHT' = { 2, 4, 6 }

We can fill the knapsack as:

1 item of weight 6 and 1 item of weight 4.
1 item of weight 6 and 2 items of weight 2.
2 items of weight 4 and 1 item of weight 2.
5 items of weight 2.

The maximum profit will be from case 3 i.e ‘27’. Therefore maximum profit = 27.
Input Format
The first line contains a single integer ‘T’ denoting the number of test cases.

The first line of each test contains two integers ‘N’ - number of elements in the array and ‘W’ - Capacity of the knapsack.

The second line of each test case contains profiti - profit of the item at the ‘i-th’ index.

The third line of each test case contains weighti - weight of the item at the ‘i-th’ index
Output Format
For each test case, return an integer denoting the maximum profit that can be obtained by filling the knapsack.
Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints
1 <= T <= 50
1 <= N <= 10^3
1 <= W <= 10^3
1 <= PROFIT[ i ] , WEIGHT[ i ] <= 10^8

Time Limit: 1sec*/

#include <bits/stdc++.h>
using namespace std;
int recur(int n, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        return (w / weight[n]) * profit[n];
    }
    if (dp[n][w] != -1)
        return dp[n][w];
    int notTake = recur(n - 1, w, profit, weight, dp);
    int take = -2;
    if (weight[n] <= w)
        take = profit[n] + recur(n, w - weight[n], profit, weight, dp);
    return dp[n][w] = max(take, notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return recur(n - 1, w, profit, weight, dp);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    for (int i = 0; i <= w; i++)
        dp[0][i] = (i / weight[0]) * profit[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int notTake = dp[i - 1][j];
            int take = -2;
            if (weight[i] <= j)
                take = profit[i] + dp[i][j - weight[i]];
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n - 1][w];
}

int unboundedKnapsackSpace(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w + 1, 0);
    for (int i = 0; i <= w; i++)
        prev[i] = (i / weight[0]) * profit[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int notTake = prev[j];
            int take = -2;
            if (weight[i] <= j)
                take = profit[i] + prev[j - weight[i]];
            prev[j] = max(take, notTake);
        }
    }
    return prev[w];
}
int main()
{
}