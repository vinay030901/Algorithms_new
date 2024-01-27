/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.
Example 1:

Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.*/
#include <bits/stdc++.h>
using namespace std;
int mx = 0, n, m, cnt = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void dfs(int x, int y, vector<vector<bool>> &vis, vector<vector<int>> &arr)
{
    vis[x][y] = 1;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] == 1 || arr[nx][ny] == 0)
            continue;
        dfs(nx, ny, vis, arr);
    }
}
int maxAreaOfIsland(vector<vector<int>> &arr)
{
    n = arr.size();
    m = arr[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && arr[i][j] == 1)
            {
                dfs(i, j, vis, arr);
                mx = max(mx, cnt);
                cnt = 0;
            }
        }
    return mx;
}
int main()
{
    // Your code here
    return 0;
}