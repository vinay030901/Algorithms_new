/*Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.



Example 1:


Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.
Example 2:

Input: board = [["X"]]
Output: [["X"]]


Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int diff[5] = {-1, 0, 1, 0, -1};
    int n, m;
    void fill(vector<vector<char>> &board, int i, int j, vector<vector<int>> &vis)
    {
        if (i >= n || i < 0 || j < 0 || j >= m || board[i][j] == 'X' || vis[i][j] == 1)
            return;
        vis[i][j] = 1;
        for (int d = 0; d < 4; d++)
        {
            int ni = i + diff[d], nj = j + diff[d + 1];
            fill(board, ni, nj, vis);
        }
    }
    void solve(vector<vector<char>> &board)
    {
        n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')
            {
                fill(board, i, 0, vis);
            }
            if (board[i][m - 1] == 'O')
                fill(board, i, m - 1, vis);
        }
        for (int j = 0; j < m; j++)
        {
            if (board[0][j] == 'O')
                fill(board, 0, j, vis);
            if (board[n - 1][j] == 'O')
                fill(board, n - 1, j, vis);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (vis[i][j] == 0)
                    board[i][j] = 'X';
                else
                    board[i][j] = 'O';
    }
};
int main()
{
    // Your code here
    return 0;
}