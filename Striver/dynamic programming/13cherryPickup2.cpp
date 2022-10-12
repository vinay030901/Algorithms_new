/*
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.


Example 1:


Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.
Example 2:


Input: grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
Output: 28
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
Total of cherries: 17 + 11 = 28.


Constraints:

rows == grid.length
cols == grid[i].length
2 <= rows, cols <= 70
0 <= grid[i][j] <= 100*/
#include <bits/stdc++.h>
using namespace std;
/*
1. express everything in terms of i1,j1 and i2,j2
2. explore all the paths
3. give the maximum sum possible*/

/*what we did here is
- we know that every position, we have 9 choices, since on alice can go 3 paths and with every alice path, we have 3 reactions for
her from bob
- so we run a loop from -1 to 1, which -1-left column, 0-down, 1-right column,
- and find the best max value from it.
- and that would be our path to go*/
int recur(vector<vector<int>> &arr, int i, int j1, int j2, vector<vector<vector<int>>> &dp, int m, int n)
{
    // here we need to start both the robots together
    if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m)
        return -1e8; // out of bounds

    if (i == n - 1)
    {
        if (j1 == j2)
            return arr[i][j1];
        else
            return arr[i][j1] + arr[i][j2];
    }

    // so we will explore all the paths where alice and bob can be together
    // there are 9 paths- for every single bob move, we have 3 alice paths
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    int mx = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int val = 0;
            if (j1 == j2)
                val = arr[i][j1];
            else
                val = arr[i][j1] + arr[i][j2];
            val += recur(arr, i + 1, j1 + dj1, j2 + dj2, dp, m, n);
            mx = max(val, mx);
        }
    }
    return dp[i][j1][j2] = mx;
}
int cherryPickup(vector<vector<int>> &arr)
{
    int n = arr.size(), m = arr[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return recur(arr, 0, 0, m - 1, dp, m, n);
}

int cherryPickupTabulation(vector<vector<int>> &arr)
{
    int n = arr.size(), m = arr[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
    for (int j1 = 0; j1 < m; j1++)

        for (int j2 = 0; j2 < m; j2++)

            if (j1 == j2)
                dp[n - 1][j1][j2] = arr[n - 1][j1];
            else
                dp[n - 1][j1][j2] = arr[n - 1][j1] + arr[n - 1][j2];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int mx = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int val = 0;
                        if (j1 == j2)
                            val = arr[i][j1];
                        else
                            val = arr[i][j1] + arr[i][j2];
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            val += dp[i + 1][j1 + dj1][j2 + dj2];
                        else
                            val += -1e8;
                        mx = max(val, mx);
                    }
                }
                dp[i][j1][j2] = mx;
            }
        }
    }
    return dp[0][0][m - 1];
}

// space optimization
int cherryPickupSpace(vector<vector<int>> &arr)
{
    int n = arr.size(), m = arr[0].size();
    vector<vector<int>> front(m, vector<int>(m, 0)), cur(m, vector<int>(m, 0));
    for (int j1 = 0; j1 < m; j1++)

        for (int j2 = 0; j2 < m; j2++)

            if (j1 == j2)
                front[j1][j2] = arr[n - 1][j1];
            else
                front[j1][j2] = arr[n - 1][j1] + arr[n - 1][j2];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int mx = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int val = 0;
                        if (j1 == j2)
                            val = arr[i][j1];
                        else
                            val = arr[i][j1] + arr[i][j2];
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            val += front[j1 + dj1][j2 + dj2];
                        else
                            val += -1e8;
                        mx = max(val, mx);
                    }
                }
                cur[j1][j2] = mx;
            }
        }
        front = cur;
    }
    return front[0][m - 1];
}
int main()
{
}