/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.



Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]

Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100*/

#include <bits/stdc++.h>
using namespace std;

// memoize code
int recur(vector<vector<int>> &arr, int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
        return arr[m][n];
    else if (m < 0 || n < 0)
        return INT_MAX;
    else if (dp[m][n] != -1)
        return dp[m][n];
    else
    {
        return dp[m][n] = arr[m][n] + min(recur(arr, m - 1, n, dp), recur(arr, m, n - 1, dp));
    }
}
int minPathSum(vector<vector<int>> &arr)
{
    int m = arr.size(), n = arr[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return recur(arr, m - 1, n - 1, dp);
}

// tabulation code
int minPathSum(vector<vector<int>> &arr)
{
    int m = arr.size(), n = arr[0].size();
    for (int i = 1; i < n; i++)
        arr[0][i] += arr[0][i - 1];
    for (int i = 1; i < m; i++)
        arr[i][0] += arr[i - 1][0];

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
        {
            arr[i][j] += min(arr[i - 1][j], arr[i][j - 1]);
        }
    return arr[m - 1][n - 1];
}

// space optimizaton

int minPathSum(vector<vector<int>> &arr)
{
    int m = arr.size(), n = arr[0].size();
    vector<int> pre(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> cur(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                cur[i] = arr[i][j];
            else
            {
                int up = arr[i][j];
                if (i > 0)
                    up += pre[j];
                else
                    up += 1e9;
                int left = arr[i][j];
                if (j > 0)
                    left += cur[j - 1];
                else
                    left += 1e9;
                cur[j] = min(up, left);
            }
        }
        pre = cur;
    }

    return pre[n - 1];
}
int main()
{
}