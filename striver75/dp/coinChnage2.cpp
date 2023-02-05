/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.



Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1*/
#include <bits/stdc++.h>
using namespace std;
int recur(vector<int> &coins, int amount, int n, vector<vector<int>> &dp)
{
    if (amount < 0)
        return 0;
    if (amount == 0)
        return 1;
    if (n == 0)
        return amount % coins[n] == 0;
    if (dp[n][amount] != -1)
        return dp[n][amount];
    int nottake = recur(coins, amount, n - 1, dp);
    int take = 0;
    if (coins[n] <= amount)
        take = recur(coins, amount - coins[n], n, dp);
    return dp[n][amount] = take + nottake;
}
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    return recur(coins, amount, n - 1, dp);
}
int main()
{
}