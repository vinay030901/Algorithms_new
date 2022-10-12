/*
Given a boolean 2D array, where each row is sorted. Find the row with the maximum number of 1s.

Example:

Input matrix
0 1 1 1
0 0 1 1
1 1 1 1  // this row has maximum 1s
0 0 0 0

Output: 2*/
#include <bits/stdc++.h>
using namespace std;
int firstOne(vector<int> &arr, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if ((mid == 0 || arr[mid - 1] == 0) && arr[mid] == 1)
        { // if our mid is 1 and previous value is 0, then we will return
            return mid;
        }
        else if (arr[mid] == 1)
            high = mid - 1; // if element is 1, we will go to left side
        else
            low = mid + 1; // if element is 0, we will go towards right side
    }
    return -1;
}
int main()
{
    vector<vector<int>> arr = {{0, 1, 1, 1}, {0, 0, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};
    int n = arr.size(), m = arr[0].size();
    /* need to count the row with maximum number of ones, this could easily be done in O(n^2) time
    but we need to do it in less time.

    so our first method could be to find the first 1 in a row, we will do that in every row and return the min value
    this would be done using binary search*/
    int mn = INT_MAX, cnt, ind;
    for (int i = 0; i < n; i++)
    {
        cnt = firstOne(arr[i], 0, m - 1); // we will find the first value of using this
        if (cnt != -1 && cnt < mn)        // whichever row has minimum count, that w1ould be the answer
        {
            mn = cnt;
            ind = i + 1;
        }
    }
    cout << "index: " << ind << endl;

    /* another way to do this
    in this process, we will start from end of first row and decrement till we get 0, then
    we will go to other row, if the value of column decrease now, that would be our answer now, because we needed to decrease
    the column count here, else we will move on, this method will take only O(m+n) time too*/
    int j = m - 1, mn_ind;
    for (int i = 0; i < n; i++)
    {
        int flag = false;
        while (j >= 0 && arr[i][j] == 1)
        {
            j--;
            flag = true;
        }
        if (flag == true)
            mn_ind = i;
    }
    cout << "row with minimum number of ones using this method: " << mn_ind + 1 << endl;
}