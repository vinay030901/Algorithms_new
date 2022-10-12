/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.



Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down


Constraints:

1 <= m, n <= 100*/

#include <bits/stdc++.h>
using namespace std;
int recur(int m, int n, vector<vector<int>> dp)
{
    // time complexity is exponential in nature here
    // space complexity is path length
    if (m == 0 && n == 0)
        return 1;
    else if (m < 0 || n < 0)
        return 0;
    if (dp[m][n] != -1)
        return dp[m][n];
    int up = recur(m - 1, n, dp);
    int left = recur(m, n - 1, dp);
    return dp[m][n] = up + left;
}
int uniquePaths(int m, int n)
{
    // here we need to find all possible ways to reach from top-left corner to bottom-right corner
    // since we want to find all ways, we need to use recursion
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << recur(m - 1, n - 1, dp) << endl;
}

// now we will move to the tabulation of the question
int uniquePathsTabulation(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int up, left;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}

// space optimization
int uniquePathsSpaceOptimization(int m, int n)
{
    /*The above solution runs in O(m * n) time and costs O(m * n) space. However, you may have noticed that each time when we update dp[i][j], we only need dp[i - 1][j] (at the previous row) and dp[i][j - 1] (at the current row). So we can reduce the memory usage to just two rows (O(n)).*/
    vector<int> cur(n, 1), pre(n, 1);
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            cur[j] = pre[j] + cur[j - 1];
        }
        pre = cur;
    }
    return pre[n - 1];
}

int uniquePathsSpaceOptimization(int m, int n)
{
    // Further inspecting the above code, pre[j] is just the cur[j] before the update. So we can further reduce the memory usage to one row.
    vector<int> cur(n, 1);
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            cur[j] += cur[j - 1];
        }
    }
    return cur[n - 1];
}
int main()
{
}