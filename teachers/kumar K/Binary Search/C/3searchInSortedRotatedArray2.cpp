/*
here is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
You must decrease the overall operation steps as much as possible.
Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false


Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104*/
#include <bits/stdc++.h>
using namespace std;
bool search(vector<int> &arr, int target)
{
    int h = arr.size() - 1, l = 0;
    while (l <= h)
    {
        int mid = (l + h) >> 1;
        if (arr[mid] == target)
            return true;

        // we have edge condition like- 1,0,1,1,1,1-so we if we arrive at 1, the value is equal on both sides
        // so we have to just increase and decrease the low and high
        if (arr[mid] == arr[l] && arr[mid] == arr[h])
        {
            l++;
            h--;
        }
        // check if the array is sorted in the left side
        else if (arr[l] <= arr[mid])
        {
            if (arr[l] <= target && arr[mid] >= target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        else
        {
            if (arr[mid] <= target && arr[h] >= target)
                l = mid + 1;
            else
                h = mid - 1;
        }
    }
    return false;
}
int main()
{

    return 0;
}