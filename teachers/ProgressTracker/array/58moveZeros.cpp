/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.



Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]


Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1


Follow up: Could you minimize the total number of operations done?*/
#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int> &arr)
{
    int j = 0;
    for (int i = 0; i < arr.size(); i++)
        if (arr[i])
            arr[j++] = arr[i];
    for (; j < arr.size(); j++)
        arr[j] = 0;
}
void moveZeroes(vector<int> &arr)
{
    int i = 0, j = 0, n = arr.size();
    while (i < n && j < n)
    {
        while (i < n && arr[i] != 0)
            i++;
        j = i + 1;
        while (j < n && arr[j] == 0)
            j++;
        if (i < n && j < n)
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
    }
}