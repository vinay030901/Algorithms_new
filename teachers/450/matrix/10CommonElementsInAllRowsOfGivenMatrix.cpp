/*
Given an m x n matrix, find all common elements present in all rows in O(mn) time and one traversal of matrix.
Example:

Input:
mat[4][5] = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {8, 1, 2, 7, 9},
            };

Output:
1 8 or 8 1
8 and 1 are present in all rows.*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> arr = {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };
    // the brute force approach to do this is to check all the elements and count their frequency
    // another approach could be sort the matrix, the same elements will appear together and we can
    // easily mark them

    // but an O(mn) solution is use maps, put every element in map and check their frequency, if it is equal to count
    // row,
    int n = arr.size(), m = arr[0].size();
    map<int, int> mp;
    for (int j = 0; j < m; j++) // first we initialise every element with 1, so if any element appear twice, it will be initialised
        // by one only
        mp[arr[0][j]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[arr[i][j]] == i) // we traverse the array and check if the element has a value of i, due to previous row
            // if it has we will increase its frequency, otherwise it will not change
            {
                mp[arr[i][j]] = i + 1;
                if (i == n - 1 && mp[arr[i][j]] == n) // if we are not the last row, we check if element has appeared those number of
                    // times, and then print the element
                    cout << arr[i][j] << " ";
            }
        }
    }
}