/*
Given an m x n 2D binary grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume
all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/
#include <bits/stdc++.h>
using namespace std;
// to do this,we simply use dfs and count the number of components in the grid
vector<int> dx = {-1, 0, 0, 1};
vector<int> dy = {0, 1, -1, 0};
bool isValid(int x, int y, int n, int m, vector<vector<int>> &vis, vector<vector<char>> &arr)
{
    // the value is valid if it is in range and it is equal to 1
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if (vis[x][y] == 1 || arr[x][y] == '0')
        return false;
    return true;
}
void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<char>> &arr, int n, int m)
{
    // we will check in all 4 directions for the 1 value, and if we find it, we call dfs, to check we used isValid function
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
        if (isValid(x + dx[i], y + dy[i], n, m, vis, arr))
            dfs(x + dx[i], y + dy[i], vis, arr, n, m);
}
int numIslands(vector<vector<char>> &arr)
{
    // finding the size of grid and making the visited matrix
    int n = arr.size(), m = arr[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] and arr[i][j] == '1') // then we call dfs if arr value is 1
            {
                cnt++;
                dfs(i, j, vis, arr, n, m);
            }
        }
    return cnt;
}
int main()
{
    vector<vector<char>> arr;
}