/*
Given a 2D array, print it in spiral form. See the following examples.

Examples:

Input:  1    2   3   4
        5    6   7   8
        9   10  11  12
        13  14  15  16
Output: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
Explanation: The output is matrix in spiral format.

Input:  1   2   3   4  5   6
        7   8   9  10  11  12
        13  14  15 16  17  18
Output: 1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11
Explanation :The output is matrix in spiral format.*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
        // to do this question, we declared 4 variables, all specifying a certain point in matrix,
        /* if our matrix is:
       top
        |
        1  2  3  4
        5  6  7  8
        9 10 11 12
 down->13 14 15 16
        |        |
       left     right
       first we print left to right and use top for row index, we increase the value of top so that next time, bottom column will
       get printed, we change the direction too
        then top to down and use right for column index, we decrease the value of right
       then right to left and use down as row, decrease the value of down
       the down to top and use left for column index, then increase the value of left, for next column
       atlast we change the direction, dir will be 0,1,2,3 in above serial*/
        int n = 4;
        int arr[n][n] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
        int top = 0, down = n - 1, left = 0, right = n - 1, dir = 0;
        while (left <= right && top <= down)
        {
                if (dir == 0)
                {
                        for (int i = left; i <= right; i++) // print left to right
                                cout << arr[top][i] << " ";
                        top++;
                }
                else if (dir == 1)
                {
                        for (int i = top; i <= down; i++)
                                cout << arr[i][right] << " ";
                        right--;
                }
                else if (dir == 2)
                {
                        for (int i = right; i >= left; i--)
                                cout << arr[down][i] << " ";
                        down--;
                }
                else
                {
                        for (int i = down; i >= top; i--)
                                cout << arr[i][left] << " ";
                        left++;
                }
                dir = (dir + 1) % 4;
        }
}