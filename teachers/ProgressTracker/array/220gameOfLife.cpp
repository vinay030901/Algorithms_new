/*According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.



Example 1:


Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
Example 2:


Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void gameOfLife(vector<vector<int>> &arr)
    {
        // https://leetcode.com/problems/game-of-life/discuss/1225591/C%2B%2B-two-approaches-with-intuition-or-faster-than-100
        // the approach is that we will make the matrix 2 or 3 for current dead or current live
        // in this way we will not have to take an extra matrix for doing this question
        int d[][2] = {{1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}};
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[0].size(); j++)
            {
                int live = 0;
                for (int k = 0; k < 8; k++)
                {
                    int x = i + d[k][0];
                    int y = j + d[k][1];
                    // cout<<x<<" "<<y<<" ";
                    if (x < 0 || x >= arr.size() || y < 0 || y >= arr[0].size())
                        continue;
                    if (arr[x][y] & 1)
                        live++;
                }
                // cout<<live<<" ";
                if (arr[i][j] == 0)
                {
                    if (live == 3)
                        arr[i][j] = 2; // dead person now alive
                }
                else if (arr[i][j] == 1)
                {
                    if (live < 2 || live > 3)
                        arr[i][j] = 3; // alive person now dead
                    // else arr[i][j]=3; // alive person alive
                }
            }
        }
        for (int i = 0; i < arr.size(); i++)
            for (int j = 0; j < arr[0].size(); j++)
            {
                if (arr[i][j] == 2)
                    arr[i][j] = 1;
                else if (arr[i][j] == 3)
                    arr[i][j] = 0;
            }
        //
    }
};
int main()
{
    // Your code here
    return 0;
}