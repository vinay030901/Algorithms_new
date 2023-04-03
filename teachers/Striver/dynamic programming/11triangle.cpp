/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.



Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10


Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104


Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
*/
#include <bits/stdc++.h>
using namespace std;
int recur(vector<vector<int>> &arr, int n, int i, int j, vector<vector<int>> &dp)
{
    if (i == n)

        return arr[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = arr[i][j] + recur(arr, n, i + 1, j, dp);
    int right = arr[i][j] + recur(arr, n, i + 1, j + 1, dp);
    return dp[i][j] = min(down, right);
}
int minimumTotal(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return recur(arr, n - 1, 0, 0, dp);
}

// tabulation method
// since in memoization, our base was when we reach the value of n, therefore in this case too
// our loop will start from n value
int minimumTotalTabulation(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (i == n - 1)
                dp[i][j] = arr[i][j];
            else
                dp[i][j] = arr[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    return dp[0][0];
}

// space optimization
int minimumTotalTabulation(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<int> cur(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (i == n - 1)
                cur[j] = arr[i][j];
            else
                cur[j] = arr[i][j] + min(cur[j], cur[j + 1]);
        }
    }
    return cur[0];
}
int main()
{
}