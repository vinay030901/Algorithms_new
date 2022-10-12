/*
Given a square matrix, turn it by 90 degrees in anti-clockwise direction without using any extra space.
Examples :

Input:
Matrix:
 1  2  3
 4  5  6
 7  8  9
Output:
 3  6  9
 2  5  8
 1  4  7
The given matrix is rotated by 90 degree
in anti-clockwise direction.

Input:
 1  2  3  4
 5  6  7  8
 9 10 11 12
13 14 15 16
Output:
 4  8 12 16
 3  7 11 15
 2  6 10 14
 1  5  9 13
The given matrix is rotated by 90 degree
in anti-clockwise direction.*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int n = arr.size(), m = arr[0].size();
    /* we need to rotate the matrix to 90 degrees, or you can say that anti clockwise
    so from -
    1  2  3  4      4  8 12 16
    5  6  7  8  ->  3  7 11 15
    9 10 11 12      2  6 10 14
    13 14 15 16     1  5  9 13

    we can easily do this question using extra space*/
    int ans[n][m] = {};
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        for (int j = m - 1; j >= 0; j--)
        {
            ans[k][i] = arr[i][j];
            k++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    /*but we can also do it inplace using just tranpose and then reversing the matrix
    1  2  3  4                   4  3  2  1                  4 8  12 16
    5  6  7  8 ->reverse row->   8  7  6  5 ->transpose->    3 7  11 15
    9  10 11 12                 12 11 10  9                  2 6  10 14
    13 14 15 16                 16 15 14  13                 1 5   9 13*/

    for (int i = 0; i < n; i++)
        reverse(arr[i].begin(), arr[i].end());
    for (int i = 0; i < n; i++)
        for (int j = i; j < m; j++)
            swap(arr[i][j], arr[j][i]);
    cout << "90 degree rotation using reverse and transpose: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}