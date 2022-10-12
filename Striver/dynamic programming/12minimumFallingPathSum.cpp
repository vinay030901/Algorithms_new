/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).



Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.*/

#include <bits/stdc++.h>
using namespace std;
int recur(vector<vector<int>> &arr, int n, int i, int j, vector<vector<int>> &dp)
{
    if (i == n)
        return arr[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    if (j == 0)
    {
        int down = arr[i][j] + recur(arr, n, i + 1, j, dp);
        int right = arr[i][j] + recur(arr, n, i + 1, j + 1, dp);
        return dp[i][j] = min(down, right);
    }
    else if (j == n)
    {
        int down = arr[i][j] + recur(arr, n, i + 1, j, dp);
        int left = arr[i][j] + recur(arr, n, i + 1, j - 1, dp);
        return dp[i][j] = min(down, left);
    }
    else
    {
        int down = arr[i][j] + recur(arr, n, i + 1, j, dp);
        int right = arr[i][j] + recur(arr, n, i + 1, j + 1, dp);
        int left = arr[i][j] + recur(arr, n, i + 1, j - 1, dp);
        return dp[i][j] = min(down, min(left, right));
    }
}
// this is like the triangle question
// the few changes we needed to do is triangle had only one starting point but this has n, so ran a loop till n and call the recursion
// another change is, here we can move to left direction too
// so I gave 2 conditons, if column value is 0, then I'll only check the down and right and if column value is n-1
// then I'll only check down and left
int minFallingPathSum(vector<vector<int>> &arr)
{
    int n = arr.size();
    int mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        mn = min(mn, recur(arr, n - 1, 0, i, dp));
    }

    return mn;
}

// now we will conver above recursion approach to tabulatio
int minFallingPathSum(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int j = 0; j < n; j++)
        dp[0][j] = arr[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int down = INT_MAX, right = INT_MAX, left = INT_MAX;
            down = arr[i][j] + dp[i - 1][j];
            if (j > 0)
                left = arr[i][j] + dp[i - 1][j - 1];
            if (j < n - 1)
                right = arr[i][j] + dp[i - 1][j + 1];
            dp[i][j] = min(down, min(left, right));
        }
    }
    int mn = INT_MAX;
    for (int i = 0; i < n; i++)
        mn = min(mn, dp[n - 1][i]);
    return mn;
}

// space optimization
int minFallingPathSum(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<int> cur(n, 0), pre(n, 0);
    for (int j = 0; j < n; j++)
        pre[j] = arr[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int down = INT_MAX, right = INT_MAX, left = INT_MAX;
            down = arr[i][j] + pre[j];
            if (j > 0)
                left = arr[i][j] + pre[j - 1];
            if (j < n - 1)
                right = arr[i][j] + pre[j + 1];
            cur[j] = min(down, min(left, right));
        }
        pre = cur;
    }
    return *min_element(pre.begin(), pre.end());
}
int main()
{
}