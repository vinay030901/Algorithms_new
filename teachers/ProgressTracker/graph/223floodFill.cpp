/*An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.



Example 1:


Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.


Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n*/
#include <bits/stdc++.h>
using namespace std;
int m, n;
bool out = false;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void dfs(int x, int y, vector<vector<bool>> &vis, int color, vector<vector<int>> &arr, int val)
{
    vis[x][y] = 1;
    arr[x][y] = color;
    for (int i = 0; i < 4; i++)
    {
        int nx = dx[i] + x, ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] == 1 || arr[nx][ny] != val)
            continue;
        dfs(nx, ny, vis, color, arr, val);
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &arr, int sr, int sc, int color)
{
    n = size(arr);
    m = size(arr[0]);
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    int val = arr[sr][sc];
    dfs(sr, sc, vis, color, arr, val);
    return arr;
}
int main()
{
    // Your code here
    return 0;
}