/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row,
you may move to either index i or index i + 1 on the next row.

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
Output: -10*/
#include <bits/stdc++.h>
using namespace std;
int recursion(int i, int j, int n, vector<vector<int>> &arr, vector<vector<int>> &v)
{
    if (i == n - 1)
        return arr[i][j];
    if (v[i][j] != -1)
        return v[i][j];
    int down = arr[i][j] + recursion(i + 1, j, n, arr, v);
    int side = arr[i][j] + recursion(i + 1, j + 1, n, arr, v);
    v[i][j] = min(down, side);
    return v[i][j];
}
int minimumTotal(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<vector<int>> v(n, vector<int>(n, -1));
    return recursion(0, 0, n, arr, v);
}
int main()
{
}