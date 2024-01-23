/*Given an m x n matrix, return all elements of the matrix in spiral order.
Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100*/
#include <bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &arr)
{
    int top = 0, right = arr[0].size() - 1, left = 0, down = arr.size() - 1, dir = 0;
    vector<int> ans;
    while (left <= right && top <= down)
    {
        if (dir == 0)
        {
            for (int i = left; i <= right; i++)
                ans.push_back(arr[top][i]);
            top++;
        }
        else if (dir == 1)
        {
            for (int i = top; i <= down; i++)
                ans.push_back(arr[i][right]);
            right--;
        }
        else if (dir == 2)
        {
            for (int i = right; i >= left; i--)
                ans.push_back(arr[down][i]);
            down--;
        }
        else if (dir == 3)
        {
            for (int i = down; i >= top; i--)
                ans.push_back(arr[i][left]);
            left++;
        }
        dir = (dir + 1) % 4;
    }
    return ans;
}
int main()
{
    // Your code here
    return 0;
}