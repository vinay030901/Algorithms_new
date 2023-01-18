/*
You are given an array ‘ARR’ of ‘N’ integers and a target number, ‘TARGET’. Your task is to build an expression out of an array by adding one of the symbols '+' and '-' before each integer in an array, and then by concatenating all the integers, you want to achieve a target. You have to return the number of ways the target can be achieved.
For Example :
You are given the array ‘ARR’ = [1, 1, 1, 1, 1], ‘TARGET’ = 3. The number of ways this target can be achieved is:
1. -1 + 1 + 1 + 1 + 1 = 3
2. +1 - 1 + 1 + 1 + 1 = 3
3. +1 + 1 - 1 + 1 + 1 = 3
4. +1 + 1 + 1 - 1 + 1 = 3
5. +1 + 1 + 1 + 1 - 1 = 3
These are the 5 ways to make. Hence the answer is 5.
Input Format :
The first line of input contains a single integer ‘T’ representing the number of test cases.

The first line of each test case contains two space-separated integers ‘N’ and ‘TARGET’ representing the size of the given array and the target.

The second line of each test case contains ‘N’ space-separated integers representing the elements of the array.
Output Format :
For each test case, print a single integer representing the number of ways to form a target.

Print a separate line for each test case.
Constraints :
1 <= T <= 10
1 <= N <= 25
-1000 <= TARGET <= 1000
0 <= ARR[i] <= 1000

Time Limit: 1 sec
Note :
You do not need to print anything. It has already been taken care of. Just implement the given function.*/
#include <bits/stdc++.h>
using namespace std;

// this question is like dividing two subset whose difference is given value, since we need a subset a decrease the second subset from it

int recur(vector<int> &arr, int n, int k, vector<vector<int>> &dp)
{
    // we will make the base condition, we have zero as input too
    if (n == 0)
    {
        if (k == 0 && arr[0] == 0)
            return 2;
        else if (k == 0 || k == arr[0])
            return 1;
        else
            return 0;
    }

    if (dp[n][k] != -1)
        return dp[n][k];
    int notTake = recur(arr, n - 1, k, dp);
    int take = 0;
    if (arr[n] <= k)
        take = recur(arr, n - 1, k - arr[n], dp);
    return dp[n][k] = take + notTake;
}
int targetSum(int n, int target, vector<int> &arr)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if ((sum + target) % 2 != 0 || (sum + target) < 0)
        return 0;
    target = (sum + target) / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return recur(arr, n - 1, target, dp);
}

int targetSumTabulation(int n, int target, vector<int> &arr)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if ((sum + target) % 2 != 0)
        return 0;
    target = (sum + target) / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    if (arr[0] <= target && arr[0] != 0)
        dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            int notTake = dp[i - 1][j];
            int take = 0;
            if (arr[i] <= j)
                take = dp[i - 1][j - arr[i]];
            dp[i][j] = take + notTake;
        }
    }
    return dp[n - 1][target];
}

int targetSumSpace(int n, int target, vector<int> &arr)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if ((sum + target) % 2 != 0)
        return 0;
    target = (sum + target) / 2;
    vector<int> prev(target + 1, 0);
    if (arr[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;
    if (arr[0] <= target && arr[0] != 0)
        prev[arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = target; j >= 0; j--)
        {
            int notTake = prev[j];
            int take = 0;
            if (arr[i] <= j)
                take = prev[j - arr[i]];
            prev[j] = take + notTake;
        }
    }
    return prev[target];
}
int main()
{
}