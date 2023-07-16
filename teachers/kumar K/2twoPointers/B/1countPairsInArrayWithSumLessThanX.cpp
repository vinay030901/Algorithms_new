// Given a sorted integer array and number x, the task is to count pairs in array whose sum is less than x.

// Examples:

// Input  : arr[] = {1, 3, 7, 9, 10, 11}
//          x = 7
// Output : 1
// There is only one pair (1, 3)

// Input  : arr[] = {1, 2, 3, 4, 5, 6, 7, 8}
//          x = 7
// Output : 6
// Pairs are (1, 2), (1, 3), (1, 4), (1, 5)
//           (2, 3) and (2, 4)
#include <bits/stdc++.h>
using namespace std;
int countPairs(vector<int> &arr, int x)
{
    int i = 0, j = arr.size() - 1, ans = 0;
    while (i < j)
    {
        if (arr[i] + arr[j] < x)
        {
            ans += (j - i); // if arr[i] + arr[j] is less than x, then all the values from i+1 to j will make a pair with i
            i++;
        }
        else
            j++;
    }
    return ans;
}