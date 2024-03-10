/*You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
Example 1:
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
Example 2:

Input: grid = [[1]]
Output: 4
Example 3:

Input: grid = [[1,0]]
Output: 4


Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid.*/
#include <bits/stdc++.h>
using namespace std;
int islandPerimeter(vector<vector<int>> &arr)
{
    int m = arr.size(), n = arr[0].size(), ans = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                int water = 0;
                if (i - 1 < 0)
                    water++;
                else if (arr[i - 1][j] == 0)
                    water++;
                if (i + 1 >= m)
                    water++;
                else if (arr[i + 1][j] == 0)
                    water++;
                if (j - 1 < 0)
                    water++;
                else if (arr[i][j - 1] == 0)
                    water++;
                if (j + 1 >= n)
                    water++;
                else if (arr[i][j + 1] == 0)
                    water++;
                ans += water;
            }
        }
    return ans;
}
int main()
{
    // Your code here
    return 0;
}