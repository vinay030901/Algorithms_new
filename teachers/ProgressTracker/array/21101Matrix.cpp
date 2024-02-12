/*Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.*/
#include <bits/stdc++.h>
using namespace std;
int dir[5] = {-1, 0, 1, 0, -1};
vector<vector<int>> updateMatrix(vector<vector<int>> &arr)
{
    int m = arr[0].size();
    int n = arr.size(), inf = m + n;
    // we can also dynamic programming for this question
    // what we will do use the previously calculated answers for our values
    // here we are using the top and left values, since the value could be 1 only, we can just add 1
    // to their minimum to find the answer till that place
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
                continue;
            int top = inf, left = inf;
            if (i - 1 >= 0)
                top = arr[i - 1][j];
            if (j - 1 >= 0)
                left = arr[i][j - 1];
            arr[i][j] = 1 + min(top, left);
        }

    // now we will use bottom and right and traverse from end, because there could be solution at the bottom too
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--)
        {
            if (arr[i][j] == 0)
                continue;
            int down = inf, right = inf;
            if (i + 1 < n)
                down = arr[i + 1][j];
            if (j + 1 < m)
                right = arr[i][j + 1];
            arr[i][j] = min(arr[i][j], 1 + min(down, right));
        }
    return arr;
}
int main()
{
    // Your code here
    return 0;
}