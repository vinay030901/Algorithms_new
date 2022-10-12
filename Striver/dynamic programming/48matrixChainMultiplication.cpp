/*
Given the dimension of a sequence of matrices in an array arr[], where the dimension of the ith matrix is (arr[i-1] * arr[i]), the task is to find the most efficient way to multiply these matrices together such that the total number of element multiplications is minimum.

Examples:


Input: arr[] = {40, 20, 30, 10, 30}
Output: 26000
Explanation:There are 4 matrices of dimensions 40×20, 20×30, 30×10, 10×30.
Let the input 4 matrices be A, B, C and D.
The minimum number of  multiplications are obtained by
putting parenthesis in following way (A(BC))D.
The minimumm is 20*30*10 + 40*20*10 + 40*10*30

Input: arr[] = {1, 2, 3, 4, 3}
Output: 30
Explanation: There are 4 matrices of dimensions 1×2, 2×3, 3×4, 4×3.
Let the input 4 matrices be A, B, C and D.
The minimum number of multiplications are obtained by
putting parenthesis in following way ((AB)C)D.
The minimum number is 1*2*3 + 1*3*4 + 1*4*3 = 30

Input: arr[] = {10, 20, 30}
Output: 6000
Explanation: There are only two matrices of dimensions 10×20 and 20×30.
So there  is only one way to multiply the matrices, cost of which is 10*20*30*/

#include <bits/stdc++.h>
using namespace std;
int mcm(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mn = INT_MAX;
    // we are partitioning the values from i to j
    // so we have an array 10  20   30 40 50
    // then we have            i,k         j6
    // therefore k will go till j-1, so that we can have solution of 40,50
    // and we we add steps, will do arr[i-1]*k, so we have 10*20 first
    // also, first- A[0]*A[1], 2nd- A[1]*A[2], 3rd- A[2]*A[3], 4th- A[3]*A[4], ith- A[i-1]*A[i]
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + mcm(arr, i, k, dp) + mcm(arr, k + 1, j, dp);
        mn = min(mn, steps);
    }
    return dp[i][j] = mn;
}
int matrixMultiplication(vector<int> &arr, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return mcm(arr, 1, n - 1, dp);
}

int mcm(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++) // since j is always at the right of i
        {
            if (i == j)
                dp[i][j] = 0;
            else
            {
                int mn = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                    mn = min(mn, steps);
                }
                dp[i][j] = mn;
            }
        }
    }
    return dp[1][n - 1];
}
int main()
{
}