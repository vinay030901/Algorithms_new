/*
Given an n x n matrix, where every row and column is sorted in non-decreasing order. Print all elements of matrix in sorted order.

Example:

Input: mat[][]  =  { {10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50},
                   };

Output:
Elements of matrix in sorted order
10 15 20 25 27 29 30 32 33 35 37 39 40 45 48 50*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> arr = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50},
    };
    // one simple way to do this put all the elements in a data structure and sort that data structure
    // in this way we will get our sorted data but its complexity is n*mLog(n*m)

    vector<int> v;
    int n = arr.size(), m = arr[0].size(), k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            v.push_back(arr[i][j]);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = v[k];
            k++;
        }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}