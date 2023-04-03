/*
Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of
indexes such that both c > a and d > b.
Example:

Input:
mat[N][N] = {{ 1, 2, -1, -4, -20 },
             { -8, -3, 4, 2, 1 },
             { 3, 8, 6, 1, 3 },
             { -4, -1, 1, 7, -6 },
             { 0, -4, 10, -5, 1 }};
Output: 18
The maximum value is 18 as mat[4][2]
- mat[1][0] = 18 has maximum difference.
The program should do only ONE traversal of the matrix. i.e. expected time complexity is O(n2)
A simple solution would be to apply Brute-Force. For all values mat(a, b) in the matrix, we find mat(c, d) that
has maximum value such that c > a and d > b and keeps on updating maximum value found so far. We finally return
the maximum value.*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> arr = {{1, 2, -1, -4, -20},
                               {-8, -3, 4, 2, 1},
                               {3, 8, 6, 1, 3},
                               {-4, -1, 1, 7, -6},
                               {0, -4, 10, -5, 1}};
    int n = arr.size(), m = arr[0].size();

    /*so we need to find the elements where differce is max and the index of second elements is 4
    greater than the index of first element.
    so to solve this we will start from the bottom end
    then we will calculate the the max of last row and last column
    we will then find the difference between the last row and upper row, and we will carry the  max difference
    after finding the max difference, we will update our row and column with the maximum value.*/

    int mx = arr[n - 1][m - 1];
    // finding the max row
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[n - 1][i] > mx)
            mx = arr[n - 1][i];
        arr[n - 1][i] = mx;
    }

    // now initialise the last column
    mx = arr[n - 1][m - 1];
    for (int i = m - 2; i >= 0; i--)
    {
        if (arr[i][m - 1] > mx)
            mx = arr[i][m - 1];
        arr[i][m - 1] = mx;
    }

    // now we will compare each value for max and initialise the value with the greater of its bottom or right
    int ans = INT_MIN;
    for(int i=n-2;i>=0;i--)
    for(int j=n-2;j>=0;j--)
    {
        if(arr[i+1][j+1]-arr[i][j]>ans)
        ans=arr[i+1][j+1]-arr[i][j];

        arr[i][j]=max(arr[i][j],max(arr[i+1][j],arr[i][j+1]));
    }
    cout<<ans;
}