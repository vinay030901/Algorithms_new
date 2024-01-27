/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.



Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.*/
#include <bits/stdc++.h>
using namespace std;
int dir[5] = {-1, 0, 1, 0, -1};
int orangesRotting(vector<vector<int>> &arr)
{
    queue<pair<int, int>> q;
    int n = arr.size(), m = arr[0].size(), fresh = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] == 2)
                q.emplace(i, j);
            else if (arr[i][j] == 1)
                fresh++;
    int cnt = -1;

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dir[i], ny = y + dir[i + 1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == 0 || arr[nx][ny] == 2)
                    continue;
                arr[nx][ny] = 2;
                q.emplace(nx, ny);
                fresh--;
            }
        }
        cnt++;
    }
    if (fresh > 0)
        return -1;
    return cnt == -1 ? 0 : cnt;
}
int main()
{
    // Your code here
    return 0;
}