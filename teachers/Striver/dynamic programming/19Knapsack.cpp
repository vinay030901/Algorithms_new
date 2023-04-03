/*
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.
Input Format:
The first line contains a single integer T representing the number of test cases.
The T-test cases are as follows:

Line 1:The first line contains an integer, that denotes the value of N.
Line 2:The following line contains N space-separated integers, that denote the values of the weight of items.
Line 3:The following line contains N space-separated integers, that denote the values associated with the items.
Line 4:The following line contains an integer that denotes the value of W. W denotes the maximum weight that a thief can carry.
Output Format :
The first and only line of output contains the maximum value that a thief can generate, as described in the task.
The output of every test case is printed in a separate line.
Constraints:
1 <= T <= 10
1 <= N <= 10^2
1<= wi <= 50
1 <= vi <= 10^2
1 <= W <= 10^3

Time Limit: 1 second
Follow Up:
Can we solve this using space complexity of not more than O(W)?*/
#include <bits/stdc++.h>
using namespace std;
int recur(vector<int> weight, vector<int> value, int n, int maxWeight, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        if (weight[n] <= maxWeight)
            return dp[n][maxWeight] = value[0];
        else
            return dp[n][maxWeight] = 0;
    }
    if (dp[n][maxWeight] != -1)
        return dp[n][maxWeight];
    int notTake = recur(weight, value, n - 1, maxWeight, dp);
    int take = INT_MIN;
    if (weight[n] <= maxWeight)
        take = value[n] + recur(weight, value, n - 1, maxWeight - weight[n], dp);
    return dp[n][maxWeight] = max(take, notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return recur(weight, value, n - 1, maxWeight, dp);
}
int knapsackTabulation(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for (int i = 0; i <= maxWeight; i++)
    {
        if (weight[0] <= i)
            dp[0][i] = value[0];
    }

    for (int i = 1; i < n; i++)
        for (int j = 0; j <= maxWeight; j++)
        {
            int notTake = dp[i - 1][j];
            int take = INT_MIN;
            if (weight[i] <= j)
                take = value[i] + dp[i - 1][j - weight[i]];
            dp[i][j] = max(take, notTake);
        }
    return dp[n - 1][maxWeight];
}

int knapsackSpace(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0), cur(maxWeight + 1, 0);
    for (int i = 0; i <= maxWeight; i++)
    {
        if (weight[0] <= i)
            prev[i] = value[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            int notTake = prev[j];
            int take = INT_MIN;
            if (weight[i] <= j)
                take = value[i] + prev[j - weight[i]];
            cur[j] = max(take, notTake);
        }
        prev = cur;
    }
    return prev[maxWeight];
}

int knapsackSingleSpace(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0);
    for (int i = 0; i <= maxWeight; i++)
    {
        if (weight[0] <= i)
            prev[i] = value[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = maxWeight; j >= 0; j--)
        {
            int notTake = prev[j];
            int take = INT_MIN;
            if (weight[i] <= j)
                take = value[i] + prev[j - weight[i]];
            prev[j] = max(take, notTake);
        }
    }
    return prev[maxWeight];
}
int main()
{
}